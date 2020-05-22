//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "IfElse.h"

IfElse::IfElse(Expr *expr, Statement *statementTrue, Statement *statementFalse) :
    expr_(expr), statementTrue_(statementTrue), statementFalse_(statementFalse) {}