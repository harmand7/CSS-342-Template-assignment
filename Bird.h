#pragma once
#include <string>
#include <ostream>
using namespace std;

class Bird
{
	friend ostream& operator<<(ostream &out, const Bird &ref);
	friend istream& operator>>(std::istream &in, Bird&ref);
public:
	Bird();
	Bird(string nName, int nID);
	Bird(const Bird &ref);
	~Bird();

	int getID() const;
	string getBirdName() const;

	Bird operator=(const Bird &ref);

	bool operator==(const Bird &ref) const;
	bool operator!=(const Bird &ref) const;

	bool operator<(const Bird &ref) const;
	bool operator>(const Bird &ref) const;

	bool operator>=(const Bird &ref) const;
	bool operator<=(const Bird &ref) const;

private:

	int id;
	string name;
};

