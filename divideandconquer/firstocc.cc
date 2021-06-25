#include <iostream>
#include <vector>
using namespace std;
 
int position(double x, const vector<double>& v, int left, int right){
  if (left>right) return -1;
  int mid = (left+right)/2;
  if (x<v[mid]) return position (x,v,left,mid-1);
  if (x>v[mid]) return position (x,v,mid+1,right);
  if (mid >= 1){
    int eq = position (x,v,left,mid-1);
    if (eq != -1) return eq;
  }
  return mid;
}
 
 
int first_occurrence (double x, const vector<double>& v){
    int l = v.size();
    if (l == 0) return -1;
    return position (x,v,0,l-1);
}
