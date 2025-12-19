#ifndef PESERTA_H
#define PESERTA_H

#include <iostream>
#include <string>
using namespace std;

//ADT PESERTA

struct Peserta {
    int id;
    string nama;
    string email;
    int umur;
    Peserta *next;
};

struct ListPeserta {
    Peserta *first;
};

//  ADT KEJUARAAN

struct Kejuaraan {
    int id;
    string nama;
};

//ADT RELASI (M–N)

struct Relasi {
    Peserta *peserta;
    Kejuaraan kejuaraan;
    Relasi *next;
};

struct ListRelasi {
    Relasi *first;
};

// PROTOTYPE FUNGSI

// Peserta
void createListPeserta(ListPeserta &LP);
void insertFirstPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
void insertLastPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
Peserta* cariPeserta(ListPeserta LP, int id);
void hapusPeserta(ListPeserta &LP, int id, ListRelasi &LR);
void tampilkanSemuaPeserta(ListPeserta LP);
int hitungTotalPeserta(ListPeserta LP);

// Relasi
void createListRelasi(ListRelasi &LR);
void buatRelasi(ListRelasi &LR, Peserta *P, int idKej, string namaKej);
void hapusRelasiPeserta(ListRelasi &LR, Peserta *P);
void tampilkanPesertaDenganKejuaraan(ListPeserta LP, ListRelasi LR);

#endif
