#include "kejuaraan.h"
#include <limits>
#include <iomanip>

void tampilkanMenu() {
    clearScreen();
    cout << "\n================================================" << endl;
    cout << "   SISTEM MANAJEMEN DATA KEJUARAAN (M to N)   " << endl;
    cout << "================================================" << endl;
    cout << "=== MENU UTAMA ===" << endl;
    cout << "1. Kelola Data Peserta" << endl;
    cout << "2. Kelola Data Kejuaraan" << endl;
    cout << "3. Kelola Relasi Peserta-Kejuaraan" << endl;
    cout << "4. Tampilkan Laporan" << endl;
    cout << "0. Keluar" << endl;
    cout << "================================================" << endl;
    cout << "Pilihan: ";
}


void menuPeserta(ListPeserta &LP, ListRelasi &LR) {
    int pilihan;
    do {
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
        cout << "================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1: {
                int id, umur;
                string nama, email;
                
                cout << "\nMasukkan ID Peserta: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Peserta: ";
                getline(cin, nama);
                cout << "Masukkan Email Peserta: ";
                getline(cin, email);
                cout << "Masukkan Umur Peserta: ";
                cin >> umur;
                
                insertFirstPeserta(LP, id, nama, email, umur);
                enterUntukLanjut();
                break;
            }
            
            case 2: {
                int id, umur;
                string nama, email;
                
                cout << "\nMasukkan ID Peserta: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Peserta: ";
                getline(cin, nama);
                cout << "Masukkan Email Peserta: ";
                getline(cin, email);
                cout << "Masukkan Umur Peserta: ";
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
                deleteLastPeserta(LP, LR);
                enterUntukLanjut();
                break;
            case 5: {
                int id;
                cout << "\nMasukkan ID Peserta yang akan dihapus: ";
                cin >> id;
                hapusPeserta(LP, id, LR);
                enterUntukLanjut();
                break;
            }
            
            case 6: {
                int id;
                cout << "\nMasukkan ID Peserta yang dicari: ";
                cin >> id;
                Peserta* P = cariPeserta(LP, id);
                if (P != NULL) {
                    cout << "\nPeserta ditemukan:" << endl;
                    cout << "ID: " << P->idPeserta << endl;
                    cout << "Nama: " << P->nama << endl;
                    cout << "Email: " << P->email << endl;
                    cout << "Umur: " << P->umur << endl;
                } else {
                    cout << "Peserta tidak ditemukan!" << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 7:
                tampilkanSemuaPeserta(LP);
                enterUntukLanjut();
                break;
                
            case 8:
                cout << "\nTotal Peserta: " << hitungTotalPeserta(LP) << endl;
                enterUntukLanjut();
                break;
                
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterUntukLanjut();
        }
    } while (pilihan != 0);
}

void menuKejuaraan(ListKejuaraan &LK, ListRelasi &LR) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader("KELOLA DATA KEJUARAAN");
        cout << "1. Tambah Kejuaraan di Awal (Insert First)" << endl;
        cout << "2. Tambah Kejuaraan di Akhir (Insert Last)" << endl;
        cout << "3. Hapus Kejuaraan di Awal (Delete First)" << endl;
        cout << "4. Hapus Kejuaraan di Akhir (Delete Last)" << endl;
        cout << "5. Hapus Kejuaraan Berdasarkan ID" << endl;
        cout << "6. Cari Kejuaraan Berdasarkan ID" << endl;
        cout << "7. Tampilkan Semua Kejuaraan" << endl;
        cout << "8. Hitung Total Kejuaraan" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1: {
                int id, tahun;
                string nama, kategori;
                
                cout << "\nMasukkan ID Kejuaraan: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Kejuaraan: ";
                getline(cin, nama);
                cout << "Masukkan Kategori Kejuaraan: ";
                getline(cin, kategori);
                cout << "Masukkan Tahun Kejuaraan: ";
                cin >> tahun;
                
                insertFirstKejuaraan(LK, id, nama, kategori, tahun);
                enterUntukLanjut();
                break;
            }
            
            case 2: {
                int id, tahun;
                string nama, kategori;
                
                cout << "\nMasukkan ID Kejuaraan: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Kejuaraan: ";
                getline(cin, nama);
                cout << "Masukkan Kategori Kejuaraan: ";
                getline(cin, kategori);
                cout << "Masukkan Tahun Kejuaraan: ";
                cin >> tahun;
                
                insertLastKejuaraan(LK, id, nama, kategori, tahun);
                enterUntukLanjut();
                break;
            }
            
            case 3:
                deleteFirstKejuaraan(LK, LR);
                enterUntukLanjut();
                break;
                
            case 4:
                deleteLastKejuaraan(LK, LR);
                enterUntukLanjut();
                break;
                
            case 5: {
                int id;
                cout << "\nMasukkan ID Kejuaraan yang akan dihapus: ";
                cin >> id;
                hapusKejuaraan(LK, id, LR);
                enterUntukLanjut();
                break;
            }
            
            case 6: {
                int id;
                cout << "\nMasukkan ID Kejuaraan yang dicari: ";
                cin >> id;
                Kejuaraan* K = cariKejuaraan(LK, id);
                if (K != NULL) {
                    cout << "\nKejuaraan ditemukan:" << endl;
                    cout << "ID: " << K->idKejuaraan << endl;
                    cout << "Nama: " << K->nama << endl;
                    cout << "Kategori: " << K->kategori << endl;
                    cout << "Tahun: " << K->tahun << endl;
                    cout << "Jumlah Peserta: " << K->jumlahPeserta << endl;
                } else {
                    cout << "Kejuaraan tidak ditemukan!" << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 7:
                tampilkanSemuaKejuaraan(LK);
                enterUntukLanjut();
                break;
                
            case 8:
                cout << "\nTotal Kejuaraan: " << hitungTotalKejuaraan(LK) << endl;
                enterUntukLanjut();
                break;
                
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterUntukLanjut();
        }
    } while (pilihan != 0);
}

void menuRelasi(ListPeserta &LP, ListKejuaraan &LK, ListRelasi &LR) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader("KELOLA RELASI PESERTA-KEJUARAAN");
        cout << "1. Buat Relasi (Peserta Ikut Kejuaraan)" << endl;
        cout << "2. Tampilkan Kejuaraan yang Diikuti Peserta" << endl;
        cout << "3. Tampilkan Peserta yang Mengikuti Kejuaraan" << endl;
        cout << "4. Hitung Jumlah Peserta dalam Kejuaraan" << endl;
        cout << "5. Hitung Jumlah Kejuaraan yang Diikuti Peserta" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1: {
                int idPeserta, idKejuaraan;
                string tanggal;
                
                cout << "\nMasukkan ID Peserta: ";
                cin >> idPeserta;
                cout << "Masukkan ID Kejuaraan: ";
                cin >> idKejuaraan;
                cin.ignore();
                cout << "Masukkan Tanggal Pendaftaran (YYYY-MM-DD): ";
                getline(cin, tanggal);
                
                Peserta* P = cariPeserta(LP, idPeserta);
                Kejuaraan* K = cariKejuaraan(LK, idKejuaraan);
                
                if (P && K) {
                    buatRelasi(LR, P, K, tanggal);
                } else {
                    cout << "Peserta atau Kejuaraan tidak ditemukan!" << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 2: {
                int id;
                cout << "\nMasukkan ID Peserta: ";
                cin >> id;
                Peserta* P = cariPeserta(LP, id);
                tampilkanKejuaraanPeserta(P, LR);
                enterUntukLanjut();
                break;
            }
            
            case 3: {
                int id;
                cout << "\nMasukkan ID Kejuaraan: ";
                cin >> id;
                Kejuaraan* K = cariKejuaraan(LK, id);
                tampilkanPesertaKejuaraan(K, LR);
                enterUntukLanjut();
                break;
            }
            
            case 4: {
                int id;
                cout << "\nMasukkan ID Kejuaraan: ";
                cin >> id;
                Kejuaraan* K = cariKejuaraan(LK, id);
                if (K != NULL) {
                    int jumlah = hitungJumlahPesertaKejuaraan(K, LR);
                    cout << "Jumlah peserta dalam kejuaraan " << K->nama << ": " << jumlah << endl;
                } else {
                    cout << "Kejuaraan tidak ditemukan!" << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 5: {
                int id;
                cout << "\nMasukkan ID Peserta: ";
                cin >> id;
                Peserta* P = cariPeserta(LP, id);
                if (P != NULL) {
                    int jumlah = hitungJumlahKejuaraanPeserta(P, LR);
                    cout << "Jumlah kejuaraan yang diikuti " << P->nama << ": " << jumlah << endl;
                } else {
                    cout << "Peserta tidak ditemukan!" << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterUntukLanjut();
        }
    } while (pilihan != 0);
}

void menuLaporan(ListPeserta &LP, ListKejuaraan &LK, ListRelasi &LR) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader("LAPORAN DAN ANALISIS");
        cout << "1. Tampilkan Semua Peserta dengan Kejuaraannya" << endl;
        cout << "2. Tampilkan Kejuaraan Paling Populer" << endl;
        cout << "3. Tampilkan Peserta dengan Kejuaraan Minimum" << endl;
        cout << "4. Tampilkan Statistik Sistem" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1:
                tampilkanPesertaDenganKejuaraan(LP, LR);
                enterUntukLanjut();
                break;
                
            case 2:
                tampilkanKejuaraanPopuler(LK, LR);
                enterUntukLanjut();
                break;
                
            case 3:
                tampilkanPesertaSedikitKejuaraan(LP, LR);
                enterUntukLanjut();
                break;
                
            case 4: {
                clearScreen();
                tampilkanHeader("STATISTIK SISTEM");
                cout << "Total Peserta: " << hitungTotalPeserta(LP) << endl;
                cout << "Total Kejuaraan: " << hitungTotalKejuaraan(LK) << endl;
                
                // Hitung total relasi
                int totalRelasi = 0;
                Relasi* R = LR.first;
                while (R != NULL) {
                    totalRelasi++;
                    R = R->next;
                }
                cout << "Total Relasi: " << totalRelasi << endl;
                
                // Rata-rata kejuaraan per peserta
                if (hitungTotalPeserta(LP) > 0) {
                    float rata2 = (float)totalRelasi / hitungTotalPeserta(LP);
                    cout << "Rata-rata kejuaraan per peserta: " << fixed << setprecision(2) << rata2 << endl;
                }
                enterUntukLanjut();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterUntukLanjut();
        }
    } while (pilihan != 0);
}

int main() {
    ListPeserta LP;
    ListKejuaraan LK;
    ListRelasi LR;
    
    createListPeserta(LP);
    createListKejuaraan(LK);
    createListRelasi(LR);
    
    // Data dummy untuk contoh
    insertLastPeserta(LP, 101, "Andi Wijaya", "andi@email.com", 21);
    insertLastPeserta(LP, 102, "Budi Santoso", "budi@email.com", 22);
    insertFirstPeserta(LP, 103, "Citra Dewi", "citra@email.com", 20);
    insertLastPeserta(LP, 104, "Dewi Anggraini", "dewi@email.com", 23);
    
    insertFirstKejuaraan(LK, 201, "Lomba Programming Nasional", "Teknologi", 2024);
    insertLastKejuaraan(LK, 202, "Lomba UI/UX Design", "Desain", 2024);
    insertFirstKejuaraan(LK, 203, "Lomba Data Science", "Analisis Data", 2024);
    insertLastKejuaraan(LK, 204, "Lomba Robotik", "Robotika", 2024);
    
    // Buat beberapa relasi
    Peserta* P1 = cariPeserta(LP, 101);
    Peserta* P2 = cariPeserta(LP, 102);
    Peserta* P3 = cariPeserta(LP, 103);
    Kejuaraan* K1 = cariKejuaraan(LK, 201);
    Kejuaraan* K2 = cariKejuaraan(LK, 202);
    Kejuaraan* K3 = cariKejuaraan(LK, 203);
    Kejuaraan* K4 = cariKejuaraan(LK, 204);
    
    if (P1 && K1) buatRelasi(LR, P1, K1, "2024-01-15");
    if (P1 && K2) buatRelasi(LR, P1, K2, "2024-01-20");
    if (P2 && K1) buatRelasi(LR, P2, K1, "2024-01-18");
    if (P3 && K3) buatRelasi(LR, P3, K3, "2024-01-22");
    if (P3 && K4) buatRelasi(LR, P3, K4, "2024-01-25");
    
    int pilihan;
    bool running = true;
    
    while (running) {
        tampilkanMenu();
        cin >> pilihan;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1:
                menuPeserta(LP, LR);
                break;
                
            case 2:
                menuKejuaraan(LK, LR);
                break;
                
            case 3:
                menuRelasi(LP, LK, LR);
                break;
                
            case 4:
                menuLaporan(LP, LK, LR);
                break;
                
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!" << endl;
                cout << "Program selesai." << endl;
                running = false;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterUntukLanjut();
        }
    }
    
    return 0;
}
