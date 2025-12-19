#ifndef LISTACARROS_H
#define LISTACARROS_H

#include <string>

struct Carro {
    std::string matricula;
    std::string marca;
    std::string modelo;
    std::string motor;
    int aluguer;
    int cc;

    Carro* next;
    Carro* prev;

    Carro(const std::string& mat,
          const std::string& mar,
          const std::string& mod,
          const std::string& mot,
          int a, int c)
        : matricula(mat), marca(mar), modelo(mod),
          motor(mot), aluguer(a), cc(c),
          next(nullptr), prev(nullptr) {}
};

class ListaCarros {
private:
    Carro* head;
    Carro* tail;

public:
    ListaCarros();
    ~ListaCarros();

    void inserirTail();
    void apagarHead();
    void listar() const;
    void listarInverso() const;
    bool vazia() const;
};

#endif
