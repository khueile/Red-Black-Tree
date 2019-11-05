/*
File: RBT.h
Author: Khue, Sarah
*/


#ifndef RBT_H
#define RBT_H

#include <string>
#include <sstream>
#include <algorithm>

template <class KeyType>
class Node
{
public:
  Node<KeyType>* parent;
  Node<KeyType>* left;
  Node<KeyType>* right;
  KeyType *key;
  bool color; //1: black; 0: red


  Node (KeyType *key)
  {
    this->key=key;
    parent=NULL;
    left=NULL;
    right=NULL;
    color = 0;
  }
};


template <class KeyType>
class RBT
{
  public:


    RBT(); // default constructor
    RBT(const RBT<KeyType>& rbt); //copy constructor
    ~RBT(); // destructor
    RBT<KeyType>& operator=(const RBT<KeyType>& rbt); // assignment operator

    bool empty() const; // return true if empty; false o/w
    Node<KeyType> *get(const KeyType& k) const; // return first item with key equal to k
    void insert(KeyType *k); // insert k into the tree
    //void remove(const KeyType& k); // delete first item with key equal to k
    Node<KeyType> *maximum() const; // return the maximum item
    Node<KeyType> *minimum()const ; // return the minimum item
    Node<KeyType> *successor(const KeyType& k) const; // return the successor of k
    Node<KeyType> *predecessor(const KeyType& k) const; // return the predecessor of k
    std::string inOrder() const; // return string of items from an inorder traversal
    std::string preOrder() const; // return string of items from a preorder traversal
    std::string postOrder() const; // return string of items from a postorder traversal

  protected:
  /* Instance variables*/
    Node<KeyType>* root;
    //void transplant(Node<KeyType> *u, Node<KeyType> *v);
    Node<KeyType>*  copy(const  Node<KeyType> * treeNode) ; // copy RBT to this RBT
    void destroy(Node<KeyType>*treeRoot); // deallocate RBT
    void leftRotate(Node<KeyType> * x);
    void rightRotate(Node<KeyType> * x);
    void insertFixUp(Node<KeyType> * z);
    std::string inOrderWalk(Node<KeyType>*treeRoot, std::string separator) const; // return string of items from an inorder traversal
    std::string preOrderWalk(Node<KeyType>*treeRoot, std::string separator) const; // return string of items from an preorder traversal
    std::string postOrderWalk(Node<KeyType>*treeRoot, std::string separator) const; // return string of items from an postorder traversal
};
class KeyError { };     // Dictionary key exception

#include "rbtree.cpp"
#endif
