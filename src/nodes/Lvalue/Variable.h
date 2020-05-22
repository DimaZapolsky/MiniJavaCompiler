//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_VARIABLE_H
#define COMPILERS_VARIABLE_H

#include "nodes/Lvalue/Lvalue.h"
#include "nodes/Identifier.h"

class Variable : public Lvalue {
public:
    Variable(Identifier* identifier);
    ~Variable() = default;

private:
    Identifier* identifier_;
};


#endif //COMPILERS_VARIABLE_H
