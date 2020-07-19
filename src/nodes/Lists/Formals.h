//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_FORMALS_H
#define COMPILERS_FORMALS_H

#include <vector>

#include "nodes/Formal.h"
#include "../../Visitors/Visitable.h"

class Formals : public Visitable {
public:
    Formals();
    ~Formals() = default;
    void AddFormal(Formal* formal);
  const std::vector<Formal *> &GetFormals() const;
 private:
    std::vector<Formal*> formals_;
};


#endif //COMPILERS_FORMALS_H
