# 🎓 Student Grades Management System

This repository contains a C++ console application designed to manage student academic records. It implements **File Organization** concepts by allowing users to store, retrieve, manipulate, and persist student data into a CSV (Comma Separated Values) file.

The system uses an interactive menu to handle student data dynamically using `std::vector` for in-memory storage and `fstream` for file operations.

## ✨ Features & Operations

### 1. Student Management (In-Memory)

The system uses a `vector<student>` to act as a dynamic database during runtime.

* **Add Student:** Allows inputting detailed information including:
* Student Name & ID.
* GPA.
* Dynamic list of Subjects and their Credit Hours.


* **View All Students:** Displays a formatted table of all currently loaded students using `iomanip` for clean alignment.
* **Edit Student:** Search for a student by **ID** and update their information completely.
* **Delete Student:** Search for a student by **ID** and remove their record from the system.

### 2. File Persistence (File Organization)

The core feature of this project is preserving data after the program closes.

* **Save to File:** Writes all student records currently in memory to a file named `students.csv`.
* **Data Format:** The file is structured as a CSV, where complex data (Subjects/Hours) is formatted into a single readable string field.

## 🛠️ Technical Implementation

### Class Structure (`student`)

The project is built around the `student` class which encapsulates:

* **Private Data:** `Name`, `ID`, `GPA`, `numSubject`, `nameSubject` (Vector), `CreditHours` (Vector).
* **Public Methods:** `setData()`, `showRow()`, `saveRow()`, and `getID()`.

### Technologies Used

* **Language:** C++
* **Libraries:**
* `<vector>`: For dynamic array management.
* `<fstream>`: For File I/O (Input/Output) operations.
* `<iomanip>`: For formatting console output.


* **Concept:** Object-Oriented Programming (OOP) & Sequential File Access.

## 🚀 Getting Started

1. **Clone the repository:**
```bash
git clone [https://github.com/ahmedelsayedali1/Student-Information-System.git]

```


2. **Compile the code:**
```bash
g++ Student_System.cpp -o app

```


3. **Run the application:**
```bash
./app

```



## 📂 File Structure Example

When you choose "Save to File", the system generates `students.csv` in the following format:

```csv
Name,ID,GPA,Subjects
Ahmed,2023001,3.8,Math : 3 | Physics : 4 |
Sarah,2023002,3.9,CS : 3 | Logic : 2 |

```

---
