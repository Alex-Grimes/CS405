#include <iostream>
#include <exception>
#include <typeinfo>

struct newException : public std::exception {
    const char* what() const throw () {
        return "My Custom Exception";
    }
};

bool do_even_more_custom_application_logic()
{
  std::cout << "Running Even More Custom Application Logic." << std::endl;
  char test1[] = "abcdefghijklmnopqrzxyzABCDEFGHIJKLMNOPQRZXYZ";
  if (sizeof(test1) >= 5) {
    throw std::length_error("Too Many Characters"); 
  }
  return true;
}
void do_custom_application_logic()
{
  std::cout << "Running Custom Application Logic." << std::endl;
  try {
        if(do_even_more_custom_application_logic())
        {
        std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::exception& ex) { 
        std::cout << ex.what() << std::endl; 
        throw newException(); 
    }
  std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
throw(std::exception)
{
    if (den == 0) { //checks for 0 
        throw std::runtime_error("Divide By 0 Error");
    }
  return (num / den);
}

void do_division()
{
  float numerator = 10.0f;
  float denominator = 0;
  try {
    auto result = divide(numerator, denominator);
    std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
  }
  catch (const std::exception& e) {
        std::cerr << "Exception Caught: " << typeid(e).name() << std::endl;
        std::cerr << "Description: " << e.what() << std::endl;
  }
   
}
int main()
{
  std::cout << "Exceptions Tests!" << std::endl;
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (newException& exc) { 
        std::cout << exc.what() << std::endl;
    }
    catch (const char* msg) { 
        std::cerr << msg << std::endl;
    }
    catch (...) { 
        std::cout << "Default Exception" << std::endl;
    }
    return 0;
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu