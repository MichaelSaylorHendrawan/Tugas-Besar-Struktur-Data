#include "kejuaraan.h"
#include <iomanip>
#include <limits>
#include <ctime>

// ==================== FUNGSI UTILITAS ====================

void clearScreen() {
    system("cls");
}

void tampilkanHeader(string judul) {
    cout << "\n================================================" << endl;
    cout << "           " << judul << endl;
    cout << "================================================" << endl;
}

void enterUntukLanjut() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// ==================== FUNGSI PESERTA (DOUBLE LINKED LIST CIRCULAR) ====================

void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void insertFirstPeserta(ListPeserta &LP, int id, string nama, string email, int umur) {
    // Cek apakah ID sudah ada
    Peserta* cek = cariPeserta(LP, id);
    if (cek != NULL) {
        cout << "ID peserta sudah ada!" << endl;
        return;
    }
    
    Peserta* P = new Peserta;
    P->idPeserta = id;
    P->nama = nama;
    P->email = email;
    P->umur = umur;
    
    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
        P->next = P;
        P->prev = P;
    } else {
        P->next = LP.first;
        P->prev = LP.last;
        LP.first->prev = P;
        LP.last->next = P;
        LP.first = P;
    }
    
    cout << "Peserta " << nama << " berhasil ditambahkan di awal list!" << endl;
}

void insertLastPeserta(ListPeserta &LP, int id, string nama, string email, int umur) {
    // Cek apakah ID sudah ada
    Peserta* cek = cariPeserta(LP, id);
    if (cek != NULL) {
        cout << "ID peserta sudah ada!" << endl;
        return;
    }
    
    Peserta* P = new Peserta;
    P->idPeserta = id;
    P->nama = nama;
    P->email = email;
    P->umur = umur;
    
    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
        P->next = P;
        P->prev = P;
    } else {
        P->next = LP.first;
        P->prev = LP.last;
        LP.last->next = P;
        LP.first->prev = P;
        LP.last = P;
    }
    
    cout << "Peserta " << nama << " berhasil ditambahkan di akhir list!" << endl;
}

void deleteFirstPeserta(ListPeserta &LP, ListRelasi &LR) {
    if (LP.first == NULL) {
        cout << "List peserta kosong!" << endl;
        return;
    }
    
    Peserta* P = LP.first;
    
    if (LP.first == LP.last) {
        // Hanya satu elemen
        hapusRelasiPeserta(LR, P);
        LP.first = NULL;
        LP.last = NULL;
    } else {
        // Lebih dari satu elemen
        hapusRelasiPeserta(LR, P);
        LP.first = P->next;
        LP.first->prev = LP.last;
        LP.last->next = LP.first;
    }
    
    cout << "Peserta " << P->nama << " berhasil dihapus dari awal list!" << endl;
    delete P;
}

void deleteLastPeserta(ListPeserta &LP, ListRelasi &LR) {
    if (LP.first == NULL) {
        cout << "List peserta kosong!" << endl;
        return;
    }
    
    Peserta* P = LP.last;
    
    if (LP.first == LP.last) {
        // Hanya satu elemen
        hapusRelasiPeserta(LR, P);
        LP.first = NULL;
        LP.last = NULL;
    } else {
        // Lebih dari satu elemen
        hapusRelasiPeserta(LR, P);
        LP.last = P->prev;
        LP.last->next = LP.first;
        LP.first->prev = LP.last;
    }
    
    cout << "Peserta " << P->nama << " berhasil dihapus dari akhir list!" << endl;
    delete P;
}

Peserta* cariPeserta(ListPeserta LP, int id) {
    if (LP.first == NULL) return NULL;
    
    Peserta* P = LP.first;
    do {
        if (P->idPeserta == id) {
            return P;
        }
        P = P->next;
    } while (P != LP.first);
    
    return NULL;
}

void hapusPeserta(ListPeserta &LP, int id, ListRelasi &LR) {
    if (LP.first == NULL) {
        cout << "List peserta kosong!" << endl;
        return;
    }
    
    Peserta* P = cariPeserta(LP, id);
    if (P == NULL) {
        cout << "Peserta dengan ID " << id << " tidak ditemukan!" << endl;
        return;
    }
    
    // Jika peserta adalah elemen pertama
    if (P == LP.first) {
        deleteFirstPeserta(LP, LR);
        return;
    }
    
    // Jika peserta adalah elemen terakhir
    if (P == LP.last) {
        deleteLastPeserta(LP, LR);
        return;
    }
    
    // Jika peserta di tengah
    P->prev->next = P->next;
    P->next->prev = P->prev;
    
    hapusRelasiPeserta(LR, P);
    cout << "Peserta " << P->nama << " berhasil dihapus!" << endl;
    delete P;
}

void tampilkanSemuaPeserta(ListPeserta LP) {
    tampilkanHeader("DAFTAR PESERTA");
    
    if (LP.first == NULL) {
        cout << "Belum ada peserta terdaftar." << endl;
        return;
    }
    
    Peserta* P = LP.first;
    int count = 1;
    
    cout << left << setw(5) << "No" 
         << setw(10) << "ID" 
         << setw(20) << "Nama" 
         << setw(25) << "Email" 
         << setw(10) << "Umur" << endl;
    cout << string(70, '-') << endl;
    
    do {
        cout << left << setw(5) << count
             << setw(10) << P->idPeserta
             << setw(20) << P->nama
             << setw(25) << P->email
             << setw(10) << P->umur << endl;
        P = P->next;
        count++;
    } while (P != LP.first);
}

void tampilkanPesertaDenganKejuaraan(ListPeserta LP, ListRelasi LR) {
    tampilkanHeader("PESERTA & KEJUARAAN YANG DIIKUTI");
    
    if (LP.first == NULL) {
        cout << "Belum ada peserta terdaftar." << endl;
        return;
    }
    
    Peserta* P = LP.first;
    do {
        cout << "\nPeserta: " << P->nama << " (ID: " << P->idPeserta 
             << ", Email: " << P->email << ", Umur: " << P->umur << ")" << endl;
        cout << "Kejuaraan yang diikuti:" << endl;
        
        Relasi* R = LR.first;
        bool adaKejuaraan = false;
        while (R != NULL) {
            if (R->peserta == P) {
                cout << "  - " << R->kejuaraan->nama 
                     << " (ID: " << R->kejuaraan->idKejuaraan 
                     << ", Kategori: " << R->kejuaraan->kategori 
                     << ", Tahun: " << R->kejuaraan->tahun << ")" << endl;
                adaKejuaraan = true;
            }
            R = R->next;
        }
        
        if (!adaKejuaraan) {
            cout << "  (Belum mengikuti kejuaraan)" << endl;
        }
        P = P->next;
    } while (P != LP.first);
}

int hitungTotalPeserta(ListPeserta LP) {
    if (LP.first == NULL) return 0;
    
    int count = 0;
    Peserta* P = LP.first;
    do {
        count++;
        P = P->next;
    } while (P != LP.first);
    
    return count;
}

// ==================== FUNGSI KEJUARAAN (SINGLE LINKED LIST) ====================

void createListKejuaraan(ListKejuaraan &LK) {
    LK.first = NULL;
}

void insertFirstKejuaraan(ListKejuaraan &LK, int id, string nama, string kategori, int tahun) {
    // Cek apakah ID sudah ada
    Kejuaraan* cek = cariKejuaraan(LK, id);
    if (cek != NULL) {
        cout << "ID kejuaraan sudah ada!" << endl;
        return;
    }
    
    Kejuaraan* K = new Kejuaraan;
    K->idKejuaraan = id;
    K->nama = nama;
    K->kategori = kategori;
    K->tahun = tahun;
    K->jumlahPeserta = 0;
    K->next = LK.first;
    LK.first = K;
    
    cout << "Kejuaraan " << nama << " berhasil ditambahkan di awal list!" << endl;
}

void insertLastKejuaraan(ListKejuaraan &LK, int id, string nama, string kategori, int tahun) {
    // Cek apakah ID sudah ada
    Kejuaraan* cek = cariKejuaraan(LK, id);
    if (cek != NULL) {
        cout << "ID kejuaraan sudah ada!" << endl;
        return;
    }
    
    Kejuaraan* K = new Kejuaraan;
    K->idKejuaraan = id;
    K->nama = nama;
    K->kategori = kategori;
    K->tahun = tahun;
    K->jumlahPeserta = 0;
    K->next = NULL;
    
    if (LK.first == NULL) {
        LK.first = K;
    } else {
        Kejuaraan* temp = LK.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = K;
    }
    
    cout << "Kejuaraan " << nama << " berhasil ditambahkan di akhir list!" << endl;
}

void deleteFirstKejuaraan(ListKejuaraan &LK, ListRelasi &LR) {
    if (LK.first == NULL) {
        cout << "List kejuaraan kosong!" << endl;
        return;
    }
    
    Kejuaraan* K = LK.first;
    hapusRelasiKejuaraan(LR, K);
    LK.first = K->next;
    
    cout << "Kejuaraan " << K->nama << " berhasil dihapus dari awal list!" << endl;
    delete K;
}

void deleteLastKejuaraan(ListKejuaraan &LK, ListRelasi &LR) {
    if (LK.first == NULL) {
        cout << "List kejuaraan kosong!" << endl;
        return;
    }
    
    if (LK.first->next == NULL) {
        // Hanya satu elemen
        deleteFirstKejuaraan(LK, LR);
        return;
    }
    
    Kejuaraan* temp = LK.first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    Kejuaraan* K = temp->next;
    hapusRelasiKejuaraan(LR, K);
    temp->next = NULL;
    
    cout << "Kejuaraan " << K->nama << " berhasil dihapus dari akhir list!" << endl;
    delete K;
}

Kejuaraan* cariKejuaraan(ListKejuaraan LK, int id) {
    Kejuaraan* K = LK.first;
    while (K != NULL) {
        if (K->idKejuaraan == id) {
            return K;
        }
        K = K->next;
    }
    return NULL;
}

void hapusKejuaraan(ListKejuaraan &LK, int id, ListRelasi &LR) {
    if (LK.first == NULL) {
        cout << "List kejuaraan kosong!" << endl;
        return;
    }
    
    // Jika elemen pertama
    if (LK.first->idKejuaraan == id) {
        deleteFirstKejuaraan(LK, LR);
        return;
    }
    
    // Cari kejuaraan
    Kejuaraan* prev = LK.first;
    Kejuaraan* curr = LK.first->next;
    
    while (curr != NULL && curr->idKejuaraan != id) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        cout << "Kejuaraan dengan ID " << id << " tidak ditemukan!" << endl;
        return;
    }
    
    // Jika elemen terakhir
    if (curr->next == NULL) {
        deleteLastKejuaraan(LK, LR);
        return;
    }
    
    // Jika elemen di tengah
    hapusRelasiKejuaraan(LR, curr);
    prev->next = curr->next;
    
    cout << "Kejuaraan " << curr->nama << " berhasil dihapus!" << endl;
    delete curr;
}

void tampilkanSemuaKejuaraan(ListKejuaraan LK) {
    tampilkanHeader("DAFTAR KEJUARAAN");
    
    if (LK.first == NULL) {
        cout << "Belum ada kejuaraan terdaftar." << endl;
        return;
    }
    
    Kejuaraan* K = LK.first;
    int count = 1;
    
    cout << left << setw(5) << "No" 
         << setw(10) << "ID" 
         << setw(25) << "Nama Kejuaraan" 
         << setw(15) << "Kategori" 
         << setw(10) << "Tahun" 
         << setw(15) << "Jml Peserta" << endl;
    cout << string(80, '-') << endl;
    
    while (K != NULL) {
        cout << left << setw(5) << count
             << setw(10) << K->idKejuaraan
             << setw(25) << K->nama
             << setw(15) << K->kategori
             << setw(10) << K->tahun
             << setw(15) << K->jumlahPeserta << endl;
        K = K->next;
        count++;
    }
}

void tampilkanKejuaraanPopuler(ListKejuaraan LK, ListRelasi LR) {
    if (LK.first == NULL) {
        cout << "Belum ada kejuaraan terdaftar." << endl;
        return;
    }
    
    // Update jumlah peserta untuk setiap kejuaraan
    Kejuaraan* K = LK.first;
    while (K != NULL) {
        K->jumlahPeserta = 0;
        K = K->next;
    }
    
    Relasi* R = LR.first;
    while (R != NULL) {
        R->kejuaraan->jumlahPeserta++;
        R = R->next;
    }
    
    // Cari kejuaraan dengan peserta terbanyak
    Kejuaraan* populer = NULL;
    int maxPeserta = 0;
    
    K = LK.first;
    while (K != NULL) {
        if (K->jumlahPeserta > maxPeserta) {
            maxPeserta = K->jumlahPeserta;
            populer = K;
        }
        K = K->next;
    }
    
    tampilkanHeader("KEJUARAAN PALING POPULER");
    if (populer != NULL && maxPeserta > 0) {
        cout << "Kejuaraan: " << populer->nama << endl;
        cout << "ID: " << populer->idKejuaraan << endl;
        cout << "Kategori: " << populer->kategori << endl;
        cout << "Tahun: " << populer->tahun << endl;
        cout << "Jumlah Peserta: " << maxPeserta << endl;
    } else {
        cout << "Belum ada peserta yang mendaftar kejuaraan." << endl;
    }
}

void tampilkanPesertaSedikitKejuaraan(ListPeserta LP, ListRelasi LR) {
    if (LP.first == NULL) {
        cout << "Belum ada peserta terdaftar." << endl;
        return;
    }
    
    Peserta* pesertaMin = NULL;
    int minKejuaraan = 9999;
    
    Peserta* P = LP.first;
    do {
        int count = hitungJumlahKejuaraanPeserta(P, LR);
        
        if (count < minKejuaraan) {
            minKejuaraan = count;
            pesertaMin = P;
        }
        P = P->next;
    } while (P != LP.first);
    
    tampilkanHeader("PESERTA DENGAN KEJUARAAN TERMINIMUM");
    if (pesertaMin != NULL) {
        cout << "Peserta: " << pesertaMin->nama << endl;
        cout << "ID: " << pesertaMin->idPeserta << endl;
        cout << "Email: " << pesertaMin->email << endl;
        cout << "Umur: " << pesertaMin->umur << endl;
        cout << "Jumlah Kejuaraan: " << minKejuaraan << endl;
    }
}

int hitungTotalKejuaraan(ListKejuaraan LK) {
    int count = 0;
    Kejuaraan* K = LK.first;
    while (K != NULL) {
        count++;
        K = K->next;
    }
    return count;
}

// ==================== FUNGSI RELASI ====================

void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

void buatRelasi(ListRelasi &LR, Peserta* P, Kejuaraan* K, string tanggal = "") {
    // Cek apakah relasi sudah ada
    Relasi* R = LR.first;
    while (R != NULL) {
        if (R->peserta == P && R->kejuaraan == K) {
            cout << "Peserta sudah terdaftar di kejuaraan ini!" << endl;
            return;
        }
        R = R->next;
    }
    
    // Buat relasi baru
    R = new Relasi;
    R->peserta = P;
    R->kejuaraan = K;
    R->tanggalDaftar = (tanggal.empty()) ? "2024-01-01" : tanggal;
    R->next = LR.first;
    LR.first = R;
    
    K->jumlahPeserta++;
    cout << "Relasi berhasil dibuat!" << endl;
    cout << P->nama << " sekarang mengikuti " << K->nama << endl;
}

void hapusRelasiPeserta(ListRelasi &LR, Peserta* P) {
    Relasi* R = LR.first;
    Relasi* prev = NULL;
    
    while (R != NULL) {
        if (R->peserta == P) {
            // Kurangi jumlah peserta di kejuaraan
            R->kejuaraan->jumlahPeserta--;
            
            if (prev == NULL) {
                LR.first = R->next;
                Relasi* temp = R;
                R = R->next;
                delete temp;
            } else {
                prev->next = R->next;
                Relasi* temp = R;
                R = R->next;
                delete temp;
            }
        } else {
            prev = R;
            R = R->next;
        }
    }
}

void hapusRelasiKejuaraan(ListRelasi &LR, Kejuaraan* K) {
    Relasi* R = LR.first;
    Relasi* prev = NULL;
    
    while (R != NULL) {
        if (R->kejuaraan == K) {
            if (prev == NULL) {
                LR.first = R->next;
                Relasi* temp = R;
                R = R->next;
                delete temp;
            } else {
                prev->next = R->next;
                Relasi* temp = R;
                R = R->next;
                delete temp;
            }
        } else {
            prev = R;
            R = R->next;
        }
    }
}

void tampilkanPesertaKejuaraan(Kejuaraan* K, ListRelasi LR) {
    if (K == NULL) {
        cout << "Kejuaraan tidak ditemukan!" << endl;
        return;
    }
    
    tampilkanHeader("PESERTA KEJUARAAN: " + K->nama);
    
    Relasi* R = LR.first;
    bool adaPeserta = false;
    
    while (R != NULL) {
        if (R->kejuaraan == K) {
            cout << "- " << R->peserta->nama 
                 << " (ID: " << R->peserta->idPeserta 
                 << ", Email: " << R->peserta->email 
                 << ", Tanggal Daftar: " << R->tanggalDaftar << ")" << endl;
            adaPeserta = true;
        }
        R = R->next;
    }
    
    if (!adaPeserta) {
        cout << "Belum ada peserta yang mendaftar." << endl;
    }
}

void tampilkanKejuaraanPeserta(Peserta* P, ListRelasi LR) {
    if (P == NULL) {
        cout << "Peserta tidak ditemukan!" << endl;
        return;
    }
    
    tampilkanHeader("KEJUARAAN PESERTA: " + P->nama);
    
    Relasi* R = LR.first;
    bool adaKejuaraan = false;
    
    while (R != NULL) {
        if (R->peserta == P) {
            cout << "- " << R->kejuaraan->nama 
                 << " (ID: " << R->kejuaraan->idKejuaraan 
                 << ", Kategori: " << R->kejuaraan->kategori 
                 << ", Tahun: " << R->kejuaraan->tahun 
                 << ", Tanggal Daftar: " << R->tanggalDaftar << ")" << endl;
            adaKejuaraan = true;
        }
        R = R->next;
    }
    
    if (!adaKejuaraan) {
        cout << "Belum mengikuti kejuaraan apapun." << endl;
    }
}

int hitungJumlahPesertaKejuaraan(Kejuaraan* K, ListRelasi LR) {
    int count = 0;
    Relasi* R = LR.first;
    while (R != NULL) {
        if (R->kejuaraan == K) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int hitungJumlahKejuaraanPeserta(Peserta* P, ListRelasi LR) {
    int count = 0;
    Relasi* R = LR.first;
    while (R != NULL) {
        if (R->peserta == P) {
            count++;
        }
        R = R->next;
    }
    return count;
}
