#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;

//This Algoriythm was written during my freshmen year either CS 161/162
//I could note find the exact lecture slide but I remember a website I used as resources
//https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int arr_size) {
  //
  for (int i = 1; i < arr_size; i++) {
    //set a compare value
    int comp = arr[i];
    int j = i - 1;
    //shift the contents of the array one position ahead of the compare value
    while (comp < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    //shift the compare value
    arr[j + 1] = comp;
  }
}

void pop_arr(int *array, int n){
    int random_num;
    //start point for random function
    srand((unsigned) time(0));
    //populate array with number 0-10000
    for(int i=0; i<n; i++){
        array[i] = (rand()%10000);
    }
}

int main () {
    //size of the array
    int n=0;

    //create array with desired samples
    int arr_1[5000];
    n=5000;
    pop_arr(arr_1, n);
    cout<< "n=5000     ";
    //begin timer for execution time
    auto begin = chrono::high_resolution_clock::now();
    insertionSort(arr_1, n);
    //end timer for execution time
    auto end = chrono::high_resolution_clock::now();
    //convert the clock cycles to miliseconds and print
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    //Reapeat for all desired sample sizes

    int arr_2[10000];
    n=10000;
    pop_arr(arr_2,n);
    cout<< "n=10000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_2, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_3[15000];
    n=15000;
    pop_arr(arr_3,n);
    cout<< "n=15000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_3, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_4[20000];
    n=20000;
    pop_arr(arr_4,n);
    cout<< "n=20000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_4, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_5[25000];
    n=25000;
    pop_arr(arr_5,n);
    cout<< "n=25000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_5, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_6[30000];
    n=30000;
    pop_arr(arr_6,n);
    cout<< "n=30000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_6, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_7[35000];
    n=35000;
    pop_arr(arr_7,n);
    cout<< "n=35000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_7, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_8[40000];
    n=40000;
    pop_arr(arr_8,n);
    cout<< "n=40000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_8, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_9[45000];
    n=45000;
    pop_arr(arr_9,n);
    cout<< "n=45000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_9, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_10[50000];
    n=50000;
    pop_arr(arr_10,n);
    cout<< "n=50000    ";
    begin = chrono::high_resolution_clock::now();
    insertionSort(arr_10, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;
  return 0;
}