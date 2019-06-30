#include "MyVector.h"
#include <bits/stdc++.h>
using namespace std;
using std::ostream;
MyVector::MyVector(int len, double *dtr) {
  length = len;
  qtr = dtr;
}
MyVector::MyVector(const MyVector &myvec) {  // copy constructor
  qtr = new double[1024];
  length = myvec.length;
  for (int i = 0; i < length; i++) {
    qtr[i] = myvec.qtr[i];
  }
}
const MyVector &MyVector::operator=(const MyVector &oth) {  // Assignment
  if (&oth == this) return *this;
  if (length != oth.length) {
    delete[] qtr;
    length = oth.length;
    qtr = new double[1024];
  }
  for (int i = 0; i < length; i++) {
    qtr[i] = oth.qtr[i];
  }
  return *this;
}
MyVector MyVector::operator+(const MyVector &oth) {
  MyVector result;
  result.qtr = new double[1024];
  int len = max(oth.length, this->length);
  result.length = len;
  for (int i = 0; i < len; i++) {
    result.qtr[i] = this->qtr[i] + oth.qtr[i];
    // printf("%f", result.qtr[i]);
  }
  return result;
}
double MyVector::operator*(const MyVector &oth) {
  double result = 0;
  int len = max(oth.length, this->length);
  for (int i = 0; i < len; i++) {
    result += this->qtr[i] * oth.qtr[i];
  }
  return result;
}
MyVector MyVector::operator*(int n) {
  MyVector result;
  result.qtr = new double[1024];
  result.length = this->length;
  for (int i = 0; i < this->length; i++) {
    result.qtr[i] = this->qtr[i] * n;
  }
  return result;
}
std::ostream &operator<<(std::ostream &os, const MyVector &dt) {
  cout << "<";
  if (dt.length > 0) os << dt.qtr[0];
  for (int i = 1; i < dt.length; i++) {
    os << "," << dt.qtr[i];
  }  // deal w/ output
  cout << ">";
  return os;
}