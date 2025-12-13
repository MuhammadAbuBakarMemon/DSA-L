#include <iostream>
#include <string>
using namespace std;

enum Status { EMPTY, OCCUPIED, DELETED };

struct HashNode 
{
    int key;
    string value;
    Status status;
};

class QuadraticHashTable
{

    private:
        HashNode* table;
        int currSize;
        int tablesize;

        int HashFunction(int key)
        {
            return (key % tablesize);
        }

        bool isPrime(int n)
        {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if ( (n % 2 == 0) || (n % 3 == 0)) return false;
            for (int m = 5; m * m <= n; m+= 6)
            {
                if ((n % m == 0) || (n % (m + 2) == 0)) return false;
            }
            return true;
        }

        int nextPrime(int n)
        {
            if (n % 2 == 0) n++;
            while(!isPrime(n))
            {
                n += 2;
            }
            return n;
        }        

    public:
        
    QuadraticHashTable(int size = 11)
    {
        currSize = 0;
        tablesize = nextPrime(size);
        table = new HashNode[tablesize];

        for(int m = 0; m < tablesize; m++)
        {
            table[m].status = EMPTY;
        }
    }

    ~QuadraticHashTable()
    {
        delete[] table;
    }

    void insert(int k, string val)
    {
        int probe = 0;
        int HashIndex = HashFunction(k);
        int index = HashIndex;

        while (table[index].status == OCCUPIED)
        {
            if (table[index].key == k)
            {
                cout << "Updating key from: " << table[index].key << " -> " << k << endl;
                table[index].key = k;
                return;
            }

            probe++;
            index = (HashIndex + (probe * probe)) % tablesize;
        }

        table[index].key = k;
        table[index].value = val;
        table[index].status = OCCUPIED;
        currSize++;

        cout << "Inserted key: " << k << "(value: " << val << ")" << " at index: " << index << "(Probes: " << probe << ")" << endl;

        if ((float)currSize / tablesize > 0.7)
        {
            rehash();
        }
    }

    string search(int k)
    {
        int HashIndex = HashFunction(k);
        int index = HashIndex;
        int probe = 0;

        while (table[index].status != EMPTY)
        {
            if(table[index].status == OCCUPIED && table[index].key == k)
            {
                cout << "Key found: " << table[index].key << " at index: " << index << endl;
                return table[index].value;
            }

            probe++;
            index = (index + (probe * probe)) % tablesize;

             // Safety break to prevent infinite loops (though rare with prime sizing)
            if (probe > tablesize) break;
        }

        return "Key not found////\n";
    }

    void remove(int k)
    {
        int HashIndex = HashFunction(k);
        int index = HashIndex;
        int probe = 0;

        while(table[index].status != EMPTY)
        {
            if (table[index].status == OCCUPIED && table[index].key == k)
            {
                table[index].status == DELETED; // lazy deletion 
                currSize--;
                cout << "[REMOVE] key: " << k << " marked as DELETED at index position: " << index << endl;
                return;
            }

            probe++;
            index = (HashIndex + (probe * probe)) % tablesize;

            if (probe > tablesize) break;
        }

        cout << "[REMOVE] key " << k << " not found.\n";

    }

    void rehash()
    {
        cout << "\n------ Load Factor > 0.7. Rehashing Table ------\n";

        HashNode* oldtable = table;
        int oldsize = tablesize;

        tablesize = nextPrime(tablesize * 2);
        table = new HashNode[tablesize];
        currSize = 0;

        for (int m = 0; m < tablesize; m++) table[m].status == EMPTY;

        for (int m = 0; m < oldsize; m++)
        {
            if (table[m].status == OCCUPIED)
            {
                insert(oldtable[m].key, oldtable[m].value);
            }
        }

        delete[] oldtable;
        cout << "Rehashing complete. New Capacity: " << tablesize << endl;
    }

    void display()
    {
        cout << "Displaying Quadratic Probing HashTable" << endl;
        cout << "In this order: INDEX\tSTATUS\tKEY\tVALUE." << endl;


        for(int m = 0; m < tablesize; m++)
        {
            cout << "Index: " << m << "\t";

            if (table[m].status == OCCUPIED)
            {
                cout << "OCCUPIED\tKey: " << table[m].key << "\tValue: "<< table[m].value;
            }
            else if (table[m].status == DELETED)
            {
                cout << "DELETED\t----\t----";
            }
            else
            {
                cout << "EMPTY\t----\t----";
            }
            cout << endl;
        }

    }

};

int main() {
    // Start with a small size to force collisions and rehash
    QuadraticHashTable ht(7); 

    cout << "1. Inserting initial data...\n";
    ht.insert(10, "Apple");  // 10%7 = 3
    ht.insert(3,  "Berry");  // 3%7 = 3 (Collision -> 3+1^2 = 4)
    ht.insert(17, "Cherry"); // 17%7 = 3 (Collision -> 3+4 = 0)
    
    ht.display();

    cout << "\n2. Testing UPDATE functionality...\n";
    // This key (10) already exists. Should update "Apple" to "Apricot".
    ht.insert(10, "Apricot"); 
    
    // Check search result
    cout << "Search Key 10: " << ht.search(10) << endl;

    cout << "\n3. Testing REMOVE functionality...\n";
    ht.remove(3); // Remove "Berry"
    
    // Check search result (should fail)
    cout << "Search Key 3: " << ht.search(3) << endl;

    cout << "\n4. Testing REHASH (Triggering load factor)...\n";
    ht.insert(25, "Date");
    ht.insert(35, "Elderberry"); // This entry should trigger the rehash
    
    ht.display();

    return 0;
}