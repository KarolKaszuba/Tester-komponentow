# 🔧 Tester Elementów Elektronicznych (Arduino)

### 🇵🇱 Wersja Polska

## 📘 Opis projektu  
Projekt przedstawia **tester podstawowych elementów elektronicznych** zbudowany na platformie **Arduino UNO R3**.  
Urządzenie umożliwia **pomiar rezystorów**, **testowanie diod (w tym LED)** oraz **analizę tranzystorów NPN**.  
Wyniki pomiarów są wyświetlane na wyświetlaczu **LCD 16x2**.

---

## ⚙️ Funkcjonalności

- 🧩 **Tryb rezystora** — pomiar rezystancji nieznanego elementu za pomocą dzielnika napięcia.  
- 💡 **Tryb diody** — identyfikacja typu diody (germanowa, krzemowa, LED) oraz pomiar napięcia przewodzenia.  
- 🔌 **Tryb tranzystora (NPN)** — pomiar napięć na bazie przy włączonym i wyłączonym zasilaniu.  
- 🔄 **Menu trybów** obsługiwane za pomocą trzech przycisków (lub pojedynczego z obsługą kliknięć).  
- 🖥️ **Wyświetlanie wyników** na ekranie LCD 16x2.  

---

## 💻 Wymagania techniczne (minimalne)

| Komponent | Wymaganie minimalne |
|------------|---------------------|
| Mikrokontroler | **Arduino UNO R3** (lub kompatybilny) |
| Wyświetlacz | LCD 16x2 (HD44780 lub zgodny) |
| Rezystor odniesienia | 10 kΩ (dokładność min. 1%) |
| Zasilanie | 5V DC (USB lub zewnętrzne) |
| Przyciski | minimum 3 wejścia cyfrowe z PULLUP |
| Przewody połączeniowe | standardowe przewody męsko-męskie |
| Płytka stykowa | zalecana do testów prototypowych |

---

## 💻 Wymagania systemowe i komputerowe

| Komponent | Minimalne wymaganie |
|------------|---------------------|
| **System operacyjny** | Windows 10 / Linux (Ubuntu 20.04+) / macOS 10.15+ |
| **Procesor** | Dwurdzeniowy 1.5 GHz lub lepszy |
| **Pamięć RAM** | Minimum 2 GB (zalecane 4 GB) |
| **Port USB** | Wymagany do komunikacji z Arduino UNO R3 |
| **Oprogramowanie** | Arduino IDE 2.0 lub nowsze (zainstalowane sterowniki CH340/ATmega) |
| **Dodatkowe biblioteki** | LiquidCrystal.h, OneButton.h |

---

## 🔩 Wykorzystany sprzęt

- Płytka rozwojowa **Arduino UNO R3**  
- Wyświetlacz **LCD 16x2**  
- Trzy przyciski do wyboru trybu pracy  
- Rezystor odniesienia 10kΩ  
- Przewody połączeniowe i płytka stykowa  
- Testowane elementy: **rezystory, diody, tranzystory NPN**

---

## 🧠 Zasada działania

Program w zależności od wybranego trybu:
1. **Rezystor** – wykorzystuje dzielnik napięcia i oblicza rezystancję badanego elementu.  
2. **Dioda** – podaje napięcie testowe i mierzy spadek napięcia, klasyfikując typ diody.  
3. **Tranzystor** – sprawdza różnicę napięcia na bazie przy włączonym i wyłączonym zasilaniu.  

---

## 🪛 Wymagane biblioteki

- `LiquidCrystal.h` — obsługa wyświetlacza LCD  
- `OneButton.h` — obsługa przycisków z rozróżnianiem kliknięć  

Zainstaluj je z **Library Managera** w środowisku Arduino IDE.

---

## 🔌 Połączenia (Pinout)

| Element | Pin Arduino | Opis |
|----------|--------------|------|
| LCD RS | 2 | Sygnał RS |
| LCD E | 3 | Enable |
| LCD D4 | 4 | Dane D4 |
| LCD D5 | 5 | Dane D5 |
| LCD D6 | 6 | Dane D6 |
| LCD D7 | 7 | Dane D7 |
| Przycisk Rezystor | 8 | Tryb rezystora |
| Przycisk Dioda | 9 | Tryb diody |
| Przycisk Tranzystor | 10 | Tryb tranzystora |
| Pin testu diody | 11 | Zasilanie testowe diody |
| Pin testu tranzystora | 12 | Zasilanie testowe tranzystora |
| Pomiar rezystora | A0 | Wejście analogowe |
| Pomiar diody | A1 | Wejście analogowe |
| Pomiar tranzystora | A2 | Wejście analogowe |

---

## ⚡ Zasilanie

Urządzenie jest zasilane z portu **USB (5V)** lub z zewnętrznego źródła 5V.

---

## 🧰 Jak używać

1. Uruchom urządzenie — pojawi się ekran powitalny.  
2. Wybierz tryb:
   - `1` — pomiar rezystora,  
   - `2` — test diody,  
   - `3` — test tranzystora.  
3. Odczytaj wynik na ekranie LCD.  
4. Kliknij dwukrotnie przycisk `1`, aby wrócić do menu głównego.  

---

## 📸 Przykładowy wygląd urządzenia

```markdown
![Tester Elementów - Arduino](images/tester.jpg)
```

---

## 🧑‍💻 Autor
Projekt: **[Karol Kaszuba]**  
Licencja: **MIT License**

---

### 🇬🇧 English Version

# 🔧 Electronic Component Tester (Arduino)

## 📘 Project Description  
This project is an **Arduino UNO R3-based electronic component tester** designed to measure **resistors**, **diodes (including LEDs)**, and **NPN transistors**.  
Measurement results are displayed on a **16x2 LCD screen**.

---

## ⚙️ Features

- 🧩 **Resistor Mode** – measures the resistance of an unknown resistor using a voltage divider.  
- 💡 **Diode Mode** – identifies diode type (Germanium, Silicon, or LED) and measures forward voltage.  
- 🔌 **Transistor Mode (NPN)** – measures voltage differences at the base with power ON/OFF.  
- 🔄 **Mode switching** via three physical buttons (or single multi-click button).  
- 🖥️ **LCD Display** for real-time measurement results.  

---
## 🧠 Working Principle

Depending on the selected mode:
1. **Resistor** – calculates resistance using a voltage divider circuit.  
2. **Diode** – applies test voltage and measures the voltage drop across the diode.  
3. **Transistor** – measures voltage changes on the transistor base.
   
---

## 💻 Technical Requirements (Minimum)

| Component | Minimum Specification |
|------------|-----------------------|
| Microcontroller | **Arduino UNO R3** (or compatible board) |
| Display | 16x2 LCD (HD44780 compatible) |
| Reference Resistor | 10 kΩ (1% tolerance or better) |
| Power Supply | 5V DC (USB or external) |
| Buttons | at least 3 digital inputs with PULLUP |
| Jumper Wires | standard male-male |
| Breadboard | recommended for prototype testing |

---

## 💻 System and Computer Requirements

| Component | Minimum Requirement |
|------------|----------------------|
| **Operating System** | Windows 10 / Linux (Ubuntu 20.04+) / macOS 10.15+ |
| **Processor** | Dual-core 1.5 GHz or better |
| **RAM** | Minimum 2 GB (4 GB recommended) |
| **USB Port** | Required for Arduino UNO R3 communication |
| **Software** | Arduino IDE 2.0 or newer (with CH340/ATmega drivers installed) |
| **Additional Libraries** | LiquidCrystal.h, OneButton.h |

---

## 🪛 Required Libraries

- `LiquidCrystal.h` — for LCD control  
- `OneButton.h` — for button input handling  

Install these from the **Arduino IDE Library Manager**.

---

## 📸 Example Photo

```markdown
![Electronic Component Tester - Arduino](images/tester.jpg)
```

---## 🔌 Wiring (Pinout)

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| LCD RS | 2 | RS signal |
| LCD E | 3 | Enable |
| LCD D4 | 4 | Data D4 |
| LCD D5 | 5 | Data D5 |
| LCD D6 | 6 | Data D6 |
| LCD D7 | 7 | Data D7 |
| Resistor Button | 8 | Resistor mode |
| Diode Button | 9 | Diode mode |
| Transistor Button | 10 | Transistor mode |
| Diode Test Voltage | 11 | Voltage source for diode |
| Transistor Test Voltage | 12 | Voltage source for transistor |
| Resistor Measurement | A0 | Analog input |
| Diode Measurement | A1 | Analog input |
| Transistor Measurement | A2 | Analog input |

---

## ⚡ Power Supply

Powered via **USB (5V)** or an external regulated **5V source**.

---

## 🧰 How to Use

1. Power on the device — a welcome message appears.  
2. Select mode:
   - `1` — resistor test,  
   - `2` — diode test,  
   - `3` — transistor test.  
3. Read the results on the LCD.  
4. Double-click `1` to return to the main menu.  

---

## 🧑‍💻 Author
Project by **[Karol Kaszuba]**  
License: **MIT License**
