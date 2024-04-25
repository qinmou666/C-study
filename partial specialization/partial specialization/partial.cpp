#include<iostream>
using namespace std;
template<typename T>
class c {
public:
	c() { cout << "test1" << endl; }
};
template<class T>
class c<T*> {
public:
	c() { cout << "test2" << endl; }

};

int main() {
	c<int> test1;
	c<int*> test2;
}