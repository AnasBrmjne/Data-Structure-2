#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

public:
    HashTable() {
        for(int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = hash1(key);
        int i = 0;

        while(table[index] != -1) {
            index = (hash1(key) + i * hash2(key)) % SIZE;
            i++;
        }

        table[index] = key;
    }

    void print() {
        for(int i = 0; i < SIZE; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    HashTable h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);

    h.print();
}