#include <iostream>
#include <vector>
#include <queue>
#include <limits>
 
using namespace std;
typedef pair<double, int> Arc;
typedef vector< vector<Arc> > Graf;
 
 
int const INFINITY = numeric_limits<int>::max();
 
 
void dijkstra(const Graf &G, int x, int y, vector<int> &dist,
                     vector<int> &p, int &distance) {
    
    /*1.ficar vector dist a infinit 
     * 2.vector parents/wherefROM A -1
     * 3. dist de x inicial a 0. 
     * 4. crear la priority_queue(invertida)
     * 5. ficar distancia 0 i punt inici (x) 
     * 6. crear vector visited a false;
     */
	distance = -1;
    int n = G.size();
    dist = vector<int>(n, INFINITY);
    dist[x] = 0;
    p = vector<int>(n, -1);
    vector<bool> visited(n, false);
    priority_queue<Arc, vector<Arc>, greater<Arc> > cua;
    cua.push(Arc(0, x));
 
    while (not cua.empty()) { //cua no esta buida
        int u = cua.top().second; // first es la distancia, aixi que agafo el punt
        cua.pop();
 
        if (not visited[u]) { // u no ha esta visited
            visited[u] = true; //ara fiquem que si
            if (u == y) { //si u ja es el nostre desti final, hem acabat
                distance = dist[u];
                return;
            }
            
            //adjacencies
            //si ladjacencia es mes gran que u amb el cost, li baixem elvalor sobreescrribintla. I GUARDEM QUE L'ADJACENCIA AQUELLES ES FILLA DE U. 
            //i fiquem a la priority_queue, la distancia i el punt que acabem de trobar.
            int m = G[u].size();
            for (int i = 0; i < m; ++i) {
                int v_desti = G[u][i].first;
                int cost = G[u][i].second;
                if (dist[v_desti] > dist[u] + cost) {
                    dist[v_desti] = dist[u] + cost;
                    p[v_desti] = u;
                    cua.push(Arc(dist[v_desti], v_desti));
                }
            }
        }
    }
}
 
 
int main() {
	int n;
	int m;
	while (cin >> n >> m) {
		Graf G(n);
        //llegir tripletes
        int aux;
        Arc arco;
        for (int i = 0; i < m; i++) {
            cin >> aux >> arco.first >> arco.second;
            G[aux].push_back(arco); //PUSH_BACK AL FINAL NO DEIXA DE SER UN VECTOR
        }

		vector<int> d;
		vector<int> p; //parents
		int x, y;
		cin >> x >> y;
		int distance;

		dijkstra(G, x, y, d, p, distance);

		if (distance != -1) cout << distance << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}
