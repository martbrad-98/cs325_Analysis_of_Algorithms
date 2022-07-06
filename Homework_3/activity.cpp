#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

//Outside references used:
//https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/
//https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

//create struct each activity
struct activity{
    int act_num;
    int start;
    int finish;
};

//bubble sort to sort by start time
void sort(activity* act_arr, int n){
    activity temp;                  // create a temp struct
    for(int i=1; i < n; i++){       //loop through the amount of actvites we have
        for(int j=0; j < n-1; j++){
            if(act_arr[j].start < act_arr[j+1].start){  //check the start times
                temp = act_arr[j];                      //swap the activites j is less than j+1
                act_arr[j] = act_arr[j+1];
                act_arr[j+1] = temp;
            }
        }
    }
}

//reverse the order of the array
void reverse_arr(activity* act_arr, int n){
    int start = 0;
    int end = n-1;
    activity temp2; // create temp struct
    while(start < end){ // loop thorugh while there are still things to reverse
        temp2 = act_arr[start];          //swap the two ends of the array
        act_arr[start] = act_arr[end];
        act_arr[end] = temp2;
        start++;
        end--;
    }
}

//select the path that chooses the maximum amount of activites
void act_path(activity* act_arr, int* path, int n, int num_act){
    int i=0;
    path[num_act] = act_arr[i].act_num; //the first start time always gets chosen first
    num_act++;

    for(int j = 1; j < n; j++){         //loop through the number of activites
        if(act_arr[j].start >= act_arr[i].finish){      //if the start time of an activite is greater than or equal to the finish of our selected activity
            path[num_act] = act_arr[j].act_num;         // add it to the path list
            num_act++;                                  // increase our number of activites
            i = j;                                      // update what our current activity is
        }
    }
}

int main(){
int n;                      //number of activites
int num_act=0;              //number of selected activites
int path[256];              //array to hold chosen path
for(int i=0; i<256; i++){
    path[i]=0;
}

fstream f;                  //open the file 
f.open("act.txt");
f >> n;                     //read the number of activites
activity act_arr[n];        //creat and array of structs of size n

for(int i=0; i < n; i++){   // read into the struct array the corresponding numbers
    f >> act_arr[i].act_num;
    f >> act_arr[i].start;
    f >> act_arr[i].finish;
}

//sort the array
sort (act_arr, n);

//revers the order
reverse_arr(act_arr, n);

//use the greedy algorithm
act_path(act_arr, path, n, num_act);

//print path 
for(int i=0; i<num_act; i++){
    cout << path[i] << " ";
}

    return 0;
}