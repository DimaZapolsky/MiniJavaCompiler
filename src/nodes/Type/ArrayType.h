//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_ARRAYTYPE_H
#define COMPILERS_ARRAYTYPE_H

#include "Type.h"
#include "SimpleType.h"

class ArrayType : public Type {
public:
    ArrayType(SimpleType* simpleType);
    ~ArrayType() = default;
    SimpleType* GetSimpleType();
    virtual std::string GetIdentifier() override;


private:
    SimpleType* simpleType_;
};


#endif //COMPILERS_ARRAYTYPE_H
