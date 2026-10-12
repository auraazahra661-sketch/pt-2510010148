#include <iostream>
#include <string>
using namespace std;

int main() {

    // TODO 1: deklarasikan variabel untuk nama dan NPM.
    // Nama bisa lebih dari satu kata, jadi gunakan string.
    // NPM juga gunakan string karena bisa diawali angka 0.
    string nama;
    string npm;

    // TODO 2: deklarasikan empat variabel nilai.
    double kehadiran, mingguan, uts, uas, rerata;

    cout << "=== SiNilai v0.1 ===\n";

    cout << "Nama      : ";
    getline(cin, nama);

    // TODO 3: baca nama dengan getline karena nama bisa mengandung spasi.

    cout << "NPM       : ";
    cin >> npm;

    cout << "\n--- Input Nilai ---\n";

    cout << "Kehadiran : ";
    cin >> kehadiran;

    cout << "\n";

    cout << "Mingguan  : ";
    cin >> mingguan;

    cout << "\n";

    cout << "UTS       : ";
    cin >> uts;

    cout << "\n";

    cout << "UAS       : ";
    cin >> uas;

    cout << "\n";

    rerata = (kehadiran + mingguan + uts + uas) / 4.0;

    cout << "\n--- Kartu Data Mahasiswa ---\n";

    cout << "Nama      : " << nama << endl;
    cout << "NPM       : " << npm << endl;
    cout << "Kehadiran : " << kehadiran << endl;
    cout << "Mingguan  : " << mingguan << endl;
    cout << "UTS       : " << uts << endl;
    cout << "UAS       : " << uas << endl;
    cout << "Rerata    : " << rerata << endl;

    return 0;
}