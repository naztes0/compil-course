#pragma once
#include "nodes.hh"

namespace ast {

class Evaluator : public ConstASTIntVisitor {
public:
  int visit(const IntegerLiteral &) override;
  int visit(const BinaryOperator &) override;
  int visit(const IfThenElse &) override;
  int visit(const Sequence &) override;
  int visit(const StringLiteral &) override;
  int visit(const Identifier &) override;
  int visit(const FunCall &) override;
  int visit(const Assign &) override;
  int visit(const WhileLoop &) override;
  int visit(const ForLoop &) override;
  int visit(const Break &) override;
  int visit(const VarDecl &) override;
  int visit(const FunDecl &) override;
  int visit(const Let &) override;
};

} 
