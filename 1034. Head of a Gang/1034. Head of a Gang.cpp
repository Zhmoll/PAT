// 可以用并查集再实现本题！
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node {
	string to;
	int time;
	Node(string to, int time) :to(to), time(time) {};
};

map<string, vector<Node>> input;
map<string, int> node_weight;
map<string, bool> visited;
map<string, int> gang;
int threshold;
int gang_weight;
string gang_head;
int gang_count;

void DFS(string name) {
	visited[name] = true;
	for (int i = 0; i < input[name].size(); i++) {
		if (!visited[input[name][i].to]) {
			if (node_weight[gang_head] < node_weight[input[name][i].to]) {
				gang_head = input[name][i].to;
			}
			gang_weight += node_weight[input[name][i].to];
			gang_count++;
			DFS(input[name][i].to);
		}
	}
}

void DFSTravesal() {
	map<string, bool>::iterator it = visited.begin();
	for (; it != visited.end(); it++) {
		if (!visited[it->first]) {
			// 初始化一个团伙
			gang_weight = node_weight[it->first];
			gang_count = 1;
			gang_head = it->first;
			// 遍历
			DFS(it->first);
			// 产生记录
			if (gang_weight > threshold*2 && gang_count > 2) {
				gang[gang_head] = gang_count;
			}
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	threshold = K;

	// input
	string name1, name2;
	int time;
	for (int i = 0; i < N; i++) {
		cin >> name1 >> name2 >> time;
		input[name1].push_back(Node(name2, time));
		visited[name1] = false;
		node_weight[name1] += time;
		node_weight[name2] += time;
	}

	DFSTravesal();

	cout << gang.size() << endl;
	map<string, int>::iterator it = gang.begin();
	for (int i = 0; i < gang.size(); i++, it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}