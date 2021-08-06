#ifndef LAB1_EX1_COMPLEX_CLASS_H_
#define LAB1_EX1_COMPLEX_CLASS_H_

#include <utility>

namespace complex_class{
class Complex{
 public:
  Complex();
  Complex(const double re, const double im);
  Complex Adding(const Complex &a, const Complex &b);
  Complex Subtracting(const Complex &a, const Complex &b);
  void Print();
  ~Complex();
 private:
	std::pair<double,double> complex_;
};
} //namespace complex_class

#endif //LAB1_EX1_COMPLEX_CLASS_H_
