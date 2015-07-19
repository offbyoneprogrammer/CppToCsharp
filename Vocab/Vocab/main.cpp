#include <iostream>
#include <vector>
#include <algorithm>
#include "vocab.h"
using namespace std;

void add_word(vector<vocab*> &vocab_list);
void print_vocab_list(vector<vocab*> &vocab_list);
void test_vocab_list(vector<vocab*> vocab_list);

int main(int argc, const char* argv[])
{
	vector<vocab*> vocab_list;
	char answer = 0;
	while (answer != 'e')
	{
		cout << "What you want to do? 1 - Do a Test, 2 - add vocab, 3 - print all vocabs, e - exit" << endl;
		cin >> answer;

		switch (answer)
		{
		case '1':
			test_vocab_list(vocab_list);
			break;
		case '2':
			add_word(vocab_list);
			break;
		case '3':
			print_vocab_list(vocab_list);
			break;
		default:
			cout << "Wrong Input" << endl;
			break;
		}
	}

	cout << "Bye" << endl;
	for (vocab* voc : vocab_list) {
		free(voc);
	}

	return 0;
}


void add_word(vector<vocab*> &vocab_list)
{
	string german;
	string english;
	cout << "German: ";
	cin >> german;
	cout << "English: ";
	cin >> english;
	vocab_list.push_back(new vocab(english, german));
}

void print_vocab_list(vector<vocab*> &vocab_list)
{
	for (vocab* voc : vocab_list) {
		cout << voc->toString() << endl;
	}
}

void test_vocab_list(vector<vocab*> vocab_list)
{
	std::random_shuffle(vocab_list.begin(), vocab_list.end());
	string answer;
	for (unsigned int i = 0; i < 10 && i < vocab_list.size(); i++)
	{
		cout << "Whats " << vocab_list[i]->getEnglish() << " in German? " << endl;
		cin >> answer;
		if (vocab_list[i]->compareGerman(answer))
			cout << "Rigth" << endl;
		else
			cout << "Wrong it is " << vocab_list[i]->getGerman() << endl;
	}
}