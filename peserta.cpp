#include "peserta.h"

//PESERTA

void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}

void insertFirstPeserta(ListPeserta &LP, int id, string nama, string email, int umur) {
    Peserta *P = new Peserta;
    P->id = id;
    P->nama = nama;
    P->email = email;
    P->umur = umur;
    P->next = LP.first;
    LP.first = P;
}

void insertLastPeserta(ListPeserta &LP, int id, string nama, string email, int umur) {
    Peserta *P = new Peserta;
    P->id = id;
    P->nama = nama;
    P->email = email;
    P->umur = umur;
    P->next = NULL;

    if (LP.first == NULL) {
        LP.first = P;
    } else {
        Peserta *Q = LP.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

Peserta* cariPeserta(ListPeserta LP, int id) {
    Peserta *P = LP.first;
    while (P != NULL) {
        if (P->id == id)
            return P;
        P = P->next;
    }
    return NULL;
}

void tampilkanSemuaPeserta(ListPeserta LP) {
    Peserta *P = LP.first;
    while (P != NULL) {
        cout << "ID: " << P->id
             << " | Nama: " << P->nama
             << " | Email: " << P->email
             << " | Umur: " << P->umur << endl;
        P = P->next;
    }
}

int hitungTotalPeserta(ListPeserta LP) {
    int total = 0;
    Peserta *P = LP.first;
    while (P != NULL) {
        total++;
        P = P->next;
    }
    return total;
}

//RELASI


void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

void buatRelasi(ListRelasi &LR, Peserta *P, int idKej, string namaKej) {
    Relasi *R = new Relasi;
    R->peserta = P;
    R->kejuaraan.id = idKej;
    R->kejuaraan.nama = namaKej;
    R->next = LR.first;
    LR.first = R;
}

void hapusRelasiPeserta(ListRelasi &LR, Peserta *P) {
    Relasi *cur = LR.first;
    Relasi *prev = NULL;

    while (cur != NULL) {
        if (cur->peserta == P) {
            if (prev == NULL)
                LR.first = cur->next;
            else
                prev->next = cur->next;

            Relasi *del = cur;
            cur = cur->next;
            delete del;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void hapusPeserta(ListPeserta &LP, int id, ListRelasi &LR) {
    Peserta *P = LP.first;
    Peserta *prev = NULL;

    while (P != NULL) {
        if (P->id == id) {
            hapusRelasiPeserta(LR, P);

            if (prev == NULL)
                LP.first = P->next;
            else
                prev->next = P->next;

            delete P;
            cout << "Peserta berhasil dihapus\n";
            return;
        }
        prev = P;
        P = P->next;
    }
    cout << "Peserta tidak ditemukan\n";
}

void tampilkanPesertaDenganKejuaraan(ListPeserta LP, ListRelasi LR) {
    Peserta *P = LP.first;
    while (P != NULL) {
        cout << P->nama << " mengikuti: ";
        Relasi *R = LR.first;
        bool ada = false;

        while (R != NULL) {
            if (R->peserta == P) {
                cout << R->kejuaraan.nama << " ";
                ada = true;
            }
            R = R->next;
        }

        if (!ada) cout << "-";
        cout << endl;
        P = P->next;
    }
}
