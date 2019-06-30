#ifndef INVESTMENT_H
#define INVESTMENT_H
using namespace std;
class Investment : public Account {
 public:
  Investment(){};
  ~Investment(){};
  double ProjectedBalance() {
    ETF = ((A / IVS) * CVS + I * A);
    return 0;
  }
  // private:
  double A;
  double IVS;
  double CVS;
  double I;
  double ETF;
};
#endif