#ifndef PESERTA_H
#define PESERTA_H

#include <iostream>
using namespace std;

// Menyimpan data peserta dan pointer ke peserta berikutnya
// Pointer next menandakan bahwa struktur ini adalah linked list
struct Peserta {
    int idPeserta;
    string nama;
    Peserta* next;
};

// Menyimpan alamat node pertama dari linked list peserta
// Ini adalah implementasi ADT List Peserta
struct ListPeserta {
    Peserta* first;
};


// prototype fungsi
void createListPeserta(ListPeserta &LP); // Menginisialisasi list peserta (list kosong)
void insertPeserta(ListPeserta &LP, int id, string nama); // Menambahkan peserta baru ke dalam list
Peserta* cariPeserta(ListPeserta LP, int id); // Mencari peserta berdasarkan id
void hapusPeserta(ListPeserta &LP, int id); // Menghapus peserta berdasarkan id

#endif

