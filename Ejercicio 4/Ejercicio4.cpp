// Ejercicio 4: Transferencias entre cuentas (objeto como parámetro)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cuenta {
public:
    string titular;
    double saldo;

    Cuenta(string titular, double saldo) {
        this->titular = titular;
        this->saldo = saldo;
    }

    void depositar(double monto) {
        saldo += monto;
    }

    bool retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            return true;
        }
        return false;
    }

    // Retira de esta cuenta y deposita en la cuenta destino solo si hay fondos
    void transferir(Cuenta &destino, double monto) {
        cout << fixed << setprecision(2);
        if (retirar(monto)) {
            destino.depositar(monto);
            cout << "Transferencia exitosa: $" << monto << " de " << titular
                 << " a " << destino.titular << endl;
        } else {
            cout << "Transferencia fallida: fondos insuficientes en la cuenta de "
                 << titular << endl;
        }
    }

    void mostrar() {
        cout << fixed << setprecision(2);
        cout << "Cuenta de " << titular << " -> Saldo: $" << saldo << endl;
    }
};

int main() {
    Cuenta c1("Ana", 500);
    Cuenta c2("Luis", 200);

    cout << "Saldos iniciales:" << endl;
    c1.mostrar();
    c2.mostrar();

    cout << "\nTransferencia válida (150):" << endl;
    c1.transferir(c2, 150);
    c1.mostrar();
    c2.mostrar();

    cout << "\nTransferencia que falla (1000):" << endl;
    c1.transferir(c2, 1000);
    c1.mostrar();
    c2.mostrar();
    return 0;
}
