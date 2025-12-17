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
