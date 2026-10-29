// Ejercicio 2: Rectángulo (firmas de métodos con distintos tipos de retorno)
class Rectangulo {
    double base;
    double altura;

    Rectangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    double calcularArea() {
        return base * altura;
    }

    double calcularPerimetro() {
        return 2 * (base + altura);
    }

    boolean esCuadrado() {
        return base == altura;
    }

    String obtenerDescripcion() {
        return "Rectángulo de " + base + " x " + altura;
    }

    void mostrar() {
        System.out.println(obtenerDescripcion());
        System.out.println("Área: " + calcularArea());
        System.out.println("Perímetro: " + calcularPerimetro());
        System.out.println("¿Es cuadrado?: " + (esCuadrado() ? "Sí" : "No"));
        System.out.println("-----------------------------");
    }
}

public class Ejercicio2 {
    public static void main(String[] args) {
        Rectangulo r1 = new Rectangulo(4, 6);
        Rectangulo r2 = new Rectangulo(5, 5);

        r1.mostrar();
        r2.mostrar();
    }
}
