// KMP ALGORITHM

#include<bits/stdc++.h>
using namespace std;

void makeLPS(int pat[], string pattern, int patternSize){
	// MAKING PATTERN ARRAY
	int j=0, i=1;
	
	while( i<patternSize ){
		if( pattern[i] == pattern[j] ){
			pat[i] = j + 1;

			i++;
			j++;
		}else{
			if( j==0 ) i++;
			if( j>0 ){
				j = pat[j-1];
			}
			
		}
	}
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// START OF PROGRAM
	string text = "GEEKS FOR GEEKS";
	string pattern = "GEEKS";


	int textSize = text.size();
	int patternSize = pattern.size();

	int pat[patternSize];
	for( int i=0; i<patternSize; i++ ) pat[i]=0;

	makeLPS(pat, pattern, patternSize);
	
	int i=0, j=0;
	while( i<textSize ){

		if( text[i] == pattern[j] ){
			i++;
			j++;
			if( j>=patternSize ){
				cout << i-j << " ";
				j = pat[j-1];
			}
		}else{
			if( j==0 ) i++;
			if( j>0 ) j = pat[j-1];
		}
	}


}

