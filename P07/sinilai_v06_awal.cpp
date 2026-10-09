// SiNilai v0.6: v0.5 yang tangguh terhadap masukan salah. Dibangun di atas v0.5 (laporan kelas).
// Yang baru: angka dibaca dengan aman (cin.fail, clear, ignore), nama divalidasi dan dirapikan
// huruf per huruf. Perhatikan: pola pembacaan aman ditulis berulang untuk empat komponen;
// itu sengaja, supaya di Pertemuan 9 kamu merasakan sendiri gunanya fungsi.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.6 ===\n";
    while (cin.fail() || jumlah_mahasiswa < 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Input tidak valid. Masukkan jumlah mahasiswa: ";
        cin >> jumlah_mahasiswa;
    }
    // TODO 1: do-while di atas berputar tanpa henti kalau pengguna mengetik huruf (cin gagal, isi jadi 0).
    //         Ganti dengan pola input_aman.cpp: baca sekali, lalu while (cin.fail() || jumlah_mahasiswa < 1)
    //         { cin.clear(); cin.ignore(1000, '\n'); minta lagi; }.

    cin.ignore(1000, '\n'); // buang Enter yang tersisa setelah angka, supaya getline nama tidak memungutnya

    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++)
    {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";

        cout << "Nama      : ";
        getline(cin, nama);
        // TODO 2: bungkus pembacaan nama dengan do-while seperti validasi_nama.cpp: ulangi selama nama
        //         kosong atau hanya spasi, atau mengandung angka. Periksa huruf per huruf dengan for.
        bool valid;

        do
        {
            valid = !nama.empty();
            bool ada_huruf = false;

            for (unsigned char c : nama)
            {
                if (isalpha(c))
                    ada_huruf = true;

                if (isdigit(c))
                    valid = false;
            }

            if (!ada_huruf)
                valid = false;

            if (!valid)
            {
                cout << "Nama tidak valid. Masukkan nama lagi: ";
                getline(cin, nama);
            }

        } while (!valid);
        // TODO 3: rapikan nama seperti rapikan_nama.cpp: huruf pertama tiap kata besar, sisanya kecil.
        int panjang = nama.length();
        bool awal_kata = true;
        for (int i = 0; i < panjang; i++)
        {
            if (nama[i] == ' ')
            {
                awal_kata = true;
            }
            else if (awal_kata)
            {
                nama[i] = toupper(nama[i]);
                awal_kata = false;
            }
            else
            {
                nama[i] = tolower(nama[i]);
            }
        }

        cout << "NPM       : ";
        getline(cin, npm);

        cout << "Kehadiran : ";
        cin >> kehadiran;
        // TODO 4: tambahkan while (cin.fail() || kehadiran < 0 || kehadiran > 100) { clear; ignore; minta lagi; }
        while (cin.fail() || kehadiran < 0 || kehadiran > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Kehadiran tidak valid. Masukkan lagi: ";
            cin >> kehadiran;
        }
        cout << "Mingguan  : ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0 || mingguan > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Mingguan tidak valid. Masukkan lagi: ";
            cin >> mingguan;
        }
        cout << "UTS       : ";
        cin >> uts;
        while (cin.fail() || uts < 0 || uts > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "UTS tidak valid. Masukkan lagi: ";
            cin >> uts;
        }
        cout << "UAS       : ";
        cin >> uas;
        while (cin.fail() || uas < 0 || uas > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "UAS tidak valid. Masukkan lagi: ";
            cin >> uas;
        }
        // TODO 5: ulangi pola TODO 4 untuk mingguan, uts, dan uas (ya, empat kali; catat rasanya).

        cin.ignore(1000, '\n'); // buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih

        double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN + uts * BOBOT_UTS + uas * BOBOT_UAS;

        string huruf_mutu;
        if (nilai_akhir >= 80)
        {
            huruf_mutu = "A";
        }
        else if (nilai_akhir >= 75)
        {
            huruf_mutu = "B+";
        }
        else if (nilai_akhir >= 70)
        {
            huruf_mutu = "B";
        }
        else if (nilai_akhir >= 65)
        {
            huruf_mutu = "C+";
        }
        else if (nilai_akhir >= 60)
        {
            huruf_mutu = "C";
        }
        else if (nilai_akhir >= 40)
        {
            huruf_mutu = "D";
        }
        else
        {
            huruf_mutu = "E";
        }

        bool lulus = nilai_akhir >= 60;

        cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu;
        if (lulus)
        {
            cout << "Lulus\n";
        }
        else
        {
            cout << "Belum lulus\n";
        }

        total_nilai += nilai_akhir;
        if (lulus)
        {
            jumlah_lulus++;
        }

        switch (huruf_mutu[0])
        {
        case 'A':
            jumlah_a++;
            break;
        case 'B':
            jumlah_b++;
            break;
        case 'C':
            jumlah_c++;
            break;
        case 'D':
            jumlah_d++;
            break;
        default:
            jumlah_e++;
        }

        if (nilai_akhir > nilai_tertinggi)
        {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++)
    {
        int banyak = 0;
        if (huruf == 'A')
        {
            banyak = jumlah_a;
        }
        else if (huruf == 'B')
        {
            banyak = jumlah_b;
        }
        else if (huruf == 'C')
        {
            banyak = jumlah_c;
        }
        else if (huruf == 'D')
        {
            banyak = jumlah_d;
        }
        else
        {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";
        for (int j = 1; j <= banyak; j++)
        {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
    return 0;
}
