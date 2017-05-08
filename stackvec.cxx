#include "stackvec.hxx"

template <typename T>
stackvec<T>::stackvec(int max) {
  data = new T[max];
  top = 0;
}

template <typename T>
stackvec<T>::~stackvec() {
  delete[] data;
}

template <typename T>
bool stackvec<T>::empty() {
  if(top == 0) {
    return true;
  }
  return false;
}

template <typename T>
void stackvec<T>::push(T value) {
  data[top] = value;
  top++;
}

template <typename T>
T stackvec<T>::pop() {
  top--;
  return data[top];
}