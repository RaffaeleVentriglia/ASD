#include <iostream>
#include <thread>
/*
	grazie alla libreria Thread è possibile sfruttare tutte le caratteristiche
	della programmazione attraverso i thread, ovvero la suddivisione di un processo
	in due sottoprocessi, che vengono eseguiti concorrentemente.
*/
#include <mutex>
/*
	questa libreria permette di creare un mutex, ovvero un oggetto che permette
	di accedere ad una determinata risorsa in maniera esclusiva
*/
using namespace std;

mutex mux;

void funz() {
	mux.lock();
	for(int i = 0; i < 5; i++) {
		cout << "Funzione 1" << endl;
	}
	mux.unlock();
}

void funz2() {
	mux.lock();
	for(int i = 0; i < 5; i++) {
		cout << "Funzione 2" << endl;
	}
	mux.unlock();
}

int main() {
	thread Th1 (funz);
	thread Th2(funz2);
	Th1.join();
	Th2.join();
	return 0;
}
