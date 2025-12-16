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

    // a) MENAMBAHKAN DATA PESERTA
    insertPeserta(LP, 1, "Andi");
    insertPeserta(LP, 2, "Budi");
    insertPeserta(LP, 3, "Citra");

    // b) MENAMBAHKAN DATA KEJUARAAN
    insertKejuaraan(LK, 101, "Lomba Coding");
    insertKejuaraan(LK, 102, "Lomba UI/UX");
    
    // c) MEMBUAT RELASI PESERTA DENGAN KEJUARAAN
    Peserta *P1 = cariPeserta(LP, 1);
    Peserta *P2 = cariPeserta(LP, 2);
    Kejuaraan *K1 = cariKejuaraan(LK, 101);
    Kejuaraan *K2 = cariKejuaraan(LK, 102);

    if (P1 != NULL && K1 != NULL) {
        buatRelasi(LR, P1, K1);   // Andi ikut Lomba Coding
    }

    if (P2 != NULL && K2 != NULL) {
        buatRelasi(LR, P2, K2);   // Budi ikut Lomba UI/UX
    }

    // d) MENGHAPUS PESERTA BESERTA RELASINYA
    // Contoh: hapus peserta dengan ID = 2 (Budi)
    hapusRelasiPeserta(LR, P2);
    hapusPeserta(LP, 2);

    // e) MENGHAPUS KEJUARAAN BESERTA RELASINYA
    // Contoh: hapus kejuaraan dengan ID = 101 (Lomba Coding)
    hapusRelasiKejuaraan(LR, K1);
    hapusKejuaraan(LK, 101);

    // OUTPUT SEDERHANA (BUKTI PROGRAM JALAN)
    cout << "program jalan." << endl;

    return 0;
}
