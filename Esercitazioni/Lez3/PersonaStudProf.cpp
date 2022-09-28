#include <iostream>
#include <string>

class Persona {
    public:
        Persona(std::string s): nome(s) {}
        virtual void Print() {
            std::cout << "Il mio nome è " << nome << std::endl;
        }
    protected:
        std::string nome;
};

class Studente : public Persona {
    public:
        Studente(std::string s, float g): Persona(s), media(g) {}
        void Print() {
            std::cout << "Il mio nome è " << nome << " e la media è " << media << std::endl;
        }
    private:
        float media;
};

class Professore : public Persona {
    public:
        Professore(std::string s, int n): Persona(s), pubblicazioni(n) {}
        void Print() {
            std::cout << "Il mio nome è " << nome << " e ho " << pubblicazioni << " pubblicazioni" << std::endl;
        }
    private:
        int pubblicazioni;
};

int main() {
    Persona* p;
    Persona x(std::string("Raffaele"));
    p = &x;
    p->Print();
    Studente y(std::string("Giuseppe"), 29);
    p = &y;
    p->Print();
    Professore z(std::string("Carmine"), 5);
    p = &z;
    p->Print();
    return 0;
}