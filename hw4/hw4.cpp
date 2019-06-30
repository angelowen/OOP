#include <bits/stdc++.h>
using namespace std;
class IntSet {
 public:
  IntSet() {
    for (int i = 0; i < 101; i++) {
      set[i] = 0;
    }
  }             // default constructor
  IntSet(int);  // alternate (overloaded) constructor
  IntSet setUnion(const IntSet&);
  IntSet setIntersection(const IntSet&);
  bool isEmpty(void);
  int size(void);
  IntSet relativeComplement(const IntSet&);
  IntSet symmetricDifference(const IntSet&);
  void setPrint(void) const;
  bool isEqualTo(const IntSet&) const;
  // Auxiliary functions
 private:
  int set[101];  // range of 0 –100
  // Private member functions, if necessary
};
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
int main() {
  IntSet Empty;  // the empty set
  // for singleton sets {0} .. {3}
  IntSet S0(0), S1(1), S2(2), S3(3);
  IntSet A, B, C, D, E, F, G;  // to hold computed sets
  // Show and test empty set
  cout << "\nShow and test the empty set...\n";
  cout << "Empty = ";
  Empty.setPrint();
  cout << " has " << Empty.size() << " elements." << endl;

  if (Empty.isEmpty())
    cout << "The set is empty\n" << endl;
  else
    cout << "The set is *not* empty\n" << endl;
  // Show and test {1}
  cout << "S1 = ";
  S1.setPrint();
  cout << " has " << S1.size() << " elements." << endl;
  if (S1.isEmpty())
    cout << "Set S1 is empty\n" << endl;
  else
    cout << "Set S1 is *not* empty\n" << endl;
  // Compute some unions
  A = S0.setUnion(Empty);
  S0.setPrint();
  cout << " union ";
  Empty.setPrint();
  cout << " = ";
  A.setPrint();
  cout << endl << endl;
  A = S0.setUnion(S1);
  B = S3.setUnion(S2);
  A.setPrint();
  cout << " union ";
  B.setPrint();
  cout << " = ";
  C = A.setUnion(B);
  C.setPrint();
  cout << endl << endl;
  A = A.setUnion(S3);
  B = B.setUnion(S0);
  A.setPrint();
  cout << " union ";
  B.setPrint();
  cout << " = ";
  D = A.setUnion(B);
  D.setPrint();
  cout << endl << endl;
  // Compute intersection, relative complement, and symmetric difference
  E = A.setIntersection(S3);
  cout << "Intersection of ";
  A.setPrint();
  cout << " and ";
  S3.setPrint();
  cout << " is: ";
  E.setPrint();
  cout << endl << endl;
  G = D.relativeComplement(S0);
  cout << "Relative complement of ";
  D.setPrint();
  cout << "and ";
  S0.setPrint();
  cout << " is: ";
  G.setPrint();
  cout << endl << endl;
  F = B.symmetricDifference(A);
  cout << "Symmetric difference of ";
  B.setPrint();
  cout << " and ";
  A.setPrint();
  cout << " is: ";
  F.setPrint();
  cout << endl << endl;
  // Test if two sets are equal
  cout << "Set A: ";
  A.setPrint();
  cout << endl;
  cout << "Set B: ";
  B.setPrint();
  cout << endl;
  if (A.isEqualTo(B))
    cout << "Set A is equal to set B\n";
  else
    cout << "Set A is not equal to set B\n";
  cout << endl;
  return 0;
}