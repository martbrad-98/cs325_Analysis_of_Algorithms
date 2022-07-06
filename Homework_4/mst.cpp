#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cmath>
 
using namespace std;
//struct to hold edges information
struct Edge {
    int src, dest, weight;
};
//struct to hold graph information
struct Graph {
    int V, E;
 
    struct Edge* edge;
};
 
//creates a graph 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*)malloc(sizeof( struct Edge));
 
    return graph;
}
 
//calculates 
int calc_weight(int* x_cor, int* y_cor){
    float dist;
    int i;

    dist = sqrt(pow(x_cor[i+1]-x_cor[i], 2)+pow(y_cor[i+1]-y_cor[i], 2));
    
    return round(dist);
}

 
int main(){
int num_testcases;
int V;
int E; // Number of edges in graph

fstream f;                  // open the file 
f.open("graph.txt");
f >> num_testcases;          // read the number of testcases
f >> V;                      // read the number of vertices for testcase

E = ((V-1)*V)/2;             // calculate number of edges for complete graph 

struct Graph* graph = createGraph(V, E);    // create a graph

int x_cor[V];                //create an array of x cordinates
int y_cor[V];                //create an array of y cordinates

for(int i=0; i < V; i++){    //populate coridnate arrays
    f >> x_cor[i];
    f >> y_cor[i];
}
 
    return 0;
}