#ifndef INTSET_H
#define INTSET_H
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
#endif