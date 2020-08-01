//
// Created by Dima Zapolsky on 18.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_

#include <vector>

#include "BaseObject.h"
#include <Objects/Int.h>

namespace objects {

class IntArray : public BaseObject {
 public:
  IntArray();
  IntArray(size_t size);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() override;
  std::string GetTypeIdentifier() override;

 private:
  std::vector<std::shared_ptr<objects::BaseObject>> value_{};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_INTARRAY_H_
