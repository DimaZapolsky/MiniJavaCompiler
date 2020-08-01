//
// Created by Dima Zapolsky on 17.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_

#include <memory>
#include <vector>
#include <string>

enum Types { Int, Boolean, IntArray, BooleanArray, Class, Null, Variable_t, Method };

namespace objects {

class Int;
class Boolean;

class BaseObject {
 public:
  Types GetType() const;

  virtual int &GetIntValue() = 0;
  virtual bool &GetBooleanValue() = 0;
  virtual std::vector<std::shared_ptr<objects::BaseObject>> &GetIntArray() = 0;
  virtual std::vector<std::shared_ptr<objects::BaseObject>> &GetBooleanArray() = 0;

  virtual std::string GetTypeIdentifier() = 0;
  virtual ~BaseObject();

 protected:
  Types type_{Null};
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_BASEOBJECT_H_
