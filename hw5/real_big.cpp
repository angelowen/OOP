#include <bits/stdc++.h>
using namespace std;
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
BigInt &BigInt::operator++() {  // Define postfix increment operator
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
BigInt BigInt::operator++(int) {  // Define prefix increment operator
  BigInt tmp = *this;
  ++*this;  // use prefix function
  return tmp;
}
int main(int argc, char **argv) {
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
  return 0;
}