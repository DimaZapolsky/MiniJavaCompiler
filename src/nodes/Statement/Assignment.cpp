//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "Assignment.h"

Assignment::Assignment(Lvalue *lvalue, Expr *expr) :
    lvalue_(lvalue), expr_(expr) {}