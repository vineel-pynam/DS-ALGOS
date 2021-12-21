#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

void bfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &dis){
	
	queue<int> q;
	q.push(vertex);
	vis[vertex] = 1;
	dis[vertex] = 0;

	while( !q.empty() ){
		int front = q.front();
		q.pop();

		for( auto it:adj[front]){
			if( !vis[it] ){
				q.push(it);
				vis[it] = 1;
				dis[it] = min(dis[it], dis[front] + 1);
			}
		}
	}	
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
	vector<int> in_deg(v+1, 0);

	for( int i=0; i<e; i++ ){

		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	vector<int> vis(v+1, 0);
	vector<int> dis(v+1, INT_MAX);
	
	for( int i=1; i<=v; i++ ){
		if( !vis[i] ){
			bfs(i, adj, vis, dis);
		}
	}

	for( int i=1; i<=v; i++) cout << dis[i] << " ";
}