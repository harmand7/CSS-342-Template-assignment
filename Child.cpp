

#include "Child.h"


Child::Child()
{
}

Child::Child(string nFirstName, string nLastName, int nAge)
{	
	FirstName = nFirstName;
	LastName = nLastName;
	age = nAge;
}

Child::Child(const Child &ref)
{
	LastName = ref.LastName;
	FirstName = ref.FirstName;
	age = ref.age;
}

int Child::getAge() const
{
	return age;
}
string Child::getLastName() const
{
	return LastName;
}
string Child::getFirstName() const
{
	return FirstName;
}

Child Child::operator=(const Child &ref)
{
	Child temp;
	temp.LastName = ref.LastName;
	temp.FirstName = ref.FirstName;
	temp.age = ref.age;
	return temp;
}

bool Child::operator==(const Child &ref) const
{
	return (ref.age == age && ref.FirstName == FirstName && ref.LastName == LastName);
}

bool Child::operator!=(const Child &ref) const
{
	return!(*this == ref);
}

bool Child::operator<(const Child &ref) const
{
	if (LastName < ref.LastName)
	{
		return true;
	}
	else if (LastName == ref.LastName)
	{
		if (FirstName == ref.FirstName)
		{
			if (age < ref.age)
			{
				return true;
			}
		}
		else if (FirstName < ref.FirstName)
		{
			return true;
		}
	}
	return false;
}
bool Child::operator>(const Child &ref) const
{
	if (LastName > ref.LastName)
	{
		return true;
	}
	else if (LastName == ref.LastName)
	{
		if (FirstName == ref.FirstName)
		{
			if (age > ref.age)
			{
				return true;
			}
		}
		else if (FirstName > ref.FirstName)
		{
			return true;
		}
	}
	return false;

}

bool Child::operator>=(const Child &ref) const
{
	return!(*this < ref);
}
bool Child::operator<=(const Child &ref) const
{
	return!(*this > ref);
}

ostream& operator<<(std::ostream &out, const Child &ref)
{
	return out << ref.FirstName.c_str() << ref.LastName.c_str() << ref.age;
}
istream& operator>>(std::istream &in, Child &ref)
{
	in >> ref.FirstName >> ref.LastName >> ref.age;
	return in;
}


Child::~Child()
{
}
