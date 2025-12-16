#ifndef KEJUARAAN_H
#define KEJUARAAN_H

#include <string>
using namespace std;

struct Kejuaraan {
    int idKejuaraan;
    string nama;
    Kejuaraan *next;
};

struct ListKejuaraan {
    Kejuaraan *first;
};

void createListKejuaraan(ListKejuaraan &LK);
void insertKejuaraan(ListKejuaraan &LK, int id, string nama);
Kejuaraan* cariKejuaraan(ListKejuaraan LK, int id);
void hapusKejuaraan(ListKejuaraan &LK, int id);

#endif
