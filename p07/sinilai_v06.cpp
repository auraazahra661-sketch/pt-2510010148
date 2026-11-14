// SiNilai v0.6: v0.5 yang tangguh terhadap masukan salah. Dibangun di atas v0.5 (laporan kelas).
// Yang baru: angka dibaca dengan aman (cin.fail, clear, ignore), nama divalidasi dan dirapikan
// huruf per huruf. Perhatikan: pola pembacaan aman ditulis berulang untuk empat komponen;
// itu sengaja, supaya di Pertemuan 9 kamu merasakan sendiri gunanya fungsi..
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const double PORSI_HADIR = 0.10;
    const double PORSI_TUGAS = 0.45;
    const double PORSI_UTS = 0.25;
    const double PORSI_UAS = 0.20;
    const double NILAI_MINIMAL_LULUS = 60;

    int n = 0;
    cout << "=== SiNilai v0.6 ===\n";
    cout << "Masukkan jumlah mahasiswa: ";
    while (!(cin >> n) || n < 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Input tidak valid. Masukkan jumlah mahasiswa: ";
    }
    // TODO 1: do-while di atas berputar tanpa henti kalau pengguna mengetik huruf (cin gagal, isi jadi 0).
    //         Ganti dengan pola input_aman.cpp: baca sekali, lalu while (cin.fail() || jumlah_mahasiswa < 1)
    //         { cin.clear(); cin.ignore(1000, '\n'); minta lagi; }.

    cin.ignore(1000, '\n'); // buang Enter yang tersisa setelah angka, supaya getline nama tidak memungutnya

    cout << fixed << setprecision(2);

    double akum_nilai = 0;
    int cacah_lulus = 0;
    string daftar_mutu = ""; // satu huruf per mahasiswa, dihitung saat laporan
    double nilai_max = -1;
    string nama_max;

    for (int idx = 0; idx < n; idx++)
    {
        string nama;
        string npm;
        double hadir = 0;
        double tugas = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << idx + 1 << " dari " << n << " ---\n";

        cout << "Nama      : ";
        getline(cin, nama);
        // TODO 2: bungkus pembacaan nama dengan do-while seperti validasi_nama.cpp: ulangi selama nama
        //         kosong atau hanya spasi, atau mengandung angka. Periksa huruf per huruf dengan for.
        bool benar;
        do
        {
            bool ada_alfabet = false;
            for (char ch : nama)
            {
                if (isalpha((unsigned char)ch))
                {
                    ada_alfabet = true;
                    break;
                }
            }
            bool ada_digit = nama.find_first_of("0123456789") != string::npos;

            benar = ada_alfabet && !ada_digit;
            if (!benar)
            {
                cout << "Nama tidak valid. Masukkan nama lagi: ";
                getline(cin, nama);
            }
        } while (!benar);
        // TODO 3: rapikan nama seperti rapikan_nama.cpp: huruf pertama tiap kata besar, sisanya kecil.
        char sebelumnya = ' ';
        for (char &ch : nama)
        {
            if (sebelumnya == ' ')
                ch = (char)toupper((unsigned char)ch);
            else
                ch = (char)tolower((unsigned char)ch);
            sebelumnya = ch;
        }

        cout << "NPM       : ";
        getline(cin, npm);

        // TODO 4: tambahkan while (cin.fail() || kehadiran < 0 || kehadiran > 100) { clear; ignore; minta lagi; }
        cout << "Kehadiran : ";
        while (!(cin >> hadir) || hadir < 0 || hadir > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Kehadiran tidak valid. Masukkan lagi: ";
        }

        cout << "Mingguan  : ";
        while (!(cin >> tugas) || tugas < 0 || tugas > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Mingguan tidak valid. Masukkan lagi: ";
        }

        cout << "UTS       : ";
        while (!(cin >> uts) || uts < 0 || uts > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "UTS tidak valid. Masukkan lagi: ";
        }

        cout << "UAS       : ";
        while (!(cin >> uas) || uas < 0 || uas > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "UAS tidak valid. Masukkan lagi: ";
        }
        // TODO 5: ulangi pola TODO 4 untuk mingguan, uts, dan uas (ya, empat kali; catat rasanya).

        cin.ignore(1000, '\n'); // buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih

        double akhir = hadir * PORSI_HADIR;
        akhir += tugas * PORSI_TUGAS;
        akhir += uts * PORSI_UTS;
        akhir += uas * PORSI_UAS;

        string predikat = (akhir >= 80)   ? "A"
                          : (akhir >= 75) ? "B+"
                          : (akhir >= 70) ? "B"
                          : (akhir >= 65) ? "C+"
                          : (akhir >= 60) ? "C"
                          : (akhir >= 40) ? "D"
                                          : "E";

        bool dinyatakan_lulus = akhir >= NILAI_MINIMAL_LULUS;

        cout << "  " << left << setw(20) << nama << right << setw(7) << akhir
             << "  " << left << setw(3) << predikat;
        if (dinyatakan_lulus)
            cout << "Lulus\n";
        else
            cout << "Belum lulus\n";

        akum_nilai += akhir;
        cacah_lulus += dinyatakan_lulus;
        daftar_mutu += predikat[0];

        if (akhir > nilai_max)
        {
            nilai_max = akhir;
            nama_max = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << n << "\n";
    cout << "Lulus            : " << cacah_lulus << "\n";
    cout << "Belum lulus      : " << n - cacah_lulus << "\n";
    cout << "Rata-rata kelas  : " << akum_nilai / n << "\n";
    cout << "Tertinggi        : " << nama_max << " (" << nilai_max << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char h = 'A'; h <= 'E'; h++)
    {
        int jumlah = (int)count(daftar_mutu.begin(), daftar_mutu.end(), h);
        cout << h << " | " << string(jumlah, '#') << " " << jumlah << "\n";
    }
    return 0;
}
