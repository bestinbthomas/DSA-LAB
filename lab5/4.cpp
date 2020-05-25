
#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void printSolution(int dist[], int V) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int *graph, int src, int V) 
{ 
	int dist[V]; 

	bool sptSet[V];

	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet, V); 

		sptSet[u] = true; 

		for (int v = 0; v < V; v++) {
            int weight = *((graph + u*V) + v);
			if (!sptSet[v] && weight && dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
        }
	} 

	printSolution(dist, V); 
} 

int main() 
{ 
    int V;
    cin>>V;
    int g[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin>>g[i][j];
        }
    }

	dijkstra((int *)g, 0, V); 

	return 0; 
} 
