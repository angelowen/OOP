#include "Date.h"
#include <bits/stdc++.h>
using namespace std;
int cal[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Date::Compare(const Date &d) {
  if (year == d.year && month == d.month && day == d.day) return 0;
  if (year > d.year) {
    return 1;
  } else if (year == d.year) {
    if (month > d.month) {
      return 1;
    } else if (month == d.month) {
      if (day > d.day) {
        return 1;
      } else
        return -1;
    }
    return -1;
  }
  return -1;
}

Date::Date(int m, int d, int y) {
  format = 'd';
  int val[5];
  val[0] = m;
  val[1] = d;
  val[2] = y;
  if (!legal_check(val)) {
    month = 1;
    day = 1;
    year = 2000;
  } else {
    month = m;
    day = d;
    year = y;
  }
}
bool legal_check(int val[]) {
  if (val[0] < 1 || val[0] > 12)  // month
    return false;
  if (val[2] < 1)  // year
    return false;
  if (val[1] < 0 || val[1] > cal[val[0]]) return false;

  return true;
}
bool Date::Set(int m, int d, int y) {
  int val[5], cnt = 0;
  val[0] = m, val[1] = d, val[2] = y;
  if (legal_check(val)) {
    month = m;
    day = d;
    year = y;
  }
};
void Date::Show() {
  char M[][13] = {"NULL", "Jan", "Feb", "Mar", "Apr", "May", "June",
                  "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
  if (format == 'd')
    cout << month << "/" << day << "/" << year << endl;
  else if (format == 't')
    printf("%02d/%02d/%02d\n", month, day, year % 100);
  else if (format == 'l')
    cout << M[month] << " " << day << "," << year << endl;
}
bool Date::SetFormat(char f) {
  char tmp = tolower(f);
  if (tmp == 'd' || tmp == 't' || tmp == 'l') {
    format = tmp;
    return true;
  } else {
    return false;
  }
}
void Date::Increment(int numDays = 1) {
  day += numDays;
  while (day > cal[month]) {
    day -= cal[month];
    month++;
    if (month == 13) {
      month = 1;
      year++;
    }
  }
};
void Date::Increment() {
  day += 1;
  while (day > cal[month]) {
    day -= cal[month];
    month++;
    if (month == 13) {
      month = 1;
      year++;
    }
  }
};
void Date::Input() {
  char str[100];
  int val[5], cnt = 0;
  while (1) {
    cnt = 0;
    cout << "please enter a date in the format (month/day/year)!!" << endl;
    cin >> str;
    char *token = strtok(str, "/");
    while (token != NULL) {
      val[cnt++] = atoi(token);
      // printf( "%s\n",token );
      token = strtok(NULL, "/");
    }
    if (!legal_check(val)) {
      cout << "Invalid date. Try again!" << endl;
    } else {
      month = val[0], day = val[1], year = val[2];
      break;
    }
  }
}