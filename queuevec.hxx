#ifndef __QUEUEVEC_HXX__
#define __QUEUEVEC_HXX__

template <typename T>
class queuevec {
private:
  T *data;
  int max, begin, end;

public:
  queuevec(int max);
  ~queuevec();

  bool empty();
  void enqueue(T value);
  T dequeue();
};

#endif