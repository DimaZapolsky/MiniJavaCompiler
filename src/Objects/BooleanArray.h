//
// Created by Dima Zapolsky on 18.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_BOOLEANARRAY_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_BOOLEANARRAY_H_

#include "BaseObject.h"

namespace objects {

class BooleanArray : public BaseObject {
 public:
  BooleanArray();
  explicit BooleanArray(std::vector<bool> value_);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<int> &GetIntArray() override;
  std::vector<bool> &GetBooleanArray() override;

 private:
  std::vector<bool> value_{};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_BOOLEANARRAY_H_
