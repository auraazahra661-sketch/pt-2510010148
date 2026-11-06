## Deklarasi AI

AI yang digunakan: GitHub Copilot.

Prompt: "Untuk TODO 4 di `sinilai_v06_awal.cpp`, bagaimana alur `cin.fail()`, `cin.clear()`, dan `cin.ignore()` membuat pembacaan nilai dapat diulang setelah pengguna memasukkan teks yang bukan angka?"

Umpan balik AI: Periksa `cin.fail()` bersama batas nilai. Jika ekstraksi gagal atau nilai di luar 0–100, pulihkan stream dengan `cin.clear()`, buang sisa baris menggunakan `cin.ignore(1000, '\n')`, lalu minta input lagi. Saya menguji pola ini dengan masukan teks dan nilai di luar rentang.
_// TODO 5: ulangi pola TODO 4 untuk mingguan, uts, dan uas (ya, empat kali; catat rasanya)._

        cin.ignore(1000, '\n'); *// buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih*

        double nilai_akhir = kehadiran \* BOBOT_KEHADIRAN + mingguan \* BOBOT_MINGGUAN + uts \* BOBOT_UTS + uas \* BOBOT_UAS;

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

periksa apakah ada yang salah

# Hasil :

Saya periksa kode SiNilai v0.6 kamu. Secara umum, struktur programnya sudah benar: menghitung nilai akhir, menentukan huruf mutu, menentukan kelulusan, mencari nilai tertinggi, dan membuat laporan kelas. Namun, ada beberapa hal yang perlu diperbaiki, terutama pada validasi input dan penghitungan sebaran huruf mutu.

## 1. Kesalahan dan kekurangan yang ditemukan

1. Validasi jumlah mahasiswa — TODO 1

Kode kamu sebenarnya sudah bisa menangani input huruf karena menggunakan `cin.fail()`, `cin.clear()`, dan `cin.ignore()`. Namun, bentuknya belum mengikuti pola yang diminta pada TODO 1, yaitu membaca sekali lalu menggunakan `while`.

Perbaikannya:

C++

```
cout << "Jumlah mahasiswa (paling sedikit 1): ";
cin >> jumlah_mahasiswa;

while (cin.fail() || jumlah_mahasiswa < 1)
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Input tidak valid. Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;
}
```

Dengan pola ini, input diminta ulang sampai berupa bilangan bulat minimal 1.

2. Validasi nama — TODO 2

Kode kamu hanya memeriksa apakah nama kosong atau mengandung angka. Ada dua kekurangan:

- Nama yang berisi spasi saja masih diterima.

- Nama yang mengandung simbol seperti `@`, `#`, atau `123` dalam bentuk campuran simbol dan huruf masih bisa diterima.

Untuk memperbaiki masalah spasi, kamu bisa menggunakan `isspace()` untuk memeriksa apakah nama hanya berisi spasi. Untuk validasi yang lebih ketat, izinkan huruf, spasi, tanda hubung, dan apostrof saja.

Contoh validasi sederhana yang lebih baik:

C++

```
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
```

Catatan: kode ini tetap mengizinkan simbol selain angka jika ada huruf dalam nama. Jika ingin validasi yang benar-benar ketat, perlu pemeriksaan karakter tambahan.

3. Merapikan nama — TODO 3

Logikanya sudah benar. Nama seperti `aKbar mUhammad` akan menjadi `Akbar Muhammad`.

Namun, penggunaan `toupper()` dan `tolower()` untuk huruf UTF-8 seperti `é` atau karakter beraksen lainnya tidak sepenuhnya didukung oleh pendekatan ini. Untuk nama biasa dengan huruf ASCII, kode kamu sudah cukup.

4. Validasi nilai kehadiran, mingguan, UTS, dan UAS — TODO 4 dan 5

Pola validasi kamu sudah benar secara umum. Akan tetapi, ketika pengguna memasukkan angka yang valid diikuti karakter lain, seperti `80abc`, `cin >> kehadiran` dapat membaca `80` sebagai angka yang valid dan meninggalkan `abc` di input.

Selain itu, input seperti `nan` atau `inf` perlu ditangani agar tidak menghasilkan nilai akhir yang tidak valid. Kamu bisa menambahkan `isfinite()` dari `<cmath>`.

Contoh:

C++

```
#include <cmath>
```

Lalu gunakan pola ini untuk setiap komponen nilai:

C++

```
cout << "Kehadiran : ";
cin >> kehadiran;

while (cin.fail() || !isfinite(kehadiran) ||
       kehadiran < 0 || kehadiran > 100)
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Kehadiran tidak valid. Masukkan lagi: ";
    cin >> kehadiran;
}
```

Ulangi pola yang sama untuk `mingguan`, `uts`, dan `uas`. Jika ingin menolak seluruh input yang mengandung karakter tambahan, gunakan pembacaan satu baris dan parsing angka secara terpisah.

5. Sebaran huruf mutu — bagian `switch`

Ini bagian yang paling perlu diperhatikan.

Kode kamu:

C++

```
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
```

Masalahnya, nilai `B+` masuk ke `jumlah_b`, tetapi nilai `C+` masuk ke `jumlah_c`. Itu sebenarnya sesuai jika kategori laporan memang hanya A, B, C, D, dan E.

Namun, laporan kamu sekarang menampilkan `A`, `B`, `C`, `D`, `E` saja. Jadi, jika tugas meminta sebaran berdasarkan huruf mutu lengkap (`A`, `B+`, `B`, `C+`, `C`, `D`, `E`), program belum memenuhi kebutuhan tersebut.

Jika kategori memang dikelompokkan berdasarkan huruf awal, kode kamu sudah benar. Jika ingin menghitung setiap nilai mutu secara terpisah, gunakan variabel dan kondisi berdasarkan string lengkap.

6. Perhitungan nilai akhir dan status kelulusan

Bagian ini sudah benar:

C++

```
double nilai_akhir =
    kehadiran * BOBOT_KEHADIRAN +
    mingguan * BOBOT_MINGGUAN +
    uts * BOBOT_UTS +
    uas * BOBOT_UAS;

bool lulus = nilai_akhir >= 60;
```

Total bobotnya adalah 0.10+0.45+0.25+0.20=1.000.10 + 0.45 + 0.25 + 0.20 = 1.000.10+0.45+0.25+0.20=1.00, sehingga perhitungan nilai akhir sudah sesuai.

7. Kartu nilai satu baris

Kode berikut sudah sesuai dengan format yang kamu gunakan:

C++

```
cout << "  " << left << setw(20) << nama
     << right << setw(7) << nilai_akhir
     << "  " << left << setw(3) << huruf_mutu;
```

Status kelulusan juga sudah ditampilkan dengan benar setelahnya.

## 2. Catatan penting tentang laporan kelas

Perulangan berikut:

C++

```
for (char huruf = 'A'; huruf <= 'E'; huruf++)
```

akan menghasilkan kategori A sampai E. Kode ini tidak menampilkan kategori `B+` dan `C+` secara terpisah. Jika tugas meminta kategori lengkap, kamu perlu mengubah variabel penghitung dan bagian laporan kelas juga.

## 3. Kesimpulan

| Bagian                        | Status                                           |
| ----------------------------- | ------------------------------------------------ |
| Input jumlah mahasiswa        | Perlu disesuaikan dengan TODO 1                  |
| Validasi nama                 | Perlu diperketat                                 |
| Perapian nama                 | Benar untuk huruf ASCII                          |
| Validasi nilai                | Perlu menangani `nan`, `inf`, dan input campuran |
| Perhitungan nilai akhir       | Benar                                            |
| Penentuan huruf mutu          | Benar                                            |
| Penentuan kelulusan           | Benar                                            |
| Kartu nilai satu baris        | Benar                                            |
| Penghitungan sebaran huruf    | Benar jika kategori berdasarkan huruf awal       |
| Rata-rata dan nilai tertinggi | Benar untuk input nilai yang valid               |

Saran saya: karena program ini disebut v0.6 yang berfokus pada ketahanan terhadap masukan salah, prioritas utamanya adalah memastikan semua input divalidasi dengan konsisten. Setelah itu, tentukan apakah laporan sebaran huruf mutu harus mengelompokkan `B+` bersama `B` dan `C+` bersama `C`, atau menampilkan semuanya secara terpisah.
