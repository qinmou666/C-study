#ifndef __COMPLEX__
#define __COMPLEX__
#include<iostream>
using namespace std;

class complex{
public:
	complex(double re = 0,double im=0)
		:re(re),im(im){}
	complex& operator+=(const complex&);
	double real() const{ return re; }
	double imag() const{ return im; }
private:
	double re, im;

	friend complex& __doapl(complex*, const complex&);
};
inline complex& 
complex::operator+=(const complex& r) {
	return __doapl(this, r);
}
inline complex&
__doapl(complex* ths, const complex& r) {
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}


inline complex
operator +(const complex& x, const complex& y)
{
	return complex(x.real() + y.real(), x.imag() + y.imag());
}
inline complex
operator+(const complex& x, double y) {
	return complex((x.real() + y), x.imag());
}
inline complex
operator+(double x, const complex& y) {
	return complex(y.real() + x, y.imag());
}
ostream&
operator<<(ostream& os, const complex& x) {
	return os << '(' << x.real() << ',' << x.imag() << ')';
 }

#endif
