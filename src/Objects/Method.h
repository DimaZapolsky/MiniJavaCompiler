//
// Created by Dima Zapolsky on 30.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_NODES_TYPE_METHOD_H_
#define NAIVEINTERPRETER_SRC_NODES_TYPE_METHOD_H_

#include <nodes/Lists/Formals.h>
#include <iostream>
#include "Objects/NonSimpleObject.h"

namespace objects {

class Method : public NonSimpleObject {
 public:
  Method(Identifier *identifier, types::Type *return_type, Formals *formals, StatementList *statement_list);
  types::Type* GetReturnType();
  Formals* GetFormals();
  Identifier *GetIdentifier() const;
  std::string GetTypeIdentifier() override;
  StatementList *GetStatementList() const;
 private:
  Identifier* identifier_;
  types::Type* return_type_;
  Formals* formals_;
  StatementList* statement_list_;
};

}

#endif //NAIVEINTERPRETER_SRC_NODES_TYPE_METHOD_H_
