
#include <stdio.h>
#define MAX (52)
int Map[MAX][MAX];
int clean[MAX][MAX];
int r, c, dir;
int cnt =1;
int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
void input(void)
{
	int i, j;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}
	for (i = 0; i <= N; i++)
	{
		Map[0][i] = 1;
		Map[N+1][i] = 1;
		Map[i][0] = 1;
		Map[i][N+1] = 1;
		clean[0][i] = 2;
		clean[N + 1][i] = 2;
		clean[i][0] = 2;
		clean[i][N + 1] = 2;
	}
}

int reverseDir(int dir)
{
	if (dir == 0) return 2;
	if (dir == 2) return 0;
	if (dir == 1) return 3;
	if (dir == 3) return 1;
}

void printClean(void)
{
	int i, j;
	for (i = 0; i <= N+1; i++)
	{
		for (j = 0; j <= N + 1; j++)
		{
			printf("%d ", clean[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void clean_process(void)
{
	int cr, cc;
	int nr, nc;
	cr = r+1; cc = c+1;
	printf("%d\n", Map[cr][cc]);
	int chk = 0;
	for (;;)
	{
		clean[cr][cc] = 1;
		
		if(cnt >= 384) printClean();
		dir -= 1;
		if (dir == -1) dir = 3;
		nr = cr + dr[dir]; nc = cc + dc[dir];
		//printf("nr : %d, nc : %d, chk : %d\n\n", nr, nc, chk);
		chk++;

		if (chk == 4)
		{
			int br, bc;
			int newdir = reverseDir(dir);
			br = cr + dr[newdir];
			bc = cc + dc[newdir];
			if (Map[br][bc] == 1 ) break;
			cr = br;
			cc = bc;
			//getch();
			//printClean();
			//printf("%d %d\n", cr, cc);
			//printf("newdir : %d, br : %d, bc : %d\n",newdir, br, bc);
			chk = 0;

		}
		if (Map[nr][nc]) continue;
		if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
		if (clean[nr][nc] == 1) continue;
		//printf("nr : %d, nc : %d\n", nr, nc);
		cr = nr;
		cc = nc;
		cnt++;
		chk = 0;
		
	}
}

int main(void)
{
	input();
	
	clean_process();
	printf("%d\n", cnt);
}
