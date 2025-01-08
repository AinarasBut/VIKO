#include <iostream>
using namespace std;

int main()
{
    int program = 0;
    cout << "1 - Masyvas | 2 - ID | Pasirinkite programa>>";
    cin >> program;

    if (program == 1) { // Masyvas
        int x=0, y=0, action = 5;
        double ats=0, maxNum = 0;
        cout << "Eilutes>> ";
        cin >> x;
        cout << "Stulpeliai>> ";
        cin >> y;
        int array[x][y];

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << i + 1 << "-ios eilutes " << j + 1 << "-asis skaitmuo>> ";
                cin >> array[i][j];
            }
        }
        cout << "================================"<<endl;
        cout << "0 - pabaigia cikla | 1 - lenteles spausdinimas | 2 - kiekvienos eilutes skaiciavimas | 3 - kiekvieno stulpelio skaiciavimas | 4 - didziausia reiksme" << endl;
        while (action != 0) {
            cout << "================================"<<endl;
            cout << "Pasirinkite veiksma >>";
            cin >> action;

            if (action == 1) { // Spausdina lentele
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        cout << "| " << array[i][j] << " | ";
                    }
                    cout << endl;
                }
            }

            else if (action == 2) { // Stulpeliu sudetis
                for (int i = 0; i < y; i++) {
                    cout << i + 1 << "-ojo stulpelio sudetis:";
                    for (int j = 0; j < y; j++) {
                        ats = ats + array[j][i];
                    }
                    cout<<ats<<endl;
                    ats = 0;
                }
            }

            else if (action == 3) { // Eiluciu sudetis
                for (int i = 0; i < x; i++) {
                    cout << i + 1 << "-ios eilutes sudetis:";
                    for (int j = 0; j < x; j++) {
                        ats = ats + array[i][j];
                    }
                    cout<<ats<<endl;
                    ats = 0;
                }
            }

            else if (action == 4) { // Didziausias skaicius
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        if (array[i][j] > maxNum) {
                            maxNum = array[i][j];
                        }
                    }
                }
                cout << "Didziausias skaicius = " << maxNum << endl;
            }
            else {
                cout << "Blogai pasirinkote veiksma!"<<endl;
            }
        }
    }

    else if (program == 2) {
        // ID
        struct ID {
            string name;
            string surname;
            int age;
        }id[50];
        int action = 5, i = 0, del = 0;
        cout<<"0 - Uzbaigti cikla | 1 - Prideti kontakta | 2 - Atspausdinti visus kontaktus | 3 - Pasalinti kontakta"<<endl;
        while (action != 0) {
            cout<<"Pasirinkite veiksma >>";
            cin >> action;
            if (action == 1) {
                cout<<"Vardas>> "; cin >> id[i].name;
                cout<<"Pavarde>> "; cin >> id[i].surname;
                cout<<"Amzius>> "; cin >> id[i].age;
                action = 5;
                i++;
            }
            else if (action == 2) {
                    cout << "===================================" << endl;
                for (int j = 0; j < i; j++) {
                    cout << "Vardas: " << id[j].name << endl;
                    cout << "Pavarde: " << id[j].surname << endl;
                    cout << "Amzius: " << id[j].age << endl;
                    cout << "===================================" << endl;
                }
            }
            else if (action == 3) {
                cout << "Pasirinkite kuri kontakta norite istrinti>>";
                cin >> del;
                id[del-1].name = "";
                id[del-1].surname = "";
                id[del-1].age = false;
                i--;
            }
        }
    }
    else {
        cout << "Ivyko klaida!";
        return 1;
    }

    return 0;
}
