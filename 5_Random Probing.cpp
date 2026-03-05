#include <iostream>
#include <cstdlib>
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
        for(int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while(table[index] != -1) {
            index = (hashFunction(key) + rand()) % SIZE;
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