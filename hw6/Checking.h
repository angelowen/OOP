#ifndef CHECKING_H
#define CHECKING_H
#include "Account.h"
using namespace std;
class Checking : public Account {
 public:
  Checking(){};
  ~Checking(){};
  double getbalance() { return cur_balance; }
  void addbal(double money) { cur_balance = money; }
  double ProjectedBalance() { return cur_balance + 0.1; }

 private:
  double cur_balance;
};
#endif