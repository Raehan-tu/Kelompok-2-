#include <iostream>
#include <string>
using namespace std;

// Batas maksimal barang yang dapat disimpan
const int MAX_BRG = 10;

// Data barang
string nama[MAX_BRG];
double harga[MAX_BRG];
int stok[MAX_BRG];
int jumlah = 0;  // berapa banyak barang yang sudah diinput

// Data penjualan
int totalTerjual = 0;
double totalPendapatan = 0.0;

// Fungsi: menambah barang baru
void tambahBarang() {
    if (jumlah >= MAX_BRG) {
        cout << "Sudah penuh, tidak bisa tambah barang.\n";
        return;
    }
    cout << "\nTambah Barang\n";
    cout << "Nama barang: ";
    cin >> nama[jumlah];
    cout << "Harga: ";
    cin >> harga[jumlah];
    cout << "Stok: ";
    cin >> stok[jumlah];
    jumlah++;
    cout << "Barang telah ditambahkan.\n";
}

// Fungsi: pembelian
void beliBarang() {
    if (jumlah == 0) {
        cout << "Belum ada barang tersedia.\n";
        return;
    }
    cout << "\nPembelian\n";
    // tampilkan daftar barang
    for (int i = 0; i < jumlah; i++) {
        cout << (i+1) << ". " << nama[i]
             << " | Harga: " << harga[i]
             << " | Stok: " << stok[i] << "\n";
    }
    int pilih;
    cout << "Pilih nomor barang: ";
    cin >> pilih;
    if (pilih < 1 || pilih > jumlah) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    int idx = pilih - 1;
    int jumlahBeli;
    cout << "Jumlah yang ingin dibeli: ";
    cin >> jumlahBeli;
    if (jumlahBeli <= 0) {
        cout << "Jumlah harus lebih dari 0.\n";
        return;
    }
    if (jumlahBeli > stok[idx]) {
        cout << "Stok tidak cukup. Stok tersedia: " << stok[idx] << "\n";
        return;
    }
    // lakukan pembelian
    stok[idx] -= jumlahBeli;
    totalTerjual += jumlahBeli;
    totalPendapatan += harga[idx] * jumlahBeli;
    cout << "Pembelian berhasil. Total bayar: "
         << harga[idx] * jumlahBeli << "\n";
}

// Fungsi: update stok (menambah stok)
void tambahStok() {
    if (jumlah == 0) {
        cout << "Belum ada barang untuk di-update.\n";
        return;
    }
    cout << "\nUpdate Stok\n";
    for (int i = 0; i < jumlah; i++) {
        cout << (i+1) << ". " << nama[i]
             << " | Stok: " << stok[i] << "\n";
    }
    int pilih;
    cout << "Pilih nomor barang: ";
    cin >> pilih;
    if (pilih < 1 || pilih > jumlah) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    int idx = pilih - 1;
    int tambahan;
    cout << "Masukkan jumlah tambahan stok: ";
    cin >> tambahan;
    if (tambahan < 0) {
        cout << "Jumlah tambahan tidak boleh negatif.\n";
        return;
    }
    stok[idx] += tambahan;
    cout << "Stok telah diperbarui. Stok sekarang: " << stok[idx] << "\n";
}

// Fungsi: laporan penjualan & stok
void laporan() {
    cout << "\nLaporan\n";
    cout << "Total barang terjual: " << totalTerjual << "\n";
    cout << "Total pendapatan: Rp " << totalPendapatan << "\n";
    
    cout << "Stok kini:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << (i+1) << ". " << nama[i]
             << " | Stok: " << stok[i] << "\n";
    }
}

int main() {

    cout << "=== Sistem Penjualan Sederhana ===\n";
    int menu;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Beli Barang\n";
        cout << "3. Tambah Stok Barang\n";
        cout << "4. Laporan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> menu;

        switch (menu) {
            case 1:
                tambahBarang();
                break;
            case 2:
                beliBarang();
                break;
            case 3:
                tambahStok();
                break;
            case 4:
                laporan();
                break;
            case 5:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan salah. Silakan ulang.\n";
        }
    } while (menu != 5);

    cout << "Terima kasih telah menggunakan sistem ini.\n";

    
    return 0;
}