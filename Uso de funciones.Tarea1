#include <iostream>
#include <cmath>
using namespace std;

void Menu();
void opcion_Mayor();
void opcion_Serie();
void opcion_Peso();

int main() {
    int opcion;
    
    do {
        Menu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                opcion_Mayor();
                break;
            case 2:
                opcion_Serie();
                break;
            case 3:
                opcion_Peso();
                break;
            case 0:
                cout << endl << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Intenta de nuevo." << endl;
                break;
        }
        
    } while (opcion != 0);
    
    return 0;
}

void Menu() {
    cout << endl << "=== MENU PRINCIPAL ===" << endl;
    cout << "1. Determinar el mayor de tres números" << endl;
    cout << "2. Calcular la serie con ciclo For" << endl;
    cout << "3. Calcular el peso total de productos" << endl;
    cout << "0. Salir" << endl; 
    cout << "Opción.- ";
}

void opcion_Mayor() {
    int a, b, c;
    
    cout << "Introduce el primer número.- ";
    cin >> a;
    cout << "Introduce el segundo número.- ";
    cin >> b;
    cout << "Introduce el tercer número.- ";
    cin >> c;
    
    if (a == b && b == c) {
        cout << "Todos los números son iguales." << endl;
    } else if (a >= b && a >= c) {
        cout << "El mayor número es.- " << a << endl;
    } else if (b >= a && b >= c) {
        cout << "El mayor número es.- " << b << endl;
    } else {
        cout << "El mayor número es.- " << c << endl;
    }
}

void opcion_Serie() {
    int x;
    double suma = 0;
    
    cout << "Introduce el valor de x.- ";
    cin >> x;
    
    for (int b = 1; b <= 10; b++) {
        suma = suma + pow(x, b);
    }
    
    cout << "La suma total de la serie es.- " << suma << endl;
}

void opcion_Peso() {
    int cantidad;
    double pesoTotal = 0.0, peso;
    
    cout << "¿Cuántos productos deseas ingresar? " << endl;
    cin >> cantidad;
    
    for (int i = 1; i <= cantidad; i++) {
        cout << "Ingresa el peso del producto " << i << " (en gramos).- ";
        cin >> peso;
        pesoTotal = pesoTotal + peso;
    }
    
    cout << "El peso total de los productos es.- " << pesoTotal << " gramos." << endl;
}
