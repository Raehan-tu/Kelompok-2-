 #include <iostream>
using namespace std;

 struct Dosen{
        int GajiPokok;
        int TunjanganIstri;
        int TunjanganAnak;
        int Iuran;
        float GajiBersih;
        float Pajak;
        float BPJS;
    };

int main() {
    Dosen GajiDosen;
    
    GajiDosen.GajiPokok = 3500000;
    GajiDosen.TunjanganIstri = 300000;
    GajiDosen.TunjanganAnak = 250000;
    GajiDosen.Iuran = 200000;
    GajiDosen.Pajak = 0.05;
    GajiDosen.BPJS = 0.01;
    
    int GajiKotor = GajiDosen.GajiPokok + GajiDosen.TunjanganIstri + GajiDosen.TunjanganAnak;
    int Iuran = GajiDosen.Iuran;
    float PajakPenghasilan = GajiKotor * GajiDosen.Pajak;
    float BPJSPenghasilan = GajiKotor * GajiDosen.BPJS;
    
    int GajiBersih = GajiKotor - PajakPenghasilan - BPJSPenghasilan - Iuran;


    
    cout << "Gaji Pokok/Bulan            : Rp " << GajiDosen.GajiPokok << endl;
    cout << "Tunjangan Istri             : Rp " << GajiDosen.TunjanganIstri << endl;
    cout << "Tunjangan Anak              : Rp " << GajiDosen.TunjanganAnak << endl;
    cout << "Gaji Kotor                  : Rp " << GajiKotor << endl;
    cout << "-----------------------------------------------\n";
    cout << "Iuran/Bulan                 : Rp " << GajiDosen.Iuran << endl;
    cout << "Pajak 5%                    : Rp " << PajakPenghasilan << endl;
    cout << "BPJS  1%                    : Rp " << BPJSPenghasilan  << endl;
    cout << "-----------------------------------------------\n";
    cout << "Total Gaji Bersih/Bulan     : Rp " << GajiBersih << endl; 
    
    return 0;
}