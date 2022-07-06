#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
  fstream f;
  string str;
  string sn;
  int n=0;
  int mid=0;
  
  f.open("data.txt", fstream::in);

  while(getline(f, str)){
    if(str.empty()){
      break;
    }

    stringstream ss(str);
    string word;
    ss >> word;
    n = stoi(word);
    int arr[n];
    int i=0;
    
    while(ss >> word){
      arr[i] = stoi(word);
      i++;
    }
      // cout << "Array before Sorting: ";
      // display(arr, n);
      mergeSort(arr, 0, n);
      cout << "Array after Sorting: ";
      display(arr, n);
    }


}