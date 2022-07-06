#include<iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;



//This Algoriythm was written during my freshmen year either CS 161/162
//I could note find the exact lecture slide but I remember the website I used as resources
//https://www.geeksforgeeks.org/merge-sort/
void merge(int *array, int l, int m, int r) {
   //declare index variables
   int i;
   int j; 
   int k;
   int left_size; 
   int right_size;
   //calculate the sizes for left and right arrays
   left_size = m-l+1; 
   right_size = r-m;
   //Create arrays with the calculated size
   int l_arr[left_size]; 
   int r_arr[right_size];
   //populate the left and right arrays from the main array
   for(i = 0; i<left_size; i++)
      l_arr[i] = array[l+i];
   for(j = 0; j<right_size; j++)
      r_arr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //merge the left and right array into the main array in sorted order
   while(i < left_size && j<right_size) {
      if(l_arr[i] <= r_arr[j]) {
         array[k] = l_arr[i];
         i++;
      }else{
         array[k] = r_arr[j];
         j++;
      }
      k++;
   }
  //Add the left array left over elements to the main array
   while(i<left_size) {
      array[k] = l_arr[i];
      i++; 
      k++;
   }
   //Add the right array left over elements to the main array
   while(j<right_size) { 
      array[k] = r_arr[j];
      j++; 
      k++;
   }
}

void mergeSort(int *array, int l, int r) {
  //recursive return for checking the starting and end points
  if(l >= r) {
    return;
  }
  //find the mid point
    int m = l+(r-l)/2;
    //sort the left and right arrays and merge
    mergeSort(array, l, m);
    mergeSort(array, m+1, r);
    merge(array, l, m, r);
}

void pop_arr(int *array, int n){
    int random_num;
    //start point for random function
    srand((unsigned) time(0));
    //populate array with numbers 0-10000
    for(int i=0; i<n; i++){
        array[i] = (rand()%10000);
    }
}

void print_screen(int *arr, int arr_size) {
  //print out the contents of the array
  for(int i=0; i<arr_size; i++){
    if(i==arr_size-1){
      cout << arr[i] << "\n";
    }
    else{
      cout << arr[i] << " ";
    }
  }
}

int main() {
    //size of the array
    int n=0;

    //create array with desired samples
    int arr_1[10000];
    n=10000;
    pop_arr(arr_1,n);
    cout<< "n=10000     ";
    //begin timer for execution time 
    auto begin = chrono::high_resolution_clock::now();
    mergeSort(arr_1, 0, n);
    //end timer for execution time
    auto end = chrono::high_resolution_clock::now();
    //convert the clock cycles to miliseconds and print
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    //Repeat for all desired sample sizes
    
    int arr_2[20000];
    n=20000;
    pop_arr(arr_2,n);
    cout<< "n=20000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_2, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_3[30000];
    n=30000;
    pop_arr(arr_3,n);
    cout<< "n=30000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_3, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_4[40000];
    n=40000;
    pop_arr(arr_4,n);
    cout<< "n=40000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_4, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_5[50000];
    n=50000;
    pop_arr(arr_5,n);
    cout<< "n=50000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_5, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_6[60000];
    n=60000;
    pop_arr(arr_6,n);
    cout<< "n=60000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_6, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_7[70000];
    n=70000;
    pop_arr(arr_7,n);
    cout<< "n=70000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_7, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_8[80000];
    n=80000;
    pop_arr(arr_8,n);
    cout<< "n=80000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_8, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_9[90000];
    n=90000;
    pop_arr(arr_9,n);
    cout<< "n=90000    ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_9, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;

    int arr_10[100000];
    n=100000;
    pop_arr(arr_10,n);
    cout<< "n=100000   ";
    begin = chrono::high_resolution_clock::now();
    mergeSort(arr_10, 0, n);
    end = chrono::high_resolution_clock::now();
    cout<< chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms"<< endl;
}