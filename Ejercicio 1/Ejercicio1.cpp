// Ejercicio 1: Libro y Autor (objeto como atributo)
#include <iostream>
#include <string>
using namespace std;

class Autor {
public:
    string nombre;
    string nacionalidad;

    Autor(string nombre, string nacionalidad) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
    }
};

class Libro {
public:
    string titulo;
    int anio;
    Autor autor; // objeto como atributo

    Libro(string titulo, int anio, Autor autor) : autor(autor) {
        this->titulo = titulo;
        this->anio = anio;
    }

    void mostrarInformacion() {
        cout << "Título: " << titulo << endl;
        cout << "Año: " << anio << endl;
        cout << "Autor: " << autor.nombre << " (" << autor.nacionalidad << ")" << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    Autor a1("Gabriel García Márquez", "Colombiana");
    Autor a2("Jorge Icaza", "Ecuatoriana");

    Libro l1("Cien años de soledad", 1967, a1);
    Libro l2("Huasipungo", 1934, a2);

    l1.mostrarInformacion();
    l2.mostrarInformacion();
    return 0;
}
