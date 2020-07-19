//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include "Type.h"

namespace types {
class SimpleType : public Type {
public:
    SimpleType() = default;
    ~SimpleType() = default;
    virtual std::string GetIdentifier() = 0;
};
}

#endif //COMPILERS_SIMPLETYPE_H
