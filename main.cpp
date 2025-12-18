#include "kejuaraan.h"
#include <limits>
#include <iomanip>

void tampilkanMenu() {
    clearScreen();
    cout << "\n================================================" << endl;
    cout << "   SISTEM MANAJEMEN DATA KEJUARAAN   " << endl;
    cout << "================================================" << endl;
    cout << "=== MENU UTAMA ===" << endl;
    cout << "1. Kelola Data Peserta (Double Circular List)" << endl;
    cout << "2. Kelola Data Kejuaraan (Single Linked List)" << endl;
    cout << "3. Kelola Relasi Peserta-Kejuaraan" << endl;
    cout << "4. Tampilkan Laporan" << endl;
    cout << "0. Keluar" << endl;
    cout << "================================================" << endl;
    cout << "Pilihan: ";
}

void menuPeserta(ListPeserta &LP, ListRelasi &LR) {
    int pilihan;
    do{
        clearScreen();
        tampilkanHeader("KELOLA DATA PESERTA");
        cout << "1. Tambah Peserta di Awal" << endl;
        cout << "2. Tambah Peserta di Akhir" << endl;
        cout << "3. Hapus Peserta di Awal" << endl;
        cout << "4. Hapus Peserta di Akhir" << endl;
        cout << "5. Hapus Peserta Berdasarkan ID" << endl;
        cout << "6. Cari Peserta Berdasarkan ID" << endl;
        cout << "7. Tampilkan Semua Peserta" << endl;
        cout << "8. Hitung Total Peserta" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "==========================================" << endl;
        cout << "PilihanL ";
        cin >> pilihan;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: {
                int id, umur:
                string nama, email;

                cout >> "\nMasukkan ID Peserta: ";
                cin >> idl
                cin.ignore();
                cout << "Masukkan Nama Peserta: ";
                getline(cin, nama);
                cout << ("Masukkan Email Peserta: ";
                getline(cin, email);
                cout << ("Masukkan Umur Peserta: ";
                cin >> umur;

                insertFirstPeserta(LP, id, nama, email, umur);
                enterUntukLanjut();
                break;
            }

                case 2: {
                    int id, umur;
                    string nama, email;

                    cout >> "\nMasukkan ID Peserta: ";
                    cin >> idl
                    cin.ignore();
                    cout << "Masukkan Nama Peserta: ";
                    getline(cin, nama);
                    cout << ("Masukkan Email Peserta: ";
                    getline(cin, email);
                    cout << ("Masukkan Umur Peserta: ";
                    cin >> umur;

                    insertLastPeserta(LP, id, nama, email, umur);
                    enterUntukLanjut();
                    break;
                    }

                    case 3: 
                        deleteFirstPeserta(LP, LR);
                        enterUntukLanjut();
                        break;

                        case 4:
                    
}

