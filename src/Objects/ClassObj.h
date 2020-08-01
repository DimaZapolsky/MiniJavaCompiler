//
// Created by Dima Zapolsky on 31.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_OBJECTS_CLASSOBJ_H_
#define NAIVEINTERPRETER_SRC_OBJECTS_CLASSOBJ_H_

#include <Objects/Class.h>
#include <Scopes/ScopeLayer.h>
#include <Objects/NonSimpleObject.h>

namespace objects {

class ClassObj : public NonSimpleObject {
 public:
  ClassObj(Identifier* identifier, std::shared_ptr<Class> a_class, std::shared_ptr<ScopeLayer> layer);
  std::string GetTypeIdentifier() override;

 private:
  Identifier* identifier_;
  std::shared_ptr<Class> class_;
  std::shared_ptr<ScopeLayer> layer_;
};

}

#endif //NAIVEINTERPRETER_SRC_OBJECTS_CLASSOBJ_H_
