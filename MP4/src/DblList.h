/// @file DblList.h
/// @brief Declaration of the DblList template class.
/// @author Joshua Fisher & Anela Quiroz

#ifndef DBLLIST_H
#define DBLLIST_H

#include <iostream>
using namespace std;


// Implementing the Node from the one in class
template <typename T>
// saw online this is how to include it efficientlly
class Node {
public:
  T data;
  Node *prev;
  Node *next;
  Node(T d)
      : data(d), prev(nullptr), next(nullptr) {
  } // found online of how to do this in one line
};

// Include necessary libraries

template <typename T> class DblList {
private:
  Node<T> *front;
  Node<T> *back;
  unsigned int size;

public:
  DblList();
  ~DblList();

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T removeNode(T value);
  T find(T value);
  T peekFront();
  bool isEmpty();
  unsigned int getSize();

  // This just shows diff pointers and etc
  void printList(bool isPrintLink);
};

// this is an implementation of a doubly linked list
template <typename T> DblList<T>::DblList() {
  front = NULL;
  back = NULL;
  size = 0;
}

template <typename T> DblList<T>::~DblList() {
  // there is a loop involved
  //  Start from the front of the list
  Node<T> *curr = front;
  while (curr != nullptr) {
    // Store the next node before deleting the current one
    Node<T> *temp = curr->next;
    // Delete the current node
    delete curr;
    // Move to the next node
    curr = temp;
  }
  // Set front and back pointers to null and size to zero
  front = nullptr;
  back = nullptr;
  size = 0;
}

template <typename T> void DblList<T>::insertFront(T d) {
  // new node object
  Node<T> *node = new Node<T>(d);

  if (isEmpty()) {
    back = node;
  } else {
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <typename T> void DblList<T>::insertBack(T d) {
  Node<T> *node = new Node<T>(d);

  if (isEmpty()) {
    front = node;
  } else {
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

template <typename T> T DblList<T>::removeFront() {
  if (isEmpty()) {
    throw runtime_error("linked list is empty");
  }

    Node<T>* temp = front;

  if (front->next == NULL) {
    back = NULL;
  } else {
    // more than one node in the list
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  delete temp;
  return data;
}

template <typename T> T DblList<T>::removeBack() {
  if (isEmpty()) {
    throw runtime_error("linkedList is empty");
  }
  Node<T>* temp = back;

  if (back->prev == NULL) {
    front = NULL;
  } else {
    back->prev->next = NULL;
  }
  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <typename T> T DblList<T>::find(T value) {
  int pos = -1; // variable to idetify position of node with matching value
  Node<T>* curr = front;

  while (curr != NULL) {
    ++pos;
    if (curr->data == value)
      break;

    curr = curr->next;
  }
  if (curr == NULL)
    pos = -1;

  return pos;
}

template <typename T> T DblList<T>::removeNode(T value) {

  if (isEmpty()) {
    throw runtime_error("list is empty");
  }

  Node<T>* curr = front;
  while (curr->data != value) {
    curr = curr->next;

    if (curr == NULL)
      return -1;
  }

  // if we get here, then we found the node to be deleted
  //  so let's proceed

  if (getSize() == 1) {
    front = NULL;
    back = NULL;
  } else if (curr == front) {
    front = curr->next;
    front->prev = NULL;
  } else if (curr == back) {
    back = curr->prev;
    back->next = NULL;
  } else {
    // current is between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  T temp = curr->data;
  --size;
  delete curr;
  return temp;
}

template <typename T> unsigned int DblList<T>::getSize() { return size; }

template <typename T> bool DblList<T>::isEmpty() { return (size == 0); }

template <typename T> void DblList<T>::printList(bool printLink) {
  Node<T>* curr = front;
  while (curr != 0) {
    if (curr == front) {
      cout << "{FRONT}: ";
    } else if (curr == back) {
      cout << "{REAR}: ";
    }
    if (printLink)
      cout << "[ PREV: " << curr->prev << " || " << curr->data
           << " || NEXT: " << curr->next << " ] ";
    else
      cout << "[ " << curr->data << " ] ";

    curr = curr->next;
    if (curr != 0) {
      cout << " <==> ";
    }
  }
  cout << endl;
}

// Needed to see the front
template <typename T> T DblList<T>::peekFront() {
  if (isEmpty()) {
    throw runtime_error("list is empty");
  }

  return front->data;
}
#endif
