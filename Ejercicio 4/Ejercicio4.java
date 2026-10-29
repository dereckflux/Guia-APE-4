import java.util.Locale;

// Ejercicio 4: Transferencias entre cuentas (objeto como parámetro)
class Cuenta {
    String titular;
    double saldo;

    Cuenta(String titular, double saldo) {
        this.titular = titular;
        this.saldo = saldo;
    }

    void depositar(double monto) {
        saldo += monto;
    }

    boolean retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            return true;
        }
        return false;
    }

    // Retira de esta cuenta y deposita en la cuenta destino solo si hay fondos
    void transferir(Cuenta destino, double monto) {
        if (retirar(monto)) {
            destino.depositar(monto);
            System.out.printf(Locale.US, "Transferencia exitosa: $%.2f de %s a %s%n", monto, titular, destino.titular);
        } else {
            System.out.printf(Locale.US, "Transferencia fallida: fondos insuficientes en la cuenta de %s%n", titular);
        }
    }

    void mostrar() {
        System.out.printf(Locale.US, "Cuenta de %s -> Saldo: $%.2f%n", titular, saldo);
    }
}

public class Ejercicio4 {
    public static void main(String[] args) {
        Cuenta c1 = new Cuenta("Ana", 500);
        Cuenta c2 = new Cuenta("Luis", 200);

        System.out.println("Saldos iniciales:");
        c1.mostrar();
        c2.mostrar();

        System.out.println("\nTransferencia válida (150):");
        c1.transferir(c2, 150);
        c1.mostrar();
        c2.mostrar();

        System.out.println("\nTransferencia que falla (1000):");
        c1.transferir(c2, 1000);
        c1.mostrar();
        c2.mostrar();
    }
}
