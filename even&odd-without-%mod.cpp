#include <iostream>
using namespace std;

int main()
{
    float number,tmp;
    int cdt;
    cout << "Num : ";
    cin >> number;
    tmp = number * 0.5;
    cdt = int(tmp);
    
    if(tmp-cdt == 0.5){
        cout << "odd" << endl;
    }else{
        cout << "even" << endl;
    }
    
return 0;
