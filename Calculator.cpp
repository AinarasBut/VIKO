#include <iostream>
using namespace std;

int main() {
    double x, y;
    string action = "+";

        cout<<"x: ";
        cin>>x;
        while (action != "!") {
            cout<<"| ! - closes program | c - reset calculator | + | - | * | / | Choose your action: ";
            cin>>action;
            if (action == "+") {
                cout<<"y: ";
                cin>>y;
                cout<<x<<" + "<<y<<" = ";
                x = x+y;
                cout<<x<<endl;
            }
            else if (action == "-") {
                cout<<"y: ";
                cin>>y;
                cout<<x<<" - "<<y<<" = ";
                x = x-y;
                cout<<x<<endl;
            }
            else if (action == "*") {
                cout<<"y: ";
                cin>>y;
                cout<<x<<" * "<<y<<" = ";
                x = x*y;
                cout<<x<<endl;
            }
            else if (action == "/") {
                cout<<"y: ";
                cin>>y;
                cout<<x<<" / "<<y<<" = ";
                x = x/y;
                cout<<x<<endl;
            }
            else if (action == "c") {
                cout<<"Calculator reseted"<<endl;
                action = "+";
                cout<<"x: ";
                cin>>x;

            }
            else if (action == "!") {
                cout<<"Program closed!"<<endl;
            }
            else {
                cout<<"Not a valid input!"<<endl;
            }
        }
    return 0;
}
