#include <iostream>
#include <vector>

using namespace std;

bool bishops (vector<vector<int>> board,int n, int m, int i,int j){
    if(i < n and j>m and i >= n and j >= m) return false;
    else{
        if(board[i][j] == 'X') return false;
        
        return bishops(board,n,m,i+1,j+1) or bishops(board,n,m,i-1,j-1);
    }
}

int main(){
    
    int t;
    cin >> t;
    int cases =1;
    while (cases <= t){

    int n; //number rows
    int m; //number columns
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int> (m));
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> board[i][j];
        }
    }
    cout << "Case " << cases <<": ";
    if(bishops(board,n,m,0,0)) cout << "yes" << endl;
    else cout << "no"<< endl;
    
    cases--;
   
        
    }

}
