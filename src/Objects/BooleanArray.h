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
  BooleanArray(size_t size);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() override;

  std::string GetTypeIdentifier() override;

 private:
  std::vector<std::shared_ptr<objects::BaseObject>> value_{};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_BOOLEANARRAY_H_
