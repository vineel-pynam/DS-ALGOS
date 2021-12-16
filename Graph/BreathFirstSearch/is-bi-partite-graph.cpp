#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

bool bfs(int v, vector<int> adj[], vector<int> &vis){
	
	queue<int> q;
	for( int i=1; i<=v; i++ ){
		if( vis[i] == -1){

			q.push(i);
			vis[i] = 0;

			while( !q.empty() ){
				int front = q.front();
				q.pop();

				for( auto it:adj[front] ){

					if( vis[it] == -1){
						q.push(it);
						vis[it] = !vis[front];
					}else if( vis[front] == vis[it] ){
						return false;
					}
				}
			}

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

	bool ans = bfs(v, adj, vis);


	if( ans ){
		cout << "Bi-partite Graph" << endl;
	}else{
		cout << "Not Bi-partite Graph" << endl;
	}
}