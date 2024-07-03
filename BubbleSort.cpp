#include <iostream>

using namespace std;
            // average and worst case O(n^2) --> Quadratic time. Not efficient. 

void bubbleSort(int a[], int size) {
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
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
        1 2 3 4 5 6 7 8 9

     */

}

