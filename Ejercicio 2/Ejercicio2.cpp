// Ejercicio 2: Rectángulo (firmas de métodos con distintos tipos de retorno)
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Rectangulo {
public:
    double base;
    double altura;

    Rectangulo(double base, double altura) {
        this->base = base;
        this->altura = altura;
    }

    double calcularArea() {
        return base * altura;
    }

    double calcularPerimetro() {
        return 2 * (base + altura);
    }

    bool esCuadrado() {
        return base == altura;
    }

    string obtenerDescripcion() {
        ostringstream ss;
        ss << fixed << setprecision(1) << "Rectángulo de " << base << " x " << altura;
        return ss.str();
    }

    void mostrar() {
        cout << fixed << setprecision(1);
        cout << obtenerDescripcion() << endl;
        cout << "Área: " << calcularArea() << endl;
        cout << "Perímetro: " << calcularPerimetro() << endl;
        cout << "¿Es cuadrado?: " << (esCuadrado() ? "Sí" : "No") << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    Rectangulo r1(4, 6);
    Rectangulo r2(5, 5);

    r1.mostrar();
    r2.mostrar();
    return 0;
}
