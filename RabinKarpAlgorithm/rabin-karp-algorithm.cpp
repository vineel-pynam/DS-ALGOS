// RABIN KARP ALGORITHM

#include<bits/stdc++.h>
using namespace std;

#define PRIME 3

long create_hash(string s, int end);
long recalculate_hash(string s, int old_index, int old_hash, int new_index, int patternSize);
bool check_equals(string text, int start, int end, string pattern, int patternSize);

void pattern_search(string text, string pattern){
	int textSize = text.size();
	int patternSize = pattern.size();

	int patternHash = create_hash(pattern, patternSize-1);
	int textHash = create_hash(text, patternSize-1);

	for( int i=1; i<=textSize-patternSize+1; i++ ){

		if( textHash == patternHash && check_equals(text, i-1, i+patternSize-2, pattern, patternSize ) ){
			cout << i-1 << " ";
		}else{
			textHash = recalculate_hash(text, i-1, textHash, i+patternSize-1, patternSize);
		}
	}

}


long create_hash(string s, int end){
	long hash = 0;
	
	for( int i=0; i<=end; i++ ){
		hash += s[i] * pow(PRIME, i);
	}

	return hash;
}

long recalculate_hash(string s, int old_index, int old_hash, int new_index, int patternSize){

	long new_hash = old_hash - s[old_index];
	new_hash /= PRIME;
	new_hash += s[new_index] * pow(PRIME, patternSize-1);
	return new_hash;
}


bool check_equals(string text, int start, int end, string pattern, int patternSize){

	int i=0, j=patternSize-1;

	while( start <= end && i <= j){
		if( text[start] != pattern[i] ) return false;
		i++;
		start++;
	}
	
	return true;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// START OF PROGRAM
	string text = "ababcabcabababd";
	string pattern = "ababd";

	pattern_search(text, pattern);
	
}