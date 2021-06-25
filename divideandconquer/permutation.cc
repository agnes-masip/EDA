#include <iostream>
#include <vector>


using namespace std;


int exp(vector<int>& v,int i,int expo){
    if(expo!=0){
        
        int x = exp(v,i,expo/2);
        if(expo%2==0) return x*x;
        else return x*x*v[i];
    }
}

void permutation(vector<int>& v, int k){
    
    for(int i=0;i<v.size();++i){
        int aux = v[i];
        int power = exp(v,i,k);
        v[i] = v[power];
        v[power] = aux;
        
    }
    
}

void swap_0(vector<int>& v, int k){
    for(int i=0;i<v.size();++i){
        v[i] = i;
    }
}
int main(){
    int n,k;
    
    while(cin >> n){
        vector<int> v(n);
        for(int i=0;i<n;++i) cin >> v[i];
            cin >> k;
        if(k != 0){
            permutation(v,k);
        }else swap_0(v,k);
        for(int i=0;i<n;++i) cout << v[i] << " ";
        
    }
    
}                            
