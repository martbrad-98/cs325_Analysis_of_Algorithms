#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;
 
//Psudeocode provided in lecture was used as well as 
//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//https://www.educative.io/blog/0-1-knapsack-problem-dynamic-solution

//Finds the max between two numbers
int Rec_max(int a, int b) { 
  if (a > b){
    return a;
  }
  else{
    return b;
  } 
}

//Finds the Max 
int Rec_knapSack(int W, int wt[], int val[], int n){ 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    //If the weight of an item is too large then get rid of it
    if (wt[n - 1] > W)
        return Rec_knapSack(W, wt, val, n - 1);
 
    // Find the max of the two cases
    else
        return Rec_max(val[n - 1] + Rec_knapSack(W - wt[n - 1], wt, val, n - 1), Rec_knapSack(W, wt, val, n - 1));
}


//Finds the Max between two numbers
int DP_max(int a, int b){
  if (a > b){
    return a;
  }
  else{
    return b;
  }
}
 
//dynamic version of knapsack
int DP_knapSack(int cap, int wt[], int val[], int n)
{
  int i, w;
  int K[n + 1][cap + 1];
 
  // Build a 2d array using n and the capacity of the knapsack
  for(i = 0; i <= n; i++){
    for(w = 0; w <= cap; w++){
      if (i == 0 || w == 0){
        K[i][w] = 0;
      }
      else if (wt[i - 1] <= w){
        K[i][w] = DP_max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      }
      else{
        K[i][w] = K[i - 1][w];
      }
    }
  }
  return K[n][cap];
}

void pop_arr(int *array, int n){
    int random_num;
    //start point for random function
    //populate array with number 0-1000
    for(int i=0; i<n; i++){
        array[i] = (rand()%1000);
    }
}

int main()
{
  //declare variables for 
  int cap = 500;
  int n = 10;
  int DP_time = 0;
  int Rec_time = 0;
  int DPMax = 0;
  int RecMax = 0;
  //start timeer for rand function
  srand((unsigned) time(0));

  while(n<=40){
    int val[n];
    int wt[n];

    pop_arr(val, n);
    pop_arr(wt, n);

    auto begin = chrono::high_resolution_clock::now();
    DP_knapSack(cap, wt, val, n);
    auto end = chrono::high_resolution_clock::now();
    DP_time = chrono::duration_cast<chrono::microseconds>(end-begin).count();

    begin = chrono::high_resolution_clock::now();
    Rec_knapSack(cap, wt, val, n);
    end = chrono::high_resolution_clock::now();
    Rec_time = chrono::duration_cast<chrono::microseconds>(end-begin).count();
    cout << "N=" << n << " W=500  "<< "DP time = " << DP_time << "ms "<< "Rec time = " << Rec_time << "ms max DP = " << DP_knapSack(cap, wt, val, n) <<" max Rec = " << Rec_knapSack(cap, wt, val, n) << endl;

    n = n+5;

  }

     

  return 0;
}