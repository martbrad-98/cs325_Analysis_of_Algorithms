#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
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
  //declare variables for opening a file and reading
  fstream f;
  string str;
  int n=0;
  //open the data.txt file
  f.open("data.txt", fstream::in);

  //read line by line
  while(getline(f, str)){
    //if the last string is empty then we have reached the end
    if(str.empty()){
      break;
    }
    //parse the first element as the array size
    stringstream ss(str);
    string word;
    ss >> word;
    n = stoi(word);
    int arr[n];
    int i=0;
    //parse the rest of the string into an array of ints
    while(ss >> word){
      arr[i] = stoi(word);
      i++;
    }
      //sort and print array
      mergeSort(arr, 0, n);
      print_screen(arr, n);
    }
  return 0;
}