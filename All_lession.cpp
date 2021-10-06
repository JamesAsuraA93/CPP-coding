#include <iostream>
using namespace std;

class Shopkeepers{ // สร้างคลาสชื่อ Shopkeepers
public:
    string type_flower;
    int mean;
    
    string meaing(int mean){
        switch (mean) {  // สร้าง Switch เพื่อผลค่าออกโดยออกเป็น string ดดยให้แสดงผลตาม case และ break ออก
            case 1:
                return "The Love";
                break;
            case 2:
                return "The White Love";
                break;
            case 3:
                return "The Honestly";
                break;
            case 4:
                return "The Remember";
                break;
            default: // ค่า default หากว่า case ไม่ตรง case ไหนเลย
                return "Nothing";
                break;
        }
    }
    void telling_meaning(){ // สร้าง Method ไม่นำค่าออก เพียงแค่ แสดงผลทางหน้าจอ
        cout << "You were pick the " << type_flower << "and meaning of this is " << "\'" << meaing(mean) << "\'." << endl;
    }
    
    void Menu_flowers(){ // สร้างฟังก์ชั่นที่เหมือนกับบบรทัด 40 เพืื่อเป็นตัว Overriding
        cout << "Rose Lily Sunflower and Carnation Flowers" << endl;
    }
};

class Menu : public Shopkeepers{ // สร้าง Sub-class เพื่อใช้เป็น Inheritance
public:
    string Customer;
    void Menu_flowers(){ // สร้างฟังก์ชั่นที่เหมือนกับบบรทัด 32 เพืื่อเป็นตัว Overriding
        cout << "[1:Rose 2:Lily 3:Sunflower 4:Carnation]" << endl;
    }
};

class Money_tax{ // สร้างคลาสเพื่อใช้เป็น Overloading
private: // สร้าง private variable เพื่อเก็บค่าตัวแปรที่ไม่ต้องการให้ถูกเข้าถึง
    int money_cost;
    float tax;

public:
    Money_tax(int MC = 0, float tx = 0){
        money_cost = MC;
        tax = tx;
    }
    
    Money_tax operator + (Money_tax const &obj){ // Method Overloading
        Money_tax temp;
        temp.money_cost = money_cost + obj.money_cost;
        temp.tax = tax + obj.tax;
        return temp; // นำค่าออกจากฟังก์ชั่น Overloading โดยที่การ Add.oparater ด้วย object
    }
    void print(){
        cout << money_cost << " + tax(" << tax << ")" << endl;
    }
    
    float Sum(){ // สร้าง method มาเพื่อนำค่าออกนอกฟังก์ชั่นโดยเป็นผลที่ได้จาก method print()
        return money_cost + (money_cost*tax);
    }
};


float Promotion(float money,int tag){ // สร้างฟังชั่นรับ Argument และใช้ parameter เป็น function parameter
    if(tag == 1){
        return money * 0.90;
    }else if (tag == 2){
        return money * 0.95;
    }else if (tag == 3){
        return money * 0.98;
    }else{
        return money;
    }
}

struct cost{ // สร้าง struct เก็บค่า bool และ int
    bool promotion;
    int Tag;
};



int main(){
    const float TAX = 0.07; // สร้างตัวแปรคงที่ไม่เปลี่ยนแปลงค่าขึ้นมาเพื่อคงค่าไว้
    Menu customer_menu; // ใช้ class Menu ที่เป็น Sub-class โดยให้ customer_menu เป็น ตัวแปร
    Shopkeepers Shop; // ใช้ class Shopkeepers โดยให้ Shop เป็นตัวแปร
    Money_tax Pay; // ใช้ class
    int Flower_cost = 100;
    int total = 0;
    int i=0,number_prize,m=0,tag;
    char coupon;
    string My_name;
    string Array_Flowers[] = {"Rose ","Lily ","Sunflower ","Carnation "}; // สร้าง Array {1,2,3,4}
    int bag[] = {}; // สร้าง Array เพื่อใช้เก็บตัวแปรใน Array
    
    struct cost Cost_way; // สร้างตัวแทนเก็บค่า struct

    // เริ่ม Output / Input
    cout << "Hello! Welcome to Shopkeepers" << endl;
    cout << "My name is Ken, what is your name?" << endl;
    cout << "Your name : ";
    cin >> My_name;
    customer_menu.Customer = My_name;
    cout << "We have : ";
    customer_menu.Shopkeepers::Menu_flowers();
    cout << "How many flowers do you want, "<< customer_menu.Customer << "?" << endl;
    cout << "Number of prize : ";
    cin >> number_prize;
    
    
    do{ // สร้าง do while loop เพื่อเก็บค่าจากผู้ใช้งาน
        cout << "What would you like to buy?" << endl;
        customer_menu.Menu_flowers();
        cout << "[1,2,3,4] : ";
        cin >> bag[i];
        if (bag[i] >= 1 && bag[i]<=4){
            i++;
        }else{
            cout << "please input range[1,2,3,4]" << endl;
        }
    }while(i < number_prize); // สร้าง do while loop เพื่อเก็บค่าจากผู้ใช้งาน
    
    
    for(int n = 0;n<number_prize;n++){ // for loop เพื่อ แสดงผลว่าในกระเป๋าเก็บตัวเลขอะไรบ้าง
        cout << "Your bag has " << bag[n] << " " << endl;
    };
    
    cout << endl;
    
    
    while(m<number_prize){ // while loop เพื่อคำนวณและแสดงผลดอกไม้และความหมายของดอกไม้
        int temp_num = bag[m];
        Shop.mean = temp_num;
        Shop.type_flower = Array_Flowers[temp_num-1];
        Shop.telling_meaning();
        m++;
    }
    
    
    while(true){ // ใช้ while loop เพิ่อถามหาคูปองจากผู้ใช้งาน
        cout << "Do you have coupon? [y/n] :";
        cin >> coupon;
        if(coupon=='y'){
            Cost_way.promotion = true; // ใช้ตัวแปรและเก็บค่าไว้ใน struct
            break;
        }
        else if(coupon=='n'){
            Cost_way.promotion = false; // ใช้ตัวแปรและเก็บค่าไว้ใน struct
            break;
        }
    }
    
    for(int k=0;k<number_prize;k++){ // ใช้ for loop เพื่อรวมจำนวนเงินที่ต้องจ่ายทั้งหมด
        total += Flower_cost;
    }
    
    int Vase = 50*number_prize;
    Money_tax Pay1(total,TAX), Pay2(Vase,0);  // ใช้ Overloading
    Money_tax Pay_all = Pay1 + Pay2; // ใช้ Overloading
    cout << "Cost with Tax is : ";
    Pay_all.print(); // แสดงผล Overloading
    
    
    // สร้าง condition if else เพื่อแสดงผลจำนวนเงินทั้งหมดที่ต้องจ่าย
    if(Cost_way.promotion){
        cout << "What your tag's coupon? [1,2,3] :";
        cin >> tag;
        Cost_way.Tag = tag; // ยกค่า tag ใส่ค่า Cost_way.Tag ของ struct
        float Sum = Pay_all.Sum(); // ให้ค่า Sum เป็นค่า Pay_all.Sum()
        cout << "Totally of money pay is : " << Promotion(Sum, Cost_way.Tag) << " Bath" << endl; // แสดงผลจำนวนเงินที่ต้องจ่ายทั้งหมดโดยเก็บภาษีและได้ส่วนลดแล้ว
        
    }else{
        Cost_way.Tag = 4; // ยกค่า 4 ใส่ค่า Cost_way.Tag ของ struct
        float Sum = Pay_all.Sum(); // ให้ค่า Sum เป็นค่า Pay_all.Sum()
        cout << "Totally of money pay is : " << Promotion(Sum, Cost_way.Tag) << " Bath" << endl; // แสดงผลจำนวนเงินที่ต้องจ่ายทั้งหมดโดยเก็บภาษีแล้ว
    }
    
    return 0;
}
