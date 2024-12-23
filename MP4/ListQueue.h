/// @file ListQueue.h
/// @brief Declaration of the ListQueue template class.
/// @author Joshua Fisher & Anela Quiroz

#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "DblList.h"

// Include necessary libraries

template <typename T> class ListQueue {
public:
  ListQueue();
  ~ListQueue();
  void enqueue(T value); // Add an element to the end of the queue
  T dequeue();           // Remove and return the front element of the queue
  T peek();       // Return the front element of the queue without removing it
  bool isEmpty(); // Check if the queue is empty
  unsigned int getSize(); // Get the number of elements in the queue
private:
  DblList<T> list; // Instance of the doubly linked list
};

template <typename T> ListQueue<T>::ListQueue() {
  // Constructor
}

template <typename T> ListQueue<T>::~ListQueue() {
  // Deconstructor
}

template <typename T> void ListQueue<T>::enqueue(T value) {
  list.insertBack(value);
}

template <typename T> T ListQueue<T>::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("Queue is Empty");
  }
  return list.removeFront();
}

template <typename T>
T ListQueue<T>::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return list.peekFront();
}

template <typename T> bool ListQueue<T>::isEmpty() {
  // Checks if the Queue is empty
  return list.isEmpty();
}

template <typename T> unsigned int ListQueue<T>::getSize() {
  // Gets the number of elements in the queue
  return list.getSize();
}

#endif
