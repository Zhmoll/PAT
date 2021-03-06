// 16点43分
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct record {
	char name[24];
	int month;
	int dd, hh, mm;
	int time;
	char action[12];
};

int toll[24];
vector<record> input, result;

bool cmp(record &a, record &b) {
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else return a.time < b.time;
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &toll[i]);
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		record a;
		scanf("%s %d:%d:%d:%d %s", a.name, &a.month, &a.dd, &a.hh, &a.mm, a.action);
		a.time = a.dd * 24 * 60 + a.hh * 60 + a.mm;
		input.push_back(a);
	}

	sort(input.begin(), input.end(), cmp);

	for (int i = 1; i < input.size(); i++) {
		if (strcmp(input[i].name, input[i - 1].name) == 0) {
			if (strcmp(input[i].action, "off-line") == 0 && strcmp(input[i - 1].action, "on-line") == 0) {
				result.push_back(input[i - 1]);
				result.push_back(input[i]);
			}
		}
	}

	char current_name[24] = { 0 };
	double total_amount = 0;
	for (int i = 0; i < result.size(); i += 2) {
		if (strcmp(result[i].name, current_name) != 0) {
			if (i != 0)
				printf("Total amount: $%.2f\n", total_amount / 100);
			strcpy(current_name, result[i].name);
			total_amount = 0;
			printf("%s %02d\n", result[i].name, result[i].month);
		}
		printf("%02d:%02d:%02d %02d:%02d:%02d %d ", result[i].dd, result[i].hh, result[i].mm,
			result[i + 1].dd, result[i + 1].hh, result[i + 1].mm, result[i + 1].time - result[i].time);
		int amount = 0;
		int dd1 = result[i].dd;		int hh1 = result[i].hh;		int mm1 = result[i].mm;
		int dd2 = result[i + 1].dd;		int hh2 = result[i + 1].hh;		int mm2 = result[i + 1].mm;
		while (dd1 < dd2 || hh1 < hh2 || mm1 < mm2) {
			amount += toll[hh1];
			mm1++;
			if (mm1 == 60) {
				mm1 = 0;
				hh1++;
				if (hh1 == 24) {
					hh1 = 0;
					dd1++;
				}
			}
		}
		printf("$%.2f\n", (double)amount / 100);
		total_amount += amount;
	}
	printf("Total amount: $%.2f\n", total_amount / 100);
	return 0;
}