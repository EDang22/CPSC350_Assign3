/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 3
* GenStack Class holding template class for stack
*/
#include <iostream>

using namespace std;

template<typename T>
class GenStack
{
  public:
    GenStack(); // constructor
    GenStack(int maxSize); // overloaded constructor
    ~GenStack(); // destructor

    void push(T d);
    T pop();
    T peek();

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    T *myArray; // pointer to array, sets pointer to first value of array and with max size, able to understand where each value of array is
};

template<typename T>
GenStack<T>::GenStack()
{
  myArray = new T[128];
  size = 128;
  top = -1;
}

template<typename T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template<typename T>
GenStack<T>::~GenStack()
{
  delete myArray;
}

template<typename T>
void GenStack<T>::push(T d)
{
  if (isFull()) // array is full, must resize and move all data over
  {
    T *ta = myArray;
    myArray = new T[size * 2];
    for (int i = 0; i < size; ++i)
    {
      myArray[i] = ta[i];
    }
    delete ta;
  }
  myArray[++top] = d;
}

template<typename T>
T GenStack<T>::pop()
{
  if (isEmpty())
  {
    cout << "Error: stack is already empty" << endl;
  }
  else
    return myArray[top--];
}

template<typename T>
T GenStack<T>::peek()
{
  if (isEmpty())
  {
    cout << "Error: stack is empty" << endl;
  }
  else
    return myArray[top];
}

template<typename T>
bool GenStack<T>::isFull()
{
  return (top == size - 1);
}

template<typename T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
