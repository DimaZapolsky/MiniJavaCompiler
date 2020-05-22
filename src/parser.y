%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;

    class ArrayCreation;
    class ArrayElement;
    class ArrayElementVal;
    class ArrayType;
    class Assert;
    class Assignment;
    class BinaryOperation;
    class Boolean;
    class ClassDeclaration;
    class ClassDeclarationList;
    class ComparisonGT;
    class ComparisonLT;
    class Declaration;
    class DeclarationList;
    class Dif;
    class Div;
    class Equal;
    class Expr;
    class ExprList;
    class False;
    class Formal;
    class Formals;
    class Identifier;
    class If;
    class IfElse;
    class Int;
    class IntegerLiteral;
    class Length;
    class LocalVariableDeclaration;
    class LogicalAnd;
    class LogicalOr;
    class Lvalue;
    class MainClass;
    class MethodDeclaration;
    class MethodInvocation;
    class MethodInvocationVal;
    class Mod;
    class Mul;
    class Not;
    class ObjectCreation;
    class Program;
    class Return;
    class SimpleType;
    class Sout;
    class Statement;
    class StatementList;
    class Sum;
    class This;
    class True;
    class Type;
    class TypeIdentifier;
    class Variable;
    class VariableDeclaration;
    class VariableVal;
    class Void;
    class While;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "nodes/Declaration/ClassDeclaration.h"
    #include "nodes/Declaration/MethodDeclaration.h"
    #include "nodes/Declaration/VariableDeclaration.h"
    #include "nodes/Expr/BinaryOperation/BinaryOperation.h"
    #include "nodes/Expr/BinaryOperation/ComparisonGT.h"
    #include "nodes/Expr/BinaryOperation/ComparisonLT.h"
    #include "nodes/Expr/BinaryOperation/Dif.h"
    #include "nodes/Expr/BinaryOperation/Div.h"
    #include "nodes/Expr/BinaryOperation/Equal.h"
    #include "nodes/Expr/BinaryOperation/LogicalAnd.h"
    #include "nodes/Expr/BinaryOperation/LogicalOr.h"
    #include "nodes/Expr/BinaryOperation/Mod.h"
    #include "nodes/Expr/BinaryOperation/Mul.h"
    #include "nodes/Expr/BinaryOperation/Sum.h"
    #include "nodes/Expr/ArrayCreation.h"
    #include "nodes/Expr/ArrayElementVal.h"
    #include "nodes/Expr/Expr.h"
    #include "nodes/Expr/False.h"
    #include "nodes/Expr/IntegerLiteral.h"
    #include "nodes/Expr/Length.h"
    #include "nodes/Expr/MethodInvocationVal.h"
    #include "nodes/Expr/Not.h"
    #include "nodes/Expr/ObjectCreation.h"
    #include "nodes/Expr/This.h"
    #include "nodes/Expr/True.h"
    #include "nodes/Expr/VariableVal.h"
    #include "nodes/Lists/ClassDeclarationList.h"
    #include "nodes/Lists/DeclarationList.h"
    #include "nodes/Lists/ExprList.h"
    #include "nodes/Lists/Formals.h"
    #include "nodes/Lists/StatementList.h"
    #include "nodes/Lvalue/ArrayElement.h"
    #include "nodes/Lvalue/Lvalue.h"
    #include "nodes/Lvalue/Variable.h"
    #include "nodes/Statement/Assert.h"
    #include "nodes/Statement/Assignment.h"
    #include "nodes/Statement/Declaration.h"
    #include "nodes/Statement/If.h"
    #include "nodes/Statement/IfElse.h"
    #include "nodes/Statement/LocalVariableDeclaration.h"
    #include "nodes/Statement/MethodInvocation.h"
    #include "nodes/Statement/Return.h"
    #include "nodes/Statement/Sout.h"
    #include "nodes/Statement/Statement.h"
    #include "nodes/Statement/While.h"
    #include "nodes/Type/ArrayType.h"
    #include "nodes/Type/Boolean.h"
    #include "nodes/Type/Int.h"
    #include "nodes/Type/SimpleType.h"
    #include "nodes/Type/Type.h"
    #include "nodes/Type/TypeIdentifier.h"
    #include "nodes/Type/Void.h"
    #include "nodes/Formal.h"
    #include "nodes/Identifier.h"
    #include "nodes/MainClass.h"
    #include "nodes/Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    EOL "\n"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    LBRACE "{"
    RBRACE "}"
    CLASS "class"
    PUBLIC "public"
    STATIC "static"
    VOID "void"
    MAIN "main"
    SOUT "System.out.println"
    SEMICOLON ";"
    INT "int"
    BOOLEAN "boolean"
    LENGTH "length"
    POINT "."
    EXTENDS "extends"
    COMMA ","
    LSBRACE "["
    RSBRACE "]"
    ASSERT "assert"
    IF "if"
    ELSE "else"
    WHILE "while"
    RETURN "return"
    NEW "new"
    THIS "this"
    TRUE "true"
    FALSE "false"
    GT ">"
    LT "<"
    AND "&&"
    OR "||"
    EQ "=="
    MOD "%"
;

%left "||"
%left "&&"
%left "!=" "=="
%nonassoc "<" ">"
%left "+" "-"
%left "*" "/" "%"
%right "new"
%right "!"
%left "." "(" "["

%token <std::string> IDENTIFIERSTR "identifier"
%token <int> NUMBERVAL "number"

%nterm <Identifier*> identifier
%nterm <IntegerLiteral*> number
%nterm <Expr*> exp
%nterm <Program*> unit
%nterm <MainClass*> main_class
%nterm <ClassDeclarationList*> class_declaration_list
%nterm <StatementList*> stmt_list
%nterm <Statement*> stmt
%nterm <ClassDeclaration*> class_declaration
%nterm <Formals*> formals
%nterm <Formal*> formal;
%nterm <DeclarationList*> declaration_list
%nterm <Declaration*> declaration
%nterm <MethodDeclaration*> method_declaration
%nterm <VariableDeclaration*> variable_declaration
%nterm <Type*> type
%nterm <TypeIdentifier*> type_identifier
%nterm <SimpleType*> simple_type
%nterm <ArrayType*> array_type
%nterm <LocalVariableDeclaration*> local_variable_declaration
%nterm <Lvalue*> lvalue
%nterm <MethodInvocation*> method_invocation
%nterm <BinaryOperation*> binary_operation
%nterm <ExprList*> expr_list

%%
%start unit;

unit:
    main_class class_declaration_list {
        $$ = new Program($1, $2);
        driver.program = $$;
    };

main_class:
    "class" identifier "{" "public" "static" "void" "main" "(" ")" "{" stmt_list "}" "}" { $$ = new MainClass($2, $11); };

class_declaration_list:
    class_declaration class_declaration_list {$2->AddClassDeclaration($1); $$ = $2;}
    | %empty { $$ = new ClassDeclarationList(); };

class_declaration:
    "class" identifier "{" declaration_list "}" { $$ = new ClassDeclaration($2, $4); }
    | "class" identifier "extends" identifier "{" declaration_list "}" { $$ = new ClassDeclaration($2, $4, $6); };

declaration_list:
    declaration declaration_list { $2->AddDeclaration($1); $$ = $2; }
    | %empty { $$ = new DeclarationList(); };

declaration:
    variable_declaration {$$ = $1; }
    | method_declaration {$$ = $1; };

variable_declaration:
    type identifier ";" { $$ = new VariableDeclaration($1, $2); };

method_declaration:
    "public" type identifier "(" ")" "{" stmt_list "}" { $$ = new MethodDeclaration($2, $3, $7); }
    | "public" type identifier "(" formals ")" "{" stmt_list "}" { $$ = new MethodDeclaration($2, $3, $5, $8); };

formals:
    formal "," formals { $3->AddFormal($1); $$ = $3; }
    | formal { $$ = new Formals(); $$->AddFormal($1); };

formal:
    type identifier { $$ = new Formal($1, $2); };

type:
    simple_type { $$ = $1; }
    | array_type {$$ = $1; };

simple_type:
    "int" { $$ = new Int(); }
    | "boolean" { $$ = new Boolean(); }
    | "void" { $$ = new Void(); }
    | identifier { $$ = new TypeIdentifier($1); };

array_type:
    simple_type "[" "]" { $$ = new ArrayType($1); };

stmt_list:
    stmt stmt_list {$2->AddStatement($1); $$ = $2;}
    | %empty {$$ = new StatementList(); };

stmt:
    "assert" "(" exp ")" {$$ = new Assert($3); }
    | local_variable_declaration {$$ = $1; }
    | "{" stmt_list "}" {$$ = $2; }
    | "if" "(" exp ")" stmt {$$ = new If($3, $5); }
    | "if" "(" exp ")" stmt "else" stmt {$$ = new IfElse($3, $5, $7); }
    | "while" "(" exp ")" stmt {$$ = new While($3, $5); }
    | "System.out.println" "(" exp ")" ";" {$$ = new Sout($3); }
    | lvalue "=" exp ";" {$$ = new Assignment($1, $3); }
    | "return" exp ";" {$$ = new Return($2); }
    | method_invocation {$$ = $1; }

method_invocation:
    exp "." identifier "(" expr_list ")" {$$ = new MethodInvocation($1, $3, $5); }
    | exp "." identifier "(" ")" {$$ = new MethodInvocation($1, $3); };

expr_list:
    exp {$$ = new ExprList(); $$->AddExpr($1); }
    | exp "," expr_list {$3->AddExpr($1); $$ = $3; };

local_variable_declaration:
    variable_declaration {$$ = new LocalVariableDeclaration($1); };

lvalue:
    identifier {$$ = new Variable($1); }
    | identifier "[" exp "]" {$$ = new ArrayElement($1, $3); };

exp:
    binary_operation {$$ = $1; }
    | exp "[" exp "]" {$$ = new ArrayElementVal($1, $3); }
    | exp "." "length" {$$ = new Length($1); }
    | "new" simple_type "[" exp "]" {$$ = new ArrayCreation($2, $4); }
    | "new" type_identifier "(" ")" {$$ = new ObjectCreation($2); }
    | "!" exp {$$ = new Not($2); }
    | "(" exp ")" { $$ = $2; }
    | identifier {$$ = new VariableVal($1); }
    | number {$$ = $1; }
    | "this" {$$ = new This(); }
    | "true" {$$ = new True(); }
    | "false" {$$ = new False(); }
    | method_invocation {$$ = new MethodInvocationVal($1); }

binary_operation:
    exp "&&" exp {$$ = new LogicalAnd($1, $3); }
    | exp "||" exp {$$ = new LogicalOr($1, $3); }
    | exp "<" exp {$$ = new ComparisonLT($1, $3); }
    | exp ">" exp {$$ = new ComparisonGT($1, $3); }
    | exp "==" exp {$$ = new Equal($1, $3); }
    | exp "+" exp {$$ = new Sum($1, $3); }
    | exp "-" exp {$$ = new Dif($1, $3); }
    | exp "*" exp {$$ = new Mul($1, $3); }
    | exp "/" exp {$$ = new Div($1, $3); }
    | exp "%" exp {$$ = new Mod($1, $3); }

identifier:
    "identifier" { $$ = new Identifier($1); }

number:
    "number" { $$ = new IntegerLiteral($1); }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
