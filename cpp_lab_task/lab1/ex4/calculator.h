#ifndef LAB1_EX4_CALCULATOR_H_
#define LAB1_EX4_CALCULATOR_H_

namespace calculator{

class Calculator{
 public:
	Calculator();
	~Calculator();
	double Add(const double &a, const double &b) const;
	double Subtract(const double &a, const double &b) const;
	double Multiply(const double &a, const double &b) const;
	double Divide(const double &a, const double &b) const;
};

}// namespace calculator

#endif //LAB1_EX4_CALCULATOR_H_
