#include <bits/stdc++.h>
#include "orgraph.h"
using namespace std;

// display adjacency matrix in console
void displayMatrix(int vertArr[20][20], int v) {  // v - number of vertices
   int i, j;
   cout << "-------------" << endl;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
          if(vertArr[i][j]!=1){
              vertArr[i][j]=0;
          }
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
   cout << "-------------" << endl;
}

//function to add edge into the matrix
void matrix_add_edge(int vertArr[20][20], int u, int v) {   
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}

// print adjacency list representation of graph
void printGraph(Graph const &graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print all neighboring vertices of given vertex
		for (Pair v : graph.adjList[i])
			cout << "(" << i << ", " << v.first <<
					", " << v.second << ") ";
		cout << endl;
	}
}

//	Make a pair between vertex x and vertex y
void addedge(list<int> *ls, int x, int y){
	ls[x].push_back(y);
	ls[y].push_back(x);
	return;
}

// Input components of all edges: src, dest, weight to "Orgraph_file.txt"
int write_to_file_edges(vector<Edge> & edges, int n){
    
    ofstream  ifs("Orgraph_file.txt");
    int q1,q2,me;
	struct Edge records[n];
	
    if(ifs.fail()) {
        cout << "Error opening student records file (Orgraph_file.txt)" <<endl;
		exit(1);
     }
	int i =0;
	for(int h = 0; h<n; h++){
     	ifs <<  edges[h].src << "  " << edges[h].dest << "  " << edges[h].weight << "\n";
	     }
}

// Input components of all edges: src, dest, weight from "Orgraph_file.txt"
int read_from_file_edges(int vertArr[20][20], list<int> *ls, vector<Edge> & edges, int n){
    
    ifstream  ifs("Orgraph_file.txt");
    int q1,q2,me;
	struct Edge records[n];
	
    if(ifs.fail()) {
        cout << "Error opening student records file (Orgraph_file.txt)" <<endl;
		exit(1);
     }
	int i =0;
	while(! ifs.eof()){
     	ifs >> q1 >> q2 >> me;
	
		records[i].src = q1;
		records[i].dest = q2;
		records[i].weight = me;
		
		addedge(ls,q1,q2);
		
		matrix_add_edge(vertArr, q1, q2);
		i++;
	}  
    for(int h = 0; h<i; h++){
        edges.push_back(Edge());
        edges[h].src = records[h].src;
        edges[h].dest = records[h].dest;
        edges[h].weight = records[h].weight;
    }
    cout << "Entered from Orgraph_file.txt:  \n";
    for(int j = 0; j < i; j++){
        cout << "-------\n";
        cout << " " << edges[j].src << " ";
        cout << edges[j].dest << " ";
        cout << edges[j].weight << "\n";
    }
 
}
 
// Input components of all edges: src, dest, weight from console
int inputedges(int vertArr[20][20], list<int>*ls, vector<Edge> & edges, int n){
    cout << "Input edges:  \n";
    for(int i = 0; i<n; i++){
        edges.push_back(Edge());
        cin >> edges[i].src;
        cin >> edges[i].dest;
        cin >> edges[i].weight;
        
        addedge(ls,edges[i].src,edges[i].dest);
        
        matrix_add_edge(vertArr, edges[i].src, edges[i].dest);
    }
    cout << "You entered:  \n";
    for(int i = 0; i<n; i++){
        cout << "-------\n";
        cout << " " << edges[i].src << " ";
        cout << edges[i].dest << " ";
        cout << edges[i].weight << "\n";
    }
  }

// Random input of components of all edges: src, dest, weight from console
int random_input(int vertArr[20][20], list<int>*ls, vector<Edge> & edges, int n){
    int rand_max1 = n;  // number of vertices
    int rand_max2;
        
    cout << "Input max for weight:  \n";
    cin >> rand_max2;
    
    for(int i = 0; i<n; i++){
        
        edges.push_back(Edge());
        edges[i].src = 0 + rand() %rand_max1;
        edges[i].dest = 0 + rand() %rand_max1;
        edges[i].weight = 0 + rand() %rand_max2;
        
        addedge(ls,edges[i].src,edges[i].dest);
        
        matrix_add_edge(vertArr, edges[i].src, edges[i].dest);
    }
    cout << "You entered:  \n";
    for(int i = 0; i<n; i++){
        cout << "-------\n";
        cout << " " << edges[i].src << " ";
        cout << edges[i].dest << " ";
        cout << edges[i].weight << "\n";
    }
  }
 
//Depth First Search of a Graph
void DFS(list<int>*ls,int num,int x){
	bool *visit= new bool[num];
	for(int i=0;i<num;i++){
		visit[i]=false;
	}
	stack<int> st;
	st.push(x);
	while(!st.empty()){
		int s=st.top();
		st.pop();
		if(!visit[s]){
			cout<<s<< " ";
			visit[s]=true;
			list<int>::iterator it;
			for(it=ls[s].begin();it!=ls[s].end();it++){
				st.push(*it);
			}
		}
	}
}

// Graph Implementation
int main()
{   
    int n; 
    int m;
    cout << "Input number of edges:  \n";
    cin >> n;
    cout << "Input number of vertices:  \n";
    cin >> m;
    
    int vertArr[20][20]; //the adjacency matrix for Graph
   
    vector<Edge> edges;
    
    //vector<Edge> edges =
	//{
	//{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
	//	{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
	//};
	
	list<int> *ls = new list<int>[n];
    //inputedges(vertArr, ls, edges, n);
    random_input(vertArr, ls, edges, m);  // for random input m == n !!!
    //read_from_file_edges(vertArr, ls, edges, n);
    write_to_file_edges(edges, n);
    
    
	Graph graph(edges, m);
	
	//all_addedge(graph, ls, m);
    
	// construct graph
	printGraph(graph, m);
    
    displayMatrix(vertArr, m);
    
    //DFS algorithm
	cout << "\n***DFS***" << endl;
	DFS(ls,m,0);
	return 0;
}
