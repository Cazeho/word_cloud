#include <iostream>
#include <string>
#include <list>
#include "dirfilelist.h"
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>






using namespace std;



using namespace std;
void wordsCount(string str) {
	int count = 1;
	//key value pair map
	//key = word, value = count
	std::map<string, int> wordsMap;
	//extract words and push in map
	istringstream wordStream(str);
	string word;

	//Extract each words and add to map
	//if it does not exist in map
	while (wordStream >> word) {
		//create a pair of map and bool
		pair<map<string, int>::iterator, bool> retrunValue;
		//insert element
		retrunValue = wordsMap.insert(pair<string, int>(word, count));
		//Check if map contains value
		if (retrunValue.second == false)
		{
			//Element already exists
			++retrunValue.first->second;
		}

	}//while
	 //Iterate elements and print words
	map<string, int>::iterator itr;
	for (itr = wordsMap.begin(); itr != wordsMap.end(); ++itr) {
		cout << '\t' << itr->first;
		cout << '\t' << itr->second << '\n';
	}

}

int main()
{
	string dirName;

	cout << "Enter directory name: ";
	/*C:\Users\manuel\[nom_du_répertoire]*/
	cin >> dirName;

	list<string> fileList;
	bool error = getDirectoryFileList(dirName, fileList);

	if (error) cout << "An error occured" << endl;
	else
	{
		fileList.sort();
		cout << "Number of files: " << fileList.size() << endl;
		cout << "File list: " << endl;
		for (list<string>::iterator it = fileList.begin(); it != fileList.end(); it++)
			cout << *it << endl;
	}


	string f;

	system("pause");
	cout << dirName;
	cout << "\n";
	cout << "select a file :";
	cin >> f;
	dirName = dirName + "\\" + f;
	cout << "\n";
	cout << dirName;
	
	
	

	string combine;
	string input;

	ifstream dataFile(dirName);

	if (dataFile)
		while (getline(dataFile, input))
			combine += input;

	cout << combine << endl;
	wordsCount(combine);

	
	

	return 0;
};




/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <class T>
struct less_second : std::binary_function<T, T, bool>
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
//const string path = "/home/andy/NetBeansProjects/WordCount/Hamlet.txt";  //Linux

int main()
{
	typedef std::pair< string, WordCounter > word_mapping;

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
	std::vector< word_mapping > result(counter.begin(), counter.end());
	std::sort(result.rbegin(), result.rend(), less_second<word_mapping>());

	for (std::vector< word_mapping >::const_iterator mit = result.begin();
		mit != result.end();
		mit++)
	{
		cout << std::setw(15)
			<< (*mit).first
			<< "\t"
			<< (*mit).second.value
			<< endl;
	}


	return 0;
}



*/



