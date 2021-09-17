#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int searchEle){

  if( low <= high ){

    int mid = low + (high-low)/2;

    if( arr[mid] == searchEle ) return true;
    
    if( arr[mid] > searchEle ) 
      return binarySearch(arr, low, mid-1, searchEle);
    else
      return binarySearch(arr, mid+1, high, searchEle);
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

  if( binarySearch(arr, 0, n-1, searchEle) ){
    cout << "Element Found" << endl;
  }else{
    cout << "Element Not Found!" << endl;
  }

}