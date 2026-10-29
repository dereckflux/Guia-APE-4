// Ejercicio 5: Biblioteca (colaboración entre clases)
#include <iostream>
#include <string>
using namespace std;

class Usuario {
public:
    string nombre;
    string cedula;

    Usuario(string nombre, string cedula) {
        this->nombre = nombre;
        this->cedula = cedula;
    }
};

class Libro {
public:
    string titulo;
    bool disponible;

    Libro(string titulo) {
        this->titulo = titulo;
        this->disponible = true;
    }

    // Intenta prestar el libro: solo es posible si está disponible
    bool prestar() {
        if (disponible) {
            disponible = false;
            return true;
        }
        return false;
    }

    void devolver() {
        disponible = true;
    }
};

class Prestamo {
public:
    Usuario *usuario;
    Libro *libro; // puntero para compartir el mismo libro entre préstamos

    Prestamo(Usuario *usuario, Libro *libro) {
        this->usuario = usuario;
        this->libro = libro;
    }

    void registrar() {
        if (libro->prestar()) {
            cout << "Préstamo exitoso: \"" << libro->titulo << "\" fue prestado a "
                 << usuario->nombre << " (C.I. " << usuario->cedula << ")." << endl;
        } else {
            cout << "Préstamo rechazado: \"" << libro->titulo << "\" no está disponible para "
                 << usuario->nombre << " (C.I. " << usuario->cedula << ")." << endl;
        }
    }
};

int main() {
    Usuario u1("Juan Pérez", "1805123456");
    Usuario u2("María López", "1804987654");
    Libro libro("Cien años de soledad");

    Prestamo p1(&u1, &libro);
    Prestamo p2(&u2, &libro);

    p1.registrar(); // el libro está disponible
    p2.registrar(); // el libro ya fue prestado
    return 0;
}
