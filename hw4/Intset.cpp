#include "Intset.h"
#include <bits/stdc++.h>
using namespace std;
IntSet::IntSet(int num) {
  for (int i = 0; i < 101; i++) {
    set[i] = 0;
  }
  set[num] = 1;
}
IntSet IntSet::setUnion(const IntSet& c) {
  IntSet A;
  for (int i = 0; i < 101; i++) {
    if (c.set[i] == 1 || set[i] == 1) A.set[i] = 1;
  }
  return A;
}
IntSet IntSet::setIntersection(const IntSet& c) {
  IntSet A;
  for (int i = 0; i < 101; i++) {
    if (c.set[i] == 1 && set[i] == 1) A.set[i] = 1;
  }
  return A;
}
bool IntSet::isEmpty() {
  for (int i = 0; i < 101; i++) {
    if (set[i] == 1) return false;
  }
  return true;
}
int IntSet::size() {
  int cnt = 0;
  for (int i = 0; i < 101; i++) {
    if (set[i] == 1) cnt++;
  }
  return cnt;
}
IntSet IntSet::relativeComplement(const IntSet& x) {
  IntSet R;
  for (int i = 0; i < 101; i++) {
    if (set[i] == 1 && x.set[i] == 0) R.set[i] = 1;
  }
  return R;
}
IntSet IntSet::symmetricDifference(const IntSet& x) {
  IntSet R;
  for (int i = 0; i < 101; i++) {
    if (set[i] == 1 || x.set[i] == 1) R.set[i] = 1;
    if (set[i] == 1 && x.set[i] == 1) R.set[i] = 0;
  }
  return R;
}
void IntSet::setPrint(void) const {
  int flag = 0;
  cout << "{";
  for (int i = 0; i < 101; i++) {
    if (set[i] == 1) {
      cout << " " << i;
      flag = 1;
    }
  }
  if (flag == 0)
    cout << "---}";
  else
    cout << " }";
}
bool IntSet::isEqualTo(const IntSet& x) const {
  for (int i = 0; i < 101; i++) {
    if (set[i] != x.set[i]) return false;
  }
  return true;
}