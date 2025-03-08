#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <cstdint>
#include <string>

// Token types
enum class TType : std::int8_t
{ number, plus, minus, star, slash, percent, power, bang, comma, function, lParen, rParen, eof };

// Tokens used in the parser
struct Token
{
   TType type;
   std::string lexeme;
};

#endif // TOKENS_HPP
