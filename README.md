
# 📋 PECA - Pension Eligibility and Calculation App

## Description
**PECA (Pension Eligibility and Calculation App)** is a C++ console-based application designed for Malaysian government servants to check their pension eligibility based on age and years of service. If eligible, the app calculates their pension and gratuity based on the provided information.

This project was developed as **Assignment 1** for the **CPT113/CPT113W/CPM213 - Programming Methodology & Data Structures** course at **Universiti Sains Malaysia** (Semester 1, 2024/2025).

---

## 🌟 Features
- ✅ **Eligibility Check** based on:
  - Minimum **40 years of age**.
  - Minimum **10 years (120 months) of service**.
- ✅ **Pension & Gratuity Calculation**:
  - Pension: `0.00167 × months of service × last salary` (capped at 360 months).
  - Gratuity: `7.5% × last salary × months of service`.
- ✅ **Interactive menu** for:
  - Inputting personal and service information.
  - Displaying user data.
  - Checking eligibility and detailed reasons for ineligibility.

---

## 💻 Technologies Used
- **C++ (Object-Oriented Programming)**
  - Inheritance
  - Composition
  - Friend Functions

---

## 📂 Project Structure
```
PECA/
│
├── PECA Code.cpp                 # Main C++ source code implementing PECA logic
└── Assignment 1_(2024)_1.3.pdf   # Assignment guidelines and detailed requirements
```

---

## ⚙️ How to Run

1. **Clone this repository:**
```bash
git clone https://github.com/your-username/PECA-Pension-Eligibility-App.git
```

2. **Navigate to the project directory:**
```bash
cd PECA-Pension-Eligibility-App
```

3. **Compile the C++ file:**
```bash
g++ "PECA Code.cpp" -o peca
```

4. **Run the program:**
```bash
./peca
```

---

## ✅ Assignment Requirements Fulfilled
- Object-Oriented Design (Inheritance, Composition, Friend functions).
- Fully interactive and user-friendly interface.
- Complete input validation for all data fields.
- No global variables or advanced data structures used (per assignment rules).

---

## ⚠️ Disclaimer
> **This project is for academic purposes only.** The pension and gratuity calculations are based on hypothetical formulas provided for the assignment and should not be used for real-world pension assessments.

---

## 👩‍💻 Author
- **Your Name**
- **CPT113/CPT113W/CPM213 - Programming Methodology & Data Structures**
- Universiti Sains Malaysia
