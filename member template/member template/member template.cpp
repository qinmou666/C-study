#include <iostream>
#include<typeinfo>
using namespace std;
template<class T>
class calculator {
public:
	calculator(T a, T b) :a(a), b(b) {};
	T operator()(T a,T b)const { return a+b; }
private:
	T a;
	T b;
};

int main() {
	calculator<int> a(1,2);
	cout<< a << endl;
}