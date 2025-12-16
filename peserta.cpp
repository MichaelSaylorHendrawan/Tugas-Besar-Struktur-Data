#include "peserta.h"


// CREATE LIST PESERTA
// Fungsi ini digunakan untuk menginisialisasi list peserta
// first diset NULL menandakan list masih kosong
void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}


// INSERT PESERTA
// Menambahkan node peserta baru ke awal linked list
void insertPeserta(ListPeserta &LP, int id, string nama) {
    // Alokasi memori untuk node baru
    Peserta* P = new Peserta;

    // Mengisi data peserta
    P->idPeserta = id;
    P->nama = nama;

    // Menghubungkan node baru ke list
    P->next = LP.first;
    LP.first = P;
}

// CARI PESERTA
// Mencari peserta berdasarkan id
// Mengembalikan alamat node peserta jika ditemukan
Peserta* cariPeserta(ListPeserta LP, int id) {
    Peserta* P = LP.first;
    while (P != NULL) {
        if (P->idPeserta == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// HAPUS PESERTA
// Menghapus node peserta berdasarkan id
void hapusPeserta(ListPeserta &LP, int id) {
    Peserta* P = LP.first;
    Peserta* prev = NULL;

    while (P != NULL) {
        if (P->idPeserta == id) {
            if (prev == NULL) {
                LP.first = P->next;
            } else {
                prev->next = P->next;
            }
            delete P;
            return;
        }
        prev = P;
        P = P->next;
    }
}
