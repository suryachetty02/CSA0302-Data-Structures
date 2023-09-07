#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Define a structure for a hash table entry
struct Entry {
    int key;
    int value;
};

// Define the hash table
struct Entry hashTable[TABLE_SIZE];

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;  // Initialize keys to -1 to indicate empty slots
        hashTable[i].value = -1; // Initialize values to -1
    }
}

// Hash function to calculate the index for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table using linear probing
void insert(int key, int value) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Function to search for a key in the hash table
int search(int key) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    return -1; // Key not found
}

// Function to display the contents of the hash table
void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Key: %d, Value: %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    initializeTable();

    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(31, 40);

    displayTable();

    int searchKey = 11;
    int result = search(searchKey);

    if (result != -1) {
        printf("Value for key %d: %d\n", searchKey, result);
    } else {
        printf("Key %d not found in the hash table.\n", searchKey);
    }

    return 0;
}
