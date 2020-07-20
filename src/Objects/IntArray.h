//
// Created by Dima Zapolsky on 18.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_

#include <vector>

#include "BaseObject.h"

namespace objects {

class IntArray : public BaseObject {
 public:
  IntArray();
  explicit IntArray(std::vector<int> value);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<int> &GetIntArray() override;
  std::vector<bool> &GetBooleanArray() override;

 private:
  std::vector<int> value_{};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_
