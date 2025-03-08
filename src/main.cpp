#include "lexer.hpp"
#include "parser.hpp"
#include "evaluator.hpp"

// Mathematical expression evaluator by chalcinxx; fancy calculator.
// This works very similarly to an interpreted programming language, but does
// not include any statements. I wasn't going for efficiency while writing
// this, as the calculator taking 1 millisecond longer does not change anything
// for me.
//
// User Input --> Lexer --> Parser --> Evaluator --> Result
//
// Firstly, the input is retrieved from the user.
// Secondly, the lexer converts the input into tokens and checks for any
// unknown characters and keywords. In this case, it also handles constants.
// Thirdly, the parser reads through the tokens, produces an AST tree and
// checks if the syntax is valid.
// Lastly, the evaluator evaluates the AST tree step by step until it gets the
// final result. Any functions found are called in this step.
//
// A great reference for creating an interpreted language in typescript, as I
// said before, a MEE is very similar to this:
// https://www.youtube.com/playlist?list=PL_2VhOvlMk4UHGqYCLWc6GO8FaPl8fQTh

int main()
{
   std::cout << "Terminal calculator with a mathematical expression evaluator." << std::endl;
   Catcher catcher;

   while (true)
   {
      // Get input from the user
      std::cout << "> ";
      std::string command;
      std::getline(std::cin, command);

      // Quit the program
      if (command == "quit"s || command == "exit"s)
      {
         std::cout << "Exiting..." << std::endl;
         break;
      }

      // Tokenize the input
      Lexer lexer (catcher, command);
      auto& tokens = lexer.tokenize();

      if (catcher.display())
         continue;

      // Parse the tokens
      Parser parser (catcher, tokens);
      auto& program = parser.parse();

      if (catcher.display())
         continue;
      
      // Evaluate the result
      Evaluator evaluator (catcher, program);
      long double result = evaluator.evaluate();

      if (catcher.display())
         continue;

      // Print out the result if everything was successful
      std::cout << "Result: " << result << std::endl;
   }
}