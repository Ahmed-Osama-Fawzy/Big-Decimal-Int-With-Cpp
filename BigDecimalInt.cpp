#include "BigDecimalInt.h"

using namespace std;

BigDecimalInt::BigDecimalInt(int decInt)
{
    num = to_string(decInt);

    if(num[0] == '+' || num[0] == '-')
    {
        num_sign = num[0];

        for(int i = 1; i <= num.size() - 1; i++)
        {
            int convertTheNumber = num[i] - '0';

            vecNumber.push_back(convertTheNumber);
        }
    }
    else
    {
        num_sign = '+';

        for(int i = 0; i < num.size() ; i++)
        {
            int convertTheNumber = num[i] - '0';

            vecNumber.push_back(convertTheNumber);
        }
    }
}

BigDecimalInt::BigDecimalInt(string theNumber) : num(theNumber)
        {

                if(num[0] == '+' || num[0] == '-')
                {
                    num_sign = num[0];

                    for(int i = 1; i <= num.size() - 1; i++)
                    {
                        int convertTheNumber = num[i] - '0';

                        vecNumber.push_back(convertTheNumber);

                    }
                }
                else
                {
                    num_sign = '+';

                    for(int i = 0; i < num.size() ; i++)
                    {
                        int convertTheNumber = num[i] - '0';

                        vecNumber.push_back(convertTheNumber);
                    }

                }

        }
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt SecNum){

    BigDecimalInt FirstNum("0");

    FirstNum.vecNumber.clear();

    FirstNum.num.clear();

    BigDecimalInt ThirdNum = *this;

    if (num_sign == SecNum.num_sign){

        FirstNum.num_sign = num_sign;

        if (vecNumber.size() > SecNum.vecNumber.size()){

            int diff = vecNumber.size() - SecNum.vecNumber.size() ;

            for (size_t i = 0; i < diff ; i++){

                SecNum.vecNumber.insert(SecNum.vecNumber.begin() , 0);}

        }else if (vecNumber.size() < SecNum.vecNumber.size()){

            int diff = SecNum.vecNumber.size() - vecNumber.size() ;

            for (size_t i = 0; i < diff ; i++){

                vecNumber.insert(vecNumber.begin() , 0);}
        };
        int i = vecNumber.size()-1;

        while(i >= 0){

            int Sum =  vecNumber[i] + SecNum.vecNumber[i];

            if (Sum > 9){

                Sum = Sum - 10 ;

                vecNumber[i-1] += 1 ;
            }

            i--;
            FirstNum.vecNumber.push_back(Sum);


        };
        reverse(FirstNum.vecNumber.begin(), FirstNum.vecNumber.end());




    }
        // -40 + 50

    else if (num_sign == "-" && SecNum.num_sign == "+"){

        //          50   +   40

        ThirdNum.num_sign = "+";

        FirstNum = SecNum - ThirdNum;

        ThirdNum.num_sign = "-";


    }

        //50-40
    else if (num_sign == "+" && SecNum.num_sign == "-"){

        SecNum.num_sign = "+";

        FirstNum = ThirdNum - SecNum ;

        SecNum.num_sign = "-";

    }

    FirstNum.convert_vector();

    return FirstNum;
};


BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    vector<int> V = vecNumber;

    check_size(V, anotherDec.vecNumber);

    if(num_sign == "+" && anotherDec.num_sign == "+")
    {
        if(big_num(V, anotherDec.vecNumber))
        {

            anotherDec.vecNumber = substraction(V, anotherDec.vecNumber);

            anotherDec.convert_vector();

            return anotherDec;
        }

        else
        {
            anotherDec.vecNumber = substraction(anotherDec.vecNumber,V);

            anotherDec.num_sign = "-";

            anotherDec.convert_vector();

            return anotherDec;
        }


    }

    else if(num_sign == "-" && anotherDec.num_sign == "-")
    {
        if(big_num(V, anotherDec.vecNumber))
        {
            anotherDec.vecNumber = substraction(V, anotherDec.vecNumber);

            anotherDec.num_sign = "-";

            anotherDec.convert_vector();

            return anotherDec;
        }

        else
        {
            anotherDec.vecNumber = substraction(anotherDec.vecNumber,V);

            anotherDec.num_sign = "+";

            anotherDec.convert_vector();

            return anotherDec;
        }

    }

        // 60+50
    else if(num_sign == "+" && anotherDec.num_sign == "-")
    {

        BigDecimalInt frstNum = *this;

        frstNum.vecNumber = V;

        anotherDec.num_sign = "+";

        frstNum = frstNum + anotherDec;

        //reverse(frstNum.vecNumber.begin(), frstNum.vecNumber.end());

        anotherDec.num_sign = "-";

        frstNum.num_sign = "+";

        frstNum.convert_vector();

        return frstNum;




    }

        //-60-50
    else if(num_sign == "-" && anotherDec.num_sign == "+")
    {
        BigDecimalInt frstNum = *this;

        frstNum.vecNumber = V;

        frstNum.num_sign = "+";

        frstNum = frstNum + anotherDec;

        frstNum.num_sign = "-";

        frstNum.convert_vector();

        return frstNum;
    }


}


void BigDecimalInt::convert_vector()
{
    string result;

    for(int i = 0; i < vecNumber.size(); i++)
    {
        if(vecNumber[i] == 0 && vecNumber.size() > 1)
        {
            vecNumber.erase(vecNumber.begin());

            i = -1;
        }

        else
        {
            break;
        }
    }

    for(int i = 0; i < vecNumber.size(); i++)
    {

        result += to_string(vecNumber[i]);
    }



    num = num_sign + result;

}


void BigDecimalInt::print()
{

    cout << num_sign;
    for(int i = 0; i < vecNumber.size(); i++)
    {
        cout << vecNumber[i];
    }
}
ostream& operator<< (ostream& output, BigDecimalInt& a)
{
cout<<a.num;

}

bool BigDecimalInt::operator> (BigDecimalInt a){

    if (a.num[0] == '-' && num[0]=='-'){

        for (int i = 0; i < a.num.length(); i++) {

            if (a.num[i] - '0' < num[i] - '0') {

                return false;

            }
        }

        return true;
    }

    else if ((a.num[0]=='+'|| isdigit(a.num[0]))&&(num[0]=='+'||isdigit(num[0]))) {

        if (a.num.length()<num.length()){

            return true;
        }

        else if (a.num.length()==num.length()) {

            for (int i = 0; i < a.num.length(); i++) {

                if (a.num[i] - '0' < num[i] - '0') {

                    return true;
                }
            }
        }
    }
    else if (a.num[0]=='-'&& (num[0]=='+'|| isdigit(num[0]))){
        return true;
    }
    else if (num[0]=='-'&& (a.num[0]=='+'|| isdigit(a.num[0]))){
        return false;
    }
}


bool BigDecimalInt::operator<(BigDecimalInt secNum){

    return !(*this > secNum);

}
bool BigDecimalInt ::operator==(BigDecimalInt a){

    if (a.num.length()== num.length())
    {
        for (int i=0;i<num.length();i++)
        {
            if (a.num[i]-'0'==num[i]-'0')
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }

}
BigDecimalInt BigDecimalInt :: operator= (BigDecimalInt a){
    num = a.num;
    return a;
}
int BigDecimalInt ::size()
{
    return num.length();
}
char BigDecimalInt:: sign() {

    if (num[0] == '-') {
        return '-';
    } else if (num[0] == '+') {
        return '+';
    } else {
        return '+';
    }
}

ostream& operator<< (ostream& output, BigDecimalInt a)
{
    cout<<a.num;
}


