#include "BigDecimalInt.h"
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
