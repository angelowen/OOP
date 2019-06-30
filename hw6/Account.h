#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
extern const int len;
class Account {
 public:
  Account(){};
  ~Account(){};
  virtual double ProjectedBalance() = 0;
  void addf(char *name) {
    firstname = new char[len];
    strcpy(firstname, name);
  }
  void addl(char *name) {
    lastname = new char[len];
    strcpy(lastname, name);
  }
  void addt(char *type) {
    type = new char[len];
    strcpy(type, type);
  }
  char *getf() { return firstname; }
  char *getl() { return lastname; }

 private:
  char *firstname;
  char *lastname;
  char *type;
};

#endif