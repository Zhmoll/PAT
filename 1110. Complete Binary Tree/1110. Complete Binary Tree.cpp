#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
struct Node {
	int lchild = -1, rchild = -1;
	bool isRoot = true;
}node[25];
int main() {
	int N;
	cin >> N;
	string lstr, rstr;
	int lchild, rchild;
	for (int i = 0; i < N; i++) {
		cin >> lstr >> rstr;
		if (lstr == "-")lchild = -1;
		else {
			lchild = stoi(lstr);
			node[lchild].isRoot = false;
		}
		if (rstr == "-")rchild = -1;
		else {
			rchild = stoi(rstr);
			node[rchild].isRoot = false;
		}
		node[i].lchild = lchild;
		node[i].rchild = rchild;
	}
	int root = -1;
	for (int i = 0; i < N; i++) {
		if (node[i].isRoot) {
			root = i;
			break;
		}
	}

	queue<int> q;
	q.push(root);
	int cnt = 0;
	int current = q.front();
	while (q.front() != -1) {
		current = q.front();
		q.pop();
		cnt++;
		q.push(node[current].lchild);
		q.push(node[current].rchild);
	}
	if (cnt == N) {
		printf("YES %d", current);
	}
	else {
		printf("NO %d", root);
	}
	return 0;
}