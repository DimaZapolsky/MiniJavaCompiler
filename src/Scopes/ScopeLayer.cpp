//
// Created by Dima Zapolsky on 25.07.2020.
//

#include "ScopeLayer.h"
#include <Objects/Uninitialized.h>

#include <utility>
ScopeLayer::ScopeLayer() = default;

ScopeLayer::ScopeLayer(std::shared_ptr<ScopeLayer> parent) {
  parent_ = std::move(parent);
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetParent() {
  return parent_;
}

void ScopeLayer::PutVar(Identifier *identifier, const std::shared_ptr<objects::BaseObject>& value) {
  if (VariableDeclared(identifier)) {
    if (value->GetTypeIdentifier() != initialized_[identifier->GetIdentifier()]->GetTypeIdentifier()) {
      throw std::runtime_error("Type mismatch in assignment");
    }
    initialized_[identifier->GetIdentifier()] = value;
  } else {
    if (parent_) {
      parent_->PutVar(identifier, value);
    } else {
      throw std::runtime_error("Variable" + identifier->GetIdentifier() + "is not declared");
    }
  }
}

bool ScopeLayer::VariableDeclared(Identifier *identifier) const {
  return initialized_.count(identifier->GetIdentifier());
}

bool ScopeLayer::VariableInitialized(Identifier *identifier) {
  return initialized_.count(identifier->GetIdentifier()) && initialized_[identifier->GetIdentifier()]->GetType() != Null;
}

std::shared_ptr<objects::BaseObject> ScopeLayer::GetVariable(Identifier *identifier) {
  if (VariableDeclared(identifier)) {
    return initialized_[identifier->GetIdentifier()];
  } else {
    if (parent_) {
      return parent_->GetVariable(identifier);
    } else {
      throw std::runtime_error("Variable " + identifier->GetIdentifier() + " is not declared");
    }
  }
}

std::shared_ptr<objects::BaseObject>* ScopeLayer::GetVariablePtr(Identifier *identifier) {
  if (VariableDeclared(identifier)) {
    return &initialized_[identifier->GetIdentifier()];
  } else {
    if (parent_) {
      return parent_->GetVariablePtr(identifier);
    } else {
      throw std::runtime_error("Variable " + identifier->GetIdentifier() + " is not declared");
    }
  }
}

void ScopeLayer::DeclareVar(Identifier *identifier, std::string type) {
  if (initialized_.count(identifier->GetIdentifier())) {
    throw std::runtime_error("Redeclaration of variable " + identifier->GetIdentifier());
  }
  initialized_[identifier->GetIdentifier()] = std::make_shared<objects::Uninitialized>(std::move(type));
}

ScopeLayer::~ScopeLayer() = default;
