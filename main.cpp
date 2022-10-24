#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void check_size(vector<int>& n1, vector<int>& n2)
{
    if(n1.size() > n2.size())
    {
        int size_diff = n1.size() - n2.size();

        for(int i = 0; i < size_diff; i++)
        {
            n2.insert(n2.begin() , 0);
        }

    }

        if(n1.size() < n2.size())
        {
            int size_diff = n2.size() - n1.size();

            for(int i = 0; i < size_diff; i++)
            {
                n1.insert(n1.begin() , 0);
            }
        }



}

// n1 = 888 and n2 = 887
bool big_num(vector<int> n1, vector<int> n2)
{
    for(int i = 0; i < n1.size(); i++)
    {
        if(n1[i] > n2[i])
        {
            return true;
        }
        else if(n2[i] > n1[i])
        {
            return false;
        }

    }

    return true;

}

vector<int> substraction(vector<int> n1, vector<int> n2)
{

    int carry = 0;

    for(int i = n1.size() - 1; i >= 0; i--)
    {
        int result = n1[i] - n2[i] - carry;

        if(result < 0)
        {
            result += 10;

            carry = 1;

            n2[i] = result;
        }

        else
        {
            n2[i] = result;

            carry = 0;
        }
    }

    return n2;
}

class BigDecimalInt{
private:

    vector<int>vecNumber;

    string num;

    string num_sign;

public:

    BigDecimalInt(int decInt)
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

   BigDecimalInt(string theNumber) : num(theNumber)
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

    BigDecimalInt operator+ (BigDecimalInt SecNum){

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


    BigDecimalInt operator-(BigDecimalInt anotherDec)
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


    void convert_vector()
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


    void print()
    {

        cout << num_sign;
        for(int i = 0; i < vecNumber.size(); i++)
        {
            cout << vecNumber[i];
        }
    }

    friend ostream& operator<< (ostream& output, BigDecimalInt& a);


    bool operator> (BigDecimalInt a){

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

bool operator<(BigDecimalInt secNum){

        return !(*this > secNum);

    }

    void PrintTheSumtion(){

        int i = vecNumber.size() -1 ;

        cout << num_sign ;

        while(i >= 0 ){

            cout << vecNumber[i];

            i--;
        }
    };
};

ostream& operator<< (ostream& output, BigDecimalInt& a)
{
    output << a.num;

    return output ;
};


int main(){

    BigDecimalInt num1("-123456789012345678901234567890");

    BigDecimalInt num2("-113456789011345678901134567890");

    BigDecimalInt num3("+200000000000000000000000000000");

    BigDecimalInt num6(40);

    BigDecimalInt num7(-50);

    cout << "num1 - num3 = ";

    BigDecimalInt num4 = num1 - num3;

    cout << num4;

    BigDecimalInt num8 = num6 + num7;

    cout << "\nnum6 + num 7 = ";

    cout << num8;

    return 0;
}
