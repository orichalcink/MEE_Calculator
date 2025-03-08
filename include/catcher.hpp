#ifndef CATCHER_HPP
#define CATCHER_HPP

#include <iostream>
#include <vector>
#include <string>

// Catch and display errors
class Catcher
{
public:
   // Constructors
   Catcher() = default;
   ~Catcher() = default;

   // Insert a new error into the catcher
   void insert(const std::string& error)
   {
      errors.push_back(error);
   }

   // Check if there are any errors
   bool any_errors() const
   {
      return errors.size() > 0;
   }

   // Display all errors if there are any
   bool display()
   {
      if (errors.size() == 0)
         return false;
      
      std::cout << std::endl << errors.size() << " error" << (errors.size() == 1 ? "" : "s") << " occurred: " << std::endl;
      for (const auto& error : errors)
         std::cout << error << std::endl;
      
      errors.clear();
      std::cout << std::endl;
      return true;
   }

private:
   std::vector<std::string> errors;
};

#endif // CATCHER_HPP
