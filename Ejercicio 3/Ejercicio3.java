import java.util.Locale;

// Ejercicio 3: Producto y Venta (objeto como parámetro)
class Producto {
    String nombre;
    double precio;
    int stock;

    Producto(String nombre, double precio, int stock) {
        this.nombre = nombre;
        this.precio = precio;
        this.stock = stock;
    }

    // Solo actúa si hay stock suficiente; devuelve si la operación se realizó
    boolean reducirStock(int cantidad) {
        if (cantidad <= stock) {
            stock -= cantidad;
            return true;
        }
        System.out.println("Stock insuficiente.");
        return false;
    }

    void mostrarProducto() {
        System.out.printf(Locale.US, "Producto: %s | Precio: $%.2f | Stock: %d%n", nombre, precio, stock);
    }
}

class Venta {
    int cantidad;

    Venta(int cantidad) {
        this.cantidad = cantidad;
    }

    // Recibe un objeto Producto como parámetro
    void aplicar(Producto producto) {
        System.out.println("Venta de " + cantidad + " unidad(es) de " + producto.nombre);
        if (producto.reducirStock(cantidad)) {
            double total = cantidad * producto.precio;
            System.out.printf(Locale.US, "Total a pagar: $%.2f%n", total);
        }
    }
}

public class Ejercicio3 {
    public static void main(String[] args) {
        Producto p = new Producto("Laptop", 850.50, 10);
        p.mostrarProducto();

        Venta v1 = new Venta(3);   // válida
        v1.aplicar(p);
        p.mostrarProducto();

        Venta v2 = new Venta(20);  // supera el stock
        v2.aplicar(p);
        p.mostrarProducto();
    }
}
