# Catatan Kesalahan Praktikum 5

## Tabel Ringkasan Kesalahan

| No | Berkas | Kategori Kesalahan | Pesan Error yang Muncul | Penyebab | Cara Memperbaiki |
|---|---|---|---|---|---|
| 1 | `k1_sintaks.cpp` | Error Sintaks | `expected ',' or ';' before 'std'`, `unused variable 'nilai'` | Deklarasi variabel `int nilai = 80` tidak diakhiri tanda titik koma, dan variabel tersebut tidak pernah dipakai di kode | Tambahkan `;` setelah `int nilai = 80`, lalu pastikan variabel `nilai` benar-benar dipakai dalam proses perhitungan (atau hapus jika memang tidak diperlukan) |
| 2 | `k2_nama.cpp` | Error Penamaan Variabel | `'Nilai' was not declared in this scope; did you mean 'nilai'`, `'bonus' was not declared in this scope` | Penulisan nama variabel tidak konsisten (`Nilai` vs `nilai`, huruf besar-kecil berpengaruh di C++), serta variabel `bonus` dipakai tanpa dideklarasikan terlebih dahulu | Samakan penulisan menjadi `nilai` di seluruh kode, dan tambahkan deklarasi untuk variabel `bonus` sebelum digunakan |
| 3 | `k3_runtime.cpp` | Error Logika (Runtime) | Terjadi pembagian dengan nol saat input jumlah mahasiswa bernilai 0 | Kode tidak memvalidasi input sebelum melakukan operasi pembagian | Tambahkan pengecekan kondisi `jumlah_mahasiswa == 0` sebelum melakukan pembagian, misalnya dengan memberi peringatan atau menghentikan proses jika nilainya nol |
| 4 | `k4_logika.cpp` | Error Logika | Hasil program dibulatkan menjadi `81`, padahal seharusnya `81.67` | Pembagian dilakukan dengan angka `3` (bertipe integer), sehingga hasilnya ikut dibulatkan ke integer | Ubah pembagi menjadi `3.0` (bertipe desimal/float) agar hasil pembagian tetap presisi |

## Kesimpulan

Dari praktikum ini, saya menilai bahwa error logika adalah jenis kesalahan yang paling perlu diwaspadai. Berbeda dengan error sintaks atau error penamaan variabel yang langsung terdeteksi saat kompilasi, error logika membuat program tetap berjalan dan tampak normal, tetapi menghasilkan output yang keliru tanpa disertai pesan kesalahan apa pun. Karena itu, proses debugging tidak cukup hanya sampai program berhasil dikompilasi dan dieksekusi — hasil akhir dan alur logika program juga wajib diperiksa serta diuji secara cermat untuk memastikan kebenarannya.
