#include "dict.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


void test_empty()
{
  Dictionary<string> fruit;
  assert(fruit.empty() == 1);

  string f1="apple";
  string*f1ptr = &f1;
  fruit.insert(f1ptr);
  assert(fruit.empty() == 0);
}

void test_insert()
{
  Dictionary<string> fruit;
  string f1="apple";
  string*f1ptr = &f1;
  fruit.insert(f1ptr);

  assert(f1 == *((*fruit.get("apple")).key));
}

void test_get()
{
  Dictionary<string> fruit;
  string f1="apple";
  string*f1ptr = &f1;
  fruit.insert(f1ptr);


  string f2="banana";
  string*f2ptr = &f2;
  fruit.insert(f2ptr);

  string f3="berry";
  string*f3ptr = &f3;
  fruit.insert(f3ptr);

  string f4="melon";
  string*f4ptr = &f4;
  fruit.insert(f4ptr);

  Node<string>*testGet = fruit.get("banana");
  assert( *((*testGet).key) == "banana" ); //correct Key value
  assert( (*testGet).key == f2ptr ); //Correct pointer

}

void test_remove()
{
  Dictionary<string> fruit;
  string f1="apple";
  string*f1ptr = &f1;
  fruit.insert(f1ptr);


  string f2="banana";
  string*f2ptr = &f2;
  fruit.insert(f2ptr);

  fruit.remove("banana");
  fruit.remove("apple");
  assert(fruit.empty() == 1);

  try
  {
    fruit.remove("peach");
  }
  catch(KeyError)
  {
    cout << "catch  remove KeyError" << endl;
  }

}

void WRONG_test_insert()
{
  Dictionary<string> fruit;
  string f1="apple";
  string*f1ptr = &f1;
  fruit.insert(f1ptr);

  try
  {
    fruit.insert(f1ptr);
  }
  catch(KeyError)
  {
    cout << "catch insert KeyError" << endl;
  }


}

int main()
{

  test_empty();
  test_insert();
  WRONG_test_insert();
  test_get();
  test_remove();

  cout << "pass all test" << endl;
  return 0;
}
