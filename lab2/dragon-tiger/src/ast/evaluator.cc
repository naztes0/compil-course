#include "evaluator.hh"
#include "../utils/errors.hh"

namespace ast {

int Evaluator::visit(const IntegerLiteral &node) {
  return node.value;
}

int Evaluator::visit(const BinaryOperator &node) {
  int left = node.get_left().accept(*this);
  int right = node.get_right().accept(*this);
  switch (node.op) {
    case o_plus:   return left + right;
    case o_minus:  return left - right;
    case o_times:  return left * right;
    case o_divide: return left / right;
    case o_eq:     return left == right ? 1 : 0;
    case o_neq:    return left != right ? 1 : 0;
    case o_lt:     return left < right ? 1 : 0;
    case o_gt:     return left > right ? 1 : 0;
    case o_le:     return left <= right ? 1 : 0;
    case o_ge:     return left >= right ? 1 : 0;
  }
  utils::error("unknown operator");
  return 0;
}

int Evaluator::visit(const IfThenElse &node) {
  int cond = node.get_condition().accept(*this);
  if (cond)
    return node.get_then_part().accept(*this);
  else
    return node.get_else_part().accept(*this);
}

int Evaluator::visit(const Sequence &node) {
  auto exprs = node.get_exprs();
  if (exprs.empty())
    utils::error("empty sequence");
  int result = 0;
  for (auto expr : exprs)
    result = expr->accept(*this);
  return result;
}

int Evaluator::visit(const StringLiteral &node) {
  utils::error(node.loc, "cannot evaluate string literal");
  return 0;
}
int Evaluator::visit(const Identifier &node) {
  utils::error(node.loc, "cannot evaluate identifier");
  return 0;
}
int Evaluator::visit(const FunCall &node) {
  utils::error(node.loc, "cannot evaluate function call");
  return 0;
}
int Evaluator::visit(const Assign &node) {
  utils::error(node.loc, "cannot evaluate assignment");
  return 0;
}
int Evaluator::visit(const WhileLoop &node) {
  utils::error(node.loc, "cannot evaluate while loop");
  return 0;
}
int Evaluator::visit(const ForLoop &node) {
  utils::error(node.loc, "cannot evaluate for loop");
  return 0;
}
int Evaluator::visit(const Break &node) {
  utils::error(node.loc, "cannot evaluate break");
  return 0;
}
int Evaluator::visit(const VarDecl &node) {
  utils::error(node.loc, "cannot evaluate variable declaration");
  return 0;
}
int Evaluator::visit(const FunDecl &node) {
  utils::error(node.loc, "cannot evaluate function declaration");
  return 0;
}
int Evaluator::visit(const Let &node) {
  utils::error(node.loc, "cannot evaluate let expression");
  return 0;
}
} // namespace ast
