#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	vector<int> to;
	int amount;
	bool isRetailer;
	bool isRoot;
};

vector<Node> node;
vector<bool> visited;

int main() {
	int N, K;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	node.resize(N);
	visited.resize(N);
	node[0].isRoot = true;
	node[0].isRetailer = false;
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);

		if (K == 0) {
			// retailer
			int amount;
			scanf("%d",&amount);
			node[i].isRetailer = true;
			node[i].isRoot = false;
			node[i].amount = amount;
		}
		else {
			// distributor
			int tmp;
			node[i].isRetailer = false;
			for (int j = 0; j < K; j++) {
				scanf("%d", &tmp);
				node[i].to.push_back(tmp);
				node[tmp].isRoot = false;
			}
		}		
	}

	queue<int> q;
	q.push(0);
	fill(visited.begin(), visited.end(), false);
	visited[0] = true;
	double retailer_sum = 0;
	int level = 0;
	while (q.size() != 0) {
		int len = q.size();
		level++;
		for (int i = 0; i < len; i++) {
			int current = q.front();
			q.pop();
			Node &currentNode = node[current];
			if (currentNode.isRetailer) {
				retailer_sum += currentNode.amount * P * pow(r / 100 + 1, level-1);
			}
			for (int j = 0; j < currentNode.to.size(); j++) {
				if (!visited[currentNode.to[j]]) {
					visited[currentNode.to[j]] = true;
					q.push(currentNode.to[j]);
				}
			}
		}
	}

	printf("%.01f", retailer_sum);

	return 0;
}