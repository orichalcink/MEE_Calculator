#ifndef LEXER_HPP
#define LEXER_HPP

#include "catcher.hpp"
#include "tokens.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std::string_literals;

// Convert the user's input into tokens and check for any unexpected characters
class Lexer
{
public:
   // Math constants
   static inline const std::unordered_map<std::string, std::string> constants
   {
      {"e"s, "2.718281828459045"s}, {"pi"s, "3.141592653589793"s}, {"tau"s, "6.283185307179586"s},
      {"phi"s, "1.618033988749895"s}, {"gamma"s, "0.577215664901532"s}, {"pie"s, "3.4517261471"s}
   };

   // Functions
   static inline const std::unordered_set<std::string> functions
   {
      "sin"s, "csc"s, "asin"s, "sinh"s, "asinh"s,
      "cos"s, "sec"s, "acos"s, "cosh"s, "acosh"s,
      "tan"s, "cot"s, "atan"s, "atan2"s, "tanh"s, "atanh"s,
      "pow"s, "sqrt"s, "cbrt"s,
      "exp"s, "ln"s, "log"s, "log2"s, "log10"s,
      "fact"s, "perm"s, "comb"s,
      "add"s, "sub"s, "mul"s, "div"s, "abs"s, "neg"s,
      "min"s, "max"s, "clamp"s, "floor"s, "ceil"s, "round"s,
      "rand"s, "randf"s, "randi"s
   };

   // Constructors
   Lexer(Catcher& catcher, const std::string& source)
      : catcher(catcher), source(source) {}
   ~Lexer() = default;

   // Tokenize the source into tokens
   std::vector<Token>& tokenize()
   {
      for (size_t index = 0; index < source.size(); ++index)
      {
         char ch = source.at(index);

         if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
            ;
         else if (ch == '+')
            tokens.push_back({TType::plus, "+"s});
         else if (ch == '-')
            tokens.push_back({TType::minus, "-"s});
         else if (ch == '*')
            tokens.push_back({TType::star, "*"s});
         else if (ch == '/')
            tokens.push_back({TType::slash, "/"s});
         else if (ch == '%')
            tokens.push_back({TType::percent, "%"s});
         else if (ch == '^')
            tokens.push_back({TType::power, "^"s});
         else if (ch == '!')
            tokens.push_back({TType::bang, "!"s});
         else if (ch == ',')
            tokens.push_back({TType::comma, ","s});
         else if (ch == '(')
            tokens.push_back({TType::lParen, "("s});
         else if (ch == ')')
            tokens.push_back({TType::rParen, ")"s});
         else if (isletter(ch))
         {
            std::string keyword;

            for (; index < source.size(); ++index)
            {
               ch = source.at(index);

               if (!isletter(ch) && !isdigit(ch))
               {
                  --index;
                  break;
               }
               keyword += std::tolower(ch);
            }

            if (functions.count(keyword))
               tokens.push_back({TType::function, keyword});
            else if (constants.count(keyword))
               tokens.push_back({TType::number, constants.at(keyword)});
            else
               catcher.insert("Unknown keyword: '"s + keyword + "'."s);
         }
         else if (validnumber(ch))
         {
            std::string number;
            bool floating  = false;
            bool lastQuote = false;

            for (; index < source.size(); ++index)
            {
               ch = source.at(index);

               if (ch == '\'')
               {
                  if (lastQuote || (index + 1 < source.size() && !validnumber(source.at(index + 1))))
                  {
                     catcher.insert("Invalid quote placement in number '"s + number + "'."s);
                     return tokens;
                  }
                  lastQuote = true;
                  continue;
               }
               lastQuote = false;

               if (ch == '.' && !floating)
               {
                  floating = true;
                  number += ch;
                  continue;
               }
               else if (ch == '.')
               {
                  catcher.insert("Invalid number with two or more commas: '"s + number + "'."s);
                  return tokens;
               }

               if (!isdigit(ch))
               {
                  --index;
                  break;
               }

               number += ch;
            }

            tokens.push_back({TType::number, number});
         }
         else
            catcher.insert("Unexpected character while lexing: '"s + ch + "'."s);
      }

      tokens.push_back({TType::eof, "eof"s});
      return tokens;
   }

   // Check if the character is a letter  
   bool isletter(char ch)
   {
      return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
   }

   // Check if the character is a digit
   bool isdigit(char ch)
   {
      return ch >= '0' && ch <= '9';
   }

   // Check if the character is a digit or a dot
   bool validnumber(char ch)
   {
      return isdigit(ch) || ch == '.';
   }

private:
   Catcher& catcher;
   std::string source;
   std::vector<Token> tokens;
};

#endif // LEXER_HPP
