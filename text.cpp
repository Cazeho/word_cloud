
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
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


using namespace std;


void text::ecrireFile(string path, char *values) {
	ofstream outfile(path);


	/*for (vector< word_mapping >::const_iterator mit = result.begin();
	mit != result.end();
	mit++)
	{
	outfile << (*mit).first << endl;
	}*/

	outfile.close();
}

	string text::lireFile(string dirName) {
		string combine;
		string i;
		ifstream dataFile(dirName);


		if (dataFile) {
			while (getline(dataFile, i))
				combine += " " + i;
		}
		cout << combine << endl;

		return combine;
	}




	string text::removeWord(string str, string word)
	{
		if (str.find(word) != string::npos)
		{
			size_t p = -1;

			string tempWord = word + " ";
			while ((p = str.find(word)) != string::npos)
				str.replace(p, tempWord.length(), "");

			tempWord = " " + word;
			while ((p = str.find(word)) != string::npos)
				str.replace(p, tempWord.length(), "");
		}
		return str;
	}
