#include <cstdio>
#include <cstring>
using namespace std;
int rate[24];

struct phoneCall {
	int begindd;
	int beginhh;
	int beginmm;
	int enddd;
	int endhh;
	int endmm;
};

struct bill {
	char name[25] = { 0 };
	int month;
	vector<phoneCall> call;
};

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", rate + i);
	}
	int N;
	scanf("%d", &N);
	int month, date, hour, minute;
	char name[25] = { 0 };
	char action[10] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d:%d %s", name, &month, &date, &hour, &minute, action);




	}



	return 0;
}