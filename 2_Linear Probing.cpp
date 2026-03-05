#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for(int i=0;i<SIZE;i++)
            table[i] = -1; // EMPTY
    }

    void insert(int key) {
        int index = hashFunction(key);

        while(table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    void print() {
        for(int i=0;i<SIZE;i++)
            cout << i << " : " << table[i] << endl;
    }

    void search(int key) {
        int index = hashFunction(key);

        while(table[index] != -1) {
            if(table[index] == key) {
                cout << "Value is found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
        }

        cout << "Value is not found\n";
    }
};

int main() {
    HashTable h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(21);

    h.print();
}