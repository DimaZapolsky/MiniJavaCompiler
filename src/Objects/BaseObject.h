//
// Created by Dima Zapolsky on 17.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_

#include <memory>
#include <vector>

enum Types { Int, Boolean, IntArray, BooleanArray, Class, Null };

namespace objects {

class BaseObject {
 public:
  Types GetType() const;

  virtual int &GetIntValue() = 0;
  virtual bool &GetBooleanValue() = 0;
  virtual std::vector<int> &GetIntArray() = 0;
  virtual std::vector<bool> &GetBooleanArray() = 0;

 protected:
  Types type_{Null};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_
