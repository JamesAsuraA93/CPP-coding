#include <iostream>
using namespace std;
int main(){
    float numbers[5],grd[5],grade = 4,sum_grd = 0,sum = 0,x;
    cout << "(4=A,3=B,2=D,1=E,0=F) of five subjects : ";
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        if(x>=0 and x<=4){
            numbers[i] = x;
        }
        else{
            break;
        }
        grd[i] = numbers[i] * grade;
        grade--;
        sum = sum + numbers[i];
        sum_grd = sum_grd + grd[i];
    }
    if(sum <= 16 and sum >= 0){
        cout << sum_grd/10 << endl;
    }
    else{
        cout << "Invalid Numbers" << endl;
    }
    return 0;
}
