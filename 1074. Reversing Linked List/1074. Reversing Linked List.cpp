#include <cstdio>
#include <stack>

using namespace std;

struct Node {
	int data;
	int next;
}list[100005];

int main() {
	int head;// the address of the first node,
	int N;// a positive N(<= e5) which is the total number of nodes,
	int K;// a positive K(<= N) which is the length of the sublist to be reversed.

	scanf("%d %d %d", &head, &N, &K);
	int tmp_address, tmp_data, tmp_next;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &tmp_address, &tmp_data, &tmp_next);
		list[tmp_address].data = tmp_data;
		list[tmp_address].next = tmp_next;
	}

	stack<int> position;
	int lastPiece = -1;
	for (int current = head; current != -1; current = list[current].next) {
		position.push(current);
		if (position.size() == K) {
			// 下个链始的位置
			int next = list[current].next;

			//
			int i = current;
			while (position.size() != 1) {
				position.pop();
				list[i].next = position.top();
				i = position.top();
			}
			list[i].next = next;
			position.pop();
			if (lastPiece == -1) {
				head = current;
			}
			else {
				list[lastPiece].next = current;
			}
			lastPiece = i;
			current = i;
		}
	}

	int point = head;
	for (; list[point].next != -1; point = list[point].next) {
		printf("%05d %d %05d\n", point, list[point].data, list[point].next);
	}
	printf("%05d %d -1", point, list[point].data);

	return 0;
}