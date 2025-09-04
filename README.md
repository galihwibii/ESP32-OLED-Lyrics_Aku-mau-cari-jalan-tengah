[README.md](https://github.com/user-attachments/files/22135855/README.md)
# 🎵 ESP32 OLED Lyrics Display – GalihWibisono Edition

Proyek ini menampilkan lirik lagu pada layar **OLED 128x64 (I2C SSD1306)** menggunakan mikrokontroler **ESP32**.  
Cocok untuk belajar dasar-dasar mikrokontroler, komunikasi I2C, penggunaan library OLED, serta manipulasi teks dengan tempo berbeda (cepat & lambat).

## 📌 Tujuan Proyek
- Menampilkan lirik satu per satu secara bergantian di layar OLED.  
- Bagian pertama → tampil **lebih cepat**.  
- Bagian kedua → tampil **lebih lambat**.  
- Setelah baris terakhir, lirik akan kembali mengulang dari awal.

## 🧰 Komponen yang Dibutuhkan
| Komponen              | Jumlah | Keterangan                           |
|-----------------------|--------|---------------------------------------|
| ESP32 Dev Board       | 1      | Bisa gunakan jenis DoIT / NodeMCU     |
| OLED Display 128x64   | 1      | Tipe I2C dengan chip SSD1306          |
| Kabel jumper male-male| 4      | Untuk koneksi antar pin               |
| Breadboard (opsional) | 1      | Untuk merapikan sambungan kabel       |
| Laptop/PC + Arduino IDE| 1     | Untuk pemrograman dan upload kode     |

## 🔌 Wiring OLED ke ESP32
| OLED Pin | ESP32 Pin |
|----------|-----------|
| GND      | GND       |
| VCC      | 3.3V      |
| SCL      | GPIO 22   |
| SDA      | GPIO 21   |

⚠️ Pastikan OLED sesuai dengan tegangan 3.3V.

## 🖥️ Instalasi Library di Arduino IDE
1. Buka Arduino IDE.  
2. Klik **Sketch > Include Library > Manage Libraries...**  
3. Cari dan Install:  
   - **Adafruit GFX Library**  
   - **Adafruit SSD1306**  
4. Pastikan board ESP32 sudah diinstall (melalui Board Manager: cari *esp32* oleh Espressif Systems).

## 💾 Struktur File
```
ESP32-OLED-Lyrics/
├── LyricsDisplay.ino   <- Kode utama proyek
└── README.md           <- Dokumentasi proyek ini
```

## 🔧 Upload Program ke ESP32
1. Hubungkan ESP32 ke komputer via kabel USB.  
2. Buka `LyricsDisplay.ino` di Arduino IDE.  
3. Pilih board: **Tools > Board > ESP32 Dev Module**.  
4. Pilih port COM yang sesuai: **Tools > Port**.  
5. Klik tombol **Upload** (ikon panah kanan).  
6. Setelah upload selesai, OLED akan menampilkan lirik sesuai tempo.

## 📜 Penjelasan Program
- Menggunakan **Adafruit SSD1306** untuk mengontrol layar OLED.  
- `lyrics_fast[]` berisi baris-baris lirik bagian cepat.  
- `lyrics_slow[]` berisi baris-baris lirik bagian lambat.  
- Fungsi `loop()` akan:
  1. Menghapus tampilan layar sebelumnya.  
  2. Menampilkan teks di tengah layar.  
  3. Memberikan delay sesuai tempo (cepat/lambat).  
  4. Pindah ke baris berikutnya dan mengulang.  

## 🧪 Contoh Output (OLED)
```
------------------------
|                      |
|  Aku mau cari         |
|  jalan tengah         |
------------------------
```

Setelah 1 detik, akan berubah jadi:
```
------------------------
|                      |
|  Buat kamu, apa       |
|  yang nggak bisa?     |
------------------------
```

## 💡 Modifikasi yang Disarankan
- 🔊 Tambahkan **DFPlayer Mini** untuk sinkron dengan audio lagu.  
- 🎮 Tambahkan **tombol** untuk skip baris manual.  
- 🧾 Tambahkan **EEPROM/SDCard** agar lirik dibaca dari file.  
- 🖋️ Gunakan **font custom** atau efek animasi scrolling.  

## 🧠 Troubleshooting
| Masalah                     | Solusi |
|-----------------------------|--------|
| Layar OLED tidak menyala    | Cek koneksi kabel & pastikan VCC-GND benar |
| Layar hanya putih/blank     | Pastikan alamat I2C `0x3C` sesuai |
| Upload gagal ke ESP32       | Cek port COM, tekan tombol BOOT saat upload jika perlu |

## 👀 Referensi
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)  
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)  

## 📝 Lisensi
Proyek ini terbuka untuk siapa saja yang ingin belajar dan mengembangkan kreativitas menggunakan ESP32.  
Bebas dimodifikasi dan disebarluaskan dengan menyertakan kredit pembuat asli.

## 🙋‍♂️ Kontributor
Dikembangkan oleh: **Galih Wibisono** (23051030021)  

Silakan fork, bintangi ⭐, dan bagikan ke teman-temanmu!
