#ifndef SAVINGS_H
#define SAVINGS_H
using namespace std;
class Savings : public Account {
 public:
  Savings(){};
  ~Savings(){};
  double getbalance() { return cur_balance; }
  void addbal(double money) { cur_balance = money; }
  void addr(double r) { rate = r; }
  double ProjectedBalance() { return cur_balance * (1 + rate); }

 private:
  double cur_balance;
  double rate;
};
#endif