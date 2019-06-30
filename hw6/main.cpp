#include <bits/stdc++.h>
#include "Account.h"
#include "Checking.h"
#include "Investment.h"
#include "Portfolio.h"
#include "Savings.h"

using namespace std;
// Savings s[len];
// Checking ch[len];
// Investment in[len];
vector<char> vec;
int save = 0, check = 0, invest = 0;
const int len = 1024;
int main() {
  char c, tmp[10];
  double a, b, a1, b1;
  char file[len], *ptr;
  char str[len], store[len], *first, *last;
  FILE *fd = stdin;
  int i, j, ncase;
  Portfolio print;
  print.menu();
  while (1) {
    cout << ">";
    scanf("%s", tmp);
    c = tmp[0];
    if (c == 'i' || c == 'I') {
      cout << "Enter filename:";
      cin >> file;
      print.importFile(file);

    } else if (c == 's' || c == 'S') {
      print.showAccounts(vec);
    } else if (c == 'e' || c == 'E') {  // output to summary.txt
      cout << "Enter filename:";
      cin >> file;
      print.createReportFile(file);
      /// fprintf
    } else if (c == 'm' || c == 'M') {
      print.menu();
    } else if (c == 'q' || c == 'Q') {
      cout << "Goodbye!" << endl;
      break;
    }
  }
  return 0;
}