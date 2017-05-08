#ifndef __QUEUE_HXX__
#define __QUEUE_HXX__

template <typename T>
class queue {
private:
  T *data;
  int max, begin, end;

public:
  queue(int max);
  ~queue();

  bool empty();
  void enqueue(T value);
  T dequeue();
};

#endif