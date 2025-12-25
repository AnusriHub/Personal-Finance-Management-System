# Personal Finance Management System (C)

## 📌 Project Overview

The **Personal Finance Management System (PFMS)** is a console-based application developed in **C** that helps users track and manage their personal finances efficiently.
It allows users to record **income and expenses**, categorize transactions, store data persistently using files, and generate **basic financial analytics**.

This project demonstrates strong command over **core and advanced C programming concepts**, making it suitable for academic evaluation, interviews, and entry-level software roles.

---

## 🎯 Objectives

* To provide a simple system for managing personal financial transactions
* To practice real-world application of **C programming concepts**
* To implement **file handling and dynamic memory allocation**
* To analyze financial data and generate meaningful insights

---

## ✨ Features

* ➕ Add income and expense transactions
* 📄 View all recorded transactions in a tabular format
* 💾 Persistent storage using file handling
* 📊 Financial analytics including:

  * Total income
  * Total expenses
  * Savings calculation
  * Highest spending category
* 🧠 Dynamic memory management using `malloc` and `realloc`

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Concepts Applied:**

  * Structures (`struct`)
  * Pointers
  * Dynamic memory allocation
  * File handling
  * String manipulation
  * Modular programming

---

## 📂 Project Structure

```
Personal-Finance-Management-System/
│
├── main.c                # Source code
├── transactions.txt      # Data file (auto-generated)
└── README.md             # Project documentation
```

---

## 🧩 Data Model

Each transaction is stored using a structure with the following fields:

* Transaction Type (`Income` / `Expense`)
* Category (e.g., Food, Rent, Salary)
* Amount
* Date (DD-MM-YYYY)

---

## ⚙️ How It Works

1. On startup, previously saved transactions are loaded from a file.
2. The user interacts with a menu-driven interface.
3. Transactions are dynamically stored in memory.
4. All data is saved to a file before program exit.
5. Analytics are computed by iterating through stored transactions.

---

## ▶️ How to Run

1. Compile the program:

   ```bash
   gcc main.c -o finance
   ```
2. Run the executable:

   ```bash
   ./finance
   ```
3. Follow the on-screen menu options.

---

## 📈 Sample Analytics Output

* Total Income
* Total Expenses
* Net Savings
* Highest Spending Category

---

## 🚀 Future Enhancements

* Monthly and yearly reports
* Category-wise expense breakdown
* Data validation and error handling
* Graphical user interface (GUI)
* Password-protected user accounts

---

## 👩‍💻 Author

**Anusri**
Computer Science Student
Aspiring Software Developer

---

## 📜 License

This project is open-source and free to use for learning and academic purposes.

