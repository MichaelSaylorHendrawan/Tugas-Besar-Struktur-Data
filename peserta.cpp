#include "peserta.h"

void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}

void insertPeserta(ListPeserta &LP, int id, string nama) {
    Peserta *P = new Peserta;
    P->idPeserta = id;
    P->nama = nama;
    P->next = LP.first;
    LP.first = P;
}

Peserta* cariPeserta(ListPeserta LP, int id) {
    Peserta *P = LP.first;
    while (P != NULL) {
        if (P->idPeserta == id)
            return P;
        P = P->next;
    }
    return NULL;
}

void hapusPeserta(ListPeserta &LP, int id) {
    Peserta *P = LP.first, *prev = NULL;
    while (P != NULL && P->idPeserta != id) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev == NULL)
            LP.first = P->next;
        else
            prev->next = P->next;
        delete P;
    }
}
