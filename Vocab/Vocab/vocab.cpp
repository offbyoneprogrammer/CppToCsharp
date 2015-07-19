#include "vocab.h"
#include <string>
#include <sstream>
#include <vector>

using std::string;

vocab::vocab(string english, string german)
{
	this->english = english;
	this->german = german;
}
string vocab::getGerman()
{
	return german;
}

string vocab::getEnglish()
{
	return english;
}

bool vocab::compareGerman(string german)
{
	return (german.compare(this->german) == 0);
}

string vocab::toString()
{
	return english + " " + german;
}
