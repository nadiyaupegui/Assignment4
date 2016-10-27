#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <cstdlib>
#include "DList.h"
#include "DNode.h"
using namespace std;


template <class T>
class GenQueue
{
public:
    GenQueue();
    ~GenQueue();
    void enqueue(const T& d);
    void dequeue();
    const T& peek() const;
    unsigned int getSize() const;

private:
    DList<T> * list;
    unsigned int size;
};


template <class T>
GenQueue<T>::GenQueue() : size(0)
{
    list = new DList<T>();
}

template <class T>
GenQueue<T>::~GenQueue()
{
    delete list;
}

template <class T>
void GenQueue<T>::enqueue(const T& d) 
{
    cout << "Tries addback" << endl;
    list -> addBack(d);
    cout << "adds back" << endl;
}

template <class T>
void GenQueue<T>::dequeue(){list -> removeFront();}

template <class T>
const T& GenQueue<T>::peek() const{return list -> front();}

template <class T>
unsigned int GenQueue<T>::getSize() const{return size;}

#endif
