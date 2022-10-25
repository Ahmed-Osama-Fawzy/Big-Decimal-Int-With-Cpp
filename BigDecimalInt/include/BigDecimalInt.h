#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void check_size(vector<int>& n1, vector<int>& n2);

bool big_num(vector<int> n1, vector<int> n2);

vector<int> substraction(vector<int> n1, vector<int> n2);

class BigDecimalInt
{
    public:
        BigDecimalInt();
        virtual ~BigDecimalInt();

        BigDecimalInt(int decInt);

        BigDecimalInt(string theNumber);

        BigDecimalInt operator+ (BigDecimalInt SecNum);

        BigDecimalInt operator-(BigDecimalInt anotherDec);

        bool operator<(BigDecimalInt secNum);

        bool operator > (BigDecimalInt anotherDec);

        bool operator==(BigDecimalInt anotherDec);

        BigDecimalInt operator= (BigDecimalInt anotherDec);

        char sign();

        int size();

        friend ostream& operator<< (ostream& output, BigDecimalInt a);


    protected:

    private:

        vector<int>vecNumber;
        string num;
        string num_sign;
        void convert_vector();
};

#endif // BIGDECIMALINT_H
