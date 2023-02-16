#include "hashNode.h"

//defualt constructor
Bucket::Bucket() {
    key = 0;
    value = " ";
}

//specific constructor
Bucket::Bucket(int key, std::string value) {
    this->key = key;
    this->value = value;
}
