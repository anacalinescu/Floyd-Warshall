// C++ Program for Floyd Warshall Algorithm 
#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 

#define INF INT_MAX

// A function to print the solution matrix 
/* A utility function to print solution */
void printSolution(vector<vector<long>> dist, int V) 
{ 
    ofstream outfile; 
    outfile.open("output.txt"); 

	outfile<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				outfile<<"INF"<<"	 "; 
			else
				outfile<<dist[i][j]<<"	 ";
		} 
		outfile<<endl; 
	} 

    outfile.close();
}  

// Solves the all-pairs shortest path 
// problem using Floyd Warshall algorithm 
void floydWarshall (vector<vector<long>> graph, int V) 
{ 
	/* dist[][] will be the output matrix 
	that will finally have the shortest 
	distances between every pair of vertices */
    vector<vector<long>> dist;
	int i, j, k; 

    for(i = 0; i < V; i++) {
        dist.push_back(vector<long>());
        for(j = 0; j < V; j++) {
            dist[i].push_back(0);
        }
    }

	/* Initialize the solution matrix same 
	as input graph matrix. Or we can say 
	the initial values of shortest distances 
	are based on shortest paths considering 
	no intermediate vertex. */
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			dist[i][j] = graph[i][j]; 
        }
    }

	/* Add all vertices one by one to 
	the set of intermediate vertices. 
	---> Before start of an iteration, 
	we have shortest distances between all 
	pairs of vertices such that the 
	shortest distances consider only the 
	vertices in set {0, 1, 2, .. k-1} as 
	intermediate vertices. 
	----> After the end of an iteration, 
	vertex no. k is added to the set of 
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < V; k++) { 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) { 
			// Pick all vertices as destination for the 
			// above picked source 
			for (j = 0; j < V; j++) { 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
                } 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(dist, V); 
} 

// Driver code 
int main() 
{ 
    char data[100];
    vector<vector<long>> graph;
    ifstream infile; 
    infile.open("input.txt"); 

    infile >> data; 

    int V = atoi(data);
    for (int i = 0; i < V; i++) {
        graph.push_back(vector<long>());
        for (int j = 0; j < V; j++) {
            graph[i].push_back(0);
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            infile >> data;
            if (strncmp(data, "INF", 3) == 0) {
                graph[i][j] = INF;
            } else {
                graph[i][j] = atoi(data);
            }
        }
    }

	// Print the solution 
	floydWarshall(graph, V); 
    infile.close();
	return 0; 
} 
