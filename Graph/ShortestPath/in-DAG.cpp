#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(2N) + O(V+E)

*/

void dfs(int vertex, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &topo){
	vis[vertex] = 1;

	for( auto it: adj[vertex] ){
		if( !vis[it.first] ){
			dfs(it.first, adj, vis, topo);
		}
	}

	topo.push(vertex);
}

void findMinDis(vector<pair<int, int>> adj[], stack<int>&topo, vector<int> &dis){

	while( !topo.empty() ){
		int top = topo.top();

		for( auto it:adj[top] ){
			dis[it.first] = min(dis[it.first], dis[top] + it.second);
		}

		topo.pop();
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

	vector<pair<int,int>> adj[v+1];
	vector<int> in_deg(v+1, 0);

	for( int i=0; i<e; i++ ){

		int u, v, w;
		cin >> u >> v >> w;

		pair<int, int> pr = {v, w};
		adj[u].push_back(pr);
	}

	vector<int> vis(v+1, 0);
	stack<int> topo;
	vector<int> dis(v+1, INT_MAX);
	

	dfs(1, adj, vis, topo);

	dis[topo.top()] = 0;
	findMinDis(adj, topo, dis);

	for( int i=1; i<=v; i++) cout << dis[i] << " ";
}