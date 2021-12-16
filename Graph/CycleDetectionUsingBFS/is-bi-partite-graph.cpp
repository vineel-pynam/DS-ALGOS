#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

bool dfs(int v, int color, vector<int> adj[], vector<int> &vis){
	
	vis[v] = color;

	for( auto it:adj[v] ){
		if( vis[it] == -1 ){
			if( !dfs(it, !color, adj, vis) ) return false;
		}else if( vis[it] == vis[v] ){
			return false;
		}
	}

	return true;
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
		adj[v].push_back(u);
	}

	vector<int> vis(v+1, -1);

	for( int i=1; i<=v; i++ ){
		if( vis[i] == -1 ){

			bool ans = dfs(i, 0, adj, vis);

			if( !ans ){
				cout << "Not Bi-partite Graph" << endl;
				return 0;
			}

		}
	}


	cout << "Bi-partite Graph" << endl;
	
}