#include <iostream>
#include <random>
using namespace std;

void isLetter()
{
    string letter;
    cout<<"Iveskite raide: ";
    cin>>letter;
    if (letter == "o" || letter == "i" || letter == "u" || letter == "a" || letter == "e")
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}

void divisor()
{
    int num1, num2, temp;
    cout<<"Iveskite pirmaji skaiciu: ";
    cin>>num1;
    cout<<"Iveskite antraji skaiciu: ";
    cin>>num2;
    while (num2 != 0)
        {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
        }
    cout<<"Bendras didziausias dalmuo: "<<num1<<endl;
}

void randomNum()
{
    int randNum = rand()%100 + 1, input, points = 1;
    cout<<"Atspekite kompiuterio sugeneruota skaiciu!"<<endl;
    while (input == 0 || randNum != input)
    {
        cout<<points<<" bandymas: ";
        cin>>input;
        if (randNum > input)
        {
            cout<<"Sugeneruotas skaicius yra didesnis!"<<endl;
            points = points + 1;
        }
        else if (randNum < input)
        {
            cout<<"Sugeneruotas skaicius yra mazesnis!"<<endl;
            points = points + 1;
        }
        else if (randNum == input)
        {
            cout<<"Atspejote sugeneruota skaiciu("<<randNum<<") per "<<points<<" bandymus"<<endl;
        }
    }
}

void Fizzbuzz()
{
    int n;
    cout<<"Iveskite skaiciu: ";
    cin>>n;
    for (int i = 1 ; i<=n ; i++)
    {
        if (i % 5 == 0 && i % 3 == 0)
        {
            cout<<"("<<i<<")FizzBuzz"<<endl;
        }
        else if (i % 3 == 0)
        {
            cout<<"("<<i<<")Fizz"<<endl;
        }
        else if (i % 5 == 0)
        {
            cout<<"("<<i<<")Buzz"<<endl;
        }
        else
        {
            cout<<i<<endl;
        }
    }
}

int main()

{
    int function = 1;
    while (function != 0)
    {
        cout<<"Noredami nutraukti programa iveskite 0"<<endl;
        cout<<"Pasirinkite funkcija 0|1|2|3|4>>";
        cin>>function;
        switch (function)
        {
            case 0:
                cout<<"Programa baigta!"<<endl;
            break;

            case 1:
                isLetter();
            break;

            case 2:
                divisor();
            break;

            case 3:
                randomNum();
            break;

            case 4:
                Fizzbuzz();
            break;

            default:
                cout<<"Tokia funkcija neegzistuoja"<<endl;
            break;
        }
        cout<<"======================================"<<endl;
    }
    return 0;
}