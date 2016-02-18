#include "Bird.h"


Bird::Bird()
{
}
Bird::Bird(string nName, int nID)
{
	name = nName;
	id = nID;
}
Bird::Bird(const Bird &ref)
{
	name = ref.name;
	id = ref.id;
}

int Bird::getID() const
{
	return id;
}
string Bird::getBirdName() const
{
	return name;
}

Bird Bird::operator=(const Bird &ref)
{
	Bird temp;
	temp.name = ref.name;
	temp.id = ref.id;
	return temp;
}

bool Bird::operator==(const Bird &ref) const
{
	return (id == ref.id && name == ref.name);
}
bool Bird::operator!=(const Bird &ref) const
{
	return!(*this == ref);
}

bool Bird::operator<(const Bird &ref) const
{
	return (id < ref.id);
}
bool Bird::operator>(const Bird &ref) const
{
	return(id>ref.id);
}

bool Bird::operator>=(const Bird &ref) const
{
	return!(*this < ref);
}
bool Bird::operator<=(const Bird &ref) const
{
	return!(*this > ref);
}

ostream& operator<<(ostream &out, const Bird &ref)
{
	out << ref.name.c_str() << ref.id;
	return out;
}
istream& operator>>(istream &in, Bird &ref)
{
	in >> ref.name >> ref.id;
	return in;
}

Bird::~Bird()
{
}
