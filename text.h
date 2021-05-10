
#pragma once
#include <string>
using namespace std;
#include <iostream>

class text {

public:
	void directory();
	void WordCloud();
	void afficheWordCloud();
	void modifier_parameterWorCloud();

	void ecrireFile(string path, char *values);
	string lireFile(string dirName);
	string removeWord(string str, string word);



};
