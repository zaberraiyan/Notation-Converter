#include "Deque.hpp"

DLinkedList::DLinkedList(){
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList(){
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const{
    return (header->next == trailer);
}

const char& DLinkedList::front() const{
    return header->next->str;
}

const char& DLinkedList::back() const{
    return trailer->prev->str;
}

void DLinkedList::add(DNode* v, const char& e){
    DNode* u = new DNode;
    u->str = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const char& e){
    add(header->next, e);
}

void DLinkedList::addBack(const char& e){
    add(trailer, e);
}

void DLinkedList::remove(DNode* v){
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront(){
    remove(header->next);
}

void DLinkedList::removeBack(){
    remove(trailer->prev);
}

bool LinkedDeque::empty() const{
    return D.empty();
}

const char& LinkedDeque::front(){
    return D.front();
}

const char& LinkedDeque::back(){
    return D.back();
}

int LinkedDeque::size()const{
    return n;
}

void LinkedDeque::insertFront(const char& e){
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const char& e){
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront(){
    D.removeFront();
    n--;
}

void LinkedDeque::removeBack(){
    D.removeBack();
    n--;
}