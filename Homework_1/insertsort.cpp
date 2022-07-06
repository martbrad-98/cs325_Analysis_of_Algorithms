#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
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

int main () {
  //declare variables for opening a file and reading
  fstream f;
  string str;
  int arr_size=0;
  
  //open the data.txt file
  f.open("data.txt", fstream::in);

  //read line by line
  while(getline(f, str)){
    //if the last string is emtpy then we have reached the end
    if(str.empty()){
      break;
    }
    //parse the first element as the array size
    stringstream ss(str);
    string word;
    ss >> word;
    arr_size = stoi(word);
    int arr[arr_size];
    int i=0;
    //parse the rest of the string into an array of ints
    while(ss >> word){
      arr[i] = stoi(word);
      i++;
    }
    //sort and print array
    insertionSort(arr, arr_size);
    print_screen(arr, arr_size);
  }
  return 0;
}