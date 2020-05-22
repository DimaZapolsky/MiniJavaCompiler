//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "IntegerLiteral.h"

IntegerLiteral::IntegerLiteral(int n) : value_(n) {}

int IntegerLiteral::GetValue() {
    return value_;
}
