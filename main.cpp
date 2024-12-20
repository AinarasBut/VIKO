#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct menuItemType {
    string item;
    double price;
    double order;
}menuItemType[8];

void getMenu() {
    ifstream menuData;
    menuData.open("menuData.txt");
    cout << "*********************************" << endl; // Seperates the menu
    for (int i=0; !menuData.eof(); i++) { // collects every line of data from txt file and prints out the menu
        menuData>>menuItemType[i].item;
        menuData>>menuItemType[i].price;
        cout << i+1 << ". " << menuItemType[i].item << " " << fixed << setprecision(2) << menuItemType[i].price << "eur" << endl;
    }
    menuData.close();
    cout << "*********************************" << endl; // Seperates the menu
}

void printCheck() {
    int order = 9, temp = 0;
    double total = 0, pvm;
    ifstream menuData;
    menuData.open("menuData.txt");
    for (int i=0; !menuData.eof(); i++) { // collects every line of data from txt file and prints out the menu
        menuData>>menuItemType[i].item;
        menuData>>menuItemType[i].price;
    }
    menuData.close();
    for(int i = 0; order != 0; i++) { // counts the order
        cout << "Enter the number of product you want to order, if you want to finish your order enter 0 >> ";
        cin >> order;
        if(order > 0){
        cout << "How many would you like to order? >>";
        cin >> temp;
        if (temp == 0) {
            while (temp > 0) {
                cout<<"You cannot order less than 1 enter again >>";
                cin >> temp;
            }
        }
            cout<<temp<<"x "<<menuItemType[order-1].item<<" has been added to your order!"<<endl;
            menuItemType[i].order = menuItemType[order-1].price*temp;
            total = menuItemType[i].order + total;
        }
    }
    pvm = total * 0.21;
    cout<<"PVM: "<<pvm<<fixed<<setprecision(2)<<endl;
    total = total + pvm;
    cout << "Your total is: " << total << fixed << setprecision(2) << endl;
}

int main() {
    int run = 100;
    while (run != 0) {
    cout << "If you want to see menu enter 1, if you want to order enter 2, if you want to close the program enter 0 >>";
    cin >> run;
        if (run == 1) {
            getMenu();
            run = 100;
        }
        else if (run == 2) {
            printCheck();
            run = 100;
        }
        else if (run != 0 && run > 2) {
            while (run != 0 && run > 1) {
                cout << "You entered an invalid choice! Please enter again >>";
                cin>>run;
            }
        }
    }
    cout<<"Program closed!";
    return 0;
}