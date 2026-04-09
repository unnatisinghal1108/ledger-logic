#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

// ================= TRANSACTION CLASS =================
class Transaction {
public:
    float amount;
    string category;

    Transaction(float amt, string cat) {
        amount = amt;
        category = cat;
    }

    Transaction() {}
};

// ================= STL =================
vector<Transaction> transList;
set<string> categories;

// ================= DMA =================
Transaction* transactions = nullptr;
int sizeArr = 0;

void addTransactionDMA(float amt, string cat) {
    Transaction* newArr = new Transaction[sizeArr + 1];

    for (int i = 0; i < sizeArr; i++) {
        newArr[i] = transactions[i];
    }

    newArr[sizeArr] = Transaction(amt, cat);

    delete[] transactions;
    transactions = newArr;
    sizeArr++;
}

// ================= FILE HANDLING =================
void saveToFile(float amt, string cat) {
    FILE* file = fopen("ledger.txt", "a");

    if (file == NULL) {
        cout << "File error\n";
        return;
    }

    fprintf(file, "%f %s\n", amt, cat.c_str());
    fclose(file);
}

void readFromFile() {
    FILE* file = fopen("ledger.txt", "r");

    if (file == NULL) {
        cout << "No data yet\n";
        return;
    }

    float amt;
    char cat[50];

    cout << "\n--- Ledger Records ---\n";
    while (fscanf(file, "%f %s", &amt, cat) != EOF) {
        cout << amt << " - " << cat << endl;
    }

    fclose(file);
}

// ================= EXCEPTION HANDLING =================
void validateAmount(float amt) {
    if (amt < 0) {
        throw "Negative amount not allowed!";
    }
}

// ================= POLYMORPHISM =================
class Report {
public:
    virtual void generate() = 0;
};

class MonthlyReport : public Report {
public:
    void generate() {
        float total = 0;
        for (auto t : transList) total += t.amount;
        cout << "\n[Monthly Report] Total Spending: " << total << endl;
    }
};

class CategoryReport : public Report {
public:
    void generate() {
        cout << "\n[Category Report]\n";
        for (auto cat : categories) {
            float sum = 0;
            for (auto t : transList) {
                if (t.category == cat) sum += t.amount;
            }
            cout << cat << " : " << sum << endl;
        }
    }
};

// ================= MOVE SEMANTICS =================
class ExpenseSummary {
public:
    vector<float> data;

    ExpenseSummary(vector<float>&& d) {
        data = move(d);
    }
};

// ================= EXTRA FEATURES =================
void searchCategory(string cat) {
    cout << "\nResults for category: " << cat << endl;
    for (auto t : transList) {
        if (t.category == cat) {
            cout << t.amount << endl;
        }
    }
}

void totalSpending() {
    float sum = 0;
    for (auto t : transList) {
        sum += t.amount;
    }
    cout << "\nTotal Spending: " << sum << endl;
}

// ================= MAIN =================
int main() {
    int choice;
    float amount;
    string category;

    do {
        cout << "\n===== LedgerLogic =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View File\n";
        cout << "3. Search Category\n";
        cout << "4. Total Spending\n";
        cout << "5. Monthly Report\n";
        cout << "6. Category Report\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter amount: ";
            cin >> amount;

            cout << "Enter category: ";
            cin >> category;

            try {
                validateAmount(amount);

                // STL
                transList.push_back(Transaction(amount, category));
                categories.insert(category);

                // DMA
                addTransactionDMA(amount, category);

                // File
                saveToFile(amount, category);

                cout << "Expense Added!\n";
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            break;

        case 2:
            readFromFile();
            break;

        case 3:
            cout << "Enter category to search: ";
            cin >> category;
            searchCategory(category);
            break;

        case 4:
            totalSpending();
            break;

        case 5: {
            Report* r = new MonthlyReport();
            r->generate();
            delete r;
            break;
        }

        case 6: {
            Report* r = new CategoryReport();
            r->generate();
            delete r;
            break;
        }

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}