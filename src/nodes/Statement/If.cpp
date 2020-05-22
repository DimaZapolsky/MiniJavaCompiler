//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "If.h"

If::If(Expr *expr, Statement *statement) :
    expr_(expr), statement_(statement) {}