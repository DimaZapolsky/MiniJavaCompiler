//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_MAINCLASS_H
#define COMPILERS_MAINCLASS_H

#include "Identifier.h"
#include "nodes/Lists/StatementList.h"
#include "../Visitors/Visitable.h"

class MainClass : public Visitable {
 public:
  MainClass(Identifier *identifier, StatementList *statementList);
  ~MainClass() = default;
  Identifier *GetIdentifier() const;
  StatementList *GetStatementList() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  Identifier *identifier_;
  StatementList *statementList_;
};

#endif //COMPILERS_MAINCLASS_H
