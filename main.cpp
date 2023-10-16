#include <iostream>
#define INFINITE 10000000

using namespace std;

int minDistance(int dist[], bool visited[], int size)
{
	int min = INFINITE;
	int pos;

	for(int i = 0; i < size; i++){
		if(!visited[i] && dist[i] <= min){
			min = dist[i];
			pos = i;
		}
	}
	return pos;
}


void dijkstra(int **graph, int source, int size){
	int distance[size];
	bool isVisited[size];

	for(int i = 0; i < size; i++){
		distance[i] = INFINITE;
		isVisited[i] = false;
	}

	distance[source] = 0;

	for(int i = 0; i < size-1; i++){
		int pos = minDistance(distance, isVisited, size);
		isVisited[pos] = true;

		for(int j = 0; j < size; j++){
			if(!isVisited[j] && graph[pos][j] && distance[pos] + graph[pos][j] < distance[j] && distance[pos] != INFINITE){
				distance[j] = distance[pos] + graph[pos][j];
			}
		}
	}

	cout << "Source Vertex         " << "Distance From Source" << endl;
	for (int i = 0; i < size; i++){
		cout << i << "                              " << distance[i] << endl;
	}	
}


int main()
{
	int size = 5;	
	int matrix[size][size] =  {{ 0, 0, 3, 0, 2 },
							   { 0, 0, 1, 7, 1 },
							   { 3, 1, 0, 7, 10 },                         
							   { 0, 7, 7, 0, 3 },
							   { 2, 10, 0, 3, 0 }};
	
	
	int** graph = new int*[size];
	for(int i = 0; i < size; i++){
		graph[i] = new int[size];
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			graph[i][j] = matrix[i][j];
		}
	}

	dijkstra(graph, 0, size);

	return 0;
}
