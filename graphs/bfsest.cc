#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool ok(int x, int y, const vector<vector<char> >& M) {
	return (x >= 0 and x < int(M.size()) and y >= 0 and y < int(M[0].size()) and M[x][y] != 'X');
}

int distancia_minima(int origX, int origY, vector<vector<char> >& M) {
	int files = M.size();
	int cols = M[0].size();
    /*1. crear una matriux igual de gran que la matriu de l'enunicat (mapa)
     * 2. crear una cua i ficar el punt d'origin.
     * 3. la matriu nova guardara totes les distancies, aixi que la de l punt origen ficarla a 0   
     */
	
	queue<pair<int,int> > Q;
	vector<vector<int> > dist(files, vector<int>(cols));
	
	Q.push({origX,origY});
	dist[origX][origY] = 0;
	
	while (Q.size() > 0) {
        
        //lo tipic de canviar de cua a alguna altra variable
		pair<int, int> punt = Q.front();
		int x = punt.first;
		int y = punt.second;
		Q.pop();
        
        //if del que volem trobat
		
		if (M[x][y] == 't') return dist[x][y];
        //assegurarnos que no es loop infinit 
		M[x][y] = 'X';
		//si la pos esta be, fem push a la cua i canviem les distancies 
		if (ok(x+1, y, M)) {Q.push({x+1,y}); dist[x+1][y] = dist[x][y] + 1;}
		if (ok(x-1, y, M)) {Q.push({x-1,y}); dist[x-1][y] = dist[x][y] + 1;}
		if (ok(x, y+1, M)) {Q.push({x,y+1}); dist[x][y+1] = dist[x][y] + 1;}
		if (ok(x, y-1, M)) {Q.push({x,y-1}); dist[x][y-1] = dist[x][y] + 1;}
	}
	return -1;
}



	int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<char> > M(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> M[i][j];
	
	int origX, origY;
	cin >> origX >> origY;
	--origX;
	--origY;
	
	int dist = distancia_minima(origX, origY, M);
	
	if(dist == -1) cout << "no treasure can be reached"; 
	else cout << "minimum distance: " << dist;
	cout << endl;
}
