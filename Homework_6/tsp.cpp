#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <vector>
 
using namespace std;


//References used for code
//https://www.techiedelight.com/graph-implementation-using-stl/
//https://stackoverflow.com/questions/36374812/how-can-i-create-an-adjacency-matrix-using-vectors-in-a-templated-graph-class-in
//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
//https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-2-weighted-graph/
//https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
//https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
struct edge{                //struct to hold componects of graph
    int src, dest, weight;
};

void create_graph(){

}

//midifed version of prims using vectors
int travllingSalesmanProblem(vector<vector<int>>& graph, int s, int V){
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
        // store current Path weight(cost)
        int current_pathweight = 0;
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

void addEdge(){

}
//function to calculate distance
int calc_weight(int* x_cor, int* y_cor){
    float dist;
    int i;

    dist = sqrt(pow(x_cor[i+1]-x_cor[i], 2)+pow(y_cor[i+1]-y_cor[i], 2));  //compute distance with floating point
    
    return round(dist);  // round value to nearest integer
}

int main(){
int V; // Number of Verticies
int E; // Number of edges in graph

fstream f;                  // open the file 
f.open("graph.txt");
f >> V;                      // read the number of vertices for testcase

vector<vector<int>> graph;   // vector to store graph

create_graph();

E = ((V-1)*V)/2;             // calculate number of edges for complete graph 

int id[V];
int x_cor[V];                //create an array of x cordinates
int y_cor[V];                //create an array of y cordinates

for(int i=0; i < V; i++){    //populate cordinate arrays
    f >> x_cor[i];
    f >> y_cor[i];
}
 
    return 0;
}