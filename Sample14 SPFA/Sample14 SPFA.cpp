#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
const int MAXV = 10010;
int n;

struct Node {
	int v, dis;
};

vector<Node> Adj[MAXV];
int m, d[MAXV], num[MAXV];
bool inq[MAXV];

bool SPFA(int s) {
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	fill(d, d + MAXV, INF);

	queue<int> Q;
	q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;

		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;

			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n) return false;
				}
			}
		}
	}
	return true;
}