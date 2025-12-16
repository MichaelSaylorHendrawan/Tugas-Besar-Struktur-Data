#include "kejuaraan.h"

void createListKejuaraan(ListKejuaraan &LK) {
    LK.first = NULL;
}

void insertKejuaraan(ListKejuaraan &LK, int id, string nama) {
    Kejuaraan *K = new Kejuaraan;
    K->idKejuaraan = id;
    K->nama = nama;
    K->next = LK.first;
    LK.first = K;
}

Kejuaraan* cariKejuaraan(ListKejuaraan LK, int id) {
    Kejuaraan *K = LK.first;
    while (K != NULL) {
        if (K->idKejuaraan == id)
            return K;
        K = K->next;
    }
    return NULL;
}

void hapusKejuaraan(ListKejuaraan &LK, int id) {
    Kejuaraan *K = LK.first, *prev = NULL;
    while (K != NULL && K->idKejuaraan != id) {
        prev = K;
        K = K->next;
    }

    if (K != NULL) {
        if (prev == NULL)
            LK.first = K->next;
        else
            prev->next = K->next;
        delete K;
    }
}
