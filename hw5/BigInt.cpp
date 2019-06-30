#include "BigInt.h"
#include <cstddef>
#include <bits/stdc++.h>
using namespace std;
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