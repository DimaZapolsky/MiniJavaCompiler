//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expr *l_expr, Expr *r_expr) :
    l_expr_(l_expr), r_expr_(r_expr) {}