#include<iostream>
using namespace std;
class Animal {
public:
	virtual void Speak() { cout << "Animal��˵��" << endl; }
};
class cat :public Animal {
public:
	void Speak() { cout << "cat��˵��" << endl; }
};
class dog :public Animal {
public:
	void Speak() { cout << "dog��˵��" << endl; }
};
void doSpeak(Animal &animal) {
	animal.Speak();
}
void test01() {
	cat c;
	doSpeak(c);
}
int main() {
	test01();
}