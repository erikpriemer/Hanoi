#include <iostream>
#include "Spiel.cpp"

int main() {

    char *gratulation = (char *) "A";
    char *fehler = (char *) "B";
    char *naechster_zug = (char *) "C";


    Spiel spiel;

    while (true) {
        spiel.darstellen();
        Zug zug = spiel.zugEingabe();
        if (spiel.zugPruefen(zug)) {
            spiel.ziehen(zug);
        } else {
            spiel.message("B");
        }
    }
}

