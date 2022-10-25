
#ifndef UNTITLED1_BIGDECIMALINT_H
#define UNTITLED1_BIGDECIMALINT_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
void check_size(vector<int>& n1, vector<int>& n2);
bool big_num(vector<int> n1, vector<int> n2);
vector<int> substraction(vector<int> n1, vector<int> n2);
class BigDecimalInt {
    vector<int>vecNumber;
    string num_sign;
public:
    string num;
    BigDecimalInt():num("000"){};
    BigDecimalInt(string decstr);
    BigDecimalInt(int decint);
    void convert_vector();

    BigDecimalInt operator+(BigDecimalInt b);
    void PrintTheSum();
    void print();
    BigDecimalInt operator-(BigDecimalInt b);
    bool operator > (BigDecimalInt anotherDec);
    bool operator<(BigDecimalInt secNum);
    friend ostream& operator<< (ostream& output, BigDecimalInt a);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    char sign();
    bool operator==(BigDecimalInt anotherDec);
    int size();

};


#endif //UNTITLED1_BIGDECIMALINT_H
