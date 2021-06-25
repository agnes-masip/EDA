#include <iostream>
#include <vector>

using namespace std;


bool reachable(vector<vector<char> >& M, int r, int c) {
	if(r < 0 or c < 0 or r >= M.size() or c >= M[0].size() or //que no pasa de la matriu
	M[r][c] == 'X') return false;
	
	if (M[r][c] == 't') return true;
    
	M[r][c] = 'X'; //perquè no torni a passar pel . !!!!!!!!!!!!
	
	return reachable(M, r+1,c) or
	reachable(M, r-1,c) or
	reachable(M, r,c+1) or
	reachable(M, r,c-1);
    //dalt,baix, esq i dreta. horitzontal i vertical
}



int main(){

    int n; //number rows
    int m; //number columns
     cin >> n >> m;
    vector<vector<char>> mapa(n, vector<char>(m));
   
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> mapa[i][j];
        }
    }
    int r,c; //initial row and column
    cin >> r >> c;
    if(reachable(mapa,r-1,c-1)) cout << "yes" << endl;
    else cout << "no" << endl;
    
}
