#include <iostream>
#include <string>
using namespace std;

const int MAX_BARANG = 5;


string namaBarang[MAX_BARANG];
int hargaBarang[MAX_BARANG];
int jumlahBarang[MAX_BARANG];
int totalBarang = 0;


void tambahBarang() {
    if (totalBarang >= MAX_BARANG) {
        cout << "Barang sudah penuh!\n";
        return;
    }

    cout << "\n=== Tambah Barang ===\n";
    cout << "Nama Barang  : ";
    cin >> namaBarang[totalBarang];
    cout << "Harga Barang : ";
    cin >> hargaBarang[totalBarang];
    cout << "Jumlah Beli  : ";
    cin >> jumlahBarang[totalBarang];

    totalBarang++;
    cout << "Barang berhasil ditambahkan!\n";
}


void tampilkanBarang() {
    cout << "\n=== Daftar Barang ===\n";
    int totalBayar = 0;

    for (int i = 0; i < totalBarang; i++) {
        int subtotal = hargaBarang[i] * jumlahBarang[i];
        cout << i+1 << ". " << namaBarang[i] << " - Rp " 
             << hargaBarang[i] << " x " << jumlahBarang[i]
             << " = Rp " << subtotal << endl;
        totalBayar += subtotal;
    }

    cout << "\nTotal Bayar: Rp " << totalBayar << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Kasir ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Daftar Belanja & Total\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;
        case 2:
            tampilkanBarang();
            break;
        case 3:
            cout << "Terima kasih telah menggunakan Sistem Kasir!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}
