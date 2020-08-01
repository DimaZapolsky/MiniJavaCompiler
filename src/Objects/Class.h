//
// Created by Dima Zapolsky on 30.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_NODES_TYPE_CLASS_H_
#define NAIVEINTERPRETER_SRC_NODES_TYPE_CLASS_H_

#include <unordered_map>
#include <Objects/NonSimpleObject.h>
#include <Objects/Method.h>
#include <nodes/Identifier.h>

namespace objects {

class Class : public NonSimpleObject {
 public:
  Class();
  bool HasMethod(std::string method);
  std::shared_ptr<Method> GetMethod(std::string method);
  bool HasVariable(std::string variable);
  std::string GetVariableType(std::string variable);
  void SetIdentifier(Identifier *identifier);
  void SetExtends(std::shared_ptr<Class> extends);
  void SetVariables(const std::unordered_map<std::string, std::string> &variables);
  void SetMethods(const std::unordered_map<std::string, std::shared_ptr<Method>> &methods);
  Identifier *GetIdentifier() const;
  std::string GetTypeIdentifier() override;

 private:
  Identifier* identifier_{nullptr};
  std::shared_ptr<Class> extends_{nullptr};
  std::unordered_map<std::string, std::string> variables_;
  std::unordered_map<std::string, std::shared_ptr<Method>> methods_;
};

}

#endif //NAIVEINTERPRETER_SRC_NODES_TYPE_CLASS_H_
