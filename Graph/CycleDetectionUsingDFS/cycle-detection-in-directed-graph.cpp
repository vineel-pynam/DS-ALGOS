#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

bool dfs(int v, vector<int> adj[], vector<int> &vis, vector<int> &dfsCheck){
	
	vis[v] = 1;
	dfsCheck[v] = 1;

	for( auto it:adj[v] ){
		if( !vis[it] ){
			if( dfs(it, adj, vis, dfsCheck) ) return true;
		}else if( dfsCheck[it] ){
			return true;
		}
	}

	dfsCheck[v] = 0;
	return false;
}


void print_matrix(int v, vector<int> adj[]){

	for( int i=0; i<v+1; i++ ){
		cout << i << " : ";
		for( auto i : adj[i] ){
			cout << i << " ";
		}
		cout << endl;
	}

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int v, e;
	cin >> v >> e;

	vector<int> adj[v+1];

	for( int i=0; i<e; i++ ){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	
	}

	vector<int> vis(v+1, 0);
	vector<int> dfsCheck(v+1, 0);


	for( int i=1; i<=v; i++ ){

		if( !vis[i] ){

			bool ans = dfs(i, adj, vis, dfsCheck);
			if( ans ){
				cout << "Cycle is present in the Graph" << endl;
				return 0;
			}

		}
	}


	cout << "Cycle is not present in the Graph" << endl;
	
}