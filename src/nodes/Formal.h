//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_FORMAL_H
#define COMPILERS_FORMAL_H

#include "Identifier.h"
#include "nodes/Type/Type.h"
#include "Visitors/Visitable.h"

class Visitable;

class Formal : public Visitable {
public:
    Formal(types::Type* type, Identifier* identifier);
    ~Formal() = default;
  types::Type *GetType() const;
  Identifier *GetIdentifier() const;
 private:
    types::Type* type_;
    Identifier* identifier_;
};


#endif //COMPILERS_FORMAL_H
