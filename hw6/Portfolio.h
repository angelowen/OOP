#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <bits/stdc++.h>
using namespace std;

extern const int len;
extern int save, check, invest;
extern vector<char> vec;

class Portfolio {
 public:
  Portfolio(){};
  ~Portfolio(){};
  bool importFile(const char *filename);
  bool createReportFile(const char *filename);
  void showAccounts(vector<char>) const;
  void menu();
};
#endif