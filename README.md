# Sistem Antrean Bank Sederhana

## Deskripsi

Program ini merupakan sistem antrean sederhana untuk layanan bank, diimplementasikan menggunakan struktur data **Queue** (antrian) dan **Stack** (tumpukan). Sistem memungkinkan pengguna untuk menambahkan antrean, memproses antrean, menampilkan antrean saat ini, melihat riwayat layanan, dan membatalkan antrean terakhir yang diproses (undo).

## Fitur

1. **Menambah antrean**: Pengguna dapat mendaftarkan nasabah ke dalam antrean dengan nomor antrean, nama, dan jenis layanan yang dipilih.
2. **Memproses antrean**: Menghapus antrean terdepan dan memindahkannya ke riwayat layanan.
3. **Menampilkan antrean**: Menampilkan semua antrean yang sedang menunggu.
4. **Menampilkan riwayat layanan**: Menampilkan daftar nasabah yang telah dilayani.
5. **Undo (membatalkan antrean terakhir yang diproses)**: Mengembalikan antrean terakhir yang telah diproses ke daftar antrean.
6. **Keluar dari program**: Mengakhiri program dan membersihkan memori yang dialokasikan.

## Struktur Program

- `main.c` : Berisi fungsi `main()` dan pengelolaan menu utama.
- `header.h` : Berisi definisi struktur data dan deklarasi fungsi.
- `fungsi.c` : Berisi implementasi fungsi terkait antrean dan stack.

## Cara Kompilasi dan Eksekusi

1. **Kompilasi program**
   ```sh
   gcc main.c fungsi.c -o antrean_bank
   ```
2. **Jalankan program**
   ```sh
   ./antrean_bank
   ```

## Hasil Eksekusi Program

Contoh eksekusi program:

```
===== Sistem Antrean Bank =====
1. Tambah Antrean
2. Proses Antrean
3. Tampilkan Antrean
4. Tampilkan Riwayat
5. Undo
6. Keluar
Pilihan: 1
Masukkan nama: Budi
Pilih jenis layanan:
  1. Setor Tunai
  2. Tarik Tunai
  3. Pembukaan Rekening
Pilihan (1-3): 2
Nasabah Budi berhasil ditambahkan ke antrean dengan layanan Tarik Tunai.
```

## Struktur Data yang Digunakan

- **Queue (Antrian)**: Digunakan untuk menyimpan antrean nasabah berdasarkan urutan kedatangan.
- **Stack (Tumpukan)**: Digunakan untuk menyimpan riwayat layanan dan fitur undo.

## Fungsi Utama

### Queue (Antrian)

- `createQueue()`: Membuat dan menginisialisasi antrean baru.
- `isEmptyQueue()`: Mengecek apakah antrean kosong.
- `enqueue()`: Menambahkan nasabah ke antrean.
- `dequeue()`: Memproses antrean terdepan dan memindahkannya ke riwayat.
- `displayQueue()`: Menampilkan semua antrean yang masih menunggu.
- `freeQueue()`: Menghapus semua elemen dalam antrean.

### Stack (Riwayat & Undo)

- `createStack()`: Membuat dan menginisialisasi stack.
- `isEmptyStack()`: Mengecek apakah stack kosong.
- `push()`: Menambahkan data ke stack (riwayat layanan).
- `displayStack()`: Menampilkan daftar layanan yang telah diproses.
- `undo()`: Mengembalikan antrean terakhir dari stack ke antrean utama.
- `freeStack()`: Menghapus semua elemen dalam stack.

### Fitur Tambahan

- `pilihLayanan()`: Memilih jenis layanan yang tersedia.
- `printMenu()`: Menampilkan menu pilihan untuk pengguna.

## Kendala dan Solusi Selama Pengembangan

1. **Kesalahan dalam pengelolaan memori**

   - *Masalah*: Program mengalami memory leak karena tidak membebaskan memori yang dialokasikan.
   - *Solusi*: Menambahkan fungsi `freeQueue()` dan `freeStack()` untuk membebaskan memori sebelum program keluar.

2. **Validasi input pengguna**

   - *Masalah*: Program sebelumnya tidak menangani input non-angka dengan baik, menyebabkan infinite loop saat pengguna memasukkan huruf.
   - *Solusi*: Menambahkan validasi input dengan `scanf()` dan membersihkan buffer input dengan `getchar()`.

3. **Implementasi fitur undo**

   - *Masalah*: Kesulitan dalam mengembalikan antrean terakhir yang telah diproses ke antrean utama.
   - *Solusi*: Menggunakan stack untuk menyimpan riwayat dan mengambil elemen terakhir yang diproses untuk dimasukkan kembali ke antrean.

## Catatan Tambahan

- Program ini menggunakan `malloc()` untuk mengalokasikan memori secara dinamis, sehingga penting untuk memastikan `freeQueue()` dan `freeStack()` dipanggil sebelum keluar dari program guna mencegah kebocoran memori.
- Input divalidasi untuk memastikan hanya pilihan yang benar yang dapat dimasukkan oleh pengguna.

## Kontributor

Program ini dikembangkan sebagai tugas praktikum struktur data dan algoritma menggunakan struktur data queue dan stack.

Almira Sadida | 2408107010004

Thary Nabila Jannatul Rizki | 2408107010009

Meurahmah Nushsharie | 2408107010035

Muhammad Azlan Syahkam | 2408107010055

Muhammad Al Hafiz | 2408107010089

