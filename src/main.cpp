#include <iostream>
#include "ListaCarros.h"

using namespace std;

int main() {
    ListaCarros lista;
    char op;

    do {
        cout << "\n************\n"
             << "* 1- Inserir *\n"
             << "* 2- Apagar  *\n"
             << "* 3- Listar  *\n"
             << "* 4- Inverso *\n"
             << "* 5- Sair    *\n"
             << "************\n"
             << "Opcao: ";

        cin >> op;

        switch (op) {
            case '1': lista.inserirTail(); break;
            case '2': lista.apagarHead(); break;
            case '3': lista.listar(); break;
            case '4': lista.listarInverso(); break;
            case '5': cout << "A sair...\n"; break;
            default: cout << "Opcao invalida!\n";
        }
    } while (op != '5');

    return 0;
}
