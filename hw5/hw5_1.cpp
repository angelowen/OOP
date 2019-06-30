#include <bits/stdc++.h>
using namespace std;
class MyVector {
 public:
  MyVector() {
    length = 0;
    qtr = NULL;  // new double[1024];
  }
  MyVector(int, double *);
  MyVector(const MyVector &);  // copy constructor
  ~MyVector() {
    if (qtr != NULL) delete[] qtr;
  };
  const MyVector &operator=(const MyVector &);
  MyVector operator+(const MyVector &);
  int operator*(const MyVector &);
  MyVector operator*(int);
  friend ostream &operator<<(ostream &, const MyVector &);

 private:
  int length;
  double *qtr;
};

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
int MyVector::operator*(const MyVector &oth) {
  int result = 0;
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
ostream &operator<<(ostream &os, const MyVector &dt) {
  cout << "<";
  if (dt.length > 0) os << dt.qtr[0];
  for (int i = 1; i < dt.length; i++) {
    os << "," << dt.qtr[i];
  }  // deal w/ output
  cout << ">";
  return os;
}

// MyVector　operator*(int n, MyVector& v)
// {
//   MyVector result;
//   result.qtr = new double[1024];
//   result.length = this->length;
//   for (int i = 0; i < this->length; i++) {
//     result.qtr[i] = this->qtr[i] * n;
//   }
//   return result;
// }

int main() {
  double V_1[] = {1, 2, 3, 4, 6};
  MyVector V1(sizeof(V_1) / sizeof(V_1[0]), V_1);
  cout << V1 << endl;  //印出<1, 2, 3, 4, 6>

  double V_2[] = {7, 6, 5, 3, 2};
  MyVector V2(sizeof(V_2) / sizeof(V_2[0]), V_2);
  cout << V2 << endl;  //印出<7, 6, 5, 3, 2>

  cout << V1 << "*" << V2 << "=" << V1 * V2
       << endl;  //印出<1, 2, 3, 4, 6>*<7, 6, 5, 3, 2>=58

  cout << V1 << "*"
       << "3"
       << "=" << V1 * 3 << endl;  //印出<1, 2, 3, 4, 6>*3=<3, 6, 9, 12, 18>

  cout << V1 << "+" << V2 << "=" << V1 + V2
       << endl;  //印出<1, 2, 3, 4, 6>+<7, 6, 5, 3, 2>=<8, 8, 8, 7, 8>

  MyVector V3;
  cout << V3 << endl;  //印出<>
  V3 = V1;
  cout << V3 << endl;  //印出<1, 2, 3, 4, 6>

  MyVector V4 = V3;
  cout << V4 << endl;  //印出<1, 2, 3, 4, 6>
  return 0;
}
