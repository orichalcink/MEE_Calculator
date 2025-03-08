#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>
#include <functional>
#include <random>
#include "catcher.hpp"

using namespace std::string_literals;

// Almost fell asleep writing this, might have some mistakes

//////////////////////////////////////////////////////////////////////////
// Sine
//////////////////////////////////////////////////////////////////////////

// Calculate sine
inline long double f_sin(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'sin' function, expected 1 argument."s);
      return 0.0;
   }
   return std::sin(args.at(0));
}

// Calculate cosecant
inline long double f_csc(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'csc' function, expected 1 argument."s);
      return 0.0;
   }
   return 1.0 / std::sin(args.at(0));
}

// Calculate arcsine
inline long double f_asin(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'asin' function, expected 1 argument."s);
      return 0.0;
   }
   return std::asin(args.at(0));
}

// Calculate hyperbolic sine
inline long double f_sinh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'sinh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::sinh(args.at(0));
}

// Calculate inverse hyperbolic sine
inline long double f_asinh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'asinh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::asinh(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Cosine
//////////////////////////////////////////////////////////////////////////

// Calculate cosine
inline long double f_cos(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'cos' function, expected 1 argument."s);
      return 0.0;
   }
   return std::cos(args.at(0));
}

// Calculate secant
inline long double f_sec(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'sec' function, expected 1 argument."s);
      return 0.0;
   }
   return 1.0 / std::cos(args.at(0));
}

// Calculate arccosine
inline long double f_acos(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'acos' function, expected 1 argument."s);
      return 0.0;
   }
   return std::acos(args.at(0));
}

// Calculate hyperbolic cosine
inline long double f_cosh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'cosh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::cosh(args.at(0));
}

// Calculate inverse hyperbolic cosine
inline long double f_acosh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'acosh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::acosh(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Tangent
//////////////////////////////////////////////////////////////////////////

// Calculate tangent
inline long double f_tan(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'tan' function, expected 1 argument."s);
      return 0.0;
   }
   return std::tan(args.at(0));
}

// Calculate cotangent
inline long double f_cot(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'cot' function, expected 1 argument."s);
      return 0.0;
   }
   return 1.0 / std::tan(args.at(0));
}

// Calculate arctangent
inline long double f_atan(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'atan' function, expected 1 argument."s);
      return 0.0;
   }
   return std::atan(args.at(0));
}

// Calculate arctangent
inline long double f_atan2(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2)
   {
      catcher.insert("Invalid argument count in 'atan2' function, expected 2 arguments."s);
      return 0.0;
   }
   return std::atan2(args.at(0), args.at(1));
}

// Calculate hyperbolic tangent
inline long double f_tanh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'tanh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::tanh(args.at(0));
}

// Calculate inverse hyperbolic tangent
inline long double f_atanh(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'atanh' function, expected 1 argument."s);
      return 0.0;
   }
   return std::atanh(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Power and Root
//////////////////////////////////////////////////////////////////////////

// Exponential function
inline long double f_exp(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'exp' function, expected 1 argument."s);
      return 0.0;
   }
   return std::exp(args.at(0));
}

// Exponentiation
inline long double f_pow(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2)
   {
      catcher.insert("Invalid argument count in 'pow' function, expected 2 arguments."s);
      return 0.0;
   }
   return std::pow(args.at(0), args.at(1));
}

// Calculate the square root
inline long double f_sqrt(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'sqrt' function, expected 1 argument."s);
      return 0.0;
   }

   if (args.at(0) < 0.0)
   {
      catcher.insert("Cannot calculate the square root of a negative number."s);
      return 0.0;
   }
   return std::sqrt(args.at(0));
}

// Calculate the cube root
inline long double f_cbrt(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'cbrt' function, expected 1 argument."s);
      return 0.0;
   }

   if (args.at(0) < 0.0)
   {
      catcher.insert("Cannot calculate the cube root of a negative number."s);
      return 0.0;
   }
   return std::cbrt(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Logarithmic
//////////////////////////////////////////////////////////////////////////

// Natural logarithm
inline long double f_ln(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'ln' function, expected 1 argument."s);
      return 0.0;
   }
   return std::log(args.at(0));
}

// Logarithm
inline long double f_log(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2)
   {
      catcher.insert("Invalid argument count in 'log' function, expected 2 arguments."s);
      return 0.0;
   }
   if (args.at(0) == 0.0)
   {
      catcher.insert("Log(0, b) is undefined."s);
      return 0.0;
   }
   if (args.at(1) == 1.0)
   {
      catcher.insert("Log(x, 1) is undefined."s);
      return 0.0;
   }

   return std::log(args.at(0)) / std::log(args.at(1));
}

// Logarithm base 2
inline long double f_log2(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'log2' function, expected 1 argument."s);
      return 0.0;
   }
   return std::log2(args.at(0));
}

// Logarithm base 10
inline long double f_log10(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'log10' function, expected 1 argument."s);
      return 0.0;
   }
   return std::log10(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Factorial
//////////////////////////////////////////////////////////////////////////

// Calculate factorial
inline long double f_fact(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'fact' function, expected 1 argument."s);
      return 0.0;
   }
   return std::tgamma(args.at(0) + 1);
}

// Calculate permutation
inline long double f_perm(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2)
   {
      catcher.insert("Invalid argument count in 'perm' function, expected 2 arguments."s);
      return 0.0;
   }
   long double n = args.at(0);
   long double k = args.at(1);

   return std::tgamma(n + 1) / std::tgamma((n - k) + 1);
}

// Calculate combinations
inline long double f_comb(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2)
   {
      catcher.insert("Invalid argument count in 'comb' function, expected 2 arguments."s);
      return 0.0;
   }
   long double n = args.at(0);
   long double k = args.at(1);

   return std::tgamma(n + 1) / (std::tgamma(k + 1) * std::tgamma((n - k) + 1));
}

//////////////////////////////////////////////////////////////////////////
// Utility
//////////////////////////////////////////////////////////////////////////

// Mass add numbers together
inline long double f_add(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'add' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double result = args.at(0);

   for (size_t i = 1; i < args.size(); ++i)
      result += args.at(i);
   return result;
}

// Mass subtract numbers
inline long double f_sub(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'sub' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double result = args.at(0);

   for (size_t i = 1; i < args.size(); ++i)
      result -= args.at(i);
   return result;
}

// Mass multiply numbers together
inline long double f_mul(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'mul' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double result = args.at(0);

   for (size_t i = 1; i < args.size(); ++i)
      result *= args.at(i);
   return result;
}

// Mass divide numbers
inline long double f_div(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'div' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double result = args.at(0);

   for (size_t i = 1; i < args.size(); ++i)
   {
      if (args.at(i) == 0.0)
      {
         catcher.insert("Division by zero is undefined."s);
         return 0.0;
      }

      result /= args.at(i);
   }
   return result;
}

// Get absolute value
inline long double f_abs(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'abs' function, expected 1 argument."s);
      return 0.0;
   }
   return std::abs(args.at(0));
}

// Negate the number
inline long double f_neg(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'neg' function, expected 1 argument."s);
      return 0.0;
   }
   return -args.at(0);
}

// Get the smallest number
inline long double f_min(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'min' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double smallest = std::numeric_limits<long double>::infinity();

   for (const auto& arg : args)
      if (arg < smallest)
         smallest = arg;
   return smallest;
}

// Get the largest number
inline long double f_max(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() < 2)
   {
      catcher.insert("Invalid argument count in 'max' function, expected atleast 2 arguments."s);
      return 0.0;
   }
   long double biggest = -std::numeric_limits<long double>::infinity();

   for (const auto& arg : args)
      if (arg > biggest)
         biggest = arg;
   return biggest;
}

// Clamp the number to the given values
inline long double f_clamp(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 3)
   {
      catcher.insert("Invalid argument count in 'clamp' function, expected 3 arguments."s);
      return 0.0;
   }
   return std::clamp(args.at(0), std::min(args.at(1), args.at(2)), std::max(args.at(1), args.at(2)));
}

// Round down
inline long double f_floor(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'floor' function, expected 1 argument."s);
      return 0.0;
   }
   return std::floor(args.at(0));
}

// Round up
inline long double f_ceil(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'ceil' function, expected 1 argument."s);
      return 0.0;
   }
   return std::ceil(args.at(0));
}

// Round to the nearest integer
inline long double f_round(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 1)
   {
      catcher.insert("Invalid argument count in 'round' function, expected 1 argument."s);
      return 0.0;
   }
   return std::round(args.at(0));
}

//////////////////////////////////////////////////////////////////////////
// Random
//////////////////////////////////////////////////////////////////////////

// Get a random floating point number
inline long double f_randf(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2 && args.size() != 0)
   {
      catcher.insert("Invalid argument count in 'randf' function, expected either 2 arguments or no arguments."s);
      return 0.0;
   }

   static thread_local std::random_device rd;
   static thread_local std::mt19937 generator(rd());

   if (args.size() == 0)
   {
      std::uniform_real_distribution<long double> dist(0.0, 1.0);
      return dist(generator);
   }
   else
   {
      std::uniform_real_distribution<long double> dist(std::min(args.at(0), args.at(1)), std::max(args.at(0), args.at(1)));
      return dist(generator);
   }
}

// Get a random floating point number
inline long double f_randi(Catcher& catcher, const std::vector<long double>& args)
{
   if (args.size() != 2 && args.size() != 0)
   {
      catcher.insert("Invalid argument count in 'randi' function, expected either 2 arguments or no arguments."s);
      return 0.0;
   }

   static thread_local std::random_device rd;
   static thread_local std::mt19937 generator(rd());

   if (args.size() == 0)
   {
      std::uniform_int_distribution<long> dist(0, 1);
      return dist(generator);
   }
   else
   {
      std::uniform_int_distribution<long> dist(std::min(args.at(0), args.at(1)), std::max(args.at(0), args.at(1)));
      return dist(generator);
   }
}

// A table of all functions, made so the evaluator looks pretty
inline const std::unordered_map<std::string, std::function<long double(Catcher&, const std::vector<long double>&)>> function_table
{
   {"sin"s, f_sin}, {"csc"s, f_csc}, {"asin"s, f_asin}, {"sinh"s, f_sinh}, {"asinh"s, f_asinh},
   {"cos"s, f_cos}, {"sec"s, f_sec}, {"acos"s, f_acos}, {"cosh"s, f_cosh}, {"acosh"s, f_acosh},
   {"tan"s, f_tan}, {"cot"s, f_cot}, {"atan"s, f_atan}, {"atan2"s, f_atan2}, {"tanh"s, f_tanh}, {"atanh"s, f_atanh},
   {"pow"s, f_pow}, {"sqrt"s, f_sqrt}, {"cbrt"s, f_cbrt},
   {"exp"s, f_exp}, {"ln"s, f_ln}, {"log"s, f_log}, {"log2"s, f_log2}, {"log10"s, f_log10},
   {"fact"s, f_fact}, {"perm"s, f_perm}, {"comb"s, f_comb},
   {"add"s, f_add}, {"sub"s, f_sub}, {"mul"s, f_mul}, {"div"s, f_div}, {"abs"s, f_abs}, {"neg"s, f_neg},
   {"min"s, f_min}, {"max"s, f_max}, {"clamp"s, f_clamp}, {"floor"s, f_floor}, {"ceil"s, f_ceil}, {"round"s, f_round},
   {"rand"s, f_randf}, {"randf"s, f_randf}, {"randi"s, f_randi}
};

#endif // FUNCTIONS_HPP
