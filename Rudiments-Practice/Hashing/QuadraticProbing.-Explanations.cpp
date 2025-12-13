#include <iostream>
#include <string>

using namespace std;

// --- 1. STATUS FLAGS ---
enum Status { EMPTY, OCCUPIED, DELETED };

// --- 2. NODE STRUCTURE ---
struct HashNode {
    int key;
    string value;
    Status status;
};

// --- 3. QUADRATIC HASH TABLE CLASS ---
class QuadraticHashTable {
private:
    HashNode* table;    // Pointer to the dynamic array
    int currentSize;    // Number of active elements
    int tableSize;      // Total capacity

    // --- HELPER: IS PRIME (Optimized 6k +/- 1 rule) ---
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    // --- HELPER: NEXT PRIME ---
    int nextPrime(int n) {
        if (n % 2 == 0) n++;
        while (!isPrime(n)) n += 2;
        return n;
    }

    // --- HASH FUNCTION ---
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // --- CONSTRUCTOR ---
    QuadraticHashTable(int size = 11) {
        tableSize = nextPrime(size);
        currentSize = 0;
        table = new HashNode[tableSize];
        
        // Initialize all slots as EMPTY
        for (int i = 0; i < tableSize; i++) {
            table[i].status = EMPTY;
        }
        cout << "Table Created. Size: " << tableSize << endl;
    }

    // --- DESTRUCTOR ---
    ~QuadraticHashTable() {
        delete[] table;
    }

    // --- INSERT FUNCTION ---
    void insert(int key, string value) {
        
        // 1. CHECK LOAD FACTOR FIRST (Task 3, Page 16 Logic)
        // If adding this element pushes us over 0.7, Rehash NOW.
        if ((float)(currentSize + 1) / tableSize > 0.7) {
            rehash();
        }

        int hashIndex = hashFunction(key);
        int probe = 0; 
        int index = hashIndex;

        // 2. PROBE LOOP 
        // We look for duplicates to UPDATE, or an empty spot to INSERT.
        while (table[index].status == OCCUPIED) {
            
            // DUPLICATE CHECK: If key exists, UPDATE value
            if (table[index].key == key) {
                cout << "[UPDATE] Key " << key << " exists. Updating value: " 
                     << table[index].value << " -> " << value << endl;
                table[index].value = value; 
                return; // Exit, size does not change
            }

            // QUADRATIC FORMULA: (Hash + i^2) % Size
            probe++;
            index = (hashIndex + (probe * probe)) % tableSize;
            
            // Safety Check
            if (probe > tableSize) {
                cout << "Error: Table full or infinite loop." << endl;
                return;
            }
        }

        // 3. INSERT NEW KEY
        table[index].key = key;
        table[index].value = value;
        table[index].status = OCCUPIED;
        currentSize++;
        
        cout << "[INSERT] Key " << key << " at Index " << index 
             << " (Hash: " << hashIndex << ", Probes: " << probe << ")\n";
    }

    // --- SEARCH FUNCTION ---
    string search(int key) {
        int hashIndex = hashFunction(key);
        int probe = 0;
        int index = hashIndex;

        // Continue searching if OCCUPIED or DELETED
        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return table[index].value;
            }
            
            probe++;
            index = (hashIndex + (probe * probe)) % tableSize;
            
            if (probe > tableSize) break; 
        }
        return "Not Found"; 
    }

    // --- REMOVE FUNCTION ---
    void remove(int key) {
        int hashIndex = hashFunction(key);
        int probe = 0;
        int index = hashIndex;

        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                // Lazy Deletion: Mark as DELETED
                table[index].status = DELETED;
                currentSize--;
                cout << "[REMOVE] Key " << key << " marked DELETED at Index " << index << endl;
                return;
            }
            
            probe++;
            index = (hashIndex + (probe * probe)) % tableSize;
            
            if (probe > tableSize) break;
        }
        cout << "[REMOVE] Key " << key << " not found." << endl;
    }

    // --- REHASH FUNCTION ---
    void rehash() {
        cout << "\n--- Load Factor Limit Reached. Rehashing... ---\n";
        
        int oldSize = tableSize;
        HashNode* oldTable = table;

        // 1. New Size: Next Prime after Double
        tableSize = nextPrime(oldSize * 2);
        table = new HashNode[tableSize];
        currentSize = 0; 

        // Initialize
        for (int i = 0; i < tableSize; i++) table[i].status = EMPTY;

        // 2. Move Data (Re-insert active items)
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].status == OCCUPIED) {
                // Recursively call insert (it handles the math for new size)
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

        delete[] oldTable;
        cout << "--- Rehashing Complete. New Size: " << tableSize << " ---\n\n";
    }

    // --- DISPLAY FUNCTION ---
    void display() {
        cout << "--------------------------------------\n";
        cout << "Index | Status   | Key  | Value\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < tableSize; i++) {
            cout << "  " << i << "   | ";
            if (table[i].status == OCCUPIED)
                cout << "OCCUPIED | " << table[i].key << "   | " << table[i].value;
            else if (table[i].status == DELETED)
                cout << "DELETED  | --   | --";
            else
                cout << "EMPTY    | --   | --";
            cout << endl;
        }
        cout << "--------------------------------------\n";
    }
};

// --- DRIVER CODE ---
int main() {
    // 1. Initialize Table (Size 7 for easy testing)
    QuadraticHashTable ht(7); 

    // 2. Insert Keys to cause collisions
    cout << "\n--- PHASE 1: Collisions ---\n";
    ht.insert(10, "Apple");  // 10%7 = 3
    ht.insert(3,  "Banana"); // 3%7 = 3 (Collision 1 -> 3+1^2 = 4)
    ht.insert(17, "Cherry"); // 17%7 = 3 (Collision 1 -> 4 [occ], Collision 2 -> 3+2^2 = 7 -> 0)
    
    ht.display();

    // 3. Test Update
    cout << "\n--- PHASE 2: Update ---\n";
    ht.insert(10, "Apricot"); // Key 10 exists at index 3
    cout << "Search 10: " << ht.search(10) << endl;

    // 4. Test Remove
    cout << "\n--- PHASE 3: Removal ---\n";
    ht.remove(3); // Remove Banana at index 4
    ht.display();

    // 5. Trigger Rehash (Check Before Logic)
    // Table Size 7. Max Items = 7 * 0.7 = 4.9 -> 4 items.
    // Currently have 2 active items (10, 17). 
    cout << "\n--- PHASE 4: Triggering Rehash ---\n";
    ht.insert(50, "Date");      // Item 3
    ht.insert(60, "Elderberry"); // Item 4
    ht.insert(70, "Fig");        // Item 5 -> Triggers REHASH
    
    ht.display();

    return 0;
}