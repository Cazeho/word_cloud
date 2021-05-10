#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>

#include "text.h"


#include <string>
#include <vector>
using namespace std;




template <class T>
struct less_second : binary_function<T, T, bool>
{
	inline bool operator()(const T& lhs, const T& rhs)
	{
		return lhs.second.value < rhs.second.value;
	}
};
class WordCounter
{
public:
	int value;
	WordCounter() : value(0) {}
	void operator++ (int) { value++; }
};
ostream& operator<<(ostream& st, WordCounter& wc)
{
	return st << wc.value;
}
// Remove unwanted characters from a string  
bool filter(char c)
{
	return isalpha(c) == 0;
}
const string path = "C:\\Users\\manuel\\Desktop\\C++\\test.txt";
int main()
{
	typedef pair< string, WordCounter > word_mapping;
	map<string, WordCounter> counter;
	ifstream input;
	input.open(path.c_str());
	if (!input)
	{
		cout << "Error in opening file\n";
		return 0;
	}
	string tok;
	while (true)
	{
		input >> tok;
		// Remove ?, !, , characters etc from string  
		tok.resize(remove_if(tok.begin(), tok.end(), filter) - tok.begin());
		if (input)
		{
			counter[tok]++;
		}
		else break;
	}
	map< string, WordCounter, less<string> >::iterator it = counter.begin();
	// And then sort and display the result:
	vector< word_mapping > result(counter.begin(), counter.end());
	sort(result.rbegin(), result.rend(), less_second<word_mapping>());
	for (vector< word_mapping >::const_iterator mit = result.begin();
		mit != result.end();
		mit++)
	{
		cout << setw(15)
			<< (*mit).first
			<< "\t"
			<< (*mit).second.value
			<< endl;
	}
	ofstream outfile("C:\\Users\\manuel\\Desktop\\C++\\process.txt");
	for (vector< word_mapping >::const_iterator mit = result.begin();
		mit != result.end();
		mit++)
	{
		outfile << (*mit).first << endl;
	}
	outfile.close();
	string choix;
	system("pause");
	cout << "choisir: ";
	cin >> choix;
	string dirName;
	dirName = "C:\\Users\\manuel\\Desktop\\C++\\process.txt";


	text t;
	 t.lireFile(dirName);

	cout << t.lireFile(dirName) << endl;
	cout << "----" << endl;

	cout << t.removeWord(t.lireFile(dirName), choix) << endl;
	return 0;
}
