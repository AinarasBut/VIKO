#include <iostream>
using namespace std;
int main()
{
    int eur, currency, action;
    double sum,
    GBP_Bendras = 0.8593, GBP_Pirkti = 0.8450, GBP_Parduoti = 0.9060,
    USD_Bendras = 1.0713, USD_Pirkti = 1.0547, USD_Parduoti = 1.1309,               // Valiutos
    INR_Bendras = 88.8260, INR_Pirkti = 85.2614, INR_Parduoti = 92.8334;

    while (action != 0)         // Pagrindinis ciklas
    {
        cout<<"Pasirinkite veiksma(0 - Uzdaro programa ; 1 - Bendras kursas ; 2 - Pirkti ; 3 - Parduoti)>>";
        cin>>action;
    if (action == 1)            // Bendro kurso ciklas
    {
        cout<<"Pasirinkite valiuta(1 - GBP ; 2 - USD ; 3 - INR)>>";
        cin>>currency;
        switch (currency)
        {
            case 1:         // GBP Bendras
                    cout<<"Bendru kursu 1e = "<<GBP_Bendras<<"GBP"<<endl;
            break;
            case 2:         // USD Bendras
                    cout<<"Bendru kursu 1e = "<<USD_Bendras<<"USD"<<endl;
            break;
            case 3:         // INR Bendras
                    cout<<"Bendru kursu 1e = "<<INR_Bendras<<"INR"<<endl;
            break;
            default:
            {
                cout<<"ERROR(1) --> Blogai pasirinkta valiuta!"<<endl;
            }
        }
    }
    else if (action > 1 && action < 4)         // Pirkimo/Pardavimo ciklas
    {
        cout<<"Pasirinkite valiuta(1 - GBP ; 2 - USD ; 3 - INR)>>";
        cin>>currency;

        switch (currency)
        {
            case 1:         // GBP Veiksmai
                if (action == 2)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur*GBP_Pirkti;
                    cout<<"Nusipirkote: "<<sum<<" valiutos"<<endl;
                }
                else if (action == 3)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur/GBP_Parduoti;
                    cout<<"Pardavete: "<<sum<<"eur"<<endl;
                }
            break;

            case 2:         // USD Veiksmai
                if (action == 2)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur*USD_Pirkti;
                    cout<<"Nusipirkote: "<<sum<<" valiutos"<<endl;
                }
                else if (action == 3)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur/USD_Parduoti;
                    cout<<"Pardavete: "<<sum<<"eur"<<endl;
                }
            break;

            case 3:         // INR Veiksmai
                if (action == 2)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur*INR_Pirkti;
                    cout<<"Nusipirkote: "<<sum<<" valiutos"<<endl;
                }
                else if (action == 3)
                {
                    cout<<"Pasirinkite suma>>";
                    cin>>eur;
                    sum = eur/INR_Parduoti;
                    cout<<"Pardavete: "<<sum<<"eur"<<endl;
                }
            break;

            default:            // Klaida pasirinkus bloga valiuta
            {
                cout<<"ERROR(2) --> Blogai pasirinkta valiuta!"<<endl;
            }
        } // switch
    } // if
    else if (action == 0)           // Uzdaroma programa pasirinkus 0
    {
        cout<<"PROGRAMA SEKMINGAI UZDARYTA"<<endl;
    }
    else
    {
        cout<<"ERROR(3) --> Blogai pasirinktas veiksmas!"<<endl;
    }
    cout<<"==========================================================================================="<<endl;
    } // while
    return 0;
}
