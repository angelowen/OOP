#ifndef BIGINT_H
#define BIGINT_H
#include <cstddef>
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
#endif