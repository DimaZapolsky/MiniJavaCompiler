//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_FALSE_H
#define COMPILERS_FALSE_H

#include "nodes/Expr/Expr.h"

class False : public Expr {
public:
    False() = default;
    ~False() = default;
};


#endif //COMPILERS_FALSE_H
