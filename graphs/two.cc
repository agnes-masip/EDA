#include <iostream>
#include <vector>

using namespace std;






int main(){

    int n; //number vertices
    int m; //number edges
    cin >> n >> m;
    vector<pair<int,int>> edges;
   
    for(int j=0;j<m;++j){
            cin >> edges[j].first >> edges[j].second;
    }

    if(n%2==0) cout << "yes" << endl;
    else cout << "no" << endl;
    
}
