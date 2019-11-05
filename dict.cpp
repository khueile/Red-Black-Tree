#include <string>
#include <iostream>
using namespace std;

template <class KeyType>
Dictionary<KeyType>::Dictionary() : BST<KeyType>()
{

}

template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType> & dic) : BST<KeyType>(dic)
{

}


template <class KeyType>
void Dictionary<KeyType>::insert(KeyType *k) 
{
  if (get(*k)!= NULL)
  {
    throw KeyError();
  }
  else
  {
    Node<KeyType>*z=new Node<KeyType>(k);
    Node<KeyType>*x = root;
    Node<KeyType>*y = new Node<KeyType>();
    y=NULL;
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
  }
}
