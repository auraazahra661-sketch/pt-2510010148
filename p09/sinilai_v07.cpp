// SiNilai v0.7: program v0.6 yang dipecah menjadi sembilan fungsi tanpa mengubah perilakunya.
// Data berpindah antarfungsi lewat parameter dan return. Variabel global tidak dipakai;
// yang ada di luar fungsi hanyalah konstanta bobot..
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Bobot penilaian (konstanta, tidak pernah berubah selama program berjalan).
const double BOBOT_HADIR = 0.10;
const double BOBOT_TUGAS = 0.45;
const double BOBOT_UTS = 0.25;
const double BOBOT_UAS = 0.20;

int bacaJumlah();
string bacaNama();
double bacaKomponen(string label);
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e);
void cetakSebaran(int a, int b, int c, int d, int e);

int main() {
    cout << "=== SiNilai v0.7 ===\n";
    int banyak_mhs = bacaJumlah();
    cout << fixed << setprecision(2);

    double jumlah_nilai = 0;
    int banyak_lulus = 0;
    int cacah_a = 0, cacah_b = 0, cacah_c = 0, cacah_d = 0, cacah_e = 0;
    double nilai_puncak = -1;
    string nama_puncak;

    for (int urut = 1; urut <= banyak_mhs; ++urut) {
        string nama, npm;
        double hadir = 0, tugas = 0, uts = 0, uas = 0;

        cout << "\n--- Mahasiswa ke-" << urut << " dari " << banyak_mhs << " ---\n";
        bacaData(nama, npm, hadir, tugas, uts, uas);

        double akhir = hitungNilaiAkhir(hadir, tugas, uts, uas);
        string mutu = hurufMutu(akhir);
        bool lulus = akhir >= 60;
        cetakBaris(nama, akhir, mutu, lulus);

        jumlah_nilai += akhir;
        if (lulus) {
            ++banyak_lulus;
        }
        perbaruiPenghitung(mutu[0], cacah_a, cacah_b, cacah_c, cacah_d, cacah_e);
        if (akhir > nilai_puncak) {
            nilai_puncak = akhir;
            nama_puncak = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << banyak_mhs << "\n";
    cout << "Lulus            : " << banyak_lulus << "\n";
    cout << "Belum lulus      : " << banyak_mhs - banyak_lulus << "\n";
    cout << "Rata-rata kelas  : " << jumlah_nilai / banyak_mhs << "\n";
    cout << "Tertinggi        : " << nama_puncak << " (" << nilai_puncak << ")\n";
    cetakSebaran(cacah_a, cacah_b, cacah_c, cacah_d, cacah_e);
    return 0;
}

// Membaca jumlah mahasiswa (bilangan bulat >= 1). Input salah ditolak dan diulang.
int bacaJumlah() {
    int n = 0;
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> n;
    while (cin.fail() || n < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Coba lagi: ";
        cin >> n;
    }
    cin.ignore(1000, '\n');
    return n;
}

// Membaca satu nilai 0..100. Huruf atau angka di luar rentang ditolak dan diulang.
double bacaKomponen(string label) {
    double angka = 0;
    cout << label << " : ";
    cin >> angka;
    while (cin.fail() || angka < 0 || angka > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 0 sampai 100. " << label << " : ";
        cin >> angka;
    }
    return angka;
}

// Membaca nama (tidak kosong, tanpa angka), lalu merapikannya menjadi Huruf Besar Di Awal Kata.
string bacaNama() {
    string teks;
    bool sah = false;
    while (!sah) {
        cout << "Nama      : ";
        getline(cin, teks);

        bool punya_huruf = false;
        bool punya_angka = false;
        for (char ch : teks) {
            if (ch != ' ') {
                punya_huruf = true;
            }
            if (isdigit(ch)) {
                punya_angka = true;
            }
        }

        if (!punya_huruf) {
            cout << "Nama tidak boleh kosong.\n";
        } else if (punya_angka) {
            cout << "Nama tidak boleh mengandung angka.\n";
        } else {
            sah = true;
        }
    }

    bool kata_baru = true;
    for (char& ch : teks) {
        if (ch == ' ') {
            kata_baru = true;
        } else {
            ch = kata_baru ? toupper(ch) : tolower(ch);
            kata_baru = false;
        }
    }
    return teks;
}

// Mengisi keenam variabel milik pemanggil lewat referensi; tidak ada return.
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas) {
    nama = bacaNama();
    cout << "NPM       : ";
    getline(cin, npm);
    kehadiran = bacaKomponen("Kehadiran ");
    mingguan = bacaKomponen("Mingguan  ");
    uts = bacaKomponen("UTS       ");
    uas = bacaKomponen("UAS       ");
    cin.ignore(1000, '\n');
}

double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas) {
    double hasil = kehadiran * BOBOT_HADIR;
    hasil += mingguan * BOBOT_TUGAS;
    hasil += uts * BOBOT_UTS;
    hasil += uas * BOBOT_UAS;
    return hasil;
}

// Mengubah nilai akhir menjadi huruf mutu. Setiap cabang langsung return.
string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 85) {
        return "A";
    }
    if (nilai_akhir >= 80) {
        return "B+";
    }
    if (nilai_akhir >= 75) {
        return "B";
    }
    if (nilai_akhir >= 70) {
        return "C+";
    }
    if (nilai_akhir >= 60) {
        return "C";
    }
    if (nilai_akhir >= 50) {
        return "D";
    }
    return "E";
}

void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus) {
    cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
         << "  " << left << setw(3) << huruf;
    cout << (lulus ? "Lulus\n" : "Belum lulus\n");
}

// a..e adalah referensi ke penghitung milik pemanggil, jadi perubahannya tersimpan di sana.
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e) {
    switch (awal) {
        case 'A': ++a; break;
        case 'B': ++b; break;
        case 'C': ++c; break;
        case 'D': ++d; break;
        default:  ++e; break;
    }
}

// Semua parameter pass by value karena fungsi ini hanya membaca.
void cetakSebaran(int a, int b, int c, int d, int e) {
    const char nama_huruf[5] = {'A', 'B', 'C', 'D', 'E'};
    const int jumlah[5] = {a, b, c, d, e};
    cout << "Sebaran huruf mutu:\n";
    for (int k = 0; k < 5; ++k) {
        cout << "  " << nama_huruf[k] << " : " << string(jumlah[k], '#')
             << " (" << jumlah[k] << ")\n";
    }
}
