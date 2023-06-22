#include <iostream> 
using namespace std; 

int main () { 
    cout << "Insira o numero de caixas: "; 
    int n, flag = 0; 
    cin >> n; // 5 
    if(n>0 && n<=10) { 
        int a[n]; 
        for(int i = 0; i < n; i++){ 
            cout << "\ndigite o número de chocolate na caixa " << i+1 << ":"; 
            cin >> a[i]; // 4 2 3 6 1
            if(i == 0; a[i]%2!=0){ 
                cout << "\n Desculpe!!! A primeira caixa sempre deve conter numero positivo.";
                return 0; 
            }
            else { 
                if(a[i] % 2 == 0){ // 4%2==0   2%2==0   3%2!=0   6%2==0   1%2!=0
                    flag++;    // flag=1   flag=2            flag=3
                }
            }
        }
        cout << "\n No. de chocolates em cada caixa: "; 
        for(int i=flag-1; i < n; i++){ 
            cout << a[i] << " "; // 3 6 1 
        }
    }

    else { 
        cout << "\nEntrada Invalida. ";
    }

    return 0;
}