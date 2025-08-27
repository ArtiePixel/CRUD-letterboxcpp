#include <iostream>
#include <string>
#pragma once

class Biblioteca{
    protected:
    std::string titulo, autor, editora;
    int data;
    float nota;

    public:
    Biblioteca(std::string t, std::string a, std::string e, int d, float n) {
        titulo = t;
        autor = a;
        editora = e;
        data = d;
        nota = n;
    }

    virtual void exibir(){
        std::cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nEditora: " << editora << "\nAno: " << data << "\nNota: " << nota << std::endl;
    }

    virtual ~Biblioteca() {}
};