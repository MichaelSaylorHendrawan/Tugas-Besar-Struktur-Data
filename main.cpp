#include <iostream>
#include "peserta.h"
#include "kejuaraan.h"
#include "relasi.h"

using namespace std;

int main() {
    ListPeserta LP;
    ListKejuaraan LK;
    ListRelasi LR;

    createListPeserta(LP);
    createListKejuaraan(LK);
    createListRelasi(LR);

    insertPeserta(LP, 1, "Andi");
    insertKejuaraan(LK, 101, "Lomba Coding");

    Peserta *P = cariPeserta(LP, 1);
    Kejuaraan *K = cariKejuaraan(LK, 101);

    if (P && K) {
        buatRelasi(LR, P, K);
    }

    cout << "Program berhasil dijalankan" << endl;
    return 0;
}
