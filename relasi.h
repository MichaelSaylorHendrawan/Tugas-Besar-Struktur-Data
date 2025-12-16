#ifndef RELASI_H
#define RELASI_H

#include "peserta.h"
#include "kejuaraan.h"

struct Relasi {
    Peserta *peserta;
    Kejuaraan *kejuaraan;
    Relasi *next;
};

struct ListRelasi {
    Relasi *first;
};

void createListRelasi(ListRelasi &LR);
void buatRelasi(ListRelasi &LR, Peserta *P, Kejuaraan *K);
void hapusRelasiPeserta(ListRelasi &LR, Peserta *P);
void hapusRelasiKejuaraan(ListRelasi &LR, Kejuaraan *K);

#endif
