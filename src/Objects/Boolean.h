//
// Created by Dima Zapolsky on 18.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_BOOLEAN_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_BOOLEAN_H_

#include "BaseObject.h"

#include <memory>

namespace objects {

class Boolean : public BaseObject {
 public:
  Boolean();
  explicit Boolean(bool value);
  int &GetIntValue() override;
  bool &GetBooleanValue() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() override;
  std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() override;
  std::string GetTypeIdentifier() override;

 private:
  bool value_{false};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_BOOLEAN_H_
