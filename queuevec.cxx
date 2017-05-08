#include "queuevec.hxx"

template <typename T>
queuevec<T>::queuevec(int max) {
  data = new T[max];
  this-> max = max;
  begin =max-1;
  end =0;
}
 
template <typename T>
queuevec<T>::~queuevec() {
  delete[] data;
}

template <typename T>
bool queuevec<T>::empty() {
  if(begin & end == 0) {
    return true;
  }
  return false;
}



template <typename T>
void queuevec<T>::enqueue(T value) {
  data[end] = value;
  end = (end+1)%max;
  
}

template <typename T>
T queuevec<T>::dequeue() {

}