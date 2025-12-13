#include <iostream>
#include <string>

using namespace std;

// --- 1. STATUS FLAGS ---
// Essential for Open Addressing to handle "Deleted" spots correctly
enum Status { EMPTY, OCCUPIED, DELETED };

// --- 2. NODE STRUCTURE ---
// Stores the Key, the Value, and the Status of the slot
struct HashNode {
    int key;
    string value;
    Status status;
};

// --- 3. DOUBLE HASH TABLE CLASS ---
class DoubleHashTable {
private:
    HashNode* table;    // Pointer to the dynamic array
    int currentSize;    // Number of active elements
    int tableSize;      // Total capacity of the table
    int PRIME_R;        // The 'R' used in the second hash function

    // --- HELPER: IS PRIME ---
    // Optimised 6k +/- 1 check
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
    // Used to resize the table to a prime number
    int nextPrime(int n) {
        if (n % 2 == 0) n++;
        while (!isPrime(n)) n += 2;
        return n;
    }

    // --- HELPER: LARGEST PRIME BELOW N ---
    // Used to find 'R' for Hash2. 
    // Manual Page 7 suggests R = 7 for Size 13.
    int getLargestPrimeBelow(int n) {
        if (n <= 2) return 2;
        int candidate = n - 1;
        while (!isPrime(candidate)) candidate--;
        return candidate;
    }

    // --- HASH FUNCTION 1 ---
    // Standard Modulo: Key % Size
    int hash1(int key) {
        return key % tableSize;
    }

    // --- HASH FUNCTION 2 (Step Size) ---
    // Formula from Manual Page 7: R - (key % R)
    // Ensures step size is never 0.
    int hash2(int key) {
        return PRIME_R - (key % PRIME_R);
    }

public:
    // --- CONSTRUCTOR ---
    DoubleHashTable(int size = 11) {
        tableSize = nextPrime(size);
        currentSize = 0;
        table = new HashNode[tableSize];
        
        // Calculate R based on table size
        PRIME_R = getLargestPrimeBelow(tableSize);

        // Initialize table
        for (int i = 0; i < tableSize; i++) {
            table[i].status = EMPTY;
        }
        
        cout << "Table Created. Size: " << tableSize << ", R: " << PRIME_R << endl;
    }

    // --- DESTRUCTOR ---
    ~DoubleHashTable() {
        delete[] table;
    }

    // --- INSERT FUNCTION ---
    // Logic: Checks load factor BEFORE inserting. Updates if duplicate.
    void insert(int key, string value) {
        
        // 1. CHECK LOAD FACTOR (Task 3, Page 16 Logic)
        // If adding this item would exceed 0.7, Rehash FIRST.
        if ((float)(currentSize + 1) / tableSize > 0.7) {
            rehash();
        }

        int hashIndex = hash1(key);
        int stepSize = hash2(key); 
        
        int probe = 0; 
        int index = hashIndex;

        // 2. PROBE LOOP (Stop at EMPTY, but continue if OCCUPIED or DELETED)
        // Note: We scan DELETED slots to see if the key exists further down (Update scenario),
        // but for insertion, we could overwrite a DELETED slot.
        // For simplicity in this "Update-aware" version, we treat DELETED as "keep looking".
        while (table[index].status == OCCUPIED) {
            
            // Check for Duplicate -> UPDATE
            if (table[index].key == key) {
                cout << "[UPDATE] Key " << key << " found. Updating value: " 
                     << table[index].value << " -> " << value << endl;
                table[index].value = value;
                return; 
            }

            // Double Hashing Formula: (Hash1 + i * Hash2) % Size
            probe++;
            index = (hashIndex + (probe * stepSize)) % tableSize;
            
            // Safety break
            if (probe > tableSize) {
                cout << "Error: Table full or infinite loop." << endl;
                return;
            }
        }

        // 3. PERFORM INSERTION
        // We found an EMPTY spot (or we could optimize to use the first DELETED spot found)
        table[index].key = key;
        table[index].value = value;
        table[index].status = OCCUPIED;
        currentSize++;
        
        cout << "[INSERT] Key " << key << " at Index " << index 
             << " (Hash1: " << hashIndex << ", Step: " << stepSize << ", Probes: " << probe << ")\n";
    }

    // --- SEARCH FUNCTION ---
    string search(int key) {
        int hashIndex = hash1(key);
        int stepSize = hash2(key);
        
        int probe = 0;
        int index = hashIndex;

        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return table[index].value;
            }
            
            probe++;
            index = (hashIndex + (probe * stepSize)) % tableSize;
            
            if (probe > tableSize) break;
        }
        return "Not Found";
    }

    // --- REMOVE FUNCTION ---
    void remove(int key) {
        int hashIndex = hash1(key);
        int stepSize = hash2(key);
        
        int probe = 0;
        int index = hashIndex;

        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                // Lazy Deletion
                table[index].status = DELETED;
                currentSize--;
                cout << "[REMOVE] Key " << key << " marked DELETED at Index " << index << endl;
                return;
            }
            
            probe++;
            index = (hashIndex + (probe * stepSize)) % tableSize;
            
            if (probe > tableSize) break;
        }
        cout << "[REMOVE] Key " << key << " not found." << endl;
    }

    // --- REHASH FUNCTION ---
    void rehash() {
        cout << "\n--- Load Factor Limit Reached. Rehashing... ---\n";
        
        int oldSize = tableSize;
        HashNode* oldTable = table;

        // 1. Calculate New Size (Next Prime after Double)
        tableSize = nextPrime(oldSize * 2);
        
        // 2. Recalculate R for the new size
        PRIME_R = getLargestPrimeBelow(tableSize);

        // 3. Allocate new table
        table = new HashNode[tableSize];
        currentSize = 0; // Reset count
        
        // Initialize
        for (int i = 0; i < tableSize; i++) table[i].status = EMPTY;

        // 4. Move Data (Re-insert active items)
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].status == OCCUPIED) {
                // Recursively call insert (it handles the math for new size)
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

        // 5. Cleanup
        delete[] oldTable;
        cout << "--- Rehashing Complete. New Size: " << tableSize << ", New R: " << PRIME_R << " ---\n\n";
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
    // 1. Start with a small table to force collisions and rehash
    // Using 7 (as in Manual Linear Probing example) or 13 (Double Hashing example)
    // Let's use 7 to make rehashing happen faster.
    DoubleHashTable ht(7); 

    // 2. Insert Keys (Demonstrating Collisions)
    cout << "\n--- PHASE 1: Insertion & Collisions ---\n";
    ht.insert(10, "Apple");  // 10%7 = 3
    ht.insert(3,  "Banana"); // 3%7 = 3 (Collision!)
    ht.insert(17, "Cherry"); // 17%7 = 3 (Collision!)
    
    // Hash1(17) = 3. 
    // Hash2(17) = 5 - (17%5) = 5-2 = 3.
    // Next = (3 + 1*3)%7 = 6. 
    // Should land at Index 6.
    
    ht.display();

    // 3. Update Existing Key
    cout << "\n--- PHASE 2: Update ---\n";
    ht.insert(10, "Apricot"); // Should update Index 3
    cout << "Search 10: " << ht.search(10) << endl;

    // 4. Remove Key
    cout << "\n--- PHASE 3: Removal ---\n";
    ht.remove(3); // Remove Banana
    ht.display();

    // 5. Trigger Rehash
    // Size is 7. Threshold 0.7 means max 4 items.
    // Currently have 2 items (10, 17).
    cout << "\n--- PHASE 4: Triggering Rehash ---\n";
    ht.insert(50, "Date");      // Item 3
    ht.insert(60, "Elderberry"); // Item 4
    ht.insert(70, "Fig");        // Item 5 -> Should trigger REHASH BEFORE insertion
    
    ht.display();

    return 0;
}