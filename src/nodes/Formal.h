//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_FORMAL_H
#define COMPILERS_FORMAL_H

#include "Identifier.h"
#include "nodes/Type/Type.h"

class Formal {
public:
    Formal(Type* type, Identifier* identifier);
    ~Formal() = default;

private:
    Type* type_;
    Identifier* identifier_;
};


#endif //COMPILERS_FORMAL_H
