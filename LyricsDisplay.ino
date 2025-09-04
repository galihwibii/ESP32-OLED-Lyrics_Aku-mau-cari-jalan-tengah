#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Lirik bagian cepat
const char* lyrics_fast[] = {
  "Aku mau cari",
  "jalan tengah",
  "Buat kamu, apa",
  "yang nggak bisa?",
  "Ajak kamu ke",
  "angkasa",
  "Go to the moon,",
  "kita berdansa"
};
int lyrics_fast_count = sizeof(lyrics_fast) / sizeof(lyrics_fast[0]);

// Lirik bagian lambat
const char* lyrics_slow[] = {
  "Aku wish you best",
  "Kamu yang the best",
  "Kata mamaku",
  "\"Masih muda,",
  "banyak waktu\"",
  "Ku merasakan apa",
  "yang kaurasakan",
  "Tanpa ragu,",
  "kamu paham aku",
  "Dua jadi satu,",
  "belah hati aku",
  "Aku mau maju,",
  "tinggal tunggu waktu"
};
int lyrics_slow_count = sizeof(lyrics_slow) / sizeof(lyrics_slow[0]);

void setup() {
  // initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
}

void loop() {
  // Bagian cepat
  for (int i = 0; i < lyrics_fast_count; i++) {
    display.clearDisplay();
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(lyrics_fast[i], 0, 0, &x1, &y1, &w, &h);
    int x = (SCREEN_WIDTH - w) / 2;
    int y = (SCREEN_HEIGHT - h) / 2;
    display.setCursor(x, y);
    display.println(lyrics_fast[i]);
    display.display();
    delay(1000); // 1 detik per baris
  }

  // Bagian lambat
  for (int i = 0; i < lyrics_slow_count; i++) {
    display.clearDisplay();
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(lyrics_slow[i], 0, 0, &x1, &y1, &w, &h);
    int x = (SCREEN_WIDTH - w) / 2;
    int y = (SCREEN_HEIGHT - h) / 2;
    display.setCursor(x, y);
    display.println(lyrics_slow[i]);
    display.display();
    delay(2000); // 2 detik per baris
  }
}
