#ifndef KEJUARAAN_H
#define KEJUARAAN_H

#include <iostream>
#include <string>
using namespace std;

// ==================== DOUBLE LINKED LIST CIRCULAR ====================
// Digunakan untuk list DENGAN relasi (memenuhi syarat berbeda)

struct Peserta {
    int idPeserta;
    string nama;
    string email;           // Data tambahan untuk memenuhi minimal 3 data
    int umur;               // Data tambahan bertipe integer
    Peserta* next;
    Peserta* prev;
};

struct ListPeserta {
    Peserta* first;
    Peserta* last;
};

// ==================== SINGLE LINKED LIST ====================
// Digunakan untuk list TANPA relasi

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

// ==================== STRUCT RELASI ====================

struct Relasi {
    Peserta* peserta;
    Kejuaraan* kejuaraan;
    string tanggalDaftar;   // Data tambahan untuk relasi
    Relasi* next;
};

struct ListRelasi {
    Relasi* first;
};

// ==================== PROTOTIPE FUNGSI PESERTA (DOUBLE CIRCULAR) ====================

void createListPeserta(ListPeserta &LP);
void insertFirstPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
void insertLastPeserta(ListPeserta &LP, int id, string nama, string email, int umur);
void deleteFirstPeserta(ListPeserta &LP, ListRelasi &LR);
void deleteLastPeserta(ListPeserta &LP, ListRelasi &LR);
Peserta* cariPeserta(ListPeserta LP, int id);
void hapusPeserta(ListPeserta &LP, int id, ListRelasi &LR);
void tampilkanSemuaPeserta(ListPeserta LP);
void tampilkanPesertaDenganKejuaraan(ListPeserta LP, ListRelasi LR);
int hitungTotalPeserta(ListPeserta LP);

// ==================== PROTOTIPE FUNGSI KEJUARAAN (SINGLE LINKED LIST) ====================

void createListKejuaraan(ListKejuaraan &LK);
void insertFirstKejuaraan(ListKejuaraan &LK, int id, string nama, string kategori, int tahun);
void insertLastKejuaraan(ListKejuaraan &LK, int id, string nama, string kategori, int tahun);
void deleteFirstKejuaraan(ListKejuaraan &LK, ListRelasi &LR);
void deleteLastKejuaraan(ListKejuaraan &LK, ListRelasi &LR);
Kejuaraan* cariKejuaraan(ListKejuaraan LK, int id);
void hapusKejuaraan(ListKejuaraan &LK, int id, ListRelasi &LR);
void tampilkanSemuaKejuaraan(ListKejuaraan LK);
void tampilkanKejuaraanPopuler(ListKejuaraan LK, ListRelasi LR);
void tampilkanPesertaSedikitKejuaraan(ListPeserta LP, ListRelasi LR);
int hitungTotalKejuaraan(ListKejuaraan LK);

// ==================== PROTOTIPE FUNGSI RELASI ====================

void createListRelasi(ListRelasi &LR);
void buatRelasi(ListRelasi &LR, Peserta* P, Kejuaraan* K, string tanggal);
void hapusRelasiPeserta(ListRelasi &LR, Peserta* P);
void hapusRelasiKejuaraan(ListRelasi &LR, Kejuaraan* K);
void tampilkanPesertaKejuaraan(Kejuaraan* K, ListRelasi LR);
void tampilkanKejuaraanPeserta(Peserta* P, ListRelasi LR);
int hitungJumlahPesertaKejuaraan(Kejuaraan* K, ListRelasi LR);
int hitungJumlahKejuaraanPeserta(Peserta* P, ListRelasi LR);

// ==================== FUNGSI MENU DAN UTILITAS ====================

void tampilkanMenu();
void clearScreen();
void tampilkanHeader(string judul);
void enterUntukLanjut();

#endif
