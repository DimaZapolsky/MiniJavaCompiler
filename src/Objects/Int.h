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
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() override;
  std::string GetTypeIdentifier() override;

 private:
  int value_{0};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_INT_H_
