#include <cstdio>
#include <vector>

using namespace std;

struct Record {
	int id, father, mother, M, area;
	int smallest;
	vector<int> child;
};

int getSmallest(Record a) {
	int smallest = a.id;
	if (a.father != -1 && a.father < smallest) smallest = a.father;
	if (a.mother != -1 && a.mother < smallest) smallest = a.mother;
	for(int i=0;i<)
}

struct Asset {
	int M, area;
	int father;
}asset[10005];

int main() {
	int N;
	scanf("%d", N);
	vector<Record > list(N);
	int id, father, mother, k, m, area, child;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &id, &father, &mother, &k);
		list[i].id = id;
		list[i].father = father;
		list[i].mother = mother;
		for (int j = 0; j < k; j++) {
			scanf("%d", child);
			list[i].child.push_back(child);
		}
		scanf("%d%d", &m, &area);
	}

	return 0;
}