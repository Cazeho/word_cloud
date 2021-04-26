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


/*
#include <map>
#include<sstream>
#include<iostream>

using namespace std;

void wordsCount(string str){

      int count = 1;
      //key value pair map
      //key = word, value = count
      std::map<string,int> wordsMap;

      //extract words and push in map
      istringstream wordStream(str);

      string word;
      //Extract each words and add to map
      //if it does not exist in map
       while(wordStream >> word){
             //create a pair of map and bool
             pair<map<string,int>::iterator,bool> retrunValue;

             //insert element
            retrunValue = wordsMap.insert( pair<string,int>(word,count));

            //Check if map contains value
            if (retrunValue.second==false)
            {
                  //Element already exists
                  ++retrunValue.first->second; 
            }     
       }//while

       //Iterate elements and print words 
       map<string,int>::iterator itr ;

       for (itr = wordsMap.begin(); itr != wordsMap.end(); ++itr){

               cout << '\t' << itr->first ;
               cout<< '\t' << itr->second << '\n';
       }
}

int main(){

      wordsCount("hello world !!! hello world !!! good day");    

      return 0;

}*/
