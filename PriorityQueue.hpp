#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

template<typename T> 

class Queue {

private:
  struct Item {
    T value;
    Item *next;
  };

  Item *first;
  Item *last;
  int _size;

  void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size)
  {
    if (item == NULL) {
      first = NULL;
      last = NULL;
      _size = 0;
      return;
    }
    first = new Item();
    first->value = item->value;
    last = first;
    _size = 1;
    while (item->next != NULL) {
      last->next = new Item();
      last = last->next;
      item = item->next;
      last->value = item->value;
      _size++;
    }
    last->next = NULL;
  }


  void deleteItems(Item *item) {
    while (item != NULL) {
      Item *aux = item;
      item = item->next;
      delete aux;
    }
  }
  
public:

  Queue() {
    first = last = NULL;
    _size = 0;
  }

  Queue(Queue &q)
  {
    copyItems(q.first, first, last, _size);
  }

  ~Queue() {
    deleteItems(first);
    _size = 0;
  }

  Queue &operator=(const Queue &q) {
    if (this != &q) {
      deleteItems(first);
      copyItems(q.first, first, last, _size);
    }
    return *this;
  }

  T front() {
    if (first == NULL) {
      cerr << "Error: front on empty queue" << endl;
      exit(0);
    }
    return first->value;
  }

  void pop() {
    if (first == NULL) {
      cerr << "Error: pop on empty queue" << endl;
      exit(0);
    }
    Item *aux = first;
    first = first-> next;
    delete aux;
    _size--;
    if (first == NULL) last = NULL;
  }
  
  void push(T value){
    _size++;
    if(last==NULL){
      Item *aux=new Item();
      aux->value=value;
      aux->next=NULL;
      first=last=aux;
      return;
    }

    Item *pitem=first;
    bool acabar=false;
    
    while(not acabar and pitem->next!=NULL){
      if(value<pitem->value){
        acabar=true;
        Item *aux=new Item();
        aux->next=pitem->next;
        aux->value=pitem->value;
        pitem->value=value;
        pitem->next=aux; 
        if(pitem==last){
          last=aux;
        }
      }else{
        pitem=pitem->next;
      }
    }

    if(pitem->next==NULL){
      Item *aux=new Item();
      aux->next=NULL;
      pitem->next=aux;
      last=aux;
      if(value<pitem->value){
        aux->value=pitem->value;
        pitem->value=value;
      }else{
        aux->value=value;
      }
    }
  }

  int size() {
    return _size;
  }

  template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);

  template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);
 
};


template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q)
{
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template<typename U>
istream &operator>>(istream &is, Queue<U> &q)
{
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
