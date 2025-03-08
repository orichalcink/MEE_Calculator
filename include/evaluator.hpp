#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "catcher.hpp"
#include "ast.hpp"
#include "functions.hpp"
#include <cmath>

using namespace std::string_literals;

// Evaluate the AST tree
class Evaluator
{
public:
   // Constructor
   Evaluator(Catcher& catcher, Program& program)
      : catcher(catcher), program(program) {}
   ~Evaluator() = default;

   // Evaluate an AST tree and return the result
   long double evaluate()
   {
      long double result = 0.0;

      for (auto& ast : program.expressions)
      {
         if (ast->type() == ExprType::number && program.expressions.size() > 1)
         {
            catcher.insert("Unexpected number while evaluating."s);
            return 0.0;
         }
         result = evaluate_expr(ast);
      }

      return result;
   }

   // Evaluate an expression
   long double evaluate_expr(std::unique_ptr<Expr>& expr)
   {
      switch (expr->type())
      {
      case ExprType::function:
         return evaluate_function_expr(expr);
      case ExprType::binary:
         return evaluate_binary_expr(expr);
      case ExprType::unary:
         return evaluate_unary_expr(expr);
      case ExprType::number:
         return static_cast<NumberLiteral*>(expr.get())->value;
      }
   }

   // Evaluate a function call
   long double evaluate_function_expr(std::unique_ptr<Expr>& expr)
   {
      auto* func = static_cast<FunctionExpr*>(expr.get());
      std::vector<long double> arguments;

      for (auto& func_arg : func->args)
         arguments.push_back(evaluate_expr(func_arg));

      if (!function_table.count(func->name))
      {
         // This should never happen
         catcher.insert("Unexpected function while evaluating."s);
         return 0.0;
      }
      return function_table.at(func->name)(catcher, arguments);
   }

   // Evaluate a binary expression
   long double evaluate_binary_expr(std::unique_ptr<Expr>& expr)
   {
      auto* binary = static_cast<BinaryExpr*>(expr.get());

      switch (binary->op)
      {
      case TType::plus:
         return evaluate_expr(binary->left) + evaluate_expr(binary->right);
      case TType::minus:
         return evaluate_expr(binary->left) - evaluate_expr(binary->right);
      case TType::star:
         return evaluate_expr(binary->left) * evaluate_expr(binary->right);
      case TType::slash:
      {
         long double right = evaluate_expr(binary->right);
         if (right == 0.0)
         {
            catcher.insert("Division by zero is undefined."s);
            return 0.0;
         }
         return evaluate_expr(binary->left) / right;
      }
      case TType::power:
         return std::pow(evaluate_expr(binary->left), evaluate_expr(binary->right));
      default:
         // This should never happen
         catcher.insert("Unsupported binary operator while evaluating."s);
         return 0.0;
      }
   }

   // Evaluate an unary expression
   long double evaluate_unary_expr(std::unique_ptr<Expr>& expr)
   {
      auto* unary = static_cast<UnaryExpr*>(expr.get());

      switch (unary->op)
      {
      case TType::plus:
         return evaluate_expr(unary->value);
      case TType::minus:
         return -evaluate_expr(unary->value);
      case TType::percent:
         return evaluate_expr(unary->value) * .01;
      case TType::bang:
         return std::tgamma(evaluate_expr(unary->value) + 1);
      default:
         // This should never happen
         catcher.insert("Unsupported unary operator while evaluating."s);
         return 0.0;
      }
   }

private:
   Catcher& catcher;
   Program& program;
};

#endif // EVALUATOR_HPP
