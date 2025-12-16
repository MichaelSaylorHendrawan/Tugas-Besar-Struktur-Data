#ifndef PESERTA_H
#define PESERTA_H

#include <iostream>
using namespace std;

struct Peserta {
    int idPeserta;
    string nama;
    Peserta* next;
};

struct ListPeserta {
    Peserta* first;
};

// prototype fungsi
void createListPeserta(ListPeserta &LP);
void insertPeserta(ListPeserta &LP, int id, string nama);
Peserta* cariPeserta(ListPeserta LP, int id);
void hapusPeserta(ListPeserta &LP, int id);

#endif

