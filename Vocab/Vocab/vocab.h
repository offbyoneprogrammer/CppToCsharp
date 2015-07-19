#include <string>
using std::string;

class vocab
{
public:

	vocab(string english, string german);

	string getGerman();

	string getEnglish();

	bool compareGerman(string german);

	string toString();


private:
	string english;
	string german;
};