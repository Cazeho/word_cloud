#include <iostream>
#include <string>
#include <list>
#include "dirfilelist.h"
#include<fstream>
#include<stdio.h>
#include <windows.h>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main()
{
  string dirName;

  cout<<"Enter directory name: ";
  cin>>dirName;

  list<string> fileList;
  bool error=getDirectoryFileList(dirName,fileList);

  if (error) cout<<"An error occured"<<endl;
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
  cin>> f;
  dirName = dirName + "\\" + f;
  cout << "\n";
  cout << dirName;



  string myText;


  ifstream MyReadFile(dirName);

  cout << "\n";
  while (getline(MyReadFile, myText)) {

	  cout << myText;
  }
  cout << "\n";
      
      
  return 0;
}
