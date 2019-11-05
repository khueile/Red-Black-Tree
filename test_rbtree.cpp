/*
File: test_heap.cpp
------------------
This program tests methods and operators of the heap class.
Author: Khanh Tran
CS271-01
Sept 29, 2019
*/

#include "rbtree.h"
#include <iostream>
#include <cassert>
using namespace std;

void test_defConstr()
{
  RBT<int> rbtree1;
  assert(rbtree1.inOrder() == "[]");
}


void test_insert()
{
  RBT<int> rbtree;
  int key1 = 1;
  int* ptr1 = &key1;
  rbtree.insert(ptr1);
  assert(rbtree.inOrder() == "[1]");


  int key2 = 5;
  int* ptr2 = &key2;
  rbtree.insert(ptr2);
  assert(rbtree.inOrder() == "[1,5]");

  int key3 = 2;
  int* ptr3 = &key3;
  rbtree.insert(ptr3);
  assert(rbtree.inOrder() == "[1,2,5]");
}

void test_empty()
{
  RBT<int> rbtree1;
  assert(rbtree1.empty() == 1);
  int key = 12;
  int* ptr = &key;
  rbtree1.insert(ptr);
  assert(rbtree1.empty() == 0);
}

void test_operatorAssign()
{
  RBT<int> rbtree1;
  assert(rbtree1.empty() == 1);

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  rbtree1.insert(ptr1);
  rbtree1.insert(ptr2);
  RBT<int> rbtree2;
  rbtree2=rbtree1;
  assert(rbtree2.inOrder() == rbtree1.inOrder());

  int key = 12;
  int* ptr = &key;
  rbtree2.insert(ptr);
  cout<<rbtree2.inOrder()<<endl;
  assert(rbtree2.inOrder() == "[11,12,22]");
}

void test_inOrder()
{
  RBT<int> rbtree;

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 15;
  int* ptr3 = &key3;
  int key4 = 2;
  int* ptr4 = &key4;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  assert(rbtree.inOrder() == "[2,11,15,22]");
}

void test_preOrder()
{
  RBT<int> rbtree;

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 15;
  int* ptr3 = &key3;
  int key4 = 2;
  int* ptr4 = &key4;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  assert(rbtree.preOrder() == "[11,2,22,15]");
}

void test_postOrder()
{
  RBT<int> rbtree;

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 15;
  int* ptr3 = &key3;
  int key4 = 2;
  int* ptr4 = &key4;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  assert(rbtree.postOrder() == "[2,15,22,11]");
}

void test_get()
{
  RBT<int> rbtree;

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 15;
  int* ptr3 = &key3;
  int key4 = 2;
  int* ptr4 = &key4;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  Node<int> *node = rbtree.get(15);
  assert( *((*node).key) == key3 ); // correct value
  assert((*node).key == ptr3);//correct pointer

  try
  {
    rbtree.get(100);
  }
  catch(KeyError)
  {
    cout << "catch get KeyError" << endl;
  }


}

void test_minimum()
{
  RBT<int> rbtree;

  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 15;
  int* ptr3 = &key3;
  int key4 = 20;
  int* ptr4 = &key4;
  int key5 = 34;
  int* ptr5 = &key5;
  int key6 = 12;
  int* ptr6 = &key6;
  int key7 = 9;
  int* ptr7 = &key7;
  int key8 = 2;
  int* ptr8 = &key8;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  rbtree.insert(ptr5);
  rbtree.insert(ptr6);
  rbtree.insert(ptr7);
  rbtree.insert(ptr8);
  Node<int> *node = rbtree.minimum();
  assert( *((*node).key) == 2 );
}
void test_maximum()
{
  RBT<int> rbtree;

  int key1 = 41;
  int* ptr1 = &key1;
  int key2 = 36;
  int* ptr2 = &key2;
  int key3 = 39;
  int* ptr3 = &key3;
  int key4 = 73;
  int* ptr4 = &key4;
  int key5 = 20;
  int* ptr5 = &key5;
  int key6 = 54;
  int* ptr6 = &key6;
  int key7 = 90;
  int* ptr7 = &key7;
  int key8 = 12;
  int* ptr8 = &key8;
  rbtree.insert(ptr1);
  rbtree.insert(ptr2);
  rbtree.insert(ptr3);
  rbtree.insert(ptr4);
  rbtree.insert(ptr5);
  rbtree.insert(ptr6);
  rbtree.insert(ptr7);
  rbtree.insert(ptr8);
  Node<int> *node = rbtree.maximum();
  assert( *((*node).key) == 90 );
}


//
// void test_remove()
// {
//   RBT<int> rbtree1;
//   int key1 = 11;
//   int* ptr1 = &key1;
//   int key2 = 22;
//   int* ptr2 = &key2;
//   int key3 = 45;
//   int* ptr3 = &key3;
//   int key4 = 30;
//   int* ptr4 = &key4;
//   int key5 = 6;
//   int* ptr5 = &key5;
//   int key6 = 24;
//   int* ptr6 = &key6;
//   rbtree1.insert(ptr1);
//   rbtree1.insert(ptr2);
//   rbtree1.insert(ptr3);
//   rbtree1.insert(ptr4);
//   rbtree1.insert(ptr5);
//   rbtree1.insert(ptr6);
//
//   rbtree1.remove(6);
//   assert(rbtree1.inOrder()=="[11,22,24,30,45]");
//   rbtree1.remove(45);
//   assert(rbtree1.inOrder()=="[11,22,24,30]");
//
//   try
//   {
//     rbtree1.remove(10);
//   }
//   catch(KeyError)
//   {
//     cout << "catch remove KeyError" << endl;
//   }
//
// }

void test_successor()
{
  RBT<int> rbtree1;
  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 45;
  int* ptr3 = &key3;
  int key4 = 30;
  int* ptr4 = &key4;
  int key5 = 6;
  int* ptr5 = &key5;
  int key6 = 24;
  int* ptr6 = &key6;
  rbtree1.insert(ptr1);
  rbtree1.insert(ptr2);
  rbtree1.insert(ptr3);
  rbtree1.insert(ptr4);
  rbtree1.insert(ptr5);
  rbtree1.insert(ptr6);
  assert(rbtree1.inOrder()=="[6,11,22,24,30,45]");

  Node<int> *node = rbtree1.successor(24);
  assert( *((*node).key) == 30);
  Node<int> *node1 = rbtree1.successor(22);
  assert( *((*node1).key) == 24);

  try
  {
    rbtree1.successor(47);
  }
  catch(KeyError)
  {
    cout << "catch successor KeyError" << endl;
  }



  RBT<int> rbtree2;
  int key11 = 111;
  int* ptr11 = &key11;
  int key12 = 562;
  int* ptr12 = &key12;
  int key13 = 75;
  int* ptr13 = &key13;
  int key14 = 390;
  int* ptr14 = &key14;
  int key15 = 6;
  int* ptr15 = &key15;
  int key16 = 214;
  int* ptr16 = &key16;
  rbtree2.insert(ptr11);
  rbtree2.insert(ptr12);
  rbtree2.insert(ptr13);
  rbtree2.insert(ptr14);
  rbtree2.insert(ptr15);
  rbtree2.insert(ptr16);
  assert(rbtree2.postOrder()=="[6,75,214,390,562,111]");
  Node<int> *node3 = rbtree2.successor(111);
  assert( *((*node3).key) == 214);
  Node<int> *node4 = rbtree2.successor(390);
  assert( *((*node4).key) == 562);


}

void test_predecessor()
{
  RBT<int> rbtree1;
  int key1 = 11;
  int* ptr1 = &key1;
  int key2 = 22;
  int* ptr2 = &key2;
  int key3 = 45;
  int* ptr3 = &key3;
  int key4 = 30;
  int* ptr4 = &key4;
  int key5 = 6;
  int* ptr5 = &key5;
  int key6 = 24;
  int* ptr6 = &key6;
  rbtree1.insert(ptr1);
  rbtree1.insert(ptr2);
  rbtree1.insert(ptr3);
  rbtree1.insert(ptr4);
  rbtree1.insert(ptr5);
  rbtree1.insert(ptr6);
  assert(rbtree1.inOrder()=="[6,11,22,24,30,45]");

  try
  {
    rbtree1.predecessor(1);
  }
  catch(KeyError)
  {
    cout << "catch predecessor KeyError" << endl;
  }


  Node<int> *node = rbtree1.predecessor(24);
  assert( *((*node).key) == 22);
  Node<int> *node1 = rbtree1.predecessor(22);
  assert( *((*node1).key) == 11);

  RBT<int> rbtree2;
  int key11 = 111;
  int* ptr11 = &key11;
  int key12 = 562;
  int* ptr12 = &key12;
  int key13 = 75;
  int* ptr13 = &key13;
  int key14 = 390;
  int* ptr14 = &key14;
  int key15 = 6;
  int* ptr15 = &key15;
  int key16 = 214;
  int* ptr16 = &key16;
  rbtree2.insert(ptr11);
  rbtree2.insert(ptr12);
  rbtree2.insert(ptr13);
  rbtree2.insert(ptr14);
  rbtree2.insert(ptr15);
  rbtree2.insert(ptr16);
  assert(rbtree2.postOrder()=="[6,75,214,390,562,111]");
  Node<int> *node3 = rbtree2.predecessor(111);
  assert( *((*node3).key) == 75);
  Node<int> *node4 = rbtree2.predecessor(390);
  assert( *((*node4).key) == 214);
}


int main()
{
  test_defConstr();
  test_insert();
  test_empty();
  test_operatorAssign();
  // test_get();
  // test_successor();
  // test_predecessor();
  // test_minimum();
  // test_maximum();
  // //test_remove();
  // test_inOrder();
  // test_preOrder();
  // test_postOrder();

  cout << "pass all test" << endl;
  return 0;
}
