#include <iostream>
#include <string>

using namespace std;

class Var

{
private:
    int* pInt;
    double* pDouble;
    string* pStr;
    int typeID; //0 - int 1 - double 2- string
public:
    Var() { typeID = -1; pInt = NULL; pDouble = NULL; pStr = NULL; };
    Var(const int& number);
    Var(const double& number);
    Var(const string& str);
    void Show();
    int toInt()const;
    double toDouble()const;
    char* toCharPtr()const;
    const string toString()const;
    Var& operator = (const Var& rightVar);
    Var& operator = (const int& number);
    Var& operator = (const double& number);
    Var& operator = (const string& str);
    const Var operator + (const Var& rightVar);
    const Var operator - (const Var& rightVar);
    const Var operator * (const Var& rightVar);
    const Var operator / (const Var& rightVar);
    Var& operator += (const Var& rightVar);
    Var& operator -= (const Var& rightVar);
    Var& operator *= (const Var& rightVar);
    Var& operator /= (const Var& rightVar);
    bool operator < (const Var& rightVar);
    bool operator > (const Var& rightVar);
    bool operator <= (const Var& rightVar);
    bool operator >= (const Var& rightVar);
    bool operator == (const Var& rightVar);
    bool operator != (const Var& rightVar);
};