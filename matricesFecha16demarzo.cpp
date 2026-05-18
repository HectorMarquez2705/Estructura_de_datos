#define MAXCOL 20
#define MAXROW 20
#include <iostream>
using namespace std;

void cargar(int matrix[MAXROW][MAXCOL], int n, int m);
void mostrar(int matrix[MAXROW][MAXCOL], int n, int m);
void sumarMatrices(int m1[MAXROW][MAXCOL], int m2[MAXROW][MAXCOL], int result[MAXROW][MAXCOL], int n, int m);
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int tamrow, tamcol, opcion;
    int matrix1[MAXROW][MAXCOL], matrix2[MAXROW][MAXCOL], matrixResult[MAXROW][MAXCOL];

    do {
        cout << "Ingrese el numero de filas.- ";
        cin >> tamrow;
    } while ((tamrow <= 0) || (tamrow > MAXROW));
    do {
        cout << "Ingrese el numero de columnas.- ";
        cin >> tamcol;
    } while ((tamcol <= 0) || (tamcol > MAXCOL));

    do {
        cout << endl <<"Menu " << endl;
        cout << "1. Cargar matriz" << endl;
        cout << "2. Mostrar matriz" << endl;
        cout << "3. Sumar dos matrices" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion.- ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << endl << "Cargar Matriz 1" << endl;
                cargar(matrix1, tamrow, tamcol);
                cout << endl << "Cargar Matriz 2" << endl;
                cargar(matrix2, tamrow, tamcol);
                break;
            case 2:
                cout << endl << "Matriz 1" << endl;
                mostrar(matrix1, tamrow, tamcol);
                cout << endl << "Matriz 2" << endl;
                mostrar(matrix2, tamrow, tamcol);
                break;
            case 3:
                sumarMatrices(matrix1, matrix2, matrixResult, tamrow, tamcol);
                cout << endl << "Resultado de la suma.-" << endl;
                mostrar(matrixResult, tamrow, tamcol);
                break;
            case 4:
                cout << "saliendo del programa :v" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);
}

void cargar(int matrix[MAXROW][MAXCOL], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "matrix [" << i << "][" << j << "].- ";
            cin >> matrix[i][j];
        }
    }
}

void mostrar(int matrix[MAXROW][MAXCOL], int n, int m)
{
    cout << "La matriz es.- " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sumarMatrices(int m1[MAXROW][MAXCOL], int m2[MAXROW][MAXCOL], int result[MAXROW][MAXCOL], int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}
