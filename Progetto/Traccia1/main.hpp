#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef enum {red,black} color;

class nodo {
    public:
    int dato;
    color c;
    nodo *padre, *dx, *sx;
    nodo();
};

class rbtree {
    public:
    nodo *radice, *foglie;

    rbtree *createrb() {
        rbtree *t = new rbtree;
        if(!t) {
            fprintf(stderr, "Errore nell'allocazione\n");
            exit(-1);
        }
        t -> radice = new nodo;
        if(!(t->radice)) {
            fprintf(stderr, "Errore nell'allocazione\n");
            exit(-2);
        }
        t->foglie = t->radice;
        t->foglie->sx = t->foglie->dx = t->foglie->padre = t->foglie;
        t->foglie->c = black;
    }
};

/*
BISOGNA INSERIRE FUNZIONE DI INSERIMENTO DEI NODI
ALL'INTERNO DELL'ALBERO RB. HA BISOGNO DELL'INSERT_FIXUP
PER RISOLVERE PROBLEMI DI CARATTERISTICHE DELL'ALBERO
*/