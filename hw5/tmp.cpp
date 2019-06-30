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
class BigInt {
 public:
  BigInt() {  // constructor
    num = NULL;
    size = 0;
  }
  // convert an array of integral digits by tmp to BigInt
  // tmp: pointer to the array
  // length: the number of digits in the array
  BigInt(const int *tmp, int length);
  BigInt(const BigInt &);  // copy constructor
  // Assignment
  const BigInt &operator=(const BigInt &);
  // destructor
  ~BigInt() {
    if (num != NULL) delete[] num;
  };
  char &operator[](int index);
  int length() const { return size; };
  char *getNum() {
    char *t = new char[1024];
    for (int i = 0; i < size; i++) {
      t[i] = num[size - i - 1];
    }
    t[size] = 0;
    return t;
  };
  BigInt &operator++();
  BigInt operator++(int);

 private:
  char *num;  // the big integer in char
  int size;   // number of digits in the big integer
};
BigInt::BigInt(const int tmp[], int len) {
  num = new char[1024];
  memset(num, 0, 1024);
  num[len] = 0;
  for (int i = 0; i < len; i++) {
    num[i] = '0' + tmp[len - i - 1];
  }
  size = len;
}
BigInt::BigInt(const BigInt &mybig) {  // copy constructor
  num = new char[1024];
  memset(num, 0, 1024);
  strcpy(num, mybig.num);
  size = mybig.size;
}

const BigInt &BigInt::operator=(const BigInt &oth) {  // Assignment
  if (&oth == this) return *this;
  if (size != oth.size) {
    delete[] num;
    size = oth.size;
    num = new char[1024];
    memset(num, 0, 1024);
  }
  for (int i = 0; i < size; i++) {
    num[i] = oth.num[i];
  }
  return *this;
}
char &BigInt::operator[](int index) {
  assert(index >= 0 && index < size);
  return num[size - index - 1];
}
BigInt &BigInt::operator++() {  // Define prefix increment operator
  num[0]++;
  num[size] = '0';
  int j;
  for (j = 0; j < size; j++) {
    if (num[j] > '9') {
      num[j] = '0';
      num[j + 1] += 1;
    }
  }
  if (num[j - 1] == '0') size += 1;
  return *this;
}
BigInt BigInt::operator++(int) {  // Define postfix increment operator
  BigInt tmp = *this;
  ++*this;  // use prefix function
  // cout << "hhhhh" << endl;
  return tmp;
}
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
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7,
             8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4,
             5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  BigInt A(a, sizeof(a) / sizeof(a[0]));
  cout << A.length() << endl;  //印出50
  cout << A.getNum()
       << endl;  //印出12345678901234567890123456789012345678901234567890
  cout << A[0] << endl;  //印出1

  BigInt B;
  B = A;                       // assignment operator
  cout << B.length() << endl;  //印出50
  cout << B.getNum()
       << endl;  //印出12345678901234567890123456789012345678901234567890

  BigInt C = B;                // copy constructor
  cout << B.length() << endl;  //印出50
  cout << B.getNum()
       << endl;  //印出12345678901234567890123456789012345678901234567890

  C++;
  cout << C.length() << endl;  //印出50
  cout << C.getNum()
       << endl;  //印出12345678901234567890123456789012345678901234567891

  ++C;
  cout << C.length() << endl;  //印出50
  cout << C.getNum()
       << endl;  //印出12345678901234567890123456789012345678901234567892
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
