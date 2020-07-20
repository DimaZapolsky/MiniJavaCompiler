//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "StatementList.h"

StatementList::StatementList() : statements_() {}

void StatementList::AddStatement(Statement *statement) {
  statements_.push_back(statement);
}
const std::vector<Statement *> &StatementList::GetStatements() const {
  return statements_;
}
void StatementList::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
