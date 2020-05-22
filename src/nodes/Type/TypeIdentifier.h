//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_TYPEIDENTIFIER_H
#define COMPILERS_TYPEIDENTIFIER_H

#include "nodes/Type/SimpleType.h"
#include "nodes/Identifier.h"

class TypeIdentifier : public SimpleType {
public:
    TypeIdentifier(Identifier* identifier);
    ~TypeIdentifier() = default;
    std::string GetIdentifier();
private:
    Identifier* identifier_;
};


#endif //COMPILERS_TYPEIDENTIFIER_H
