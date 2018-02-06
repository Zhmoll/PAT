#include <cstdio>
#include <algorithm>

using namespace std;

struct stu {
	int id;
	int C;
	int C_rank;
	int M;
	int M_rank;
	int E;
	int E_rank;
	double A;
	int A_rank;
}item[2005];

stu* result[1000005] = { NULL };

bool cmp_C(stu a, stu b) {
	if (a.C != b.C) return a.C > b.C;
	else return a.id < b.id;
}

bool cmp_M(stu a, stu b) {
	if (a.M != b.M) return a.M > b.M;
	else return a.id < b.id;
}

bool cmp_E(stu a, stu b) {
	if (a.E != b.E) return a.E > b.E;
	else return a.id < b.id;
}

bool cmp_A(stu a, stu b) {
	if (a.A != b.A) return a.A > b.A;
	else return a.id < b.id;
}

int main() {
	int N_COUNT = 0, M_COUNT = 0; // N学生总数，M检查排名的学生总数
	scanf("%d%d", &N_COUNT, &M_COUNT);

	// 输入成绩
	int id, C, M, E, A, t;
	for (int i = 0; i < N_COUNT; i++) {
		scanf("%d %d %d %d", &id, &C, &M, &E);
		item[i].id = id;
		item[i].C = C;
		item[i].M = M;
		item[i].E = E;
		item[i].A = A = (double)(C + M + E) / 3;
	}

	sort(item, item + N_COUNT, cmp_C);
	item[0].C_rank = 1;
	for (int i = 1; i < N_COUNT; i++) {
		if (item[i].C == item[i - 1].C)
			item[i].C_rank = item[i - 1].C_rank;
		else
			item[i].C_rank = i + 1;
	}

	sort(item, item + N_COUNT, cmp_M);
	item[0].M_rank = 1;
	for (int i = 1; i < N_COUNT; i++) {
		if (item[i].M == item[i - 1].M)
			item[i].M_rank = item[i - 1].M_rank;
		else
			item[i].M_rank = i + 1;
	}

	sort(item, item + N_COUNT, cmp_E);
	item[0].E_rank = 1;
	for (int i = 1; i < N_COUNT; i++) {
		if (item[i].E == item[i - 1].E)
			item[i].E_rank = item[i - 1].E_rank;
		else
			item[i].E_rank = i + 1;
	}

	sort(item, item + N_COUNT, cmp_A);
	item[0].A_rank = 1;
	for (int i = 1; i < N_COUNT; i++) {
		if (item[i].A == item[i - 1].A)
			item[i].A_rank = item[i - 1].A_rank;
		else
			item[i].A_rank = i + 1;
	}

	for (int i = 0; i < N_COUNT; i++) {
		result[item[i].id] = &item[i];
	}

	// 输入检查成绩的同学
	for (int i = 0; i < M_COUNT; i++) {
		scanf("%d", &id);
		if (!result[id]) {
			printf("N/A\n");
			continue;
		}

		if (result[id]->A_rank <= result[id]->E_rank&&
			result[id]->A_rank <= result[id]->M_rank&&
			result[id]->A_rank <= result[id]->C_rank)
			printf("%d A\n", result[id]->A_rank);
		else if (result[id]->C_rank < result[id]->A_rank&&
			result[id]->C_rank <= result[id]->M_rank&&
			result[id]->C_rank <= result[id]->E_rank)
			printf("%d C\n", result[id]->C_rank);
		else if (result[id]->M_rank < result[id]->A_rank&&
			result[id]->M_rank < result[id]->C_rank&&
			result[id]->M_rank <= result[id]->E_rank)
			printf("%d M\n", result[id]->M_rank);
		else if (result[id]->E_rank < result[id]->A_rank&&
			result[id]->E_rank < result[id]->M_rank&&
			result[id]->E_rank < result[id]->C_rank)
			printf("%d E\n", result[id]->E_rank);

	}
	return 0;
}