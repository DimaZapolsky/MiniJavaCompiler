//
// Created by Dima Zapolsky on 31.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_NONSIMPLEOBJECT_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_NONSIMPLEOBJECT_H_

#include <Objects/BaseObject.h>

namespace objects {

class NonSimpleObject : public BaseObject {
 public:
  virtual int &GetIntValue() override;
  virtual bool &GetBooleanValue() override;
  virtual std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() override;
  virtual std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() override;
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_NONSIMPLEOBJECT_H_
