#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;


struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }


    void insert(int key) {
        int index = hashFunction(key);

        Node* newNode = new Node(key);


        if (table[index] == nullptr) {
            table[index] = newNode;
        } 
        else {
            Node* temp = table[index];

            while (temp != nullptr) {
                if (temp->data == key) {
                    cout << "Element already exists!\n";
                    delete newNode;
                    return;
                }
                if (temp->next == nullptr)
                    break;
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }


    bool find(int key) {
        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }

        return false;
    }


    void remove(int key) {
        int index = hashFunction(key);

        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == key) {

                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }

                delete temp;
                cout << "Deleted successfully\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Element not found\n";
    }


    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(7);

    ht.print();

    cout << "\nFind 25: " << (ht.find(25) ? "Found" : "Not Found") << endl;

    ht.remove(25);
    ht.print();

    return 0;
}