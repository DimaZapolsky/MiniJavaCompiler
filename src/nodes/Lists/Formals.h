//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_FORMALS_H
#define COMPILERS_FORMALS_H

#include "nodes/Formal.h"
#include <vector>

class Formals {
public:
    Formals();
    ~Formals() = default;
    void AddFormal(Formal* formal);

private:
    std::vector<Formal*> formals_;
};


#endif //COMPILERS_FORMALS_H
