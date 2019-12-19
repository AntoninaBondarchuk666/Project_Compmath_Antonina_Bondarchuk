#ifndef ORGRAPH_H
#define ORGRAPH_H
#include <stdio.h>
#include<iostream>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src;
	int dest;
	int weight;
};

typedef pair<int, int> Pair;

// class to represent a graph object
class Graph
{
public:
   
	// construct a vector of vectors of Pairs to represent an adjacency list
	vector<vector<Pair>> adjList;
	
	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<Pair>
		adjList.resize(N);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;

			// insert at the end
			adjList[src].push_back(make_pair(dest, weight));
		}
	}
};

//******************************************
    //FUNCTIONS
    void printGraph(Graph const &graph, int N);
    void addedge(list<int> *ls,int x,int y);
    int inputedges(list<int> *ls, vector<Edge> & edges, int n);
    int read_from_file_edges(list<int> *ls, vector<Edge> & edges, int n);
    void DFS(list<int>*ls,int num,int x);
    void displayMatrix(int v);
    void matrix_add_edge(int myvertArr[20][20], int u, int v);
    int random_input(int myvertArr[20][20], list<int>*ls, vector<Edge> & edges, int n);
    int write_to_file_edges(vector<Edge> & edges, int n);
    //******************************************
#endif
