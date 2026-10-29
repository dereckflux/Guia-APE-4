// Ejercicio 3: Producto y Venta (objeto como parámetro)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    double precio;
    int stock;

    Producto(string nombre, double precio, int stock) {
        this->nombre = nombre;
        this->precio = precio;
        this->stock = stock;
    }

    // Solo actúa si hay stock suficiente; devuelve si la operación se realizó
    bool reducirStock(int cantidad) {
        if (cantidad <= stock) {
            stock -= cantidad;
            return true;
        }
        cout << "Stock insuficiente." << endl;
        return false;
    }

    void mostrarProducto() {
        cout << fixed << setprecision(2);
        cout << "Producto: " << nombre << " | Precio: $" << precio
             << " | Stock: " << stock << endl;
    }
};

class Venta {
public:
    int cantidad;

    Venta(int cantidad) {
        this->cantidad = cantidad;
    }

    // Recibe un objeto Producto como parámetro (por referencia para modificar el original)
    void aplicar(Producto &producto) {
        cout << "Venta de " << cantidad << " unidad(es) de " << producto.nombre << endl;
        if (producto.reducirStock(cantidad)) {
            double total = cantidad * producto.precio;
            cout << fixed << setprecision(2) << "Total a pagar: $" << total << endl;
        }
    }
};

int main() {
    Producto p("Laptop", 850.50, 10);
    p.mostrarProducto();

    Venta v1(3);   // válida
    v1.aplicar(p);
    p.mostrarProducto();

    Venta v2(20);  // supera el stock
    v2.aplicar(p);
    p.mostrarProducto();
    return 0;
}
