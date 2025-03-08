#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast.hpp"
#include "catcher.hpp"

using namespace std::string_literals;

// Parse the tokens into an AST tree and check for valid syntax
class Parser
{
public:
   // Constructors
   Parser(Catcher& catcher, std::vector<Token>& tokens)
      : catcher(catcher), tokens(tokens) {}
   ~Parser() = default;

   // Parse the tokens into an AST tree
   Program& parse()
   {
      while (!is(TType::eof))
         program.expressions.push_back(std::move(parse_additive_expr()));

      return program;
   }

   // Parse binary plus and minus expressions
   std::unique_ptr<Expr> parse_additive_expr()
   {
      auto left = parse_implicit_multiplication_expr();

      while (is(TType::plus) || is(TType::minus))
      {
         TType op = tokens.at(index).type;
         advance();

         auto right = parse_implicit_multiplication_expr();
         left = std::make_unique<BinaryExpr>(left, op, right);
      }
      return left;
   }

   // Parse implicit multiplication
   std::unique_ptr<Expr> parse_implicit_multiplication_expr()
   {
      auto left = parse_multiplicative_expr();

      while (is(TType::number) || is(TType::lParen) || is(TType::function))
      {
         auto right = (is(TType::number) ? parse_multiplicative_expr() : (is(TType::lParen) ? parse_primary_expr() : parse_function_calls()));
         left = std::make_unique<BinaryExpr>(left, TType::star, right);
      }
      return left;
   }

   // Parse binary multiplication and divide expressions
   std::unique_ptr<Expr> parse_multiplicative_expr()
   {
      auto left = parse_exponentiation_expr();

      while (is(TType::star) || is(TType::slash))
      {
         TType op = tokens.at(index).type;
         advance();

         auto right = parse_exponentiation_expr();
         left = std::make_unique<BinaryExpr>(left, op, right);
      }
      return left;
   }

   // Parse binary exponentiation expressions 
   std::unique_ptr<Expr> parse_exponentiation_expr()
   {
      auto left = parse_unary_expr();

      while (is(TType::power))
      {
         TType op = tokens.at(index).type;
         advance();

         auto right = parse_exponentiation_expr();
         left = std::make_unique<BinaryExpr>(left, op, right);
      }
      return left;
   }

   // Parse unary expressions
   std::unique_ptr<Expr> parse_unary_expr()
   {
      if (is(TType::minus) || is(TType::plus))
      {
         TType op = tokens.at(index).type;
         advance();

         auto expr = parse_percentage_expr();
         return std::make_unique<UnaryExpr>(op, expr);
      }
      return parse_percentage_expr();
   }

   // Parse percentage expressions
   std::unique_ptr<Expr> parse_percentage_expr()
   {
      auto value = parse_factorial_expr();

      if (is(TType::percent))
      {
         advance();
         value = std::make_unique<UnaryExpr>(TType::percent, value);
      }
      return value;
   }

   // Parse factorial expressions
   std::unique_ptr<Expr> parse_factorial_expr()
   {
      auto value = parse_function_calls();

      if (is(TType::bang))
      {
         advance();
         value = std::make_unique<UnaryExpr>(TType::bang, value);
      }
      return value;
   }

   // Parse function calls
   std::unique_ptr<Expr> parse_function_calls()
   {
      if (!is(TType::function))
         return parse_primary_expr();

      auto function = std::make_unique<FunctionExpr>(tokens.at(index).lexeme);
      advance();

      if (!is(TType::lParen))
      {
         catcher.insert("Expected left parenthesis '(' after function call '"s + function->name + "'."s);
         return function;
      }
      advance();

      if (is(TType::rParen))
      {
         advance();
         return function;
      }

      auto value = parse_additive_expr();
      function->args.push_back(std::move(value));

      while (is(TType::comma))
      {
         advance();
         auto value = parse_additive_expr();
         function->args.push_back(std::move(value));
      }

      if (!is(TType::rParen))
         catcher.insert("Expected right parenthesis ')' to close function call '"s + function->name + "', but got '"s + tokens.at(index).lexeme + "' instead."s);

      advance();
      return function;
   }

   // Parse the types and parenthesis
   std::unique_ptr<Expr> parse_primary_expr()
   {
      if (is(TType::number))
      {
         long double number = std::stold(tokens.at(index).lexeme);
         advance();
         return std::make_unique<NumberLiteral>(number);
      }
      else if (is(TType::lParen))
      {
         advance();
         auto value = parse_additive_expr();

         if (!is(TType::rParen))
            catcher.insert("Unclosed parenthesis."s);

         advance();
         return value;
      }
      else
      {
         catcher.insert("Expected a primary expression, got '"s + tokens.at(index).lexeme + "' instead."s);
         advance();
         return std::make_unique<NumberLiteral>(0.0);
      }
   }

   // Advance the index by one
   void advance()
   {
      if (index + 1 < tokens.size()) ++index;
   }

   // Check if the current token is the given type
   bool is(TType type) const
   {
      return tokens.at(index).type == type;
   }

private:
   Catcher& catcher;
   std::vector<Token>& tokens;
   Program program;
   size_t index = 0;
};

#endif // PARSER_HPP
