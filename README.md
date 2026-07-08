# Dutch Villa

**Aplikasi Booking Villa Berbasis Console — Bahasa C**

Dutch Villa adalah aplikasi **CRUD booking villa** berbasis console yang dibuat menggunakan **Bahasa C** dan **Windows API**. Aplikasi ini dikembangkan sebagai proyek **UAS (Ujian Akhir Semester)** untuk menyelesaikan pelatihan **Logika & Algoritma Pemrograman** di **PUB**.

---

## 📌 Tujuan Proyek

- ✅ Melengkapi tugas **UAS Logika & Algoritma**
- ✅ Menuntaskan pelatihan **Logika & Algoritma Pemrograman Bahasa C**
- ✅ Menerapkan konsep:
  - Struktur data (`struct`, array)
  - Validasi input real-time
  - Operasi file I/O (`fopen`, `fscanf`, `fprintf`)
  - Algoritma navigasi menu (arrow key + enter)
  - CRUD (Create, Read, Update, Delete)
- ⏱ **Dikerjakan dalam 10 hari**
  - Mulai: **1 Januari 2025, 00:00**
  - Selesai: **10 Januari 2025, 23:59**

---

## 🏗 Fitur

| Fitur | Keterangan |
|-------|-----------|
| **Registrasi User** | Daftar akun baru (nama, umur, username, password, no HP) dengan validasi real-time |
| **Login User & Admin** | Login dengan kredensial yang tersimpan di file teks |
| **Booking Villa** | Pilih dari 8 villa, tentukan jumlah malam, lakukan pembayaran |
| **Riwayat Booking** | Lihat histori booking yang pernah dilakukan |
| **Profil & Update** | Lihat dan ubah data diri (nama, umur, username, password, no HP) |
| **Admin Panel** | Lihat data seluruh user, tambah/hapus villa |
| **Navigasi Arrow Key** | Pilih menu dengan tombol panah arah + Enter |
| **Animasi Console** | Loading bar, efek warna, ASCII art banner |
| **Validasi Input** | Validasi karakter per karakter untuk setiap field |

---

## 🖥 Teknologi

| Teknologi | Keterangan |
|-----------|-----------|
| **Bahasa** | C (C89/C99) |
| **Compiler** | MinGW-w64 GCC |
| **Platform** | Windows (Console) |
| **API** | Windows API (`windows.h`) — cursor positioning, warna |
| **Penyimpanan** | File teks (`.txt`) — database flat file |

---

## 🚀 Cara Menjalankan

### Compile
```bash
gcc main.c -o main.exe
```

### Run
```bash
main.exe
```

Atau langsung jalankan `main.exe` dari File Explorer.

---

## 📂 Struktur File

```
DUTCH VILLA/
├── main.c              # Entry point program
├── villa.c             # Logika utama (menu, booking, admin, dll)
├── validasi.c          # Fungsi validasi input real-time
├── admin.txt           # Kredensial admin (default: admin / villa123)
├── FLOWCHART MIDO.png  # Flowchart aplikasi
└── FLOWCHART MIDO.drawio # File sumber flowchart
```

---

## 👤 Info Pembuat

| | |
|---|---|
| **Nama** | Ahmad Zaki Hossam Mido |
| **Institusi** | PUB |
| **Tujuan** | UAS Logika & Algoritma Pemrograman |

---

## 📝 Catatan

- Login admin: `admin` / `villa123`
- Login user: daftar akun baru melalui menu User
- Data tersimpan dalam file teks biasa (format: `namafile.txt`)
- Layar console optimal pada resolusi **174x43**
