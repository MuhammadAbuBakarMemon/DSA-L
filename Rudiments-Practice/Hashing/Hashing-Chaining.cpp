#include <iostream>
#include <string>
using namespace std;

// using  linked list pattern for chaining
struct HashNode 
{

    string key;
    int value;
    HashNode* next;

    HashNode(string m, int n) : key(m), value(n), next(NULL) {}

};

class HashTable 
{
    private:
        HashNode** table;
        int numBuckets;
        int currSize;

        unsigned long hashFunction(const string& key) const
        {
            unsigned long sum =  0;
            
            for (char c : key)
            {
                sum += int(c);  //use the ASCII value of the charcater c
            }

            return sum % numBuckets;
            
        }

        float getLoadFactor() const
        {
            return (currSize / numBuckets);
        }

        void rehash()
        {

            cout << "\n[Load Factor  > 0.7]  Rehashing from " << numBuckets << " to " << numBuckets * 2 << "////"<< endl;
            
            int oldNumBuckets = numBuckets;
            numBuckets *= 2;
            currSize = 0; // this current size gets recalculated and rehashed during the insert function's execution 

            HashNode** oldtable = table;
            table = new HashNode* [numBuckets];

            for (int m = 0; m < numBuckets; m++)
            {
                table[m] = NULL;
            }

            for (int m = 0; m < oldNumBuckets; m++)
            {
                HashNode* current = oldtable[m];

                // reinserting all of our old elements into the new hash table, after recalculalting their hashes 
                while (current != NULL)
                {
                    insert(current->key, current->value); // insert function re-calculates the hash for new size
                    
                    // this next line is only written so that we can free the old memory once we do not need it after we have copied the old elements from it 
                    HashNode* prev = current;
                    current = current->next;

                    // the old node was deleted, this was a pointer and not an array
                    delete prev;
                }
            }       
            
            delete[] oldtable;

        }

        public:    

        HashTable(int size = 10)
        {
            numBuckets = size;
            currSize = 0;

            table = new HashNode* [size];


            for (int m = 0; m < numBuckets; m++)
            {
                table[m] = NULL;
            }
        }

        ~HashTable()
        {
            for (int m = 0; m < numBuckets; m++)
            {
                HashNode* trav = table[m];

                while (trav != NULL)
                {
                    HashNode* prev = trav;
                    trav = trav->next;

                    delete prev;
                }

                table[m] = NULL;

            }

            delete[] table;
        }

        // void insert(string key, int value)
        // {
        //     if (getLoadFactor() > 0.7)
        //     {
        //         rehash();
        //     }

        //     int index = hashFucntion(key);

        //     HashNode* trav = table[index];
        //     // HashNode* prev = NULL;  //this is useless since we perform insertion at the front/head of the list 

        //     while (trav != NULL)
        //     {
        //         if (trav->key == key)
        //         {
        //             trav->value = value;
        //             cout << "key [" << key << "] updated." << endl;
        //             return;
        //         }

        //         //prev = trav;  //this is useless since we perform insertion at the front/head of the list 
        //         trav = trav->next;
        //     }

        //     currSize++;
        //     HashNode* n = new HashNode(key, value);
            
        //     n->next = table[index];
        //     table[index] = n;

        //     cout << "Key [" << key << "] inserted at index ["  << index << "]." << endl;

        // }

        void insert(string key, int value)
        {
            if (getLoadFactor() > 0.7)
            {
                rehash();
            }

            int index = hashFunction(key);

            // now we check if the key already exists in our program 
            HashNode* trav = table[index];
            // HashNode* prev = NULL;  //this is useless since we perform insertion at the front/head of the list 

            while (trav != NULL)
            {
                if (trav->key == key)
                {
                    trav->value = value;
                    cout << "key [" << key << "] updated." << endl;
                    return;
                }

                // prev = trav;  //this is useless since we perform insertion at the front/head of the list 
                trav = trav->next;
            }

            // when it passes through the above loop without returning we know for a fact that the particular key did not exist in our program 
            HashNode* newNode = new HashNode(key, value);
            currSize++;

            newNode->next = table[index];
            table[index] = newNode; 

            cout << "Key [" << key << "] inserted at index " << index << "." << endl;
 
        }

        void remove(string key)
        {
            int index = hashFunction(key);

            HashNode* trav = table[index];
            HashNode* prev = NULL;

            while (trav != NULL)
            {
                if (trav->key == key)
                {
                    // if the node to be deleted is at the front/head of the queue (not necessary that it is the only element in the chain at that)
                    // particular index position in the haahtable
                    if (prev == NULL)
                    {
                        table[index] = trav->next;
                    }
                    // if the node in positioned somewhere in between or at the end of the chain then the procedure for deletion would be a little different
                    else
                    {
                        prev->next = trav->next;
                    } 

                    delete trav;
                    currSize--;
                    cout << "Key [" << key << "] removed." << endl;
                    return;
                }
                prev = trav;
                trav = trav->next;
            }

            cout << "Key [" << key << "] not found, could not remove." << endl;

        }

        // void remove(string key)
        // {

        //     int index = hashFunction(key);

        //     HashNode* trav = table[index];
        //     HashNode* prev = NULL;

        //     while (trav != NULL)
        //     {
        //         if (trav->key == key)
        //         {
        //             if (prev == NULL)
        //             {
        //                 table[index] = trav->next;
        //             }
        //             else 
        //             {
        //                 prev->next = trav->next;
        //             }

        //             delete trav;
        //             currSize--;

        //             cout << "Key [" << key << "] removed." << endl;
        //             return;
        //         }

        //         prev = trav;
        //         trav = trav->next;
                
        //     }

        //     cout << "Key [" << key << "] not found, could not remove." << endl;
        // }

        bool search(string key, int &resultValue)
        {
            int index = hashFunction(key);

            HashNode* trav = table[index];

            while(trav != NULL)
            {
                if (trav->key == key)
                {
                    resultValue = trav->value;
                    return true; 
                }

                trav = trav->next;
            }
            return false;
        }

        void display()
        {

            cout << "\n------- Current Hash Table State -------\n";

            for (int m = 0; m < numBuckets; m++)
            {
                cout << "Bucket "<< m << ": " << endl;  
                HashNode* trav = table[m];

                if (trav == NULL)
                {
                    cout << "Empty////" << endl;
                }
                else 
                {
                    while (trav != NULL)
                    {
                        cout << "{" << trav->key << "," << trav->value << "}" << "->";
                        trav = trav->next;
                    }

                    cout << "NULL" << endl;
                }

                cout << endl;
            }

            cout << "-------------------------------------------------\n";

        }
};

int main(void)
{

    HashTable studentsGrades(5);

    cout << "=== Hash Table from scratch (NO STL) ===" << endl; 

    // Insertion forcing collisions
    studentsGrades.insert("Abu Bakar", 80);
    studentsGrades.insert("Ali", 30);
    studentsGrades.insert("usama", 2);
    studentsGrades.insert("Fatima", 49);
    studentsGrades.insert("Waqar", 23);

    // using display()
    studentsGrades.display();

    // moving onto searching////

    int gradeStorer = 0;

    string searchkey = "Abu Bakar";

    if (studentsGrades.search(searchkey, gradeStorer))
    {
        cout << "Found " << searchkey << ":" << gradeStorer << endl;
    }
    else
    {
        cout << searchkey << " not found." << endl;
    }

    // updating

    cout << "\nUpdating Ali's grade: "  << endl;
    studentsGrades.insert("Ali", 100);

    // removing

    cout << "\nRemoving Waqar////" << endl;
    studentsGrades.remove("Waqar");
    
    studentsGrades.display();
    return 0;
}