// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 19 "parser.y"

#include "driver.hh"
#include "location.hh"

#include "nodes/NodesInclude.h"

static yy::parser::symbol_type yylex(Scanner &scanner, Driver &driver) {
  return scanner.ScanToken();
}

#line 56 "/home/ubuntu/proj/src/parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
                                                                                                                        #  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

                                                                                                                        # define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 147 "/home/ubuntu/proj/src/parser.cpp"

/* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
std::string
parser::yytnamerr_(const char *yystr) {
  if (*yystr == '"') {
    std::string yyr;
    char const *yyp = yystr;

    for (;;)
      switch (*++yyp) {
        case '\'':
        case ',':goto do_not_strip_quotes;

        case '\\':
          if (*++yyp != '\\')
            goto do_not_strip_quotes;
          else
            goto append;

        append:
        default:yyr += *yyp;
          break;

        case '"':return yyr;
      }
    do_not_strip_quotes:;
  }

  return yystr;
}

/// Build a parser object.
parser::parser(Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_(false),
      yycdebug_(&std::cerr),
#else
    :
#endif
      scanner(scanner_yyarg),
      driver(driver_yyarg) {}

parser::~parser() {}

parser::syntax_error::~syntax_error() YY_NOEXCEPT YY_NOTHROW
{}

/*---------------.
  | Symbol types.  |
  `---------------*/



// by_state.
parser::by_state::by_state() YY_NOEXCEPT
    : state(empty_state) {}

parser::by_state::by_state(const by_state &that) YY_NOEXCEPT
    : state(that.state) {}

void
parser::by_state::clear() YY_NOEXCEPT {
  state = empty_state;
}

void
parser::by_state::move(by_state &that) {
  state = that.state;
  that.clear();
}

parser::by_state::by_state(state_type s) YY_NOEXCEPT
    : state(s) {}

parser::symbol_number_type
parser::by_state::type_get() const YY_NOEXCEPT {
  if (state == empty_state)
    return empty_symbol;
  else
    return yystos_[+state];
}

parser::stack_symbol_type::stack_symbol_type() {}

parser::stack_symbol_type::stack_symbol_type(YY_RVREF (stack_symbol_type)that)
    : super_type(YY_MOVE(that.state), YY_MOVE(that.location)) {
  switch (that.type_get()) {
    case 69: // binary_operation
      value.YY_MOVE_OR_COPY<BinaryOperation *>(YY_MOVE(that.value));
      break;

    case 56: // class_declaration
      value.YY_MOVE_OR_COPY<ClassDeclaration *>(YY_MOVE(that.value));
      break;

    case 53: // class_declaration_list
      value.YY_MOVE_OR_COPY<ClassDeclarationList *>(YY_MOVE(that.value));
      break;

    case 60: // declaration
      value.YY_MOVE_OR_COPY<Declaration *>(YY_MOVE(that.value));
      break;

    case 59: // declaration_list
      value.YY_MOVE_OR_COPY<DeclarationList *>(YY_MOVE(that.value));
      break;

    case 50: // exp
      value.YY_MOVE_OR_COPY<Expr *>(YY_MOVE(that.value));
      break;

    case 70: // expr_list
      value.YY_MOVE_OR_COPY<ExprList *>(YY_MOVE(that.value));
      break;

    case 58: // formal
      value.YY_MOVE_OR_COPY<Formal *>(YY_MOVE(that.value));
      break;

    case 57: // formals
      value.YY_MOVE_OR_COPY<Formals *>(YY_MOVE(that.value));
      break;

    case 48: // identifier
      value.YY_MOVE_OR_COPY<Identifier *>(YY_MOVE(that.value));
      break;

    case 49: // number
      value.YY_MOVE_OR_COPY<IntegerLiteral *>(YY_MOVE(that.value));
      break;

    case 66: // local_variable_declaration
      value.YY_MOVE_OR_COPY<LocalVariableDeclaration *>(YY_MOVE(that.value));
      break;

    case 67: // lvalue
      value.YY_MOVE_OR_COPY<Lvalue *>(YY_MOVE(that.value));
      break;

    case 52: // main_class
      value.YY_MOVE_OR_COPY<MainClass *>(YY_MOVE(that.value));
      break;

    case 61: // method_declaration
      value.YY_MOVE_OR_COPY<MethodDeclaration *>(YY_MOVE(that.value));
      break;

    case 68: // method_invocation
      value.YY_MOVE_OR_COPY<MethodInvocation *>(YY_MOVE(that.value));
      break;

    case 51: // unit
      value.YY_MOVE_OR_COPY<Program *>(YY_MOVE(that.value));
      break;

    case 55: // stmt
      value.YY_MOVE_OR_COPY<Statement *>(YY_MOVE(that.value));
      break;

    case 54: // stmt_list
      value.YY_MOVE_OR_COPY<StatementList *>(YY_MOVE(that.value));
      break;

    case 62: // variable_declaration
      value.YY_MOVE_OR_COPY<VariableDeclaration *>(YY_MOVE(that.value));
      break;

    case 46: // "number"
      value.YY_MOVE_OR_COPY<int>(YY_MOVE(that.value));
      break;

    case 45: // "identifier"
      value.YY_MOVE_OR_COPY<std::string>(YY_MOVE(that.value));
      break;

    case 65: // array_type
      value.YY_MOVE_OR_COPY<types::ArrayType *>(YY_MOVE(that.value));
      break;

    case 64: // simple_type
      value.YY_MOVE_OR_COPY<types::SimpleType *>(YY_MOVE(that.value));
      break;

    case 63: // type
      value.YY_MOVE_OR_COPY<types::Type *>(YY_MOVE(that.value));
      break;

    default:break;
  }

#if 201103L <= YY_CPLUSPLUS
  // that is emptied.
  that.state = empty_state;
#endif
}

parser::stack_symbol_type::stack_symbol_type(state_type s, YY_MOVE_REF (symbol_type)that)
    : super_type(s, YY_MOVE(that.location)) {
  switch (that.type_get()) {
    case 69: // binary_operation
      value.move<BinaryOperation *>(YY_MOVE(that.value));
      break;

    case 56: // class_declaration
      value.move<ClassDeclaration *>(YY_MOVE(that.value));
      break;

    case 53: // class_declaration_list
      value.move<ClassDeclarationList *>(YY_MOVE(that.value));
      break;

    case 60: // declaration
      value.move<Declaration *>(YY_MOVE(that.value));
      break;

    case 59: // declaration_list
      value.move<DeclarationList *>(YY_MOVE(that.value));
      break;

    case 50: // exp
      value.move<Expr *>(YY_MOVE(that.value));
      break;

    case 70: // expr_list
      value.move<ExprList *>(YY_MOVE(that.value));
      break;

    case 58: // formal
      value.move<Formal *>(YY_MOVE(that.value));
      break;

    case 57: // formals
      value.move<Formals *>(YY_MOVE(that.value));
      break;

    case 48: // identifier
      value.move<Identifier *>(YY_MOVE(that.value));
      break;

    case 49: // number
      value.move<IntegerLiteral *>(YY_MOVE(that.value));
      break;

    case 66: // local_variable_declaration
      value.move<LocalVariableDeclaration *>(YY_MOVE(that.value));
      break;

    case 67: // lvalue
      value.move<Lvalue *>(YY_MOVE(that.value));
      break;

    case 52: // main_class
      value.move<MainClass *>(YY_MOVE(that.value));
      break;

    case 61: // method_declaration
      value.move<MethodDeclaration *>(YY_MOVE(that.value));
      break;

    case 68: // method_invocation
      value.move<MethodInvocation *>(YY_MOVE(that.value));
      break;

    case 51: // unit
      value.move<Program *>(YY_MOVE(that.value));
      break;

    case 55: // stmt
      value.move<Statement *>(YY_MOVE(that.value));
      break;

    case 54: // stmt_list
      value.move<StatementList *>(YY_MOVE(that.value));
      break;

    case 62: // variable_declaration
      value.move<VariableDeclaration *>(YY_MOVE(that.value));
      break;

    case 46: // "number"
      value.move<int>(YY_MOVE(that.value));
      break;

    case 45: // "identifier"
      value.move<std::string>(YY_MOVE(that.value));
      break;

    case 65: // array_type
      value.move<types::ArrayType *>(YY_MOVE(that.value));
      break;

    case 64: // simple_type
      value.move<types::SimpleType *>(YY_MOVE(that.value));
      break;

    case 63: // type
      value.move<types::Type *>(YY_MOVE(that.value));
      break;

    default:break;
  }

  // that is emptied.
  that.type = empty_symbol;
}

#if YY_CPLUSPLUS < 201103L
                                                                                                                        parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 69: // binary_operation
        value.copy< BinaryOperation* > (that.value);
        break;

      case 56: // class_declaration
        value.copy< ClassDeclaration* > (that.value);
        break;

      case 53: // class_declaration_list
        value.copy< ClassDeclarationList* > (that.value);
        break;

      case 60: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 59: // declaration_list
        value.copy< DeclarationList* > (that.value);
        break;

      case 50: // exp
        value.copy< Expr* > (that.value);
        break;

      case 70: // expr_list
        value.copy< ExprList* > (that.value);
        break;

      case 58: // formal
        value.copy< Formal* > (that.value);
        break;

      case 57: // formals
        value.copy< Formals* > (that.value);
        break;

      case 48: // identifier
        value.copy< Identifier* > (that.value);
        break;

      case 49: // number
        value.copy< IntegerLiteral* > (that.value);
        break;

      case 66: // local_variable_declaration
        value.copy< LocalVariableDeclaration* > (that.value);
        break;

      case 67: // lvalue
        value.copy< Lvalue* > (that.value);
        break;

      case 52: // main_class
        value.copy< MainClass* > (that.value);
        break;

      case 61: // method_declaration
        value.copy< MethodDeclaration* > (that.value);
        break;

      case 68: // method_invocation
        value.copy< MethodInvocation* > (that.value);
        break;

      case 51: // unit
        value.copy< Program* > (that.value);
        break;

      case 55: // stmt
        value.copy< Statement* > (that.value);
        break;

      case 54: // stmt_list
        value.copy< StatementList* > (that.value);
        break;

      case 62: // variable_declaration
        value.copy< VariableDeclaration* > (that.value);
        break;

      case 46: // "number"
        value.copy< int > (that.value);
        break;

      case 45: // "identifier"
        value.copy< std::string > (that.value);
        break;

      case 65: // array_type
        value.copy< types::ArrayType* > (that.value);
        break;

      case 64: // simple_type
        value.copy< types::SimpleType* > (that.value);
        break;

      case 63: // type
        value.copy< types::Type* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 69: // binary_operation
        value.move< BinaryOperation* > (that.value);
        break;

      case 56: // class_declaration
        value.move< ClassDeclaration* > (that.value);
        break;

      case 53: // class_declaration_list
        value.move< ClassDeclarationList* > (that.value);
        break;

      case 60: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 59: // declaration_list
        value.move< DeclarationList* > (that.value);
        break;

      case 50: // exp
        value.move< Expr* > (that.value);
        break;

      case 70: // expr_list
        value.move< ExprList* > (that.value);
        break;

      case 58: // formal
        value.move< Formal* > (that.value);
        break;

      case 57: // formals
        value.move< Formals* > (that.value);
        break;

      case 48: // identifier
        value.move< Identifier* > (that.value);
        break;

      case 49: // number
        value.move< IntegerLiteral* > (that.value);
        break;

      case 66: // local_variable_declaration
        value.move< LocalVariableDeclaration* > (that.value);
        break;

      case 67: // lvalue
        value.move< Lvalue* > (that.value);
        break;

      case 52: // main_class
        value.move< MainClass* > (that.value);
        break;

      case 61: // method_declaration
        value.move< MethodDeclaration* > (that.value);
        break;

      case 68: // method_invocation
        value.move< MethodInvocation* > (that.value);
        break;

      case 51: // unit
        value.move< Program* > (that.value);
        break;

      case 55: // stmt
        value.move< Statement* > (that.value);
        break;

      case 54: // stmt_list
        value.move< StatementList* > (that.value);
        break;

      case 62: // variable_declaration
        value.move< VariableDeclaration* > (that.value);
        break;

      case 46: // "number"
        value.move< int > (that.value);
        break;

      case 45: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 65: // array_type
        value.move< types::ArrayType* > (that.value);
        break;

      case 64: // simple_type
        value.move< types::SimpleType* > (that.value);
        break;

      case 63: // type
        value.move< types::Type* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

template<typename Base>
void
parser::yy_destroy_(const char *yymsg, basic_symbol<Base> &yysym) const {
  if (yymsg)
    YY_SYMBOL_PRINT (yymsg, yysym);
}

#if YYDEBUG
template<typename Base>
void
parser::yy_print_(std::ostream &yyo,
                  const basic_symbol<Base> &yysym) const {
  std::ostream &yyoutput = yyo;
  YYUSE (yyoutput);
  symbol_number_type yytype = yysym.type_get();
#if defined __GNUC__ && !defined __clang__ && !defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
                                                                                                                          // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
  yyo << (yytype < yyntokens_ ? "token" : "nterm")
      << ' ' << yytname_[yytype] << " ("
      << yysym.location << ": ";
  YYUSE (yytype);
  yyo << ')';
}
#endif

void
parser::yypush_(const char *m, YY_MOVE_REF (stack_symbol_type)sym) {
  if (m)
    YY_SYMBOL_PRINT (m, sym);
  yystack_.push(YY_MOVE(sym));
}

void
parser::yypush_(const char *m, state_type s, YY_MOVE_REF (symbol_type)sym) {
#if 201103L <= YY_CPLUSPLUS
  yypush_(m, stack_symbol_type(s, std::move(sym)));
#else
                                                                                                                          stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
}

void
parser::yypop_(int n) {
  yystack_.pop(n);
}

#if YYDEBUG
std::ostream &
parser::debug_stream() const {
  return *yycdebug_;
}

void
parser::set_debug_stream(std::ostream &o) {
  yycdebug_ = &o;
}

parser::debug_level_type
parser::debug_level() const {
  return yydebug_;
}

void
parser::set_debug_level(debug_level_type l) {
  yydebug_ = l;
}
#endif // YYDEBUG

parser::state_type
parser::yy_lr_goto_state_(state_type yystate, int yysym) {
  int yyr = yypgoto_[yysym - yyntokens_] + yystate;
  if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
    return yytable_[yyr];
  else
    return yydefgoto_[yysym - yyntokens_];
}

bool
parser::yy_pact_value_is_default_(int yyvalue) {
  return yyvalue == yypact_ninf_;
}

bool
parser::yy_table_value_is_error_(int yyvalue) {
  return yyvalue == yytable_ninf_;
}

int
parser::operator()() {
  return parse();
}

int
parser::parse() {
  int yyn;
  /// Length of the RHS of the rule being reduced.
  int yylen = 0;

  // Error handling.
  int yynerrs_ = 0;
  int yyerrstatus_ = 0;

  /// The lookahead symbol.
  symbol_type yyla;

  /// The locations where the error started and ended.
  stack_symbol_type yyerror_range[3];

  /// The return value of parse ().
  int yyresult;

#if YY_EXCEPTIONS
  try #endif // YY_EXCEPTIONS
  {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear();
    yypush_(YY_NULLPTR, 0, YY_MOVE(yyla));

    /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
    yynewstate:
    YYCDEBUG << "Entering state " << int(yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


    /*-----------.
  | yybackup.  |
  `-----------*/
    yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_(yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty()) {
      YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
      try #endif // YY_EXCEPTIONS
      {
        symbol_type yylookahead(yylex(scanner, driver));
        yyla.move(yylookahead);
      }
#if YY_EXCEPTIONS
      catch (const syntax_error &yyexc) {
        YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
        error(yyexc);
        goto yyerrlab1;
      }
#endif // YY_EXCEPTIONS
    }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get()) {
      goto yydefault;
    }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0) {
      if (yy_table_value_is_error_(yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_("Shifting", state_type(yyn), YY_MOVE(yyla));
    goto yynewstate;


    /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
    yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


    /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
    yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn]) {
        case 69: // binary_operation
          yylhs.value.emplace<BinaryOperation *>();
          break;

        case 56: // class_declaration
          yylhs.value.emplace<ClassDeclaration *>();
          break;

        case 53: // class_declaration_list
          yylhs.value.emplace<ClassDeclarationList *>();
          break;

        case 60: // declaration
          yylhs.value.emplace<Declaration *>();
          break;

        case 59: // declaration_list
          yylhs.value.emplace<DeclarationList *>();
          break;

        case 50: // exp
          yylhs.value.emplace<Expr *>();
          break;

        case 70: // expr_list
          yylhs.value.emplace<ExprList *>();
          break;

        case 58: // formal
          yylhs.value.emplace<Formal *>();
          break;

        case 57: // formals
          yylhs.value.emplace<Formals *>();
          break;

        case 48: // identifier
          yylhs.value.emplace<Identifier *>();
          break;

        case 49: // number
          yylhs.value.emplace<IntegerLiteral *>();
          break;

        case 66: // local_variable_declaration
          yylhs.value.emplace<LocalVariableDeclaration *>();
          break;

        case 67: // lvalue
          yylhs.value.emplace<Lvalue *>();
          break;

        case 52: // main_class
          yylhs.value.emplace<MainClass *>();
          break;

        case 61: // method_declaration
          yylhs.value.emplace<MethodDeclaration *>();
          break;

        case 68: // method_invocation
          yylhs.value.emplace<MethodInvocation *>();
          break;

        case 51: // unit
          yylhs.value.emplace<Program *>();
          break;

        case 55: // stmt
          yylhs.value.emplace<Statement *>();
          break;

        case 54: // stmt_list
          yylhs.value.emplace<StatementList *>();
          break;

        case 62: // variable_declaration
          yylhs.value.emplace<VariableDeclaration *>();
          break;

        case 46: // "number"
          yylhs.value.emplace<int>();
          break;

        case 45: // "identifier"
          yylhs.value.emplace<std::string>();
          break;

        case 65: // array_type
          yylhs.value.emplace<types::ArrayType *>();
          break;

        case 64: // simple_type
          yylhs.value.emplace<types::SimpleType *>();
          break;

        case 63: // type
          yylhs.value.emplace<types::Type *>();
          break;

        default:break;
      }


      // Default location.
      {
        stack_type::slice range(yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try #endif // YY_EXCEPTIONS
      {
        switch (yyn) {
          case 2:
#line 125 "parser.y"
          {
            yylhs.value.as<Program *>() =
                new Program(yystack_[1].value.as<MainClass *>(), yystack_[0].value.as<ClassDeclarationList *>());
            driver.program = yylhs.value.as<Program *>();
          }
#line 1078 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 3:
#line 131 "parser.y"
          {
            yylhs.value.as<MainClass *>() =
                new MainClass(yystack_[11].value.as<Identifier *>(), yystack_[2].value.as<StatementList *>());
          }
#line 1084 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 4:
#line 134 "parser.y"
          {
            yystack_[1].value.as<ClassDeclarationList *>()->AddClassDeclaration(yystack_[0].value.as<ClassDeclaration *>());
            yylhs.value.as<ClassDeclarationList *>() = yystack_[1].value.as<ClassDeclarationList *>();
          }
#line 1090 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 5:
#line 135 "parser.y"
          { yylhs.value.as<ClassDeclarationList *>() = new ClassDeclarationList(); }
#line 1096 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 6:
#line 138 "parser.y"
          {
            yylhs.value.as<ClassDeclaration *>() =
                new ClassDeclaration(yystack_[3].value.as<Identifier *>(), yystack_[1].value.as<DeclarationList *>());
          }
#line 1102 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 7:
#line 139 "parser.y"
          {
            yylhs.value.as<ClassDeclaration *>() = new ClassDeclaration(yystack_[5].value.as<Identifier *>(),
                                                                        yystack_[3].value.as<Identifier *>(),
                                                                        yystack_[1].value.as<DeclarationList *>());
          }
#line 1108 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 8:
#line 142 "parser.y"
          {
            yystack_[1].value.as<DeclarationList *>()->AddDeclaration(yystack_[0].value.as<Declaration *>());
            yylhs.value.as<DeclarationList *>() = yystack_[1].value.as<DeclarationList *>();
          }
#line 1114 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 9:
#line 143 "parser.y"
          { yylhs.value.as<DeclarationList *>() = new DeclarationList(); }
#line 1120 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 10:
#line 146 "parser.y"
          { yylhs.value.as<Declaration *>() = yystack_[0].value.as<VariableDeclaration *>(); }
#line 1126 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 11:
#line 147 "parser.y"
          { yylhs.value.as<Declaration *>() = yystack_[0].value.as<MethodDeclaration *>(); }
#line 1132 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 12:
#line 150 "parser.y"
          {
            yylhs.value.as<VariableDeclaration *>() =
                new VariableDeclaration(yystack_[2].value.as<types::Type *>(), yystack_[1].value.as<Identifier *>());
          }
#line 1138 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 13:
#line 153 "parser.y"
          {
            yylhs.value.as<MethodDeclaration *>() = new MethodDeclaration(yystack_[6].value.as<types::Type *>(),
                                                                          yystack_[5].value.as<Identifier *>(),
                                                                          yystack_[1].value.as<StatementList *>());
          }
#line 1144 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 14:
#line 154 "parser.y"
          {
            yylhs.value.as<MethodDeclaration *>() = new MethodDeclaration(yystack_[7].value.as<types::Type *>(),
                                                                          yystack_[6].value.as<Identifier *>(),
                                                                          yystack_[4].value.as<Formals *>(),
                                                                          yystack_[1].value.as<StatementList *>());
          }
#line 1150 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 15:
#line 157 "parser.y"
          {
            yystack_[0].value.as<Formals *>()->AddFormal(yystack_[2].value.as<Formal *>());
            yylhs.value.as<Formals *>() = yystack_[0].value.as<Formals *>();
          }
#line 1156 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 16:
#line 158 "parser.y"
          {
            yylhs.value.as<Formals *>() = new Formals();
            yylhs.value.as<Formals *>()->AddFormal(yystack_[0].value.as<Formal *>());
          }
#line 1162 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 17:
#line 161 "parser.y"
          {
            yylhs.value.as<Formal *>() =
                new Formal(yystack_[1].value.as<types::Type *>(), yystack_[0].value.as<Identifier *>());
          }
#line 1168 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 18:
#line 164 "parser.y"
          { yylhs.value.as<types::Type *>() = yystack_[0].value.as<types::SimpleType *>(); }
#line 1174 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 19:
#line 165 "parser.y"
          { yylhs.value.as<types::Type *>() = yystack_[0].value.as<types::ArrayType *>(); }
#line 1180 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 20:
#line 168 "parser.y"
          { yylhs.value.as<types::SimpleType *>() = new types::Int(); }
#line 1186 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 21:
#line 169 "parser.y"
          { yylhs.value.as<types::SimpleType *>() = new types::Boolean(); }
#line 1192 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 22:
#line 170 "parser.y"
          { yylhs.value.as<types::SimpleType *>() = new types::Void(); }
#line 1198 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 23:
#line 171 "parser.y"
          { yylhs.value.as<types::SimpleType *>() = new types::TypeIdentifier(yystack_[0].value.as<Identifier *>()); }
#line 1204 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 24:
#line 174 "parser.y"
          { yylhs.value.as<types::ArrayType *>() = new types::ArrayType(yystack_[2].value.as<types::SimpleType *>()); }
#line 1210 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 25:
#line 177 "parser.y"
          {
            yystack_[1].value.as<StatementList *>()->AddStatement(yystack_[0].value.as<Statement *>());
            yylhs.value.as<StatementList *>() = yystack_[1].value.as<StatementList *>();
          }
#line 1216 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 26:
#line 178 "parser.y"
          { yylhs.value.as<StatementList *>() = new StatementList(); }
#line 1222 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 27:
#line 181 "parser.y"
          { yylhs.value.as<Statement *>() = new Assert(yystack_[1].value.as<Expr *>()); }
#line 1228 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 28:
#line 182 "parser.y"
          { yylhs.value.as<Statement *>() = yystack_[0].value.as<LocalVariableDeclaration *>(); }
#line 1234 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 29:
#line 183 "parser.y"
          { yylhs.value.as<Statement *>() = yystack_[1].value.as<StatementList *>(); }
#line 1240 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 30:
#line 184 "parser.y"
          {
            yylhs.value.as<Statement *>() = new If(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Statement *>());
          }
#line 1246 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 31:
#line 185 "parser.y"
          {
            yylhs.value.as<Statement *>() = new IfElse(yystack_[4].value.as<Expr *>(),
                                                       yystack_[2].value.as<Statement *>(),
                                                       yystack_[0].value.as<Statement *>());
          }
#line 1252 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 32:
#line 186 "parser.y"
          {
            yylhs.value.as<Statement *>() =
                new While(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Statement *>());
          }
#line 1258 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 33:
#line 187 "parser.y"
          { yylhs.value.as<Statement *>() = new Sout(yystack_[2].value.as<Expr *>()); }
#line 1264 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 34:
#line 188 "parser.y"
          {
            yylhs.value.as<Statement *>() =
                new Assignment(yystack_[3].value.as<Lvalue *>(), yystack_[1].value.as<Expr *>());
          }
#line 1270 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 35:
#line 189 "parser.y"
          { yylhs.value.as<Statement *>() = new Return(yystack_[1].value.as<Expr *>()); }
#line 1276 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 36:
#line 190 "parser.y"
          { yylhs.value.as<Statement *>() = yystack_[0].value.as<MethodInvocation *>(); }
#line 1282 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 37:
#line 193 "parser.y"
          {
            yylhs.value.as<MethodInvocation *>() = new MethodInvocation(yystack_[5].value.as<Expr *>(),
                                                                        yystack_[3].value.as<Identifier *>(),
                                                                        yystack_[1].value.as<ExprList *>());
          }
#line 1288 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 38:
#line 194 "parser.y"
          {
            yylhs.value.as<MethodInvocation *>() =
                new MethodInvocation(yystack_[4].value.as<Expr *>(), yystack_[2].value.as<Identifier *>());
          }
#line 1294 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 39:
#line 197 "parser.y"
          {
            yylhs.value.as<ExprList *>() = new ExprList();
            yylhs.value.as<ExprList *>()->AddExpr(yystack_[0].value.as<Expr *>());
          }
#line 1300 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 40:
#line 198 "parser.y"
          {
            yystack_[2].value.as<ExprList *>()->AddExpr(yystack_[0].value.as<Expr *>());
            yylhs.value.as<ExprList *>() = yystack_[2].value.as<ExprList *>();
          }
#line 1306 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 41:
#line 201 "parser.y"
          {
            yylhs.value.as<LocalVariableDeclaration *>() =
                new LocalVariableDeclaration(yystack_[0].value.as<VariableDeclaration *>());
          }
#line 1312 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 42:
#line 204 "parser.y"
          { yylhs.value.as<Lvalue *>() = new Variable(yystack_[0].value.as<Identifier *>()); }
#line 1318 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 43:
#line 205 "parser.y"
          {
            yylhs.value.as<Lvalue *>() =
                new ArrayElement(yystack_[3].value.as<Identifier *>(), yystack_[1].value.as<Expr *>());
          }
#line 1324 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 44:
#line 208 "parser.y"
          { yylhs.value.as<Expr *>() = yystack_[0].value.as<BinaryOperation *>(); }
#line 1330 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 45:
#line 209 "parser.y"
          {
            yylhs.value.as<Expr *>() =
                new ArrayElementVal(yystack_[3].value.as<Expr *>(), yystack_[1].value.as<Expr *>());
          }
#line 1336 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 46:
#line 210 "parser.y"
          { yylhs.value.as<Expr *>() = new Length(yystack_[2].value.as<Expr *>()); }
#line 1342 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 47:
#line 211 "parser.y"
          {
            yylhs.value.as<Expr *>() =
                new ArrayCreation(yystack_[3].value.as<types::SimpleType *>(), yystack_[1].value.as<Expr *>());
          }
#line 1348 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 48:
#line 213 "parser.y"
          { yylhs.value.as<Expr *>() = new Not(yystack_[0].value.as<Expr *>()); }
#line 1354 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 49:
#line 214 "parser.y"
          { yylhs.value.as<Expr *>() = yystack_[1].value.as<Expr *>(); }
#line 1360 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 50:
#line 215 "parser.y"
          { yylhs.value.as<Expr *>() = new VariableVal(yystack_[0].value.as<Identifier *>()); }
#line 1366 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 51:
#line 216 "parser.y"
          { yylhs.value.as<Expr *>() = yystack_[0].value.as<IntegerLiteral *>(); }
#line 1372 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 52:
#line 217 "parser.y"
          { yylhs.value.as<Expr *>() = new This(); }
#line 1378 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 53:
#line 218 "parser.y"
          { yylhs.value.as<Expr *>() = new True(); }
#line 1384 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 54:
#line 219 "parser.y"
          { yylhs.value.as<Expr *>() = new False(); }
#line 1390 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 55:
#line 220 "parser.y"
          { yylhs.value.as<Expr *>() = new MethodInvocationVal(yystack_[0].value.as<MethodInvocation *>()); }
#line 1396 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 56:
#line 223 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new LogicalAnd(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1402 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 57:
#line 224 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new LogicalOr(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1408 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 58:
#line 225 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new ComparisonLT(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1414 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 59:
#line 226 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new ComparisonGT(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1420 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 60:
#line 227 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Equal(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1426 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 61:
#line 228 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Sum(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1432 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 62:
#line 229 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Dif(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1438 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 63:
#line 230 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Mul(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1444 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 64:
#line 231 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Div(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1450 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 65:
#line 232 "parser.y"
          {
            yylhs.value.as<BinaryOperation *>() =
                new Mod(yystack_[2].value.as<Expr *>(), yystack_[0].value.as<Expr *>());
          }
#line 1456 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 66:
#line 235 "parser.y"
          { yylhs.value.as<Identifier *>() = new Identifier(yystack_[0].value.as<std::string>()); }
#line 1462 "/home/ubuntu/proj/src/parser.cpp"
            break;

          case 67:
#line 238 "parser.y"
          { yylhs.value.as<IntegerLiteral *>() = new IntegerLiteral(yystack_[0].value.as<int>()); }
#line 1468 "/home/ubuntu/proj/src/parser.cpp"
            break;

#line 1472 "/home/ubuntu/proj/src/parser.cpp"

          default:break;
        }
      }
#if YY_EXCEPTIONS
      catch (const syntax_error &yyexc) {
        YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
        error(yyexc);
        YYERROR;
      }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_(yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_(YY_NULLPTR, YY_MOVE(yylhs));
    }
    goto yynewstate;


    /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
    yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_) {
      ++yynerrs_;
      error(yyla.location, yysyntax_error_(yystack_[0].state, yyla));
    }

    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3) {
      /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

      // Return failure if at end of input.
      if (yyla.type_get() == yyeof_)
        YYABORT;
      else if (!yyla.empty()) {
        yy_destroy_("Error: discarding", yyla);
        yyla.clear();
      }
    }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


    /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
    yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_(yylen);
    yylen = 0;
    goto yyerrlab1;


    /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
    yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;) {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_(yyn)) {
          yyn += yy_error_token_;
          if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_) {
            yyn = yytable_[yyn];
            if (0 < yyn)
              break;
          }
        }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size() == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_("Error: popping", yystack_[0]);
        yypop_();
        YY_STACK_PRINT ();
      }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type(yyn);
      yypush_("Shifting", YY_MOVE(error_token));
    }
    goto yynewstate;


    /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
    yyacceptlab:
    yyresult = 0;
    goto yyreturn;


    /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
    yyabortlab:
    yyresult = 1;
    goto yyreturn;


    /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
    yyreturn:
    if (!yyla.empty())
      yy_destroy_("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_(yylen);
    while (1 < yystack_.size()) {
      yy_destroy_("Cleanup: popping", yystack_[0]);
      yypop_();
    }

    return yyresult;
  }
#if YY_EXCEPTIONS
  catch (...) {
    YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
    // Do not try to display the values of the reclaimed symbols,
    // as their printers might throw an exception.
    if (!yyla.empty())
      yy_destroy_(YY_NULLPTR, yyla);

    while (1 < yystack_.size()) {
      yy_destroy_(YY_NULLPTR, yystack_[0]);
      yypop_();
    }
    throw;
  }
#endif // YY_EXCEPTIONS
}

void
parser::error(const syntax_error &yyexc) {
  error(yyexc.location, yyexc.what());
}

// Generate an error message.
std::string
parser::yysyntax_error_(state_type yystate, const symbol_type &yyla) const {
  // Number of reported tokens (one for the "unexpected", one per
  // "expected").
  std::ptrdiff_t yycount = 0;
  // Its maximum.
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  // Arguments of yyformat.
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

  /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
  if (!yyla.empty()) {
    symbol_number_type yytoken = yyla.type_get();
    yyarg[yycount++] = yytname_[yytoken];

    int yyn = yypact_[+yystate];
    if (!yy_pact_value_is_default_(yyn)) {
      /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      // Stay within bounds of both yycheck and yytname.
      int yychecklim = yylast_ - yyn + 1;
      int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
      for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
            && !yy_table_value_is_error_(yytable_[yyx + yyn])) {
          if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
            yycount = 1;
            break;
          } else
            yyarg[yycount++] = yytname_[yyx];
        }
    }
  }

  char const *yyformat = YY_NULLPTR;
  switch (yycount) {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
    default: // Avoid compiler warnings.
    YYCASE_ (0, YY_("syntax error"));
    YYCASE_ (1, YY_("syntax error, unexpected %s"));
    YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
    YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
    YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
    YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
  }

  std::string yyres;
  // Argument number.
  std::ptrdiff_t yyi = 0;
  for (char const *yyp = yyformat; *yyp; ++yyp)
    if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount) {
      yyres += yytnamerr_(yyarg[yyi++]);
      ++yyp;
    } else
      yyres += *yyp;
  return yyres;
}

const signed char parser::yypact_ninf_ = -81;

const signed char parser::yytable_ninf_ = -56;

const short
    parser::yypact_[] =
    {
        -8, -33, 21, -81, -81, 12, -81, 14, 27, -33,
        -81, 25, -2, 42, -81, -33, 54, 61, 48, 63,
        -81, -10, -81, -81, -81, -81, -81, -81, -81, -33,
        52, -81, -81, 70, -33, 66, 62, 128, 81, 85,
        -81, -81, -81, -81, -3, 125, 84, 86, 72, -33,
        569, -81, 87, 89, 91, 92, 94, 569, -10, -81,
        -81, -81, 569, -81, 0, -81, 475, -81, -81, -81,
        100, 497, -81, -81, 96, -10, -81, -81, 24, -81,
        163, -81, 569, 569, 569, 569, 288, 88, 23, 569,
        569, 569, 569, 569, -7, 569, 569, 569, 569, 569,
        569, 569, 569, 194, -81, -81, -81, -81, 298, 336,
        342, 380, -81, 569, 386, 44, 44, 23, 23, -81,
        103, 424, 547, 547, 525, 503, 553, 23, 430, -81,
        225, 101, -81, 256, 256, 452, -81, 565, -81, -81,
        -81, -81, 83, -81, -81, -81, 475, 59, 256, -81,
        569, -81, 475
    };

const signed char
    parser::yydefact_[] =
    {
        0, 0, 0, 5, 66, 0, 1, 2, 0, 0,
        4, 0, 0, 0, 9, 0, 0, 0, 0, 0,
        6, 0, 22, 20, 21, 23, 8, 11, 10, 0,
        18, 19, 9, 0, 0, 0, 0, 0, 0, 0,
        12, 24, 7, 26, 0, 0, 0, 0, 16, 0,
        0, 26, 0, 0, 0, 0, 0, 0, 0, 52,
        53, 54, 0, 67, 50, 51, 0, 25, 41, 28,
        0, 36, 44, 26, 0, 0, 17, 50, 0, 55,
        0, 3, 0, 0, 0, 0, 0, 0, 48, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 26, 15, 49, 29, 0, 0,
        0, 0, 35, 0, 0, 62, 61, 63, 64, 46,
        0, 0, 59, 58, 56, 57, 60, 65, 0, 13,
        0, 0, 27, 0, 0, 0, 43, 0, 45, 34,
        14, 33, 30, 32, 47, 38, 39, 0, 0, 37,
        0, 31, 40
    };

const signed char
    parser::yypgoto_[] =
    {
        -81, -1, -81, 26, -81, -81, -81, -48, -80, -81,
        55, -81, 99, -81, -81, 2, -20, 77, -81, -81,
        -81, -43, -81, -81
    };

const short
    parser::yydefgoto_[] =
    {
        -1, 77, 65, 66, 2, 3, 7, 45, 67, 10,
        47, 48, 17, 26, 27, 68, 29, 30, 31, 69,
        70, 79, 72, 147
    };

const short
    parser::yytable_[] =
    {
        5, 34, 71, 80, -42, 1, 22, 46, 12, 14,
        23, 24, 4, 22, 18, 119, 25, 23, 24, 28,
        25, 6, 15, 8, 49, 103, 89, 9, 35, 90,
        91, 92, 93, 39, 106, 4, 25, 71, 4, 28,
        13, 11, 4, 25, 64, -23, 94, 94, 76, 95,
        95, 92, 93, 142, 143, 49, 130, 25, 16, 32,
        71, 96, 97, 98, 99, 100, 101, 94, 151, 149,
        95, 19, 33, 20, 25, 21, 78, 22, 36, 64,
        38, 23, 24, 86, 150, 40, 101, 71, 88, 41,
        71, 71, 43, 120, 44, 73, 74, 75, 82, 81,
        83, 84, 64, 85, 102, 71, 4, 104, 108, 109,
        110, 111, 137, 148, 113, 114, 115, 116, 117, 118,
        141, 121, 122, 123, 124, 125, 126, 127, 128, 64,
        105, 37, 64, 64, 50, 87, 51, 52, 0, 135,
        42, 22, 21, 53, 22, 23, 24, 64, 23, 24,
        0, 0, 0, 54, 55, 0, 56, 57, 58, 59,
        60, 61, 0, 146, 0, 0, 0, 0, 0, 62,
        4, 63, 50, 4, 51, 107, 152, 0, 0, 22,
        0, 53, 0, 23, 24, 0, 0, 0, 0, 0,
        0, 54, 55, 0, 56, 57, 58, 59, 60, 61,
        0, 0, 0, 50, 0, 51, 129, 62, 4, 63,
        22, 0, 53, 0, 23, 24, 0, 0, 0, 0,
        0, 0, 54, 55, 0, 56, 57, 58, 59, 60,
        61, 0, 0, 0, 50, 0, 51, 140, 62, 4,
        63, 22, 0, 53, 0, 23, 24, 0, 0, 0,
        0, 0, 0, 54, 55, 0, 56, 57, 58, 59,
        60, 61, 0, 0, 0, 50, 0, 51, 0, 62,
        4, 63, 22, 0, 53, 0, 23, 24, 0, 0,
        0, 0, 0, 0, 54, 55, 0, 56, 57, 58,
        59, 60, 61, 90, 91, 92, 93, 0, 0, 0,
        62, 4, 63, 90, 91, 92, 93, 112, 131, 0,
        0, 94, 0, 0, 95, 0, 0, 0, 0, 0,
        0, 94, 0, 0, 95, 96, 97, 98, 99, 100,
        101, 0, 0, 0, 0, 96, 97, 98, 99, 100,
        101, 90, 91, 92, 93, 0, 132, 90, 91, 92,
        93, 0, 133, 0, 0, 0, 0, 0, 0, 94,
        0, 0, 95, 0, 0, 94, 0, 0, 95, 0,
        0, 0, 0, 96, 97, 98, 99, 100, 101, 96,
        97, 98, 99, 100, 101, 90, 91, 92, 93, 0,
        134, 90, 91, 92, 93, 0, 0, 0, 0, 0,
        0, 0, 0, 94, 0, 0, 95, 0, 0, 94,
        0, 0, 95, 136, 0, 0, 0, 96, 97, 98,
        99, 100, 101, 96, 97, 98, 99, 100, 101, 90,
        91, 92, 93, 0, 0, 90, 91, 92, 93, 0,
        0, 0, 0, 0, 0, 0, 0, 94, 0, 139,
        95, 138, 0, 94, 0, 0, 95, 90, 91, 92,
        93, 96, 97, 98, 99, 100, 101, 96, 97, 98,
        99, 100, 101, 0, 0, 94, 0, 0, 95, 144,
        90, 91, 92, 93, 0, 0, 0, 0, 0, 96,
        97, 98, 99, 100, 101, 0, 0, 0, 94, 0,
        0, 95, -55, -55, -55, -55, 0, 0, 90, 91,
        92, 93, 96, 97, 98, 99, 100, 101, 0, 0,
        -55, 0, 0, -55, 0, 0, 94, 0, 0, 95,
        90, 91, 92, 93, -55, -55, -55, -55, -55, -55,
        96, 97, 98, 0, 100, 101, 0, 0, 94, 0,
        0, 95, 90, 91, 92, 93, 0, 0, 90, 91,
        92, 93, 96, 97, 0, 0, 100, 101, 0, 0,
        94, 0, 0, 95, 50, 145, 94, 0, 50, 95,
        0, 0, 0, 0, -56, -56, 0, 0, 0, 101,
        96, 97, 0, 0, 0, 101, 0, 0, 58, 59,
        60, 61, 58, 59, 60, 61, 0, 0, 0, 62,
        4, 63, 0, 62, 4, 63
    };

const short
    parser::yycheck_[] =
    {
        1, 21, 45, 51, 4, 13, 16, 10, 9, 11,
        20, 21, 45, 16, 15, 22, 17, 20, 21, 17,
        21, 0, 24, 11, 44, 73, 26, 13, 29, 5,
        6, 7, 8, 34, 10, 45, 37, 80, 45, 37,
        15, 14, 45, 44, 45, 45, 23, 23, 49, 26,
        26, 7, 8, 133, 134, 75, 104, 58, 16, 11,
        103, 37, 38, 39, 40, 41, 42, 23, 148, 10,
        26, 17, 9, 12, 75, 14, 50, 16, 26, 80,
        10, 20, 21, 57, 25, 19, 42, 130, 62, 27,
        133, 134, 11, 94, 9, 11, 10, 25, 9, 12,
        9, 9, 103, 9, 4, 148, 45, 11, 82, 83,
        84, 85, 9, 30, 26, 89, 90, 91, 92, 93,
        19, 95, 96, 97, 98, 99, 100, 101, 102, 130,
        75, 32, 133, 134, 9, 58, 11, 12, -1, 113,
        12, 16, 14, 18, 16, 20, 21, 148, 20, 21,
        -1, -1, -1, 28, 29, -1, 31, 32, 33, 34,
        35, 36, -1, 137, -1, -1, -1, -1, -1, 44,
        45, 46, 9, 45, 11, 12, 150, -1, -1, 16,
        -1, 18, -1, 20, 21, -1, -1, -1, -1, -1,
        -1, 28, 29, -1, 31, 32, 33, 34, 35, 36,
        -1, -1, -1, 9, -1, 11, 12, 44, 45, 46,
        16, -1, 18, -1, 20, 21, -1, -1, -1, -1,
        -1, -1, 28, 29, -1, 31, 32, 33, 34, 35,
        36, -1, -1, -1, 9, -1, 11, 12, 44, 45,
        46, 16, -1, 18, -1, 20, 21, -1, -1, -1,
        -1, -1, -1, 28, 29, -1, 31, 32, 33, 34,
        35, 36, -1, -1, -1, 9, -1, 11, -1, 44,
        45, 46, 16, -1, 18, -1, 20, 21, -1, -1,
        -1, -1, -1, -1, 28, 29, -1, 31, 32, 33,
        34, 35, 36, 5, 6, 7, 8, -1, -1, -1,
        44, 45, 46, 5, 6, 7, 8, 19, 10, -1,
        -1, 23, -1, -1, 26, -1, -1, -1, -1, -1,
        -1, 23, -1, -1, 26, 37, 38, 39, 40, 41,
        42, -1, -1, -1, -1, 37, 38, 39, 40, 41,
        42, 5, 6, 7, 8, -1, 10, 5, 6, 7,
        8, -1, 10, -1, -1, -1, -1, -1, -1, 23,
        -1, -1, 26, -1, -1, 23, -1, -1, 26, -1,
        -1, -1, -1, 37, 38, 39, 40, 41, 42, 37,
        38, 39, 40, 41, 42, 5, 6, 7, 8, -1,
        10, 5, 6, 7, 8, -1, -1, -1, -1, -1,
        -1, -1, -1, 23, -1, -1, 26, -1, -1, 23,
        -1, -1, 26, 27, -1, -1, -1, 37, 38, 39,
        40, 41, 42, 37, 38, 39, 40, 41, 42, 5,
        6, 7, 8, -1, -1, 5, 6, 7, 8, -1,
        -1, -1, -1, -1, -1, -1, -1, 23, -1, 19,
        26, 27, -1, 23, -1, -1, 26, 5, 6, 7,
        8, 37, 38, 39, 40, 41, 42, 37, 38, 39,
        40, 41, 42, -1, -1, 23, -1, -1, 26, 27,
        5, 6, 7, 8, -1, -1, -1, -1, -1, 37,
        38, 39, 40, 41, 42, -1, -1, -1, 23, -1,
        -1, 26, 5, 6, 7, 8, -1, -1, 5, 6,
        7, 8, 37, 38, 39, 40, 41, 42, -1, -1,
        23, -1, -1, 26, -1, -1, 23, -1, -1, 26,
        5, 6, 7, 8, 37, 38, 39, 40, 41, 42,
        37, 38, 39, -1, 41, 42, -1, -1, 23, -1,
        -1, 26, 5, 6, 7, 8, -1, -1, 5, 6,
        7, 8, 37, 38, -1, -1, 41, 42, -1, -1,
        23, -1, -1, 26, 9, 10, 23, -1, 9, 26,
        -1, -1, -1, -1, 37, 38, -1, -1, -1, 42,
        37, 38, -1, -1, -1, 42, -1, -1, 33, 34,
        35, 36, 33, 34, 35, 36, -1, -1, -1, 44,
        45, 46, -1, 44, 45, 46
    };

const signed char
    parser::yystos_[] =
    {
        0, 13, 51, 52, 45, 48, 0, 53, 11, 13,
        56, 14, 48, 15, 11, 24, 16, 59, 48, 17,
        12, 14, 16, 20, 21, 48, 60, 61, 62, 63,
        64, 65, 11, 9, 63, 48, 26, 59, 10, 48,
        19, 27, 12, 11, 9, 54, 10, 57, 58, 63,
        9, 11, 12, 18, 28, 29, 31, 32, 33, 34,
        35, 36, 44, 46, 48, 49, 50, 55, 62, 66,
        67, 68, 69, 11, 10, 25, 48, 48, 50, 68,
        54, 12, 9, 9, 9, 9, 50, 64, 50, 26,
        5, 6, 7, 8, 23, 26, 37, 38, 39, 40,
        41, 42, 4, 54, 11, 57, 10, 12, 50, 50,
        50, 50, 19, 26, 50, 50, 50, 50, 50, 22,
        48, 50, 50, 50, 50, 50, 50, 50, 50, 12,
        54, 10, 10, 10, 10, 50, 27, 9, 27, 19,
        12, 19, 55, 55, 27, 10, 50, 70, 30, 10,
        25, 55, 50
    };

const signed char
    parser::yyr1_[] =
    {
        0, 47, 51, 52, 53, 53, 56, 56, 59, 59,
        60, 60, 62, 61, 61, 57, 57, 58, 63, 63,
        64, 64, 64, 64, 65, 54, 54, 55, 55, 55,
        55, 55, 55, 55, 55, 55, 55, 68, 68, 70,
        70, 66, 67, 67, 50, 50, 50, 50, 50, 50,
        50, 50, 50, 50, 50, 50, 69, 69, 69, 69,
        69, 69, 69, 69, 69, 69, 48, 49
    };

const signed char
    parser::yyr2_[] =
    {
        0, 2, 2, 13, 2, 0, 5, 7, 2, 0,
        1, 1, 3, 8, 9, 3, 1, 2, 1, 1,
        1, 1, 1, 1, 3, 2, 0, 4, 1, 3,
        5, 7, 5, 5, 4, 3, 1, 6, 5, 1,
        3, 1, 1, 4, 1, 4, 3, 5, 2, 3,
        1, 1, 1, 1, 1, 1, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 1, 1
    };

// YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
// First, the terminals, then, starting at \a yyntokens_, nonterminals.
const char *
    const parser::yytname_[] =
    {
        "\"end of file\"", "error", "$undefined", "\"\\n\"", "\"=\"", "\"-\"",
        "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"",
        "\"class\"", "\"public\"", "\"static\"", "\"void\"", "\"main\"",
        "\"System.out.println\"", "\";\"", "\"int\"", "\"boolean\"",
        "\"length\"", "\".\"", "\"extends\"", "\",\"", "\"[\"", "\"]\"",
        "\"assert\"", "\"if\"", "\"else\"", "\"while\"", "\"return\"", "\"new\"",
        "\"this\"", "\"true\"", "\"false\"", "\">\"", "\"<\"", "\"&&\"",
        "\"||\"", "\"==\"", "\"%\"", "\"!=\"", "\"!\"", "\"identifier\"",
        "\"number\"", "$accept", "identifier", "number", "exp", "unit",
        "main_class", "class_declaration_list", "stmt_list", "stmt",
        "class_declaration", "formals", "formal", "declaration_list",
        "declaration", "method_declaration", "variable_declaration", "type",
        "simple_type", "array_type", "local_variable_declaration", "lvalue",
        "method_invocation", "binary_operation", "expr_list", YY_NULLPTR
    };

#if YYDEBUG
const unsigned char
    parser::yyrline_[] =
    {
        0, 125, 125, 131, 134, 135, 138, 139, 142, 143,
        146, 147, 150, 153, 154, 157, 158, 161, 164, 165,
        168, 169, 170, 171, 174, 177, 178, 181, 182, 183,
        184, 185, 186, 187, 188, 189, 190, 193, 194, 197,
        198, 201, 204, 205, 208, 209, 210, 211, 213, 214,
        215, 216, 217, 218, 219, 220, 223, 224, 225, 226,
        227, 228, 229, 230, 231, 232, 235, 238
    };

// Print the state stack on the debug stream.
void
parser::yystack_print_() {
  *yycdebug_ << "Stack now";
  for (stack_type::const_iterator
           i = yystack_.begin(),
           i_end = yystack_.end();
       i != i_end; ++i)
    *yycdebug_ << ' ' << int(i->state);
  *yycdebug_ << '\n';
}

// Report on the debug stream that the rule \a yyrule is going to be reduced.
void
parser::yy_reduce_print_(int yyrule) {
  int yylno = yyrline_[yyrule];
  int yynrhs = yyr2_[yyrule];
  // Print the symbols being reduced, and their result.
  *yycdebug_ << "Reducing stack by rule " << yyrule - 1
             << " (line " << yylno << "):\n";
  // The symbols being reduced.
  for (int yyi = 0; yyi < yynrhs; yyi++)
    YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                     yystack_[(yynrhs) - (yyi + 1)]);
}
#endif // YYDEBUG

} // yy
#line 2051 "/home/ubuntu/proj/src/parser.cpp"

#line 240 "parser.y"

void
yy::parser::error(const location_type &l, const std::string &m) {
  std::cerr << l << ": " << m << '\n';
}