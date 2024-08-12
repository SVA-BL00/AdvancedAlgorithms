#include <iostream>
#include <vector>
using namespace std;

// The merge function receives a pointer to an int vector, the left, mid, and right elements.
// Splits the vector in left and right and merges them back sorted in the original vector.
void merge(vector<int>& _array, int _left, int _mid, int _right){
    // DIVIDE
    int n1 = _mid - _left + 1;
    int n2 = _right - _mid;

    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = _array[_left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = _array[_mid + j + 1];
    }

    int i = 0, j = 0;
    int k = _left;
    // CONQUER
    while(i < n1 && j < n2){
        if (L[i] >= R[j]){
            _array[k] = L[i];
            i++;
        }else{
            _array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        _array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        _array[k] = R[j];
        j++;
        k++;
    }

}

// The function mergeSort receives an array, the left, and right indexes. If left and right index is equal, it's the base case.
// Otherwise it gets the mid value, and sends both left and right parts to be divided and merged.
void mergeSort(vector<int>& array, int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(){
    int n, num;
    vector<int> array;
    cout << "Ingresa un numero de elementos: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Ingresa un numero: ";
        cin >> num;
        array.push_back(num);
    }

    mergeSort(array, 0, n - 1);

    for (unsigned int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}