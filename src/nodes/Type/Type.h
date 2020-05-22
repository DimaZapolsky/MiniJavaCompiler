//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_TYPE_H
#define COMPILERS_TYPE_H

#include <string>

class Type {
public:
    Type() = default;
    ~Type() = default;
    virtual std::string GetIdentifier() = 0;
};


#endif //COMPILERS_TYPE_H