//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_OBJECTCREATION_H
#define COMPILERS_OBJECTCREATION_H

#include "nodes/Expr/Expr.h"
#include "nodes/Type/TypeIdentifier.h"

class ObjectCreation : public Expr {
public:
    ObjectCreation(TypeIdentifier* typeIdentifier);
    ~ObjectCreation() = default;

private:
    TypeIdentifier* typeIdentifier_;
};


#endif //COMPILERS_OBJECTCREATION_H
