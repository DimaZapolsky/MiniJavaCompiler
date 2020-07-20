//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "MainClass.h"

MainClass::MainClass(Identifier *identifier, StatementList *statementList) :
    identifier_(identifier), statementList_(statementList) {}
Identifier *MainClass::GetIdentifier() const {
  return identifier_;
}
StatementList *MainClass::GetStatementList() const {
  return statementList_;
}
void MainClass::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
