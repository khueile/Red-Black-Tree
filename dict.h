/*
File: dict.h
Author: Khue Le, Khanh Tran
*/

#ifndef DICT
#define DICT

#include "hashtable.h"
#include <string>
#include <math.h>

const int NUMSLOT = 100;
template <class KeyType>
class Dict : public HashTable<KeyType>
{
public:
  Dict(int numberOfSlots=NUMSLOT);             // default constructor
  Dict(const Dict<KeyType>& d);  // copy constructor
  bool empty() const; // return true if empty; false o/w
  KeyType *get(const KeyType& k) const; // return first item with key equal to k
  void insert(KeyType *k); // insert k into the tree
  void remove(const KeyType& k); // delete first item with key equal to k
  std::string toString() const;
  using HashTable<KeyType>::slots;
};
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const Dict<KeyType>& d)
{
  stream << d.toString();
  return stream;
}

#include "dict.cpp"
#endif
