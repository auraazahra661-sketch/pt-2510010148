// SiNilai v0.1: data satu mahasiswa.
// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.
// Lengkapi bagian TODO. Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.
#include <iostream>
#include <string>

using namespace std;

int main() {
    // TODO 1: deklarasikan variabel untuk nama dan NPM.
    //         Nama bisa lebih dari satu kata. NPM adalah deretan angka yang tidak pernah
    //         dihitung, dan bisa diawali 0, jadi pikirkan tipe yang tepat.
    string npm, nama;
    // TODO 2: deklarasikan empat variabel nilai: kehadiran, mingguan, uts, uas.
    //         Nilai bisa berisi pecahan seperti 85.5.
    double kehadiran, mingguan, uts, uas;
    cout << "=== SiNilai v0.1 ===\n";
    cout << "Nama      : ";
    // TODO 3: baca nama. Ingat, nama bisa mengandung spasi.
getline (cin, nama);
    cout << "NPM       : ";
    cin >> npm;
    cout << "kehadiran";
    cin >> kehadiran;
    cout << "mingguan";
    cin >> mingguan;
    cout << "uts";
    cin >> uts;
    cout << "uas";
    cin >> uas;

    // TODO 4: baca NPM.

    // TODO 5: baca keempat komponen nilai, satu per satu, dengan prompt seperti di atas.

    cout << "\n--- Kartu Data Mahasiswa ---\n";
    // TODO 6: tampilkan semua data yang tadi dibaca, satu baris per data, rata seperti prompt.
    cout << "Nama : " << nama; 
    cout << "Npm  : " << npm;
    cout << "Kehadiran : " << kehadiran;
    cout << "Mingguan : " << mingguan;
    cout << "uts : " << uts;
    cout << "uas : " << uas;
    return 0;
}
