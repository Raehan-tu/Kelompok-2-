#include <iostream>
#include <string>
using namespace std;

const int MAX_KAMAR = 5;
int hargaSewa = 800000;

string namaPenyewa[MAX_KAMAR];
int lamaSewa[MAX_KAMAR];
int totalSewa = 0;

void tambahSewa() {
    if (totalSewa >= MAX_KAMAR) {
        cout << "Semua kamar sudah penuh!\n";
        return;
    }

    cout << "\n=== Tambah Penyewa Kos ===\n";
    cout << "Nama Penyewa : ";
    cin >> namaPenyewa[totalSewa];
    cout << "Harga Sewa per Bulan : " <<  hargaSewa << endl;
    cout << "Lama Sewa (bulan) : ";
    cin >> lamaSewa[totalSewa];

    totalSewa++;
    cout << "Data penyewa berhasil ditambahkan!\n";
}

void tampilkanSewa() {
    cout << "\n=== Daftar Penyewa Kos ===\n";
   
    for (int i = 0; i < totalSewa; i++) {
        int total = hargaSewa * lamaSewa[i];
        cout << i+1 << ". " << namaPenyewa[i] 
             << " - Rp " << hargaSewa 
             << "/bulan x " << lamaSewa[i] 
             << " bulan = Rp " << total << endl;
       
    }
}

void tampilkanpendapatan() {
    cout << "\n=== Total Pendapatan dari Sewa Kos ===\n";
    int totalpendapatan = 0;
    for (int i = 0; i < totalSewa ; i++) {
    totalpendapatan += hargaSewa * lamaSewa[i];

    }
    cout << "Total Pelanggan = " << totalSewa << endl;
    cout << "Total Pendapatan = Rp " << totalpendapatan << endl;
    
}

int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Sewa Kos ===\n";
        cout << "1. Tambah Penyewa\n";
        cout << "2. Tampilkan Data Penyewa & Harga \n";
        cout << "3. Tampilkan Total Pendapatan \n";
        cout << "4. Keluar \n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahSewa();
            break;
        case 2:
            tampilkanSewa();
            break;
        case 3:
            tampilkanpendapatan();
            break;
         case 4:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
