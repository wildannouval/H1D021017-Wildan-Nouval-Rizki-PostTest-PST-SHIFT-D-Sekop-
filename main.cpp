// memanggil library yang digunakan
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// mendefinisikan pin yang digunakan untuk LED merah dan hijau
int ledmerah = D1;
int ledhijau = D2;

// inisialisasi objek LCD dengan alamat I2C 0x27 dan ukuran 10x2
LiquidCrystal_I2C lcd(0x27, 10, 2);

// mendefinisiakan pin SDA dan SCL untuk I2C
int SDA_pin = D5;
int SCL_pin = D6;

void setup() {
    // mengatur pin LED merah dan hijau sebagai output
    pinMode(ledmerah, OUTPUT);
    pinMode(ledhijau, OUTPUT);

    // menginisialisasi I2C dengan pin SDA dan SCL yang ditentukan
    Wire.begin(SDA_pin, SCL_pin);

    // menginisialisasi LCD
    lcd.init();
    
    // menyalakan lampu latar / backlight LCD
    lcd.backlight();
}

void loop() {
    // menyalakan LED merah dan matikan LED hijau
    digitalWrite(ledmerah, HIGH);
    digitalWrite(ledhijau, LOW);

    // atur kursor LCD ke kolom 0, baris 0
    lcd.setCursor(0, 0);

    // membersihkan layar LCD
    lcd.clear();

    // menampilkan teks "LED MERAH" pada LCD
    lcd.print("LED MERAH");

    // tunggu selama 5 detik
    delay(5000);

    // matikan LED merah dan nyalakan LED hijau
    digitalWrite(ledmerah, LOW);
    digitalWrite(ledhijau, HIGH);

    // atur kursor LCD ke kolom 0, baris 0
    lcd.setCursor(0, 0);

    // membersihkan layar LCD
    lcd.clear();

    // Tampilkan teks "LED HIJAU" pada LCD
    lcd.print("LED HIJAU");

    // Tunggu selama 5 detik
    delay(5000);
}