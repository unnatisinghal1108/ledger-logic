# 💰 LedgerLogic — Daily Expense Tracker

A C++ console application for tracking daily expenses, built to demonstrate three core systems programming concepts: **Dynamic Memory Allocation**, **STL containers**, and **Move Semantics**.

---

## Features

- Add expenses with an amount and category
- View total spending across all entries
- Search transactions by category
- Monthly and per-category spending reports
- Parallel DMA and STL data pipelines (intentional, for learning purposes)

---

## Concepts Demonstrated

### 🔧 Dynamic Memory Allocation
A raw `Transaction*` array grows manually on the heap using `new[]` and `delete[]`. Every insert allocates a larger array, copies existing data, and frees the old memory — illustrating exactly what higher-level containers handle automatically.

### 📦 STL Containers
Two STL containers run in parallel with the DMA array:
- `std::vector<Transaction>` — ordered list of all transactions, auto-resizing
- `std::set<string>` — unique, sorted category names (no duplicate logic needed)

### ⚡ Move Semantics (C++11)
The `ExpenseSummary` class accepts a `vector<float>&&` and uses `std::move` to transfer ownership in O(1) time — avoiding an O(n) deep copy when building report data structures.

---

## Getting Started

### Prerequisites
- C++11 or later (`-std=c++11`)
- Any standard C++ compiler: `g++`, `clang++`, MSVC

### Build & Run

```bash
g++ -std=c++11 -o ledgerlogic main.cpp
./ledgerlogic
```

---

## Project Structure

```
LedgerLogic/
├── main.cpp              # Entry point and menu loop
├── Transaction.h         # Transaction struct (amount, category)
├── ExpenseSummary.h      # Move-semantics demo class
├── dma.cpp               # addTransactionDMA() implementation
├── stl.cpp               # STL vector/set operations
└── README.md
```

---

## Usage Example

```
=== LedgerLogic ===
1. Add Expense
2. Total Spending
3. Search by Category
4. Monthly Report
5. Category Report
6. Exit

> 1
Amount: 250
Category: Food
Transaction added.

> 5
Category Report:
Food       : 250.00
Transport  : 120.00
Utilities  : 800.00
```

---

## Implementation Notes

**Why two parallel data structures?**  
The DMA array and STL vector are both updated on every insert. This is deliberate — the project is structured to contrast manual heap management (`new`/`delete[]`) with the safety and convenience of the STL side by side.

**DMA vs. STL performance:**  
The DMA `addTransactionDMA()` function is O(n) per insert (full copy each time). `std::vector::push_back` is amortized O(1). For a real-world tracker, only the STL approach would be used.

**Move semantics payoff:**  
`ExpenseSummary` uses `std::move` to transfer a `vector<float>` in O(1). For large datasets (millions of records), this avoids the O(n) copy that would otherwise occur when building summary structures.

---

## Learning Goals

This project was built as part of a structured exploration of:

- Manual heap memory management in C++
- STL container selection (`vector` vs `set` and when to use each)
- C++11 move semantics and rvalue references
- The Rule of Five and ownership semantics

---

## License

MIT — free to use, fork, and learn from.
