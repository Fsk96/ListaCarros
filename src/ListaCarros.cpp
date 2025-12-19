#include "ListaCarros.h"
#include <iostream>
#include <limits>

using namespace std;

ListaCarros::ListaCarros() : head(nullptr), tail(nullptr) {}

ListaCarros::~ListaCarros() {
    while (!vazia()) {
        apagarHead();
    }
}

bool ListaCarros::vazia() const {
    return head == nullptr;
}

void ListaCarros::inserirTail() {
    string mat, mar, mod, mot;
    int a, c;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Matricula: ";
    getline(cin, mat);
    cout << "Marca: ";
    getline(cin, mar);
    cout << "Modelo: ";
    getline(cin, mod);
    cout << "Tipo de Motor: ";
    getline(cin, mot);
    cout << "Cilindrada: ";
    cin >> c;
    cout << "Aluguer Diario: ";
    cin >> a;

    Carro* novo = new Carro(mat, mar, mod, mot, a, c);

    novo->prev = tail;
    if (!tail)
        head = novo;
    else
        tail->next = novo;

    tail = novo;
}

void ListaCarros::apagarHead() {
    if (vazia()) return;

    Carro* aux = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete aux;
}

void ListaCarros::listar() const {
    if (vazia()) {
        cout << "Lista vazia.\n";
        return;
    }

    Carro* aux = head;
    while (aux) {
        cout << "Matricula: " << aux->matricula << "\n"
             << "Marca: " << aux->marca << "\n"
             << "Modelo: " << aux->modelo << "\n"
             << "Motor: " << aux->motor << "\n"
             << "Cilindrada: " << aux->cc << "\n"
             << "Aluguer diario: " << aux->aluguer << "\n"
             << "--------------------------\n";
        aux = aux->next;
    }
}

void ListaCarros::listarInverso() const {
    if (vazia()) {
        cout << "Lista vazia.\n";
        return;
    }

    Carro* aux = tail;
    while (aux) {
        cout << "Matricula: " << aux->matricula << "\n"
             << "Marca: " << aux->marca << "\n"
             << "Modelo: " << aux->modelo << "\n"
             << "Motor: " << aux->motor << "\n"
             << "Cilindrada: " << aux->cc << "\n"
             << "Aluguer diario: " << aux->aluguer << "\n"
             << "--------------------------\n";
        aux = aux->prev;
    }
}
