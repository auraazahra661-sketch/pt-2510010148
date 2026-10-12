# P01 Dasar C++ dan Rata-Rata

Folder ini berisi contoh program C++ awal dan catatan kesalahan praktikum.

## Isi

| Berkas                 | Kegunaan                                                                          |
| ---------------------- | --------------------------------------------------------------------------------- |
| `hello.cpp`            | Program pertama untuk mencetak teks ke terminal                                   |
| `rerata.cpp`           | Menghitung jumlah dan rata-rata tiga nilai; latihan tipe data dan presisi pecahan |
| `catatan_kesalahan.md` | Ringkasan kesalahan sintaks, penamaan variabel, runtime, dan logika               |

## Deklarasi AI

AI yang digunakan: GitHub Copilot.

Prompt: "Di `rerata.cpp`, mengapa menghitung rata-rata dengan `jumlah / 3` dapat menghilangkan bagian pecahan, dan bagaimana memperbaikinya?"

Umpan balik AI: Jika `jumlah` dan pembaginya bertipe integer, pembagian akan membuang pecahan. Gunakan pembagi desimal seperti `3.0` agar operasi menghasilkan nilai pecahan, lalu simpan hasilnya pada variabel `double`. Saya membandingkan hasilnya dengan tiga nilai contoh.
