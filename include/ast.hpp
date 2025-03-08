#ifndef AST_HPP
#define AST_HPP

#include "tokens.hpp"
#include <vector>
#include <memory>

// Type of the expression
enum class ExprType : std::int8_t
{ binary, unary, function, number };

// Expression
struct Expr
{
   virtual ~Expr() = default;
   virtual ExprType type() const = 0;
};

// Function calls
struct FunctionExpr : public Expr
{
   std::string name;
   std::vector<std::unique_ptr<Expr>> args;

   FunctionExpr(const std::string& name)
      : name(name) {}

   ExprType type() const override
   {
      return ExprType::function;
   }
};

// Expressions with two values and a single operator
struct BinaryExpr : public Expr
{
   std::unique_ptr<Expr> left;
   TType op;
   std::unique_ptr<Expr> right;

   BinaryExpr(std::unique_ptr<Expr>& left, TType op, std::unique_ptr<Expr>& right)
      : left(std::move(left)), op(op), right(std::move(right)) {}

   ExprType type() const override
   {
      return ExprType::binary;
   }
};

// Expressions with one value and a single operator
struct UnaryExpr : public Expr
{
   TType op;
   std::unique_ptr<Expr> value;

   UnaryExpr(TType op, std::unique_ptr<Expr>& value)
      : op(op), value(std::move(value)) {}

   ExprType type() const override
   {
      return ExprType::unary;
   }
};

// Number literal
struct NumberLiteral : public Expr
{
   long double value;

   NumberLiteral(long double value)
      : value(value) {}

   ExprType type() const override
   {
      return ExprType::number;
   }
};

// Contains the whole AST tree
struct Program
{
   std::vector<std::unique_ptr<Expr>> expressions;
};

#endif // AST_HPP
