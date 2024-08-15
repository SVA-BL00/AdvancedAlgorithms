#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <list>
#include <string>
#include <time.h>
#include <cmath>
#include <iostream>

class HashTable{
    public:
        HashTable();
        HashTable(int totalSize);

        ~HashTable(){
            delete[] table;
        }

        void insertItem(int);
        void deleteItem(int);
        void displayTable();

    private:
        const double LOAD_FACTOR = 0.80;
        int size, totalSize, prime, a, b;
        std::list<int> *table;

        bool checkPrime(int);
        int getPrime(int);
        int universalFunction(int);
        int quadraticProb(int, int);
        void checkSize();
};
#endif