//
// Created by Dima Zapolsky on 31.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_VARIABLE_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_VARIABLE_H_

#include <nodes/Identifier.h>
#include <Objects/NonSimpleObject.h>
#include <nodes/Type/Type.h>

namespace objects {

class Variable : public NonSimpleObject {
 public:
  Variable(Identifier *identifier, types::Type *type);
  Identifier *GetIdentifier() const;
  types::Type *GetVarType() const;
  std::string GetTypeIdentifier() override;
 private:
  Identifier* identifier_;
  types::Type *var_type_;
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_VARIABLE_H_
