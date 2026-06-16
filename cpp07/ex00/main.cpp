#include "templates.hpp"
#include <iostream>
#include <string>

int main () {
  int i=5, j=6;
  long l=10, m=8;
  std::string c = "chaine1";
  std::string d = "chaine2";

  std::cout << "Variables" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "Ints: i=" << i << "; j=" << j << ";" << std::endl;
  std::cout << "Longs: l=" << l << "; m=" << m << ";" << std::endl;
  std::cout << "Strings: c=" << c << "; d=" << d << ";" << std::endl;
  std::cout << std::endl;

  std::cout << "Max" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << ::max(i, j) << std::endl;
  std::cout << ::max(l, m) << std::endl;
  std::cout << ::max(c, d) << std::endl;
  std::cout << std::endl;
   
  std::cout << "Min" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << ::min(i, j) << std::endl;
  std::cout << ::min(l, m) << std::endl;
  std::cout << ::min(c, d) << std::endl;
  std::cout << std::endl;
     
  std::cout << "Swap" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  ::swap(i, j);
  ::swap(l, m);
  ::swap(c, d);
  std::cout << "Ints: i=" << i << "; j=" << j << ";" << std::endl;
  std::cout << "Longs: l=" << l << "; m=" << m << ";" << std::endl;
  std::cout << "Strings: c=" << c << "; d=" << d << ";" << std::endl;
  std::cout << std::endl;

  return 0;
}
