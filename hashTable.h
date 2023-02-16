#include <iostream>
#include "hashNode.h"

#define TABLE_SIZE 59 //set table size 

class hashTable{
    private:
        int collisions; //count collisions
        Bucket table[TABLE_SIZE]; //static array at compile time
    public:
        hashTable(); //constructor
        ~hashTable(); //destructor
        int hash(int key); //hash function
        void quadraticProbing(int index, int key, std::string value); //quadratic probing function
        void insert(int key, std::string value); //insert items into table
        std::string search(int key); //search by course number
        void print(); //print the hash table
};
