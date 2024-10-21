#include<stdio.h>
#include<stdlib.h>

#define size 10
int hashtable[size];

int hashFunction(int key){
    return key % size; 
}

void insert(int key){
    int index = hashFunction(key);
    int i = 0;
    while(hashtable[(index + i) % size] != -1){
        i++;
        if(i == size){
            printf("Table full\n");
        }
    }
    hashtable[(index + i) % size] = key;
}

int search(int key) {
    int index = hash_function(key);
    
    int i = 0;
    while (hash_table[(index + i) % TABLE_SIZE] != key) {
        if (hash_table[(index + i) % TABLE_SIZE] == -1 || i == TABLE_SIZE) {
            return -1; // Key not found
        }
        i++;
    }
    return (index + i) % TABLE_SIZE; // Return the index of the found key
}

void display() {
    printf("\n+-----------+-----------+\n");
    printf("| Index     | Key        |\n");
    printf("+-----------+-----------+\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == -1) {
            printf("| %-9d | %-9s |\n", i, "Empty");
        } else {
            printf("| %-9d | %-9d |\n", i, hash_table[i]);
        }
    }
    printf("+-----------+-----------+\n");
}