#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

// returns maximum of two parameters that are received

int max(int a, int b){
    if (a > b)
        return a;
     else
        return b;

}

int DP_knapsack(int cap, int wt[], int val[], int n, int Maxwt){
  int i, w;
  int K[n + 1][W + 1];
 
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
     // stores the result of Knapsack
     int res = K[i][w];
     int w = cap;
    //Add items to array
     return K[n][cap];

}

int main(){
    int T;          //test cases
    int n;          //number of items items
    int val[100];   //prices
    int wt[100];    //weights of items
    int num_p;      //number of people
    int Maxwt = 0;  //Max weight

    fstream f;
    f.open("shopping.txt")

    //read the value of T
    f >> T;

    //loop for how many test cases we have
    for (int k = 0; k < T; k++){
        f >> n;
        //read the price and weight of each item
        for (int i = 0; i < n; i++){
            f >> val[i];
            f >> wt[i];
        }
        int max_price = 0;

        //read number of people
        f >> num_p;
        //find max price of items that can be carried by
        for (int j = 0; j < num_p; j++){
            //read the max weight
            f >> Maxwt;
            //find the max price a person can carry
            max_price = max_price + DP_knapsack();
        }
        //print the array with what the family can carry
        for (int t = 0; t < num_p; t++){
  
        }
    }
    return 0;

}