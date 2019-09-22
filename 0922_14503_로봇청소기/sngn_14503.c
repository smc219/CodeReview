#pragma warning(disable : 4996)

/* 14503. 로봇 청소기 */
#if 0
/*
https://www.acmicpc.net/problem/14503
*/
#endif
#if 0
#include <stdio.h>
#define MAX (55)
typedef struct str
{
	int y, x;
}POS;
int a[MAX][MAX];
int V[MAX][MAX]; // 청소여부체크
int N, M;
POS init;
int dir;
POS Q[MAX*MAX*2];
int wp, rp;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
POS dd[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int cnt;

void input(void)
{
	int i,j;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &init.y, &init.x, &dir);
	init.y++;
	init.x++;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void CLEAN_WORK(void)
{
	int i;
	POS robot;
	POS chk;

	wp=rp=0; cnt=0;
	Q[wp++] = init;

	while(wp>rp)
	{
		robot = Q[rp++];
	}
}

void CLEANING(void)
{
	int i;
	POS robot = {0};
	POS chk;

	wp=rp=0; cnt=0;
	Q[wp++] = init;
	V[init.y][init.x] = 1; // cleaned
	cnt++;

	while(wp>rp)
	{
		robot = Q[rp++];
		for(i=0;i<4;i++)
		{

			// 항상 왼쪽방향 체크
			if(dir-1<0)
			{
				chk.y = robot.y+dy[dir+3];
				chk.x = robot.x+dx[dir+3];
			}
			else
			{
				chk.y = robot.y+dy[dir-1];
				chk.x = robot.x+dx[dir-1];
			}

			
			if(dir-1<0) dir+=4;
			dir--;

			if(V[chk.y][chk.x]==0 && a[chk.y][chk.x]==0) 
			{
				//printf("%d [%d] %d %d -> %d %d\n", i, dir, robot.y, robot.x, chk.y, chk.x);
				robot = chk; // 전진
				V[robot.y][robot.x]=1; // 청소
				cnt++; // 청소한 칸의 개수
				i = (-1);
			}
		}
		// 회전없이 뒤로 한 칸
		if(dir-2<0)
		{
			robot.y+=dy[dir+2];
			robot.x+=dx[dir+2];
		} 
		else
		{
			robot.y+=dy[dir-2];
			robot.x+=dx[dir-2];
		}
		if(a[robot.y][robot.x]) continue;
		Q[wp++] = robot;
	}
}
int main(void)
{
	input();
	CLEANING();
	printf("%d\n", cnt);

	return 0;
}
#endif