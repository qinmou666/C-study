#pragma once
#define __MYSTRING__
#include<iostream>
using namespace std;

class String {
public:
	String(const char*);
	String(const String& str);
	String& operator=(const String& str);
	~String();
	char* get_c_str()const{return m_data;}
	String& operator+=(const String& str);
private:
	char* m_data;
	friend String& __doapl(String*,const String& str);
};
String::String(const char* cstr = 0) {
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	 }
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

String::String(const String& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}
String::~String() {
	delete[] m_data;
}

String&
String::operator=(const String& str) {
	if (this == &str)
		return *this;
	delete[] str.m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data,str.m_data);
	return *this;
}
inline String&
String::operator+=(const String& str) { 
	return __doapl(this, str);
}
inline String&
__doapl(String* ths, const String& str) {
	if (ths == &str)
		return *ths;
	String& m_data = new char[strlen(ths->m_data) + strlen(str.m_data) + 1];
	strcat(ths->m_data, str.m_data);
	return *ths;
}


ostream&
operator <<(ostream& os, const String& str) {
	return os << str.get_c_str();

}
