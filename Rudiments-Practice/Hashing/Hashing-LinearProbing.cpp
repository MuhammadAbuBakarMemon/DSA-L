#include <iostream>
using namespace std;

struct HashNode
{

    string key;
    int value;

    HashNode(string m, int n) : key(m), value(n) {} 

};

class HashTable 
{
    private:
        HashNode** table;
        HashNode* dummy;
        int numBuckets;
        int currSize;

        unsigned long hashFunction(string key)
        {
            unsigned long sum = 0;

            for (char c : key)
            {
                sum += c;
            }

            return sum % numBuckets;
        }

        float getLoadFactor()
        {
            return (float) currSize/numBuckets;
        }

        void rehash()
        {
            cout << "Load factor > 0.7, performing reshashing and resizing the hash table////" << endl;

            int oldNumBuckets = numBuckets;
            numBuckets *= 2;
            HashNode** oldtable = table;
            
            table = new HashNode* [numBuckets];
            currSize = 0;

            for (int m = 0; m < numBuckets; m++)
            {
                table[m] = NULL;
            }

            for (int m = 0; m < oldNumBuckets; m++)
            {
                if (oldtable[m] != NULL && oldtable[m] != dummy)
                {
                    insert(oldtable[m]->key, oldtable[m]->value);

                    delete oldtable[m];
                }
            }

            delete[] oldtable;
        }

        public:
            HashTable(int size = 10)
            {

                numBuckets = size;
                currSize = 0;

                table = new HashNode* [numBuckets];
                
                dummy = new HashNode("", -1);
                // this is used a mareker for deleted slots 

                for (int m = 0; m < numBuckets; m++)
                {
                    table[m] = NULL;
                } 

            }

            ~HashTable()
            {
                for (int m = 0; m < numBuckets; m++)
                {
                    if (table[m] != NULL && table[m] != dummy)
                    {
                        delete table[m];
                    }
                }

                delete[] table;
                delete dummy;
            }

            void insert(string k, int v)
            {

                if (getLoadFactor() > 0.7)
                {
                    rehash();
                }
                
                int idx = hashFunction(k);
                int oIdx = idx;
                int firstDummyIndex = -1;

                // keep on moving until we find a free position in the table
                while (table[idx] != NULL)
                {
                    // case 1: we find a key with the similar key at that obtained index, means we should update the value only 
                    if (table[idx] != dummy && table[idx]->key == k)
                    {
                        table[idx]->value = v;
                        cout << "key [" << k << "] updated.\n";
                        return;
                    } 

                    // record any deleted nodes for potential use ahead during insertion 
                    if (table[idx] == dummy && firstDummyIndex == -1)
                    {
                        firstDummyIndex = idx;
                    }

                    // cirrcularly wrapping around in the hashtable 
                    idx = (idx + 1) % numBuckets;

                    // if we complete one cycle break the loop
                    if (idx == oIdx) break;
                }

                if (firstDummyIndex != -1)
                {
                    idx = firstDummyIndex;
                }

                currSize++;
                table[idx] = new HashNode(k, v);
                cout << "Key: " << k << " inserted at index: " << idx << "\n";

            }

            void remove(string key)
            {
                
                int idx = hashFunction(key);
                int oIdx = idx;

                while (table[idx] != NULL)
                {

                    // found and the table's index location is not already marekd as a tombstone/deleted....

                    if (table[idx] != dummy && table[idx]->key == key)
                    {
                        delete table[idx];
                        table[idx] = dummy;
                        currSize--;
                        cout << "removed key: " << key << "\n";
                        return;
                    }

                    idx = (idx + 1) % numBuckets;

                    if (oIdx == idx) break;
                }

                cout << "Key: " << key << " was not found; therefore, could not remove/////\n";
            }

            bool search(string key, int &resultValue)
            {

                int idx = hashFunction(key);
                int oIdx = idx;
                
                while (table[idx] != NULL)
                {
                    if (table[idx] != dummy && table[idx]->key == key)
                    {
                        resultValue = table[idx]->value;
                        return true;
                    }

                    idx = (idx + 1) % numBuckets;

                    if (oIdx == idx) break;
                }

                return false;

            }

            void display()
            {
                cout << "---- Hash Table (Linear Probing) ----\n";

                for (int m = 0; m < numBuckets; m++)
                {

                    cout << "Bucket: " << m << "\n";

                    if (table[m] == NULL)
                    {
                        cout << "[Empty]\n";
                    }
                    else if (table[m] == dummy)
                    {
                        cout << "[Deleted/Tombstone]\n";
                    }
                    else 
                    {
                        cout << "{" << table[m]->key << "," << table[m]->value << "}\n";
                    }
                }

                cout << "----------------------------------------------------\n";
            }


};

int main(void)
{
    
    HashTable StudentsGrades(5);

    cout << "=== Hash Table Linear Probing (NO STL) ===\n";

    StudentsGrades.insert("Abu Bakar", 30);
    StudentsGrades.insert("Fatima", 11);
    StudentsGrades.insert("Waqar", 3093);
    StudentsGrades.insert("Aimen", 125);
    StudentsGrades.insert("Ali",23);
    
    StudentsGrades.insert("Ghullam Muhammad",1);
    StudentsGrades.insert("Salma",45);
    StudentsGrades.insert("Waqar",7432);

    StudentsGrades.display();

    StudentsGrades.remove("Aimen");
    StudentsGrades.remove("Waqar");

    int data = 0;

    // StudentsGrades.search("Abu Bakar", &data);
    if (StudentsGrades.search("Ali", data))
    {
        cout << "Key Ali found with result value of: " << data << endl;
    }
    else 
    {
        cout << "Key Ali not found\n" << endl;
    }

    if (StudentsGrades.search("Raza", data))
    {
        cout << "Key Raza found with result value of: " << data << endl;
    }
    else 
    {
        cout << "Key Raza not found\n" << endl;
    }

    StudentsGrades.display();


    return 0;
}