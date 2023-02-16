#include <iostream>
#include <fstream>
#include "hashTable.h"

//Pre-conditon: hashTable is a variable that is an instance of the hashTable class.
//Post-condition: Returns nothing, but reads in the data from the file and inserts it into the hash table.
void readDataFromFile(hashTable &hashTable);

//Pre-condition: hashTable is a variable that is an instance of the populated hashTable class.
//Post-condition: Returns the name of the course searched for by the user.
std::string getUserInput(hashTable &hashTable);

int main(void) {
    std::string courseName = " "; //course name to be searched for
    hashTable table; //create instance of hashTable class
    char again = 'y'; //start the loop and store users response

    while(again == 'y'){
        readDataFromFile(table); //read in data from file and insert into hash table

        courseName = getUserInput(table); //get user input and search for course name

        std::cout << "The courses name is: " << courseName << std::endl << std::endl; //print out course name

        //ask user if they want to search again
        std::cout << "Would you like to search for another course? (y/n): ";
        std::cin >> again;
        std::cout << "---------------------------------------------------------------" << std::endl;
    }


    return 0;
}

//get data from the file and insert into hash table
void readDataFromFile(hashTable &hashTable) {
    std::ifstream file;
    int courseNum = 0;
    std::string courseName = " ";
    int count = 0;

    file.open("data.txt"); //open file

    if (file.is_open()) { //check to make sure its open
        while(!file.eof()) {
            file >> courseNum; //get the course number
            getline(file, courseName); //get the course name
            count++;
            //std::cout << count << ". " << courseNum << " " << courseName << " ";
            hashTable.insert(courseNum, courseName); //insert the course number and name into the hash table
            
            
        }
    }

    //if the file fails to open
    else {
        std::cout << "File is not open" << std::endl;
    }

    file.close(); //close the file
}

//get user input and search for course name
std::string getUserInput(hashTable &hashTable) {
    int courseNum = 0;
    std::string courseName = " ";

    //get users input
    std::cout << "Enter the course number you'd like to look up: ";
    std::cin >> courseNum;
    std::cout << std::endl;

    courseName = hashTable.search(courseNum); //search for the course name

    return courseName; //return the course name
}
