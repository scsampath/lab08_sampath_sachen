//Created by Sachen Sampath, CS32, 6/1/2020
#include "SimpleList.h"

#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
SimpleList<T>::SimpleList() {
    //set numElements to 0
    numElements = 0;
    //allocate array elements with size of CAPACITY
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList() {
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
    if(index < 0 || index >= numElements){
        throw InvalidIndexException();
    }
    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    if(numElements == 0){
        return true;
    }
    return false;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException) {
    if(empty()){
        throw EmptyListException();
    }
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException) {
    if(empty()){
        throw EmptyListException();
    }
    return elements[numElements - 1];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException) {
    if(numElements == CAPACITY){
        throw FullListException();
    }
    elements[numElements] = item;
    numElements++;
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException) {
    //checking if list is empty or there is no element at the index position
    if(empty()){
        throw EmptyListException();
    }
    else if(index >= numElements){
        throw InvalidIndexException();
    }
    //removing the element at the index
    numElements--;
    //shifting all elements inserted after the index
    for(int i = index; i < numElements; i++){
        elements[i] = elements[i + 1];
    }
}