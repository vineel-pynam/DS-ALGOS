#include<bits/stdc++.h>
using namespace std;

/*
	Time Complexity : O((V+E)logN)
	Space Complexity: O(2N) + O(V+E)

*/

void findMinDis(vector<pair<int, int>> adj[], priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> &pq, vector<int> &dis){

	pq.push({0, 1});
	dis[1] = 0;

	while( !pq.empty() ){
		
		int prev = pq.top().second;
		pq.pop();

		for( auto it: adj[prev]){
			int next = it.first;
			int nextDist = it.second;

			if( dis[next] > dis[prev] + nextDist ){

				dis[it.first] = dis[prev] + it.second;
				pq.push({nextDist, next});
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

	vector<pair<int,int>> adj[v+1];
	vector<int> in_deg(v+1, 0);

	for( int i=0; i<e; i++ ){

		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> dis(v+1, INT_MAX);

	findMinDis(adj, pq, dis);

	for( int i=1; i<=v; i++) cout << dis[i] << " ";
}