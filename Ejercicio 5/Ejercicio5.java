// Ejercicio 5: Biblioteca (colaboración entre clases)
class Usuario {
    String nombre;
    String cedula;

    Usuario(String nombre, String cedula) {
        this.nombre = nombre;
        this.cedula = cedula;
    }
}

class Libro {
    String titulo;
    boolean disponible;

    Libro(String titulo) {
        this.titulo = titulo;
        this.disponible = true;
    }

    // Intenta prestar el libro: solo es posible si está disponible
    boolean prestar() {
        if (disponible) {
            disponible = false;
            return true;
        }
        return false;
    }

    void devolver() {
        disponible = true;
    }
}

class Prestamo {
    Usuario usuario;
    Libro libro;

    Prestamo(Usuario usuario, Libro libro) {
        this.usuario = usuario;
        this.libro = libro;
    }

    void registrar() {
        if (libro.prestar()) {
            System.out.println("Préstamo exitoso: \"" + libro.titulo + "\" fue prestado a "
                    + usuario.nombre + " (C.I. " + usuario.cedula + ").");
        } else {
            System.out.println("Préstamo rechazado: \"" + libro.titulo + "\" no está disponible para "
                    + usuario.nombre + " (C.I. " + usuario.cedula + ").");
        }
    }
}

public class Ejercicio5 {
    public static void main(String[] args) {
        Usuario u1 = new Usuario("Juan Pérez", "1805123456");
        Usuario u2 = new Usuario("María López", "1804987654");
        Libro libro = new Libro("Cien años de soledad");

        Prestamo p1 = new Prestamo(u1, libro);
        Prestamo p2 = new Prestamo(u2, libro);

        p1.registrar(); // el libro está disponible
        p2.registrar(); // el libro ya fue prestado
    }
}
