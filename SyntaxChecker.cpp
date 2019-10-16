/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 3
* SyntaxChecker implementation file, implemented constructors and check file
*/
#include <iostream>
#include <fstream>
#include "SyntaxChecker.h"
#include "GenStack.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{
  fileName = "";
}

SyntaxChecker::SyntaxChecker(string f)
{
  fileName = f;
}

// method that check files for delimiter syntax errors, returns true if no errors
bool SyntaxChecker::checkFile()
{
  string line = ""; // represents current line
  int lineNum = 0; // line number
  GenStack<char> delimiters; // stack of opening delimiters ( "{" , "[" , "(")
  bool isComment = false;
  ifstream file(fileName);
  if (file)
  {
    while (getline(file, line))
    {
      ++lineNum;
      for (int i = 0; i < line.length(); ++i)
      {
        if ((line[i] == '{' || line[i] == '[' || line[i] == '(') && !isComment) // if opening delimiters, adds to stack
        {
          delimiters.push(line[i]);
          continue;
        }
        else if (line[i] == '}' && !isComment)
        {
          if (delimiters.peek() == '{')
          {
            delimiters.pop();
            break;
          }
          else if (delimiters.peek() == '[')
          {
            cout << "Error on line " << lineNum << ": expected ] found }" << endl;
            return false;
          }
          else
          {
            cout << "Error on line " << lineNum << ": expected ) found }" << endl;
            return false;
          }
        }
        else if (line[i] == ']' && !isComment)
        {
          if (delimiters.peek() == '[')
          {
            delimiters.pop();
            break;
          }
          else if (delimiters.peek() == '{')
          {
            cout << "Error on line " << lineNum << ": expected } found ]" << endl;
            return false;
          }
          else
          {
            cout << "Error on line " << lineNum << ": expected ) found ]" << endl;
            return false;
          }
        }
        else if (line[i] == ')' && !isComment)
        {
          if (delimiters.peek() == '(')
          {
            delimiters.pop();
            break;
          }
          else if (delimiters.peek() == '[')
          {
            cout << "Error on line " << lineNum << ": expected ] found )" << endl;
            return false;
          }
          else
          {
            cout << "Error on line " << lineNum << ": expected } found )" << endl;
            return false;
          }
        }
        else if (line[i] == '/')
        {
          if (i != line.length() - 1)
          {
            if (line[i + 1] == '/') // indicates line will be comment
            {
              continue;
            }
            else if (line[i + 1] == '*') // indicates beginning of multi line comment
            {
              isComment = true;
            }
          }
        }
        else if (isComment && line[i] == '*')
        {
          if (i != line.length() - 1)
          {
            if (line[i + 1] == '/') // indicates end of multi line comment
            {
              isComment = false;
            }
          }
        }
        else if (line[i] == '\'' || line[i] == '\"') // indicates beginning or end of quotation marks
        {
          if (isComment)
            isComment = false;
          else
            isComment = true;
        }
      }
    }
    if (!delimiters.isEmpty()) // if reached end of file and still items in stack (means missing delimiters)
    {
      if (delimiters.peek() == '(')
      {
        cout << "Error: Reached end of file ) expected" << endl;
        return false;
      }
      else if (delimiters.peek() == '[')
      {
        cout << "Error: Reached end of file ] expected" << endl;
        return false;
      }
      else
      {
        cout << "Error: Reached end of file } expected" << endl;
        return false;
      }
    }
  }
  else
  {
    cout << "Error: File could not be opened" << endl;
    return false;
  }
  cout << "File clean" << endl;
  return true;
}
