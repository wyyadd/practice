#ifndef LAB1_EX5_INTEGER_SET_H_
#define LAB1_EX5_INTEGER_SET_H_

namespace integer_set{

class IntegerSet{
 public:
	IntegerSet(){};
	IntegerSet(int*, int);
	~IntegerSet(){};
	void Input();
	void Output();
	void Insert(int);
	void Delete(int);
	bool IsEqualTo(const IntegerSet& x);
	static IntegerSet Union(const IntegerSet& a, const IntegerSet& b);
	static IntegerSet Intersection(const IntegerSet& a, const IntegerSet& b);
 private:
	bool arr_[101] = {0};
};

}// namespace integer_set
#endif //LAB1_EX5_INTEGER_SET_H_
