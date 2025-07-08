# Grocery Galore Billing System 🛒

A C++ console-based inventory and billing system designed to simulate a grocery store's operations with separate **Administrator** and **Cashier** portals.

## 💡 Features

### 👨‍💼 Administrator
- Add, update, delete products
- View all product listings
- View sales and profit history

### 👩‍💻 Cashier
- View products
- Search products by type (e.g., food, clothes)
- Order products and generate receipt
- Checkout with card or cash
- Automatic inventory updates

---

## 🧰 Technologies Used

- C++ (Standard Libraries only)
- Console UI (Windows-compatible)

---

## ⚙️ Setup Instructions

### 🔧 Step 1: Install a C++ Compiler (MinGW)

If `g++` isn't recognized:
1. Download GCC/MinGW from [WinLibs](https://winlibs.com/#download)
2. Extract it to `C:\mingw64`
3. Add this path to Environment Variables:
-C:\mingw64\mingw64\bin
4. Restart VS Code or Command Prompt.
5. Confirm installation:
g++ --version

---

### Step 2: Compile and Run
```bash
g++ -o GroceryManagement_System main.cpp
.\GroceryManagement_System.exe



