#include "hashTable.h"

//defualt constructor 
hashTable::hashTable() {
    collisions = 0;
}

//destructor
hashTable::~hashTable() {
    std::cout << "Destructor ran \n" << std::endl; //so we know it ran
}

//Pre-condition: Key is an integer value, the course number, read in from the file.
//Post-conditon: Returns an integer value, the index of the bucket for the hash table.
int hashTable::hash(int key) {
    return key % TABLE_SIZE; //standard hash function
    
}

/*Pre-condition: Index is an integer value, the index of the bucket for the hash table. Key is an integer value, the course number, read in from the file. 
Value is a string value, the course name, read in from the file.*/
//Post-condition: Returns nothing. Inserts the key and value into the hash table uisng quadratic probing.
void hashTable::quadraticProbing(int index, int key, std::string value) {
    collisions++; //if we enter this function, its because a collision occured
        for(int j = collisions; j < TABLE_SIZE; j++) {
            int t = (index + j * j) % TABLE_SIZE; //compute new index t
            //if this index is empty, insert the key and value
                if(table[t].key == 0) {
                    table[t].key = key;
                    table[t].value = value;
                    //std::cout << table[t].key << " " << table[t].value << " " << "New Bucket: " << t << std::endl;
                    break;
                }
                //if the index is not empty, increment j and try again
                else{
                    //std::cout << table[t].key << " " << table[t].value << " " << "Collision at: " << t << std::endl;
                    collisions++;
                }
        }
}

//Pre-condition: Key is an integer value, the course number, and value is a string, the course name, read in from the file.
//Post-conditon: Returns nothing, but inserts the key and value into the hash table at their calculated indice.
void hashTable::insert(int key, std::string value) {
    int index = hash(key); //use normal hash function
    //std::cout << "Bucket: " << index << std::endl;
    if (table[index].key == 0) {
        table[index].key = key;
        table[index].value = value;
    }
    
    //a collision occured so time to use quadratic probing
    else {
        quadraticProbing(index, key, value);
    }
    
}

//Pre-condition: Key is an integer value, the course number.
//Post-conditon: Returns a string value, the course name, that is being searched for by the user. Returns "Invalid course number" if the course number is not in the hash table.
std::string hashTable::search(int key) {
    collisions = 0; //reset collisions or else the computed indices will be off
    std::string NOT_FOUND = "Invalid course number ! \n";

    int index = hash(key); //use normal hash function

    //if the key is found at the computed index, return the value
    if (table[index].key == key) {
        return table[index].value;
    }

    //if we get a collision, use quadratic probing to find the key, in short, we retrace our steps from the insert function
    else {
        for(int j = collisions; j < TABLE_SIZE; j++) {
            int t = (index + j * j) % TABLE_SIZE;
            if(table[t].key == key) { //once we find the course, return the course name
                return table[t].value;
            }
        }
    }
    return NOT_FOUND; //return this if the course number doesn't exist
}

//Pre-condition: None, except that the hash table should be populated.
//Post-conditon: Returns nothing, but prints the hash table to the console.
void hashTable::print() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(table[i].key != 0) { //make sure the bucket is not empty
            std::cout << table[i].key << " " << table[i].value << std::endl;
        }
    }
}
