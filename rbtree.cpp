/*
File: rbt.cpp
Author: Khue Le, Khanh Tran
Nov 1,2019
CS271, Dr. Lall

File:rbt.cpp
--------------------------
This cpp file  inludes all the functions for the Binary Search Tree.
*/

#include <string>
#include <cmath>
#include <iostream>
using namespace std;

/*
 * Function: RBT
 * --------------------------
 * Returns none
 * Default constructor of RBT
 *
 */
template <class KeyType>
RBT<KeyType>::RBT()
// Precondition: None
// Postcondition: a rbt with root is NULL
{
  root = NULL;
}

/*
 * Function:~RBT
 * --------------------------
 * Returns none
 * Destructor of RBT
 *
 */
template <typename KeyType>
RBT<KeyType>::~RBT()
/*
Precondition: the rbt is not empty

Postcondition: no rbt exists

*/
{
  destroy(root);
}

template <class KeyType>
RBT<KeyType>::RBT(const RBT<KeyType>& rbt)
/*
Precondition: rbt is no empty

Postcondition: two rbt have the same value

*/
{
  copy(rbt.root);
}


template <class KeyType>
RBT<KeyType>& RBT<KeyType>::operator=(const RBT<KeyType>& rbt) // assignment operator
/*
Precondition: one rbt that is not empty and one is empty

Postcondition: two rbt have the same value but do not have the same address

*/
{
  if (root ==rbt.root)
  {
    return *this;
  }
  destroy(root);

  root=copy(rbt.root);

  return *this;
}

template <class KeyType>
bool RBT<KeyType>::empty() const // return true if empty; false o/w
/*
Precondition: rbt exists

Postcondition: return 1 if rbt is empty, 0 if not

*/
{
  return root == NULL;

}


template <typename KeyType>
Node<KeyType> *RBT<KeyType>::get(const KeyType& k) const
/*
Precondition: rbt is not empty

Postcondition: return a pointer which points to the node which key is k

*/
{
  Node<KeyType> *x=root;

  while (x!=NULL && *(x->key)!=k  )
  {
    if (k<*(x->key))
    {
      x=x->left;
    }
    else
    {
      x=x->right;
    }
  }


  return x;

}

//
// template <typename KeyType>
// void RBT<KeyType>::remove(const KeyType& k)
// /*
// Precondition: rbt is not empty, k exists in rbt
//
// Postcondition: without the node contain k
//
// */
// {
//   if (get(k) == NULL)
//   {
//     throw KeyError{};
//   }
//
//   Node<KeyType> * del=get(k);
//   if (del->left==NULL)
//   {
//     transplant(del,del->right);
//   }
//   else if(del->right==NULL)
//   {
//     transplant(del,del->left);
//   }
//   else
//   {
//     Node<KeyType>* x=del->right;
//     while (x->right!=NULL)
//     {
//       x=x->right;
//     }
//     if (x->parent!=del)
//     {
//       transplant(x,x->right);
//       x->right=del->right;
//       x->right->parent=x;
//     }
//     else
//     {
//       transplant(del,x);
//       x->left=del->left;
//       x->left->parent=x;
//     }
//   }
// }
//
// template <typename KeyType>
// void RBT<KeyType>::transplant(Node<KeyType> *u, Node<KeyType> *v)
// /*
// Precondition:the two nodes  exist
//
// Postcondition: return a rbt with node v and the subtree of node u
//
// */
// {
//  if (u->parent==NULL)
//  {
//    root=v;
//  }
//  else if (u==(u->parent)->left) {
//    u->parent->left=v;
//  }
//  else
//  {
//    u->parent->right=v;
//  }
//  if (v!=NULL)
//  {
//    v->parent=u->parent;
//  }
// }

template <typename KeyType>
Node<KeyType> *RBT<KeyType>::minimum() const
/*
Precondition: rbt is not empty

Postcondition: return a pointer which points to the node which key is minimum value

*/
{
  Node<KeyType>* x=root;
  while (x->left!=NULL)
  {
    x=x->left;
  }
  return x;

}

template <typename KeyType>
Node<KeyType> *RBT<KeyType>::maximum()const
/*
Precondition: rbt is not empty

Postcondition: return a pointer which points to the node which key is maximum value

*/
{
  Node<KeyType>* x=root;
  while (x->right!=NULL)
  {
    x=x->right;
  }
  return x;
}

template <typename KeyType>
Node<KeyType> *RBT<KeyType>::successor(const KeyType& k) const
/*
Precondition: rbt is not empty, k is in RBT.

Postcondition: return a pointer which points to the node which key is the next one larger than k

*/
{
  if (get(k) == NULL)
  {
    throw KeyError{};
  }

  Node<KeyType> * x=get(k);
  if (x->right!= NULL)
  {
    x=x->right;
    while (x->left!=NULL)
    {
      x=x->left;
    }
    return x;
  }
  else
  {
    Node<KeyType> * y=x->parent;
    while (y!=NULL && x==y->right)
    {
      x=y;
      y=y->parent;
    }
    return y;
  }
}


template <typename KeyType>
Node<KeyType> *RBT<KeyType>::predecessor(const KeyType& k) const
/*
Precondition: rbt is not empty, k is in RBT.

Postcondition: return a pointer which points to the node which key is the next one smaller than k

*/
{
  if (get(k) == NULL)
  {
    throw KeyError{};
  }
  Node<KeyType> * x=get(k);
  if (x->left!= NULL)
  {
    x=x->left;
    while (x->right!=NULL)
    {
      x=x->right;
    }
    return x;
  }
  else
  {
    Node<KeyType> *y =x->parent;
    while (y != NULL && x== y->left)
    {
      x=y;
      y=y->parent;
    }
    return y;
  }
}

template <class KeyType>
void RBT<KeyType>::leftRotate(Node<KeyType> * x)
{
  Node<KeyType> * y = x->right;
  x->right = y->left;
  if(y->left != NULL)
  {
    y->left->parent = x;
  }
  y ->parent = x->parent;
  if (x->parent == NULL)
  {
    root = y;
  }
  else if (x == x->parent-> left)
  {
    x ->parent -> left = y;
  }
  else
  {
    x-> parent ->right = y;
  }
  y->left = x;
  x->parent = y;

}

template <class KeyType>
void RBT<KeyType>::rightRotate(Node<KeyType> * x)
{
  Node<KeyType> * y = x->left;
  x->left = y->right;
  if(y->right != NULL)
  {
    y->right->parent = x;
  }
  y ->parent = x->parent;
  if (x->parent == NULL)
  {
    root = y;
  }
  else if (x == x->parent-> right)
  {
    x ->parent -> right = y;
  }
  else
  {
    x-> parent ->left = y;
  }
  y->right = x;
  x->parent = y;

}

template <class KeyType>
void RBT<KeyType>::insert(KeyType *k) // insert k into the tree
/*
Precondition: rbt exist

Postcondition: a tree has a node with k value

*/
{
  Node<KeyType>*z=new Node<KeyType>(k);
  Node<KeyType>*x = root;
  Node<KeyType>*y = new Node<KeyType>(k);
  y = NULL;
  while (x != NULL )
  {
    y = x;
    if (*(z->key) < *(x->key))
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }

  z->parent = y;
  if (y==NULL)
  {
    root=z;
  }
  else if (*(z->key)<*(y->key))
  {
    y->left = z;
  }
  else
  {
    y->right = z;
  }
  z->color = 0;
  insertFixUp(z);
}

template <class KeyType>
void RBT<KeyType>::insertFixUp(Node<KeyType> *z) // insert k into the tree
{
  Node<KeyType>*y = new Node<KeyType>(*z);
  y = NULL;
  while (z->parent != NULL && z->parent->color == 0)
  {
    if ( z -> parent == z->parent ->parent -> left)//if parent is grandparent's left child
    {
      y = z ->parent -> parent -> right;
      if (y != NULL && y->color == 0)
      {
        z ->parent ->color = 1;
        y->color = 1;
        z ->parent ->parent->color = 0;
        z = z ->parent ->parent;
      }
      else
      {
        if (z == z->parent->right)
        {
          z=z->parent;
          leftRotate(z);
        }
        z->parent->color = 1;
        z->parent->parent->color = 0;
        rightRotate(z->parent->parent);
      }

    }
    else
    {
      y = z ->parent -> parent -> left;
      if (y != NULL && y->color == 0)
      {
        z ->parent ->color = 1;
        y->color = 1;
        z ->parent ->parent->color = 0;
        z = z ->parent ->parent;
      }
      else
      {
        if (z == z->parent->left)
        {
          z=z->parent;
          rightRotate(z);
        }
        z->parent->color = 1;
        z->parent->parent->color = 0;
        leftRotate(z->parent->parent);
      }
    }
  }
  root->color= 1;
}

template <class KeyType>
string RBT<KeyType>::inOrder() const // return string of items from an inorder traversal
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in inorder walk

*/
{
  string separator = "";
  string str = '[' + inOrderWalk(root,separator) + ']';

  return str;
}

template <class KeyType>
std::string RBT<KeyType>::inOrderWalk(Node<KeyType>*treeRoot, string separator) const
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in inorder walk

*/
{
  string str;
  stringstream ss;
  if (treeRoot != NULL)
  {
    str=str+(inOrderWalk(treeRoot->left,separator));
    if (str=="")
    {ss<<separator<<*(treeRoot->key);}
    else{ss<<","<<*(treeRoot->key);}
    separator = ",";
    str=str+ss.str();
    str=str+inOrderWalk(treeRoot->right,separator);
  }
  return str;

}



template <typename KeyType>
std::string RBT<KeyType>::preOrder() const
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in preorder walk

*/
{
  string separator = "";
  string str = '[' + preOrderWalk(root,separator) + ']';

  return str;
}

template <typename KeyType>
std::string RBT<KeyType>::preOrderWalk(Node<KeyType>*treeRoot, string separator) const
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in preorder walk

*/
{
  string str;
  stringstream ss;
  if (treeRoot != NULL)
  {
    ss<<separator<<*(treeRoot->key);
    separator = ",";
    str=str+ss.str();
    str=str+(preOrderWalk(treeRoot->left,separator));
    str=str+preOrderWalk(treeRoot->right,separator);
  }
  return str;

}

template <typename KeyType>
std::string RBT<KeyType>::postOrder() const
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in postorder walk

*/
{
  string separator = "";
  string str = '[' + postOrderWalk(root,separator) + ']';

  return str;
}

template <typename KeyType>
std::string RBT<KeyType>::postOrderWalk(Node<KeyType>*treeRoot, string separator) const
/*
Precondition: rbt exist

Postcondition: a string print the element of rbt in postorder walk

*/
{
  string str;
  stringstream ss;
  if (treeRoot != NULL)
  {

    str=str+(postOrderWalk(treeRoot->left,separator));
    if (str!="")
    {separator = ",";}
    str=str+postOrderWalk(treeRoot->right,separator);
    if (str!="")
    {separator = ",";}
    ss<<separator<<*(treeRoot->key);
    str=str+ss.str();
  }
  return str;

}


template <class KeyType>
Node<KeyType>* RBT<KeyType>::copy(const Node<KeyType> *treeNode)
/*
Precondition: one rbt that is not empty and one is empty

Postcondition: two rbt have the same value but do not have the same address

*/
{

  if (treeNode==NULL)
  {
    Node<KeyType>* copyNode= NULL;
    return copyNode;
  }
  else
  {
    Node<KeyType>* copyNode= new Node<KeyType>(treeNode->key);
    copyNode->key=treeNode->key;
    copyNode->parent=treeNode->parent;
    copyNode->left=copy(treeNode->left);
    copyNode->right=copy(treeNode->right);
    return copyNode;
  }
}



template <typename KeyType>
void RBT<KeyType>::destroy(Node<KeyType> *treeRoot)
/*
Precondition: the rbt is not empty

Postcondition: no rbt exists

*/
{
  Node<KeyType> *curr = treeRoot;
  if (curr != NULL)
  {
    destroy(treeRoot->left);
    destroy(treeRoot->right);
    delete curr;
  }
}
