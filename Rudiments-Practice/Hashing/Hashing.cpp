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

        void insert(string key, int value)
        {
            if (getLoadFactor() > 0.7)
            {
                rehash();
            }

            int index = hashFunction(key);

            // now we check if the key already exists in our program 
            HashNode* trav = table[index];
            HashNode* prev = NULL;

            while (trav != NULL)
            {
                if (trav->key == key)
                {
                    
                }
            }

        }
};

int main(void)
{
    
    return 0;
}