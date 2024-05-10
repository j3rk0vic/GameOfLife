#include "game_of_life.h"
#include <ctime>

game_of_life::game_of_life() {
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

bool game_of_life::slucajna_vrijednost() {
    return rand() % 2 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j) {
    if (i < 0 || j < 0 || i >= REDAKA || j >= STUPACA)
        return false;
    return _generacija[i][j];
}

void game_of_life::sljedeca_generacija() {
    bool nova_generacija[REDAKA][STUPACA] = {}; // Nova generacija, inicijalno svi elementi su postavljeni na false

    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            int broj_susjeda = 0;
            // Provjeravan susjedne celije oko trenutne
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    // Priskacen trenutnu celiju i provjeravan granice polja
                    if ((di == 0 && dj == 0) || i + di < 0 || i + di >= REDAKA || j + dj < 0 || j + dj >= STUPACA)
                        continue;
                    // Provjeravan je li susjedna celija ziva
                    if (_generacija[i + di][j + dj])
                        broj_susjeda++;
                }
            }
            // Primjenjujen pravila igre
            _generacija[i][j] = (broj_susjeda == 3 || (broj_susjeda == 2 && _generacija[i][j]));
        }
    }
}

void game_of_life::iscrtaj() {
    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            std::cout << (_generacija[i][j] ? '*' : '-');
        }
        std::cout << std::endl;
    }
}
