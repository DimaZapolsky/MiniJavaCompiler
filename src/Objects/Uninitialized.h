//
// Created by Dima Zapolsky on 01.08.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_UNINITIALIZED_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_UNINITIALIZED_H_

#include <Objects/NonSimpleObject.h>
#include <nodes/Type/Type.h>

namespace objects {

class Uninitialized : public NonSimpleObject {
 public:
  Uninitialized(std::string type);
  std::string GetTypeIdentifier() override;
 private:
  std::string var_type_;
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_UNINITIALIZED_H_
