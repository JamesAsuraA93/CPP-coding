#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "น้อนบัว :";
    cin >> x;
    switch (x){
    case 1 ... 10:
        cout << "Start" << endl;
        break;
    case 11 ... 19:
        cout << "Mid" << endl;
        break;
    case 20 ... 31:
        cout << "End" << endl;
        break;
    default:
        cout << "InvalidNumber" << endl;
        break;
    }

return 0;

}
