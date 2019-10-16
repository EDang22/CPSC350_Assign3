/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 3
* SyntaxChecker header file
*/
#include <iostream>
#include <string>

using namespace std;

class SyntaxChecker
{
  public:

    SyntaxChecker(); // default constructor
    SyntaxChecker(string f); // constructor with given file name
    bool checkFile(); // reads file for syntax errors
    string fileName;
};
