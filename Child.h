#pragma once
#include <string>
#include <ostream>
using namespace std;
class Child
{

	friend ostream& operator<<(std::ostream &out, const Child &ref);
	friend istream& operator>>(std::istream &in, Child &ref);

public:
	Child();
	Child(string nFirst, string nLast, int nAge);
	Child(const Child &ref);
	~Child();

	int getAge() const;
	string getLastName() const;
	string getFirstName() const;

	Child operator=(const Child &ref);

	bool operator==(const Child &ref) const;
	bool operator!=(const Child &ref) const;

	bool operator<(const Child &ref) const;
	bool operator>(const Child &ref) const;

	bool operator>=(const Child &ref) const;
	bool operator<=(const Child &ref) const;

private:
	string FirstName;
	string LastName;
	int age;
};

