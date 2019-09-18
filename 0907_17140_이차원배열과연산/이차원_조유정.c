// #17140. 이차원 배열과 연산
#if 0
#include <stdio.h>
#define MAX (110)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int r, c, k;
int A[MAX][MAX];
int visited[MAX];
int cnt;
int cnts[MAX];
int idx[MAX];
int rlen = 3;
int clen = 3;

void Input(void)
{
	int i, j;
	scanf("%d %d %d", &r, &c, &k);
	for (i = 1; i <= rlen; i++)
	{
		for (j = 1; j <= clen; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
}

void Sort_Arrs(void)
{
	int i, j, tmp;
	for (i = 1; i <= cnt; i++)
	{
		for (j = i + 1; j <= cnt; j++)
		{
			if ((cnts[i] > cnts[j]) || ((cnts[i] == cnts[j]) && (idx[i] > idx[j])))
			{
				tmp = cnts[i];
				cnts[i] = cnts[j];
				cnts[j] = tmp;
				tmp = idx[i];
				idx[i] = idx[j];
				idx[j] = tmp;
			}
		}
	}
}

void Calc_Row(void)
{
	int i, j;
	int tmp, lim;
	int max = 0;

	for (i = 1; i <= rlen; i++)
	{
		cnt = 0;
		for (j = 1; j <= clen; j++)
		{
			if (A[i][j] == 0) continue;
			if (visited[A[i][j]] == 0){
				visited[A[i][j]] = ++cnt;
				idx[cnt] = A[i][j];
				cnts[cnt] = 0;
			}
			cnts[visited[A[i][j]]]++;
		}

		Sort_Arrs();

		lim = MIN(clen, 50);
		for (j = 1; j <= lim; j++)
		{
			if (j <= cnt)
			{
				A[i][2 * j - 1] = idx[j];
				A[i][2 * j] = cnts[j];
			}
			else A[i][2 * j - 1] = A[i][2 * j] = 0;
		}

		for (j = 1; j <= cnt; j++)
		{
			visited[idx[j]] = 0;
		}

		tmp = MIN(cnt * 2, 100);
		if (tmp > max) max = tmp;
	}
	clen = max;
}

void Calc_Col(void)
{
	int i, j;
	int tmp, lim;
	int max = 0;

	for (j = 1; j <= clen; j++)
	{
		cnt = 0;
		for (i = 1; i <= rlen; i++)
		{
			if (A[i][j] == 0) continue;
			if (visited[A[i][j]] == 0){
				visited[A[i][j]] = ++cnt;
				idx[cnt] = A[i][j];
				cnts[cnt] = 0;
			}
			cnts[visited[A[i][j]]]++;
		}

		Sort_Arrs();

		lim = MIN(rlen, 50);
		for (i = 1; i <= lim; i++)
		{
			if (i <= cnt)
			{
				A[2 * i - 1][j] = idx[i];
				A[2 * i][j] = cnts[i];
			}
			else A[2 * i - 1][j] = A[2 * i][j] = 0;
		}

		for (i = 1; i <= cnt; i++)
		{
			visited[idx[i]] = 0;
		}

		tmp = MIN(cnt * 2, 100);
		if (tmp > max) max = tmp;
	}
	rlen = max;
}

int Get_Sol(void)
{
	int t = 0;
	int i, j;
	for (;;)
	{
		if (A[r][c] == k) return t;
		if (t > 100) return -1;
		if (rlen >= clen) Calc_Row();
		else Calc_Col();

		/*
		getch();
		printf("%d %d %d ***\n", t, rlen, clen);
		for(i = 1; i <= rlen; i++)
		{
		for(j = 1; j <= clen; j++)
		{
		printf("%2d ", A[i][j]);
		}
		printf("\n");
		}
		printf("\n\n");
		*/
		t++;
	}
}

int main(void)
{
	Input();
	printf("%d\n", Get_Sol());
	return 0;
}
#endif