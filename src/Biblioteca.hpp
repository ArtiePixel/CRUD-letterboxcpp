#pragma once
#include <iostream>
#include <string>

class Biblioteca{
    protected:
    std::string titulo, autor, editora;
    int data, tipo;
    float nota;

    public:
    Biblioteca(){}
    Biblioteca(int ti, std::string t, std::string a, std::string e, int d, float n) {
        tipo = ti;
        titulo = t;
        autor = a;
        editora = e;
        data = d;
        nota = n;
    }

    virtual void exibir(){
        std::cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nEditora: " << editora << "\nAno: " << data << "\nNota: " << nota << std::endl;
    }
    
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    std::string getEditora() const { return editora; }
    int getData() const { return data; }
    float getNota() const { return nota; }
    int getTipo() const { return tipo; }

    virtual ~Biblioteca() {}
};