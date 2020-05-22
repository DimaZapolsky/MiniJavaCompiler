//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "While.h"

While::While(Expr *expr, Statement *statement) :
    expr_(expr), statement_(statement) {}