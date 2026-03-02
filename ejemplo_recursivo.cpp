#include <iostream>
using namespace std;

long long factorial(int n);
void decimalABinario(int n);
void binarioADecimal(long long binario, int base, int resultado);

long long factorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void decimalABinario(int n) {
    if (n < 0) {
        cout << "Error: ingresa un numero positivo." << endl;
        return;
    }
    if (n == 0) return;
    decimalABinario(n / 2);
    cout << n % 2;
}

void binarioADecimal(long long binario, int base = 1, int resultado = 0) {
    if (binario == 0) {
        cout << "Decimal: " << resultado << endl;
        return;
    }
    int digito = binario % 10;
    if (digito != 0 && digito != 1) {
        cout << "Error: el numero ingresado no es binario valido." << endl;
        return;
    }
    binarioADecimal(binario / 10, base * 2, resultado + digito * base);
}

int main() {
    int opcion;

    do {
        cout << "1. Calcular Factorial" << endl;
        cout << "2. Decimal a Binario" << endl;
        cout << "3. Binario a Decimal" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int num;
                cout << "Ingresa un numero entero no negativo: ";
                cin >> num;
                long long result = factorial(num);
                if (result == -1)
                    cout << "Error: el factorial no esta definido para negativos." << endl;
                else
                    cout << "Factorial de " << num << " = " << result << endl;
                break;
            }
            case 2: {
                int num;
                cout << "Ingresa un numero decimal: ";
                cin >> num;
                if (num < 0) {
                    cout << "Error: ingresa un numero positivo." << endl;
                } else if (num == 0) {
                    cout << "Binario: 0" << endl;
                } else {
                    cout << "Binario: ";
                    decimalABinario(num);
                    cout << endl;
                }
                break;
            }
            case 3: {
                long long num;
                cout << "Ingresa un numero binario: ";
                cin >> num;
                binarioADecimal(num);
                break;
            }
            case 4:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl;
        }

    } while (opcion != 4);

    return 0;
}
