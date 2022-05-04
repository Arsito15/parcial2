// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Estudiante.h"
#include <iostream>
#include <string>
using namespace  std;
int main() {
    int opc;
    string estudiante;
    //Estudiante e = Estudiante();
    //e.leer();
    while (1){
        cout << "Escoga el ejercicio que desee: " << endl;
    cout << "1.Ingreso: " << endl;
    cout << "2.Leer: " << endl;
    cout << "3.Actualizar: " << endl;
    cout << "4.Eliminar: " << endl;
    cin >> opc;

    switch (opc) {
    case 1:
        cout << "Ingrese estudiante:";
        getline(cin, estudiante);
        Estudiante e = Estudiante(estudiante);
        e.crear();
        system("pause");
    break;
    case 2:
        cout << "Lectura de estudiante:";
        Estudiante e = Estudiante(estudiante);
        e.leer();
        system("pause");
        break;
    case 3:
        cout << "Actualizacion de proveedor:";
        getline(cin, estudiante);
        Estudiante e = Estudiante(estudiante);
        e.actualizar();
        system("pause");
        break;
    case 4:
        cout << "Eliminar estudiante:";
        getline(cin, estudiante);
        Estudiante e = Estudiante(estudiante);
        e.eliminar();
        system("pause");
        break;

    }
    }
    return 0;
}


