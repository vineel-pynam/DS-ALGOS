#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

bool bfs(int v, vector<int> adj[], vector<int> &vis){
	
	queue<pair<int,int>> q;

	for( int i=1; i<v+1; i++ ){
		if( !vis[i] ){

			q.push({i, -1});
			vis[i] = 1;

			while( !q.empty() ){
				pair<int, int> front = q.front();
				q.pop();
				
				int curr = front.first;
				int parent = front.second;

				for( auto it:adj[curr] ){
					if( !vis[it] ){
						q.push({it, curr});
						vis[it] = 1;
					}else if( it != parent ){
						return true;
					}
				}
			}
		}
	}

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
		adj[v].push_back(u);
	}

	vector<int> vis(v+1, 0);

	// print_matrix(v, adj);

	bool ans = bfs(v, adj, vis);

	if( ans ){
		cout << "Cycle is present in the Graph" << endl;
	}else{
		cout << "Cycle is not present in the Graph" << endl;
	}
}