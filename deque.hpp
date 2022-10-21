//DATA STRUCTURES SEC 2 PROJECT 2
//Zaber Raiyan Choudhury

//linked list and deque code taken from slides

#ifndef DEQUE_H
#define DEQUE_H

#include <string>
using namespace std;

class DNode { // doubly linked list node
private:
   char str;
   int i; //to count
   DNode* prev; //backpointer
   DNode* next; //frontpointer
   friend class DLinkedList; //giving access to list
};


class DLinkedList { // doubly linked list
public:
   DLinkedList(); // constructor
   ~DLinkedList(); // destructor

   bool empty() const; // is list empty?
   const char& front() const;
   const char& back() const;
   
   void addFront(const char& e); // add to front of list
   void addBack(const char& e); // add to back of list
   void removeFront(); // remove from front
   void removeBack(); // remove from back

private: // local type definitions
   DNode* header; // list sentinels
   DNode* trailer;

protected: // local utilities
   void add(DNode* v, const char& e); //insert new node before v
   void remove(DNode* v); // remove node v
};


class LinkedDeque { // deque as doubly linked list
public:
   LinkedDeque(); // constructor
   int size() const; // number of items in the deque
   bool empty() const; // is the deque empty?
   const char& front(); // first char
   const char& back(); // last char

   void insertFront(const char& e); // insert new first char
   void insertBack(const char& e); // insert new last element
   void removeFront(); // remove first element
   void removeBack(); // remove last element

private:
  DLinkedList D; // doubly linked list of elements
  int n=0; // number of elements
  friend class NotationConverter;
};

#endif