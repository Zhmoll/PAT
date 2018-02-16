#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int stk[100005] = { 0 };
int stk_Mirror[100005] = { 0 };
int length = 0;

inline void push(int i) {
	stk[length++] = i;
}

inline int pop() {
	return stk[--length];
}

inline int peekMedian() {
	for (int i = 0; i < length; i++)
		stk_Mirror[i] = stk[i];
	sort(stk_Mirror, stk_Mirror + length);
	if (length % 2 == 0)
		return stk_Mirror[length / 2 - 1];
	else
		return stk_Mirror[length / 2];
}

int main() {
	int N, num;
	scanf("%d", &N);
	char action[15] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%s", action);
		if (strcmp(action, "Push") == 0) {
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(action, "Pop") == 0) {
			if (length == 0)
				printf("Invalid\n");
			else
				printf("%d\n", pop());
		}
		else if (strcmp(action, "PeekMedian") == 0) {
			if (length == 0)
				printf("Invalid\n");
			else
				printf("%d\n", peekMedian());
		}
	}
	return 0;
}