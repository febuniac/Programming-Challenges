#ifndef __STACKVEC_HXX__
#define __STACKVEC_HXX__

template <typename T>
class stackvec {
private:
  T *data;
  T top;

public:
  stackvec(int max);
  ~stackvec();

  bool empty();
  void push(T value);
  T pop();
};

#endif