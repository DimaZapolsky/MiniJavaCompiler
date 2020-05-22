//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_INT_H
#define COMPILERS_INT_H

#include "SimpleType.h"

class Int : public SimpleType {
public:
    Int() = default;
    ~Int() = default;
    virtual std::string GetIdentifier() override;
};


#endif //COMPILERS_INT_H
