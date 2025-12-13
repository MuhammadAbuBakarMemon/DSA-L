#include <iostream>
#include <string>
using namespace std;

enum Status { OCCUPIED, DELETED, EMPTY };

struct HashNode
{
    int key;
    string value;
    Status status;
};

class DoubleHashTable 
{
    private:
        HashNode* table;
        int currSize;
        int tablesize;
        int PRIME_R;

        int HashFunction1(int k)
        {
            return (k % tablesize);
        }

        int HashFunction2(int n)
        {
            // PRIME_R has to be berween 1 and a prime number below the table's size
            return PRIME_R - (n % PRIME_R);
        }

        int isPrime(int n)
        {
            if (n <= 1) return false;
            if (n <= 2 || n <= 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int m = 5; m * m <= n; m++)
            {
                if ((n % m == 0) || (n % (m + 2) == 0)) return false;
            }
            return true;
        }

        int nextPrime(int n)
        {
            if (n % 2 == 0) n--;
            while (!(isPrime(n)))
            {
                n += 2;
            }
            return n;
        }
        
        int getLargestPrimeBelow(int n)
        {
            // we need a safety check here as well becs we are traversing backwardds to find a prime number
            if(n <= 2) return 2;
            int candidate = n -1;
            while (!isPrime(candidate))
            {
                candidate--;
            }
            return candidate;
        }

    public:
        DoubleHashTable(int size = 11)
        {
            currSize = 0;
            // here we forgot to ensure that our table size is a prime number
            // tablesize = size;
            tablesize = nextPrime(size);
            table = new HashNode[tablesize];

            for (int m = 0; m < tablesize; m++)
            {
                table[m].status = EMPTY;
            }

            PRIME_R = getLargestPrimeBelow(tablesize);

            cout << "HashTable created with size: " << tablesize << ", R: " << PRIME_R << endl;
        }

        ~DoubleHashTable()
        {
            delete[] table;
        }

        void insert(int k, string v)
        {

            if ((float) currSize/tablesize > 0.7)
            {
                rehash();
            }

            int HashIndex = HashFunction1(k);
            int stepsize = HashFunction2(k);
            int index = HashIndex;

            int probe = 0;

            while (table[index].status == OCCUPIED)
            {
                if (table[index].key = k)
                {
                    cout << "[UPDATE] Key: " << k << " found. Updating value: " 
                         << table[index].value << "->" << v << endl;
                         table[index].value = v;
                         return;  
                }

                // Double Hashing Formula: (Hash1 + i * Hash2) % Size
                probe++;
                index = (HashIndex + (probe * stepsize) ) % tablesize;

                if (probe > tablesize) 
                {
                    cout << "Error: table full or infinite loop/////\n";
                    return;
                }
            }
            
            table[index].key = k;
            table[index].value = v;
            table[index].status = OCCUPIED; 
            currSize++;

            cout << "[INSERT] key: " << k << " at Index: " << index 
                 << "(Hash 1: " << HashIndex << ", Stepsize: " << stepsize << ", Probes: " << probe << ")\n";  

        }

        string search(int k)
        {
            int HashIndex = HashFunction1(k);
            int index = HashIndex;
            int stepsize = HashFunction2(k);
            int probe = 0;

            while (table[index].status != EMPTY)
            {
                if (table[index].status == OCCUPIED && table[index].key == k)
                {
                    return table[index].value; 
                }

                probe++;
                index = (HashIndex + (probe * stepsize)) % tablesize;

                if (probe > tablesize)
                {
                    break;
                }
            }

            return "Key Not Found.//////\n";
        }


        void remove(int k)
        {
            int HashIndex = HashFunction1(k);
            int stepsize = HashFunction2(k);
            int index = HashIndex;

            int probe = 0;

            while (table[index].status != EMPTY)
            {
                if (table[index].status == OCCUPIED && table[index].key == k)
                {
                    // cout << "[DELETE] Key: " << k << " at Index: " << index 
                    //      << "(Hash1: " << HashIndex << ", Stepsize: " << stepsize << ", Probe: " << probe << ")";
                    table[index].status = DELETED;
                    currSize--;

                    cout << "[REMOVE] key " << k << " marked deleted at Index: " << index << endl;
                    return;
                }

                probe++;
                index = (HashIndex + (probe * stepsize)) % tablesize;

                if(probe > tablesize) break;
            }

            cout << "[REMOVE] Key: " << k << " not found." << endl;
        }

        void rehash()
        {
            cout << "\n------ Load Factor > 0.7 limmit reached, rehashing ------\n";

            int oldsize = tablesize;
            HashNode* oldtable = table;

            int tablesize = nextPrime(tablesize * 2);

            // DO NOT FORGET TO UPDATE PRIME_R
            PRIME_R = getLargestPrimeBelow(tablesize);

            table = new HashNode[tablesize];
            currSize = 0;

            for (int m = 0; m < tablesize; m++) table[m].status = EMPTY;

            for (int m = 0; m < oldsize; m++)
            {
                if (oldtable[m].status == OCCUPIED)
                {
                    insert(oldtable[m].key, oldtable[m].value);
                }
            }

            // cleanup
            delete[] oldtable;
            cout << "------ Rehashing complete. New Size: " << tablesize << ", New R: " << PRIME_R << "------" << endl;
        }

        void display()
        {
            
            cout << "\n------ Displaying HashTable ------\n";

            cout << "Index\tStatus\tKey\tValue\n";
            
            for (int m = 0; m < tablesize; m++)
            {
                cout << "HashTable Index: " << m << endl;

                if (table[m].status == OCCUPIED)
                {
                    cout << "\tOCCUPIED\t" << table[m].key << "\t" << table[m].value << endl;
                }
                else if (table[m].status == DELETED)
                {
                    cout << "\tDELETED\t------\t------\n";
                }
                else 
                {
                    cout << "\tEMPTY\t------\t------\n";
                }
            }
            cout << endl;

        }
};

int main(void)
{
    
    return 0;
}