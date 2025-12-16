#include "relasi.h"

void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

void buatRelasi(ListRelasi &LR, Peserta *P, Kejuaraan *K) {
    Relasi *R = new Relasi;
    R->peserta = P;
    R->kejuaraan = K;
    R->next = LR.first;
    LR.first = R;
}

void hapusRelasiPeserta(ListRelasi &LR, Peserta *P) {
    Relasi *R = LR.first, *prev = NULL;
    while (R != NULL) {
        if (R->peserta == P) {
            if (prev == NULL)
                LR.first = R->next;
            else
                prev->next = R->next;
        } else {
            prev = R;
        }
        R = R->next;
    }
}

void hapusRelasiKejuaraan(ListRelasi &LR, Kejuaraan *K) {
    Relasi *R = LR.first, *prev = NULL;
    while (R != NULL) {
        if (R->kejuaraan == K) {
            if (prev == NULL)
                LR.first = R->next;
            else
                prev->next = R->next;
        } else {
            prev = R;
        }
        R = R->next;
    }
}
