#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, string address) :m_name(name), m_address(address) {};
	~Person();

	string GetName() const { return m_name; };
	string GetAddress() const { return m_address; };
private:
	string m_name, m_address;
};

