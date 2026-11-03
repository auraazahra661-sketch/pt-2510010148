// UTS Praktikum Paket B: Fotokopi Kampus.
// Lengkapi TODO 1 sampai TODO 6 sesuai lembar soal. Bagian yang sudah ada jangan diubah kecuali diminta.
// Bangun dengan baseline kelas; program harus bebas warning. Uji dengan: ./fotokopi < contoh_masukan.txt
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int HARGA_KECIL = 300;     // 1 sampai 50 halaman
    const int HARGA_SEDANG = 250;    // 51 sampai 200 halaman
    const int HARGA_BESAR = 200;     // lebih dari 200 halaman
    const int BATAS_KECIL = 50;
    const int BATAS_SEDANG = 200;
    const int MAKS_HALAMAN = 1000;

    int jumlah = 0;
    cout << "=== Fotokopi Kampus ===\n";
    cout << "Jumlah pesanan: ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {           // contoh pembacaan aman; pakai pola ini untuk halaman
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah pesanan: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total_halaman = 0;
    int total_pendapatan = 0;
    int banyak_kecil = 0;
    int banyak_sedang = 0;
    int banyak_besar = 0;
    // TODO 5a: deklarasikan penampung biaya terbesar (mulai -1) dan nama pemesannya.
    int biaya_terbesar = -1;
    string nama_terbesar;

    for (int i = 1; i <= jumlah; i++) {
        string nama;
        int halaman = 0;
        char warna = ' ';

        cout << "\n--- Pesanan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca nama dengan getline sampai sah (tidak kosong atau hanya spasi, dan tanpa angka),
        //         lalu rapikan menjadi Huruf Besar Di Awal Kata.
        //         Pesan penolakan: "Nama tidak boleh kosong." dan "Nama tidak boleh mengandung angka."
        cout << "Nama pemesan : ";
        getline(cin, nama);
        while (cin.good()) {
            if (nama.find_first_not_of(" \t") == string::npos) {
                cout << "Nama tidak boleh kosong.\n";
            } else {
                bool ada_angka = false;
                for (size_t k = 0; k < nama.size(); k++) {
                    if (isdigit(static_cast<unsigned char>(nama[k]))) {
                        ada_angka = true;
                    }
                }
                if (!ada_angka) {
                    break;
                }
                cout << "Nama tidak boleh mengandung angka.\n";
            }
            cout << "Nama pemesan : ";
            getline(cin, nama);
        }
        bool awal_kata = true;
        for (size_t k = 0; k < nama.size(); k++) {
            unsigned char c = static_cast<unsigned char>(nama[k]);
            if (isspace(c)) {
                awal_kata = true;
            } else if (awal_kata) {
                nama[k] = static_cast<char>(toupper(c));
                awal_kata = false;
            } else {
                nama[k] = static_cast<char>(tolower(c));
            }
        }

        // TODO 2: baca halaman dengan aman (bilangan bulat 1 sampai MAKS_HALAMAN), pola seperti jumlah di atas.
        //         Pesan penolakan: "Harus bilangan bulat 1 sampai 1000. Halaman: "
        cout << "Halaman (1-" << MAKS_HALAMAN << "): ";
        cin >> halaman;
        while (cin.fail() || halaman < 1 || halaman > MAKS_HALAMAN) {
            if (cin.eof()) {
                return 1;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus bilangan bulat 1 sampai 1000. Halaman: ";
            cin >> halaman;
        }

        // TODO 3: baca warna (char), jadikan huruf besar, ulangi selama bukan 'Y' atau 'T'.
        //         Pesan penolakan: "Hanya Y atau T. Berwarna (Y/T): "
        cout << "Berwarna (Y/T): ";
        cin >> warna;
        warna = static_cast<char>(toupper(static_cast<unsigned char>(warna)));
        while(warna != 'Y' && warna != 'T' ){
            if(cin.eof()){
                return 1;
            }
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Hanya Y atau T. Berwarna (Y/T): ";
            cin >> warna;
            warna = static_cast<char>(toupper(static_cast<unsigned char>(warna)));
        }
        cin.ignore(1000, '\n');

        // TODO 4: tentukan harga per halaman dari jumlah halaman (kecil, sedang, besar) dan tambah
        //         penghitung kategorinya; biaya = halaman * harga, dikali 2 bila berwarna.
        int biaya = 0;
        int harga = 0;
        if (halaman <= BATAS_KECIL) {
            harga = HARGA_KECIL;
            banyak_kecil++;
        } else if (halaman <= BATAS_SEDANG) {
            harga = HARGA_SEDANG;
            banyak_sedang++;
        } else {
            harga = HARGA_BESAR;
            banyak_besar++;
        }
        biaya = halaman * harga;
        if (warna == 'Y') {
            biaya *= 2;
        }

        cout << "  " << left << setw(16) << nama << right << setw(6) << halaman;
        if (warna == 'Y') {
            cout << setw(7) << "Warna";
        } else {
            cout << setw(7) << "Hitam";
        }
        cout << setw(9) << biaya << "\n";

        total_halaman += halaman;
        total_pendapatan += biaya;
        // TODO 5b: perbarui biaya terbesar dan nama pemesannya bila biaya ini lebih besar.
        if (biaya > biaya_terbesar) {
            biaya_terbesar = biaya;
            nama_terbesar = nama;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah pesanan    : " << jumlah << "\n";
    cout << "Total halaman     : " << total_halaman << "\n";
    cout << "Total pendapatan  : " << total_pendapatan << "\n";
    cout << "Rata-rata halaman : " << static_cast<double>(total_halaman) / jumlah << "\n";
    // TODO 5c: cetak "Terbesar          : " diikuti nama dan biaya terbesar dalam kurung.
    cout << "Terbesar          : " << nama_terbesar << " (" << biaya_terbesar << ")\n";

    cout << "\nSebaran ukuran pesanan:\n";
    // TODO 6: tiga baris batang (Kecil, Sedang, Besar) memakai perulangan bersarang:
    //         perulangan luar memilih label dan jumlahnya, perulangan dalam mencetak tanda # sebanyak itu.
    //         Format tiap baris: label rata kiri selebar 7, lalu "| ", batang, spasi, jumlah. Contoh: "Kecil  | ## 2"
    for (int b = 0; b < 3; b++) {
        string label;
        int banyak = 0;
        if (b == 0) {
            label = "Kecil";
            banyak = banyak_kecil;
        } else if (b == 1) {
            label = "Sedang";
            banyak = banyak_sedang;
        } else {
            label = "Besar";
            banyak = banyak_besar;
        }
        cout << left << setw(7) << label << "| ";
        for (int k = 0; k < banyak; k++) {
            cout << '#';
        }
        cout << " " << banyak << "\n";
    }

    return 0;
}