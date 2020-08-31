//
// Created by Dima Zapolsky on 18/05/2020.
//

#include <iostream>
#include <driver.hh>
#include "Visitors/PrintVisitor.h"
#include "Visitors/Interpreter.h"

int main(int argc, char **argv) {
  int result = 0;
  Driver driver;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == std::string("-p")) {
      driver.trace_parsing = true;
    } else if (argv[i] == std::string("-s")) {
      driver.trace_scanning = true;
    } else if (!driver.parse(argv[i])) {
      PrintVisitor print_visitor("tree.txt");
      ScopeBuilderVisitor builder_visitor;
      driver.program->Accept(&builder_visitor);
      driver.program->Accept(&print_visitor);
      Interpreter interpreter(builder_visitor.GetRoot());
      interpreter.SetClasses(builder_visitor.GetClasses());
      driver.program->Accept(&interpreter);
      std::cout << "OK" << std::endl;
    } else {
      std::cout << "ERROR" << std::endl;
    }
  }

  return result;
}