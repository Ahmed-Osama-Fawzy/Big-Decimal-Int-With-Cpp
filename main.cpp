#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
using namespace std;

struct Card
{
    int RightSide ;
    int LeftSide ;
    Card(int L , int R):LeftSide(L),RightSide(R){};
};
vector<Card>Input;
vector<Card>Chain;

void MakeTheChain(){
    if(Input.size() != 0){
       for (size_t t = 0; t < Input.size(); t++){
            if(Chain[Chain.size()-1].RightSide == Input[t].LeftSide){
                Chain.push_back(Input[t]);
                Input.erase(Input.begin() + t);
            }else if(Chain[0].LeftSide == Input[t].RightSide){
                Chain.insert(Chain.begin() , Input[t]);
                Input.erase(Input.begin() + t);
            };
        };
    }
}

int main(){
    int NumofCards ;
    cout << "Enter The # Of Cards: ";
    cin>> NumofCards ;
    int R , L ;
    for (size_t i = 0; i < NumofCards; i++){
        cin >> L >> R;
        Input.push_back(Card(L,R));
    }
    cout << endl ;
    Chain.push_back(Input[0]);
    Input.erase(Input.begin());

    MakeTheChain();

    for (size_t i = 0; i < Chain.size(); i++){
       cout << Chain[i].LeftSide << " | " << Chain[i].RightSide << " - ";
    }
    cout << endl ;
    return 0 ;
}
