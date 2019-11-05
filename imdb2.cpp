/*
File: imdb.cpp
Author: Khue Le, Sarah Li
Oct 22nd,2019
CS271, Dr. Lall

--------------------------
This is a program that inserts information from the accompanying file from IMDb 1
into a Dict object with movie/show title as keys and genres as values. Your
program should print the genre for any title entered.
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "dict.h"
using namespace std;

Dict<Pair> readFile()
{
  Dict<Pair> dict;
  ifstream fin("data.tsv");

  if (!fin)
  {
      cout << "Error opening file. Shutting down..." << endl;
  }
  // get current line
  for( std::string line; getline( fin, line ,'\n'); )
  {
      // store current line in a stream
      stringstream ss;
      ss<<line;

      // parse current line
      int column = 0;
      string title;
      string genre;

      for(std::string current; getline(ss,current,'\t');)
      {
        if (column == 3) //get title
        {
          title = current;
        }
        if (column == 8) //get genre
        {
          genre = current;
        }
        column +=1;

      }
      //Pair *fooptr=new Pair(title,genre);
      try
      {
        dict.insert(new Pair(title,genre));
      }
      catch(KeyError)
      {
        //cout << "repeated title" << endl;
      }
      //delete fooptr;
  }
  return dict;
}
int main()
{

  cout<<"Wait a bit..."<<endl;
  Dict<Pair> dict = readFile();
  string input;
  cout<<"Enter title: ";
  cin>>input;
  Pair inputnode(input,"");
  Node<Pair>*resultptr=dict.get(inputnode);
  Node<Pair> result = *resultptr;
  cout<<(*(result.key)).getvalue()<<endl;



}
