
#include "BigDecimalInt.h"
using namespace std;
int main() {
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

    cout << num8<<endl;

    cout<<(num1=num2) <<endl;
    cout<<num1.size()<<endl;
    cout<<num1.sign()<<endl;
}
