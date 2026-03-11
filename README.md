# Scholarship-Management-System
Semester II SPrint I  ||  C++ Final Project 

# 🎓 Scholarship Management System (C++)

A console-based **Scholarship Management System** developed in C++ that automates eligibility verification, fund allocation, and student status tracking. Built as Case Study 61 for B.Tech CSE Semester II at ITM Skills University.

---

## 🌟 Overview

Managing scholarship applications manually is time-consuming and error-prone. This system automates the entire process — checking each student's GPA and family income against defined scholarship criteria, allocating funds to eligible students, and displaying a clean formatted status report on the console.

The simulation runs through a menu-driven interface and supports adding multiple students, processing all of them at once, and tracking any individual by their ID.

---

## 🚀 Features

- Add students with full input validation (ID, Name, GPA, Family Income)
- Automatically process and verify eligibility against multiple scholarships
- Allocate funds to the first matching scholarship (priority-based)
- View a full formatted status report for all students
- Track any individual student by their ID
- Duplicate student ID detection
- Clean, bordered console output

---

## 🎯 Scholarships Defined

| Scholarship | Min GPA | Max Family Income | Fund Amount |
|---|---|---|---|
| Merit Base | 8.5 | Rs. 8,00,000 | Rs. 50,000 |
| Need Base  | 7.0 | Rs. 4,00,000 | Rs. 30,000 |

---

## 🖥️ Menu Options

```
=======================================
  SCHOLARSHIP MANAGEMENT SYSTEM MENU
=======================================
1. Add New Student
2. Process Scholarships (Verify Eligibility)
3. View Full Status Report (Console)
4. Track a Specific Student by ID
5. Exit System
```

> ⚠️ Always run **Option 2 (Process)** before viewing the report — otherwise all students will show status as `Pending`.

---

## ⚙️ Program Workflow

```
START
  │
  ▼
Load Scholarships (Merit Base + Need Base)
  │
  ▼
Show Menu
  │
  ├── 1. Add Student  →  Validate Input  →  Store in Array
  │
  ├── 2. Process  →  For each student, check all scholarships
  │                      ├── Match found  →  Approved + Fund Assigned
  │                      └── No match     →  Rejected
  │
  ├── 3. View Report  →  Display all students as bordered cards
  │
  ├── 4. Track by ID  →  Find and display single student
  │
  └── 5. Exit
```

---

## 🏗️ Project Structure

```
ScholarshipManagement.cpp   ← Single file, fully self-contained
```

### Classes

| Class | Responsibility |
|---|---|
| `Scholarship` | Stores name, minGPA, maxIncome, fundAmount; has `checkEligibility()` |
| `Student` | Stores student data; has `displayStatus()` for formatted output |
| `ScholarshipSystem` | Central controller — manages all students and scholarships |

---

## 📋 Sample Output

```
  ===============================================
       ITM SKILLS UNIVERSITY
       Scholarship Status Report
  ===============================================
  Total Students: 3

  +-----------------------------------------------+
  | ID       : 101
  | Name     : Harsh Kumar
  | GPA      : 9
  | Status   : Approved - Merit Base
  | Funds    : Rs. 50000
  +-----------------------------------------------+
  +-----------------------------------------------+
  | ID       : 102
  | Name     : Priya Sharma
  | GPA      : 7.2
  | Status   : Approved - Need Base
  | Funds    : Rs. 30000
  +-----------------------------------------------+
  +-----------------------------------------------+
  | ID       : 103
  | Name     : Rahul Verma
  | GPA      : 5.5
  | Status   : Rejected - Does not meet any scholarship criteria
  | Funds    : Rs. 0
  +-----------------------------------------------+
  ===============================================
```

---

## 🛡️ Input Validation

| Field | Validation |
|---|---|
| Student ID | Digits only, must be a positive integer, no duplicates |
| Full Name | Letters and spaces only — numbers/symbols are rejected |
| GPA | Numeric, range 0.0 to 10.0 |
| Family Income | Numeric, must be non-negative |

All validators use `getline`-based reading to prevent input buffer issues. Name validation uses ASCII range checks — no extra libraries needed.

---

## 🧠 Concepts Used

- Object-Oriented Programming (Classes, Constructors, Encapsulation)
- Nested loops for eligibility processing
- Input validation with `stoi` / `stod` and `pos` checking
- ASCII range-based name validation (no extra libraries)
- Menu-driven program flow with `switch-case`

---

## 🛠️ Technologies Used

- **Language:** C++ (C++11 or later)
- **Standard Libraries only:**
  - `<iostream>` for input/output
  - `<string>` for string handling
- **IDE:** VS Code with C++ extension
- **Compiler:** g++

---

## 📦 How to Run

### Prerequisites
- g++ compiler (C++11 or later)
- Any terminal or VS Code

### Compile & Run

```bash
g++ ScholarshipManagement.cpp -o scholarship
./scholarship
```

**On Windows:**
```bash
g++ ScholarshipManagement.cpp -o scholarship.exe
scholarship.exe
```

---

## 🔮 Future Improvements

Possible enhancements include:

- File-based persistence to save and reload student records between sessions
- Sorting students by GPA or allocated funds
- Support for adding custom scholarships at runtime
- Graphical User Interface (GUI) version
- Export status report to a `.txt` or `.csv` file
- Multi-criteria scholarships (e.g., category-based, merit + need combined)

---

## 👨‍💻 Author

**Harsh Kumar**  
B.Tech CSE 2025-29 | Semester II  
School of Future Tech, ITM Skills University

---

## 📄 License

This project was created for academic purposes as part of Case Study 61 — B.Tech CSE Semester II, C++, ITM Skills University.
