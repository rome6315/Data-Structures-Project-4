#include <string>
#include <iostream>

//this struct is used as the object for each array indice in the hashTable class
struct Bucket{
    int key; //course number
    std::string value; //course name

    //constructors
    Bucket();
    Bucket(int key, std::string value);
};
