#include<iostream>
class Component {
public:
	Component() { printf("ComonentG\n"); }
	~Component() { printf("ComonentX\n"); }
};
class Afirst {
public:
	Afirst() { printf("AfirstG\n"); }
	~Afirst() { printf("AfirstX\n"); }
};
class Base:public Afirst {
public:
	Base() { printf("BaseG\n"); }
	~Base() { printf("BaseX\n");}
	Component C;
};

class Derived:public Base {
public:
	Derived() { printf("DerivedG\n"); }
	~Derived() { printf("DerivedX\n"); }
};

int main() {
	Derived D;
	std::cout << "-------" << std::endl;
	Base B;
}