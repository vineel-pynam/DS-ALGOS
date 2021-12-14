#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O(V+E)
	Space Complexity: O(V+E)

*/

void bfs(int v, vector<int> adj[], vector<int> &vis){

	queue<int> q;

	for( int i=1; i<v+1; i++ ){

		if( !vis[i] ){
			
			q.push(i);
			vis[i] = 1;



			while( !q.empty() ){
				int front = q.front();
				q.pop();
				cout << front << " ";
				for( auto it: adj[front] ){
					if( !vis[it] ){
						q.push(it);
						vis[it] = 1;
					}
				}
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

	for( int i=0; i<e; i++ ){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(v+1);

	bfs(v, adj, vis);
}