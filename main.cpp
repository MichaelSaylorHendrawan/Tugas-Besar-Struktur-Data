#include "peserta.h"
#include "kejuaraan.h"
#include "relasi.h"

void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}

void createListKejuaraan(ListKejuaraan &LK) {
    LK.first = NULL;
}

void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}










int main() {
    ListPeserta LP;
    ListKejuaraan LK;
    ListRelasi LR;

    createListPeserta(LP);
    createListKejuaraan(LK);
    createListRelasi(LR);

    return 0;
}
