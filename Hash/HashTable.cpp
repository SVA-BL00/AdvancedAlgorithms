#include "HashTable.hpp"

HashTable::HashTable(){
    this -> totalSize = 11;
    table = new std::list<int>[totalSize];

    srand(time(NULL));

    int initializer = totalSize * 2 + (rand() % 10);
    this -> prime = getPrime(initializer);

    a = rand() % totalSize;
    b = 1 + (rand() % totalSize);

    size = 0;
}

HashTable::HashTable(int _totalSize){
    int t_size = getPrime(_totalSize);
    this -> totalSize = t_size;
    table = new std::list<int>[totalSize];

    srand(time(NULL));

    int initializer = totalSize * 2 + (rand() % 10);
    this -> prime = getPrime(initializer);

    this -> a = rand() % totalSize;
    this -> b = 1 + (rand() % totalSize);

    size = 0;
}

bool HashTable::checkPrime(int n){
    if (n == 1 || n == 0){
        return false;
    }
    int sqr_root = sqrt(n);
    for (int i = 2; i <= sqr_root; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int HashTable::getPrime(int n){
    if (n % 2 == 0){
        n++;
    }
    while (!checkPrime(n)){
        n += 2;
    }
    return n;
}

int HashTable::universalFunction(int k){
    int index = ((a * k + b) % prime) % totalSize;
    return index;
}

int HashTable::quadraticProb(int k, int tries){
    int index = (universalFunction(k) + a * tries + b * tries * tries) % totalSize;
    return index;
}

void HashTable::insertItem(int data){
    int tries = 0;
    int index;
    do{
        index = quadraticProb(data, tries);
        tries++;
    } while (!table[index].empty());
    table[index].push_back(data);
    size += 1;
    isLoaded();
}

void HashTable::deleteItem(int data){
    int tries = 0;
    int index;
    do{
        index = quadraticProb(data, tries);
        tries++;
    } while (table[index].empty());
    table[index].remove(data);
    size -= 1;
}

void HashTable::displayTable(){
    for (int i = 0; i < totalSize; i++){
        std::cout << "Table[" << i << "]";
    for (auto x: table[i]){
        std::cout << "-->" << x;
    }
    std::cout << std::endl;
    }
}

void HashTable::isLoaded(){
    if ((float)size / totalSize >= LOAD_FACTOR){
        std::list<int>* temp = table;
        int oldSize = totalSize;

        totalSize *= 2;
        HashTable newHashTable = HashTable(totalSize);

        for (int i = 0; i < oldSize; i++) {
            for (int key : temp[i]) {
                newHashTable.insertItem(key);
            }
        }
        delete[] table;

        this->table = newHashTable.table;
        this->totalSize = newHashTable.totalSize;
        this->size = newHashTable.size;
        this->prime = newHashTable.prime;
        this->a = newHashTable.a;
        this->b = newHashTable.b;

        newHashTable.table = nullptr;
    }
}