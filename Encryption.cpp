#include <iostream>
#include <string>
using namespace std;

int main() {
    int n=0, m=0, temp=0, abc = 26, action; // n - word | m - secretKey | abc - amount of letters in alphabet
    while (action != 1 && action != 2) {
        cout<<"1 - Alphabet 2 - ASCII"<<endl;
        cout<<"Choose action :";
        cin >> action;
        if (action != 1 && action != 2) {
            cout<<"Invalid action!"<<endl;
        }
    }
    if (action == 1) { // Alphabet
        cout<<"Enter amount of letters for Word: ";
        cin >> n;

        int secretKeyValue[n], wordValue[n]; // secretKey and Word value converted into numbers
        string alphabet[]{ "A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O",
            "P", "Q", "R", "S","T", "U", "V", "W", "X", "Y", "Z"},
        // This program is using english alphabet with 26 letters!
        secretKey[n], word[n], encWord[n], decWord[n]; // secretKey and word input
        for (int i = 0 ; i<n ; i++) {
            cout<<"Enter letter ("<<i+1<<"):";
            cin >> word[i];
        }
        for (int i = 0 ; i<n ; i++) { // Gets values for word | Temp is used to get number value
            for(int j = 0 ; word[i] != alphabet[j] ; j++) {
                temp++;
            }
            wordValue[i] = temp;
            temp = 0;
            //cout<<"|"<<wordValue[i]<<"| ";
        }
        cout<<"Enter amount of letters for secretWord: ";
        cin >> m;
        while (m > n){
            cout<<"It has to be lower than letters for word! Enter new amount:";
            cin >> m;
        }
        for (int i = 0 ; i<m ; i++) {
            cout<<"Enter letter ("<<i+1<<"):";
            cin >> secretKey[i];
        }

        if (n > m) { // Continues secretKey until its lenght is = word
            for (m ; n != m ; m++) {
                secretKey[m] = secretKey[temp];
                temp++;
            }
            temp = 0;
        }

        for (int i = 0 ; i<n ; i++) { // Gets values for secretKey | Temp is used to get number value
            for(int j = 0 ; secretKey[i] != alphabet[j] ; j++) {
                temp++;
            }
            secretKeyValue[i] = temp;
            temp = 0;
            //cout<<"|"<<secretKeyValue[i]<<"| ";
        }
        if (action == 1) {
            // Alphabet
            for (int i = 0 ; i<n ; i++) { // Encryption
                temp = wordValue[i] + secretKeyValue[i];
                if (temp > abc) {
                    encWord[i] = alphabet[temp-abc];
                    decWord[i] = alphabet[wordValue[i]-abc];
                }
                else if (temp <= abc){
                    encWord[i] = alphabet[temp];
                    decWord[i] = alphabet[wordValue[i]];
                }
            }
            cout<<"Encrypted: ";
            for (int i = 0 ; i<n ; i++) {
                cout<<encWord[i];
            }
            cout<<endl<<"Decrypted: ";
            for (int i = 0 ; i<n ; i++) {
                cout<<decWord[i];
            }
        }
    }
    if (action == 2) {
        // ASCII
        cout<<"Enter amount of letters for Word: ";
        cin >> n;
        char letterX[n], letterY[n];
        int encrypted[n], charValueX[n], charValueY[n], decrypted[n];
        for (int i = 0 ; i<n ; i++) {
            cout<<"Enter letter ("<<i+1<<"):";
            cin >> letterX[i];
            charValueX[i] = int(letterX[i]);
            //cout<<charValueX[i];
        }
        cout<<"Enter amount of letters for secretWord: ";
        cin >> m;
        while (m > n){
            cout<<"It has to be lower than letters for word! Enter new amount:";
            cin >> m;
        }
        for (int i = 0 ; i<m ; i++) {
            cout<<"Enter letter ("<<i+1<<"):";
            cin >> letterY[i];
            charValueY[i] = int(letterY[i]);
            //cout<<charValueY[i];
        }
        if (n > m) { // Continues secretKey until its lenght is = word
            temp = 0;
            for (m ; n != m ; m++) {
                letterY[m] = letterY[temp];
                temp++;
            }
        }
        cout<<"Encrypted: ";
        //cout<<char(charValueX[0]);
        for (int i = 0 ; i<n ; i++) {
            encrypted[i] =  charValueX[i] + charValueY[i] + 33;
            decrypted[i] = encrypted[i] - charValueY[i] - 33;
            if (encrypted[i] > 126) {
                encrypted[i] = encrypted[i] - 93;
            }
            cout<<char(encrypted[i]);
        }
        cout<<endl<<"Decrypted: ";
        for (int i = 0 ; i<n ; i++) {
            cout<<char(decrypted[i]);
        }
    }
    return 0;
}