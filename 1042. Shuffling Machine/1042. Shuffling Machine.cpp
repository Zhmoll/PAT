#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int K = 0; // 重复次数
	scanf("%d", &K);

	string card[55];
	string card_next[55];
	int move[55] = {0};
	for (int i = 1; i <= 13; i++) {
		card[i] = "S" + to_string(i);
		card[i + 13] = "H" + to_string(i);
		card[i + 26] = "C" + to_string(i);
		card[i + 39] = "D" + to_string(i);
	}
	card[53] = "J1";
	card[54] = "J2";

	for (int i = 1; i <= 54; i++) {
		scanf("%d", move + i);
	}

	for (int times = 0; times < K; times++) {
		for (int i = 1; i <= 54; i++) {
			card_next[move[i]] = card[i].c_str();
		}
		swap(card, card_next);
	}

	for (int i = 1; i <= 54; i++) {
		printf("%s", card[i].c_str());
		if (i != 54)printf(" ");
	}

	return 0;
}