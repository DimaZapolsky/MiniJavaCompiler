//
// Created by Dima Zapolsky on 18.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_INT_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_INT_H_

#include "BaseObject.h"

namespace objects {

class Int : public BaseObject {
 public:
  Int();
  explicit Int(int value);
  explicit Int(std::shared_ptr<int> value);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<int> &GetIntArray() override;
  std::vector<bool> &GetBooleanArray() override;
  bool IsInitialized() override;

 private:
  std::shared_ptr<int> value_{nullptr};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_INT_H_
