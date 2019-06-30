#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <cstddef>
#include <ostream>
using namespace std;
class MyVector {
 public:
  MyVector() {
    length = 0;
    qtr = NULL;  // new double[1024];
  }
  MyVector(int, double *);
  MyVector(const MyVector &);  // copy constructor
  ~MyVector(){
      // if (qtr != NULL) delete[] qtr;
  };
  const MyVector &operator=(const MyVector &);
  MyVector operator+(const MyVector &);
  double operator*(const MyVector &);
  MyVector operator*(int);
  friend std::ostream &operator<<(ostream &, const MyVector &);

 private:
  int length;
  double *qtr;
};
#endif