#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Barang {
    string namabarang;
    float hargaperunit;
    int jumlahterjual;
    float totalpendapatan;
};

vector<Barang> penjualan;

void tambahpenjualan() {
    char lagi;
    do {
        Barang barang;
        cout << "\nNama barang:";
        cin >> barang.namabarang;
        cout << "Harga per barang: ";
        cin >> barang.hargaperunit;
        cout << "Jumlah barang terjual: ";
        cin >> barang.jumlahterjual;
        
        barang.totalpendapatan = barang.hargaperunit * barang.jumlahterjual;
        
        penjualan.push_back(barang);
        
        cout << "Apakah ingin memasukkan data penjualan lagi? (Y/N) : ";
        cin >> lagi;
    } while (lagi == 'Y' || lagi == 'y');
}

void tampilkanlaporan() {
    cout << "\n=========================================================================================================\n";
    cout << "                                     DAFTAR PENJUALAN BARANG                                               \n";
    cout << "=========================================================================================================" << endl;
    cout << setw(4) << "No" << setw(20) << "Nama Barang" << setw(20) << "Harga per Barang" << setw(20) << "Jumlah Terjual" << setw(20) << "Total Pendapatan" << endl;
    cout << "=========================================================================================================" << endl;
    
    float totalkeseluruhan = 0;
    for (int i = 0; i < penjualan.size(); i++) {
        cout << setw(4) << i + 1 << setw(20) << penjualan[i].namabarang << setw(20) << fixed << setprecision(2) << penjualan[i].hargaperunit << setw(20) << penjualan[i].jumlahterjual << setw(28) << fixed << setprecision(2) << penjualan[i].totalpendapatan << endl;
        totalkeseluruhan += penjualan[i].totalpendapatan;
    }
    
    cout << "=========================================================================================================" << endl;
    cout << setw(60) << "Total Pendapatan Keseluruhan: Rp " << fixed << setprecision(2) << totalkeseluruhan << endl;
}

int main() {
    cout << "❦︎❦︎❦︎ Total Pendapatan Penjualan Barang❦︎❦︎❦︎\n" << endl;
    tambahpenjualan();
    tampilkanlaporan();
    
    return 0;
}
