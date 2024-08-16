#include "HashTable.hpp"
using namespace std;

int main(){
    int op, num;
    HashTable example;
    do{
        cout << "---EJEMPLO DE HASH TABLE---\n[1] INSERT\n[2] DELETE\n[3] PRINT\n[4] EXIT" << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Dime un numero: ";
                cin >> num;
                example.insertItem(num);
                break;
            case 2:
                cout << "Dime un numero: ";
                cin >> num;
                example.deleteItem(num);
                break;
            case 3:
                example.displayTable();
                break;
            case 4:
                exit(1);
            default:
                cout << "No válido" << endl;
        }
    }while (op != 4);
    return 0;

}