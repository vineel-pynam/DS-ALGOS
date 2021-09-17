#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int searchEle, int n){
  int low = 0, high=n-1;

  while( low<=high ){
    int mid = low + (high-low)/2;
    if( arr[mid] == searchEle ) return true;

    if( arr[mid] < searchEle ) 
      low=mid+1;
    else
      high=mid-1;
  }

  return false;

}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  
  for( int i=0; i<n; i++ ){
    cin >> arr[i];
  }

  int searchEle;
  cin >> searchEle;

  if( binarySearch(arr, searchEle, n) ){
    cout << "Element Found" << endl;
  }else{
    cout << "Element Not Found!" << endl;
  }

}