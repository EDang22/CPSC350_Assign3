/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 3
* Main file, checks file and asks user for another file
*/
#include <iostream>
#include <string>
#include "SyntaxChecker.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 2)
  {
    SyntaxChecker Assign3(argv[1]);
    if (Assign3.checkFile())
    {
      while (true)
      {
        char ans;
        cout << "Do you want to analyze another file? (Enter Y for yes and N for no)" << endl;
        cin >> ans;
        if (tolower(ans) == 'y')
        {
          cout << "Enter file path" << endl;
          cin >> Assign3.fileName;
          Assign3.checkFile();
        }
        else if (tolower(ans) == 'n')
        {
          cout << "Goodbye!" << endl;
          return 0;
        }
        else
        {
          cout << "Error: Invalid input" << endl;
          cin.clear();
          cin.ignore();
        }
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    cout << "Error: invalid format, try again" << endl;
    return -1;
  }
}
