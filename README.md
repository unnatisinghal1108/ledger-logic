# 💰 LedgerLogic — Expense Tracker (C++)

A C++ console application to track daily expenses.  
This project demonstrates core programming concepts including STL, Dynamic Memory Allocation (DMA), File Handling, Polymorphism, Exception Handling, and Move Semantics.

---

## 🚀 Features

- Add expenses (amount + category)
- Store data in file (`ledger.txt`)
- View saved records
- Search transactions by category
- Calculate total spending
- Generate:
  - Monthly report (total spending)
  - Category-wise report

---

## 🧠 Concepts Used

### 📦 STL
- `vector<Transaction>` → stores all transactions  
- `set<string>` → stores unique categories  

### 🔧 Dynamic Memory Allocation (DMA)
- Manual array resizing using `new[]` and `delete[]`
- Demonstrates how memory is managed without STL

### 📁 File Handling
- Uses `fopen`, `fprintf`, `fscanf`
- Stores transactions in `ledger.txt`

### ⚠️ Exception Handling
- Prevents negative expense entries using `throw`

### 🔁 Polymorphism
- Base class `Report`
- Derived classes:
  - `MonthlyReport`
  - `CategoryReport`

### ⚡ Move Semantics
- `ExpenseSummary` class uses `std::move` for efficient data transfer

---

## 🛠️ Build & Run

```bash
g++ -std=c++11 -o ledger ledger.cpp
./ledger
```

---

## 📂 Files

- ledger.cpp
- ledger.exe
- ledger.txt (generated during runtime)
- README.md

---

## 💡 Usage

```
===== LedgerLogic =====
1. Add Expense
2. View File
3. Search Category
4. Total Spending
5. Monthly Report
6. Category Report
7. Exit
```

---

## ⚠️ Notes

- DMA implementation is for learning purposes (STL is preferred in real applications)
- Data persists in `ledger.txt`
- Categories are stored uniquely using `set`

---

## 📌 Purpose

This project is built for academic learning and demonstrates multiple C++ concepts in a single application.
