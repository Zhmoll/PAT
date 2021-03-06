#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> Adj;
vector<int> inDegree;
int N, M;

bool topo() {
	int num = 0;
	priority_queue<int> q;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int u = q.top();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0)
				q.push(v);
		}
		num++;
	}
	if (num == N) return true;
	else return false;
}

int main() {

	return 0;
}