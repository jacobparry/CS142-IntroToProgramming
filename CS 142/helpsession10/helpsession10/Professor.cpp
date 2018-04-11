#include "Professor.h"


Professor::Professor()
{
}


Professor::~Professor()
{
}

void Professor::Add_Class(string add_class)
{
	classes_taught.push_back(add_class);
}