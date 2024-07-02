#include <iostream>

using namespace std;
            // O(n^2) --> Quadratic time. Not efficient. 

void bubbleSort(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i;j++) {
            if (array[j] > array[j + 1]) { //if the jth element of array is greater than the next element
                int temp = array[j]; // store position j of array in temp variable
                array[j] = array[j + 1]; // set the next element into position of j of array
                array[j + 1] = temp; // set temp into postion of the next element 
            }
        }
    }
}



int main() {

    int myArray[] = { 6,4,2,5,1,3,8,9,7};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6

     */

}

