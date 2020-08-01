//
// Created by Dima Zapolsky on 25.07.2020.
//

#ifndef NAIVEINTERPRETER_SCOPELAYER_H
#define NAIVEINTERPRETER_SCOPELAYER_H

#include <cinttypes>
#include <unordered_map>
#include <unordered_set>

#include "../nodes/Identifier.h"
#include "../Objects/BaseObject.h"

 class ScopeLayer : public std::enable_shared_from_this<ScopeLayer> {
 public:
  ScopeLayer();
  ~ScopeLayer();
  explicit ScopeLayer(std::shared_ptr<ScopeLayer> parent);

  std::shared_ptr<ScopeLayer> GetParent();

  void DeclareVar(Identifier* identifier, std::string type);
  void PutVar(Identifier *identifier, const std::shared_ptr<objects::BaseObject>& value);
  std::shared_ptr<objects::BaseObject> GetVariable(Identifier* identifier);
  std::shared_ptr<objects::BaseObject>* GetVariablePtr(Identifier* identifier);
  bool VariableDeclared(Identifier *identifier) const;
  bool VariableInitialized(Identifier *identifier);

 private:
  std::shared_ptr<ScopeLayer> parent_;
  std::unordered_map<std::string, std::shared_ptr<objects::BaseObject>> initialized_;
};

#endif //NAIVEINTERPRETER_SCOPELAYER_H
