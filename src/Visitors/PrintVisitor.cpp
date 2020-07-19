//
// Created by Dima Zapolsky on 13.07.2020.
//

#include "PrintVisitor.h"

//void PrintVisitor::Visit(Visitable *visitable) {
//  throw std::runtime_error("visiting base class is incorrect");
//}

PrintVisitor::PrintVisitor(const std::string &file_path) : file_(file_path) {}

void PrintVisitor::PrintLine(const std::string& line) {
  file_ << std::string((tabs_ - 1) * 4, ' ') << line << std::endl;
}

void PrintVisitor::Visit(ClassDeclaration *visitable) {
  tabs_++;
  PrintLine("-Class Declaration:");
  PrintLine("  -identifier:");
  visitable->GetIdentifier()->Accept(this);
  if (visitable->GetExtends()) {
    PrintLine("  -extends:");
    visitable->GetExtends()->Accept(this);
  }
  PrintLine("  -declaration list");
  visitable->GetDeclarationList()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(MethodDeclaration *visitable) {
  tabs_++;
  PrintLine("-MethodDeclaration:");
  PrintLine("  -type:");
  visitable->GetType()->Accept(this);
  PrintLine("  -identifier:");
  visitable->GetIdentifier()->Accept(this);
  PrintLine("  -formals:");
  visitable->GetFormals()->Accept(this);
  PrintLine("  -statement_list:");
  visitable->GetStatementList()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(VariableDeclaration *visitable) {
  tabs_++;
  PrintLine("-VariableDeclaration:");
  PrintLine("  -type:");
  visitable->GetType()->Accept(this);
  PrintLine("  -identifier:");
  visitable->GetIdentifier()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(BinaryOperation *visitable) {
  tabs_++;
  PrintLine("  -left_expr:");
  visitable->GetLExpr()->Accept(this);
  PrintLine("  -right_expr:");
  visitable->GetRExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(ComparisonGT *visitable) {
  PrintLine("    ComparisonGT:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(ComparisonLT *visitable) {
  PrintLine("    ComparisonLT:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(Dif *visitable) {
  PrintLine("    Difference:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(Div *visitable) {
  PrintLine("    Division:");
  Visit((BinaryOperation*) visitable);
}
void PrintVisitor::Visit(Equal *visitable) {
  PrintLine("    Equality:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(LogicalAnd *visitable) {
  PrintLine("    Logical and:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(LogicalOr *visitable) {
  PrintLine("    Logical or:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(Mod *visitable) {
  PrintLine("    Modulo:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(Mul *visitable) {
  PrintLine("    Multiplication:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(Sum *visitable) {
  PrintLine("    Sum:");
  Visit((BinaryOperation*) visitable);
}

void PrintVisitor::Visit(ArrayCreation *visitable) {
  tabs_++;
  PrintLine("-ArrayCreation:");
  PrintLine("  -type:");
  visitable->GetSimpleType()->Accept(this);
  PrintLine("  -expression:");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(ArrayElementVal *visitable) {
  tabs_++;
  PrintLine("-Array element value:");
  PrintLine("  -array:");
  visitable->GetExpr()->Accept(this);
  PrintLine("  -index:");
  visitable->GetIndex()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Expr *visitable) {
  tabs_++;
  PrintLine("-Expression:");
  tabs_--;
}

void PrintVisitor::Visit(False *visitable) {
  tabs_++;
  PrintLine("-False");
  tabs_--;
}

void PrintVisitor::Visit(IntegerLiteral *visitable) {
  tabs_++;
  PrintLine("-Integer literal = " + std::to_string(visitable->GetValue()));
  tabs_--;
}

void PrintVisitor::Visit(Length *visitable) {
  tabs_++;
  PrintLine("-Length:");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(MethodInvocationVal *visitable) {
  tabs_++;
  PrintLine("Method invocation value:");
  visitable->GetMethodInvocation()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Not *visitable) {
  tabs_++;
  PrintLine("Not");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(ObjectCreation *visitable) {
  tabs_++;
  PrintLine("Object creation:");
  visitable->GetTypeIdentifier()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(This *visitable) {
  tabs_++;
  PrintLine("This");
  tabs_--;
}

void PrintVisitor::Visit(True *visitable) {
  tabs_++;
  PrintLine("True");
  tabs_--;
}

void PrintVisitor::Visit(VariableVal *visitable) {
  tabs_++;
  PrintLine("Variable Value:");
  visitable->GetIdentifier()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(ClassDeclarationList *visitable) {
  tabs_++;
  PrintLine("Class declaration list:");
  for (auto &decl : visitable->GetClassDeclarations()) {
    decl->Accept(this);
  }
  tabs_--;
}

void PrintVisitor::Visit(DeclarationList *visitable) {
  tabs_++;
  PrintLine("Declaration list:");
  for (auto & decl : visitable->GetDeclarations()) {
    decl->Accept(this);
  }
  tabs_--;
}

void PrintVisitor::Visit(ExprList *visitable) {
  tabs_++;
  PrintLine("Expression list:");
  for (auto & expr : visitable->GetExpressions()) {
    expr->Accept(this);
  }
  tabs_--;
}

void PrintVisitor::Visit(Formals *visitable) {
  tabs_++;
  PrintLine("Formals");
  for (auto & formal : visitable->GetFormals()) {
    formal->Accept(this);
  }
  tabs_--;
}

void PrintVisitor::Visit(StatementList *visitable) {
  tabs_++;
  PrintLine("Statement list:");
  for (auto & statement : visitable->GetStatements()) {
    statement->Accept(this);
  }
  tabs_--;
}

void PrintVisitor::Visit(ArrayElement *visitable) {
  tabs_++;
  PrintLine("Array element:");
  PrintLine("  -identifier:");
  visitable->GetIdentifier()->Accept(this);
  PrintLine("  -index:");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Lvalue *visitable) {
  tabs_++;
  PrintLine("Lvalue");
  tabs_--;
}

void PrintVisitor::Visit(Variable *visitable) {
  tabs_++;
  PrintLine("Variable:");
  visitable->GetIdentifier()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Assert *visitable) {
  tabs_++;
  PrintLine("Assert:");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Assignment *visitable) {
  tabs_++;
  PrintLine("Assignment:");
  PrintLine("  -lvalue:");
  visitable->GetLvalue()->Accept(this);
  PrintLine("  -index:");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Declaration *visitable) {
  tabs_++;
  PrintLine("Declaration");
  tabs_--;
}

void PrintVisitor::Visit(If *visitable) {
  tabs_++;
  PrintLine("If:");
  PrintLine("  -condition:");
  visitable->GetExpr()->Accept(this);
  PrintLine("  -statement:");
  visitable->GetStatement()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(IfElse *visitable) {
  tabs_++;
  PrintLine("If else:");
  PrintLine("  -condition:");
  visitable->GetExpr()->Accept(this);
  PrintLine("  -true statement:");
  visitable->GetStatementTrue()->Accept(this);
  PrintLine("  -false statement:");
  visitable->GetStatementFalse()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(LocalVariableDeclaration *visitable) {
  tabs_++;
  PrintLine("Local variable declaration:");
  visitable->GetVariableDeclaration()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(MethodInvocation *visitable) {
  tabs_++;
  PrintLine("Method invocation:");
  PrintLine("  -object:");
  visitable->GetExpr()->Accept(this);
  PrintLine("  -name:");
  visitable->GetIdentifier()->Accept(this);
  PrintLine("  -formals:");
  visitable->GetExprList()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Return *visitable) {
  tabs_++;
  PrintLine("Return");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Sout *visitable) {
  tabs_++;
  PrintLine("Sout");
  visitable->GetExpr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Statement *visitable) {
  tabs_++;
  PrintLine("Statement:");
  tabs_--;
}

void PrintVisitor::Visit(While *visitable) {
  tabs_++;
  PrintLine("While:");
  PrintLine("  -condition:");
  visitable->GetExpr()->Accept(this);
  PrintLine("  -statement:");
  visitable->GetStatement()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(types::ArrayType *visitable) {
  tabs_++;
  PrintLine("Array type:");
  visitable->GetSimpleType()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(types::Boolean *visitable) {
  tabs_++;
  PrintLine("Boolean");
  tabs_--;
}

void PrintVisitor::Visit(types::Int *visitable) {
  tabs_++;
  PrintLine("Int");
  tabs_--;
}

void PrintVisitor::Visit(types::SimpleType *visitable) {
  tabs_++;
  PrintLine("SimpleType = " + visitable->GetIdentifier());
  tabs_--;
}

void PrintVisitor::Visit(types::Type *visitable) {
  tabs_++;
  PrintLine("Type = " + visitable->GetIdentifier());
  tabs_--;
}

void PrintVisitor::Visit(types::TypeIdentifier *visitable) {
  tabs_++;
  PrintLine("TypeIdentifier");
  visitable->GetIdentifierPtr()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(types::Void *visitable) {
  tabs_++;
  PrintLine("Void");
  tabs_--;
}

void PrintVisitor::Visit(Formal *visitable) {
  tabs_++;
  PrintLine("Formal:");
  PrintLine("  -type:");
  visitable->GetType()->Accept(this);
  PrintLine("  -name:");
  visitable->GetIdentifier()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Identifier *visitable) {
  tabs_++;
  PrintLine("Identifier = " + visitable->GetIdentifier());
  tabs_--;
}

void PrintVisitor::Visit(MainClass *visitable) {
  tabs_++;
  PrintLine("Main class:");
  PrintLine("  -name:");
  visitable->GetIdentifier()->Accept(this);
  PrintLine("  -statements:");
  visitable->GetStatementList()->Accept(this);
  tabs_--;
}

void PrintVisitor::Visit(Program *visitable) {
  tabs_++;
  PrintLine("Program:");
  PrintLine("  -main class:");
  visitable->GetMainClass()->Accept(this);
  PrintLine("  -classes:");
  visitable->GetClassDeclarationList()->Accept(this);
  tabs_--;
}

