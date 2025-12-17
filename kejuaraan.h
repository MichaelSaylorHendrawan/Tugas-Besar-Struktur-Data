#ifndef KEJUARAAN_H
#define KEJUARAAN_H

#include <iostream>
#include <string>
using namespace std;

struct Peserta {
    int idPeserta;
    string nama;
    string email;
    int umur;
    Peserta* next;
    Peserta* prev;
};

struct ListPeserta {
    Peserta* first;
    Peserta* last;
};


struct Kejuaraan {
    int idKejuaraan;
    string nama;
    string kategori;        // Data tambahan untuk memenuhi minimal 3 data
    int tahun;              // Data tambahan bertipe integer
    int jumlahPeserta;
    Kejuaraan* next;
};

struct ListKejuaraan {
    Kejuaraan* first;
};

struct Relasi {
    Peserta* peserta;
    Kejuaraan* kejuaraan;
    string tanggalDaftar;   // Data tambahan untuk relasi
    Relasi* next;
};

struct ListRelasi {
    Relasi* first;
};

// ======= PROTOTIPE FUNGSI PESERTA (DOUBLE CIRCULAR) ==========
void createListPeserta(ListPeserta &LP);
void insertFirstPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
void insertLastPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
void deleteFirstPeserta(ListPeserta &LP, ListRelasi &LR);
void deleteLastPeserta(ListPeserta &LP, ListRelasi &LR);
Peserta* cariPeserta(ListPeserta LP, int id);
void hapusPeserta(ListPeserta &LP, int id, ListRelasi &LR);
