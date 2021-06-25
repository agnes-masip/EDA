#include <iostream>
#include <vector>
using namespace std;
 
int position(double x, const vector<double>& v, int left, int right){
        if (left>right) return -1;
        int mid = (left+right)/2;
        if(v[mid]>v[mid+1]){
            int aux = v[mid]; //no llegir
            v[mid] = v[mid+1];
            v[mid+1] = aux;
            return position(x,v,left,mid);
        }
        if (x<v[mid]) return position (x,v,left,mid-1);
        if (x>v[mid]) return position (x,v,mid+1,right);
        if (mid >= 1){
            int eq = position (x,v,left,mid-1);
            if (eq != -1) return eq;
        }
        return mid;
    }
 

bool resistant_search(double x, const vector<double>& v){
    
      int m = v.size();
    if (m == 0) return -1;
    return position (x,v,0,m-1);
}



int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
