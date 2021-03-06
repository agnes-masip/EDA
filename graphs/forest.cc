#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Graph
{
	private:
	
	// number of vertices
	int n;
	
	// pointer -> array containing adjacency lists
	list<int> *adj;
	
	// DFS Search
	void DFS(int v, vector<bool> &visited) {
		visited[v] = true;
		for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (not visited[(*i)]) {
				DFS((*i), visited);
			}
		}
	}
	
	public:
	
	// Constructor
	Graph(int n)
	{
		this->n = n;
		adj = new list<int> [n];
	}
	
	// Add edge
	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	
	// Returns number of connected components
	int connectedComponents() {
		// Initialize visited vector
		vector<bool> visited(n, false);
		int cc = 0;
		
		//
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				DFS(i, visited);
				++cc;
			}
		}
		
		return cc;
	}
};



int main(){

    int n; //number of vertices
    int m; //number of edges
     while (cin >> n >> m){
         Graph g(n);
    
            for(int i=0;i<m;++i){
                int v,w;
                cin >> v >> w;
                g.addEdge(v,w);
            }
        int cc = g.connectedComponents();
        
        if (n - cc == m) { //formula del forest
            cout << cc << endl;
            
        } else cout << "no" << endl;
    }
    
}
