#ifndef __Date_H
#define __Date_H
bool legal_check(int val[]);
class Date {
 private:
  int month, day, year;
  char format;

 public:
  Date() : month(1), day(1), year(2000), format('d'){};
  Date(int, int, int);
  void Show();
  void Input();
  bool Set(int m, int d, int y);
  int GetMonth() { return month; };
  int GetDay() { return day; };
  int GetYear() { return year; };
  bool SetFormat(char);
  void Increment(int);
  void Increment(void);
  int Compare(const Date &d);
};

#endif