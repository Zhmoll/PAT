#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector<int> shuffling(55);
vector<string> card(55);
vector<string> card_tmp(55);
int main() {
	int K;
	scanf("%d", &K);

	char tmp[2] = { 0 };
	for (int i = 1; i <= 13; i++) {
		card[i] = "S" + to_string(i);
		card[i + 13] = "H" + to_string(i);
		card[i + 26] = "C" + to_string(i);
		card[i + 39] = "D" + to_string(i);
	}
	card[53] = "J1";
	card[54] = "J2";

	for (int i = 1; i <= 54; i++) {
		scanf("%d", &shuffling[i]);
	}

	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= 54; j++) {
			card_tmp[shuffling[j]] = card[j];
		}
		card = card_tmp;
	}
	for (int i = 1; i <= 54; i++) {
		printf("%s", card[i].c_str());
		if (i != 54) printf(" ");
	}
	return 0;
}