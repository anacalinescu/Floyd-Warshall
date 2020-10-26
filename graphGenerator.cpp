#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>
using namespace std; 

int main() { 
    long long V = 1000;
    ofstream outfile; 
    outfile.open("input.txt"); 

    outfile << V << "\n"; 

    for(long long i = 0; i < V; i++) {
        for(long long j = 0; j < V; j++) {
            if ( i == j) {
                outfile << "INF" << " ";
            } else {
                int number = rand() % 90 + 10;
                outfile << number << " ";
            }
        }
        outfile << "\n";
    }
    outfile.close();
	return 0; 
} 