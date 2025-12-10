# Advanced Student Stack Simulator

A comprehensive **C program** that simulates stack operations using a custom **Student structure**, featuring push, pop, peek, display, and internal state visualization. Designed with clarity, structure, and user interaction in mind.

---

## 🚀 Features

* Stack implementation using dynamic memory allocation
* Student details stored as a structure (ID, Name, Department, CGPA)
* User-friendly menu-driven interface
* Overflow & Underflow detection
* Visual internal stack state display
* Input buffer handling
* Clean and modular code with separate utility functions

---

## 📂 Project Structure

```
📁 StudentStackSimulator
│
├── main.c        # Full program code
├── README.md     # Project documentation
└── (optional) Makefile / screenshots / extra files
```

---

## 🧠 How It Works

The program uses a dynamically allocated array to store Student structures. A `Stack` structure tracks:

* `data` → pointer to Student array
* `top` → index of the top element
* `capacity` → max allowed students

Operations include:

* **PUSH** → Insert student
* **POP** → Remove top student
* **PEEK** → View the top student
* **DISPLAY** → Show entire stack
* **SHOW STATE** → Debug-style internal representation

---

## 🖥️ How to Run

### **On Windows (GCC / MinGW)**

```sh
gcc main.c -o stack.exe
stack.exe
```

### **On Linux / macOS**

```sh
gcc main.c -o stack
./stack
```

---

## 📸 Sample Output (Text Mode)

```
===========================================
      ADVANCED STUDENT STACK SIMULATOR
===========================================
Enter maximum number of students in stack: 3

1. PUSH
2. POP
3. PEEK
4. DISPLAY
5. SHOW INTERNAL STATE
6. EXIT
```

---

## ✨ Highlights

* Clean interaction prompts
* Perfect for **DSA lab submissions**
* Demonstrates practical use of **structures + stack**
* Beginner-friendly with professional output formatting

---

## 🔧 Technologies Used

* **C Programming Language**
* Standard Libraries: stdio.h, stdlib.h, string.h

---

## 📜 License

This project is open-source. Feel free to use or modify.

---

## 🤝 Contributing

Pull requests are welcome! If you find bugs or want improvements:

1. Fork this repo
2. Create a new branch
3. Commit your changes
4. Open a pull request

---

## 👨‍💻 Author

Developed as part of a **Data Structures and Algorithms mini-project**.

If you want me to:

* Generate a **Makefile**
* Split code into **header (.h)** and **source (.c)** files
* Create a **GitHub repository layout**

Just tell me! 🙂
