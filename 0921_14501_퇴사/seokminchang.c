
#include <stdio.h>
#define MAX (20)
typedef struct
{
	int day;
	int Ti;
	int Pi;
}COU;
int N;
int wp, rp;
int max;
COU counsel[MAX];
COU Que[MAX * MAX * 30];
void input(void)
{
	int i;
	int num1, num2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &num1, &num2);
		counsel[i].Ti = num1;
		counsel[i].Pi = num2;
	}
}

void InQueue(int day, int ti, int pi)
{
	Que[wp].day = day;
	Que[wp].Ti = ti;
	Que[wp++].Pi = pi;
}

COU OutQueue(void)
{
	return Que[rp++];
}

void printQue(void)
{
	int i;
	for (i = rp; i <= wp; i++)
	{
		printf("%d %d %d\n", Que[i].day, Que[i].Ti, Que[i].Pi);
	}
	printf("\n\n");
}

void BFS(int day)
{
	int i;
	COU out;
	rp = wp = 0;
	if (counsel[day].Ti + day - 1 > N) return;
	InQueue(day, counsel[day].Ti, counsel[day].Pi);
	while (rp < wp)
	{
		out = OutQueue();
		for (i = day + 1; i <= N; i++)
		{
			//if (i == 10) printQue();
			if (out.day + out.Ti > i) continue;
			if (i + counsel[i].Ti - 1 > N) continue;
			InQueue(i, counsel[i].Ti, out.Pi + counsel[i].Pi);
			if (out.Pi + counsel[i].Pi > max) max = out.Pi + counsel[i].Pi;
		}

	}
}	


int main(void)
{
	int i;
	input();
	for (i = 1; i <= N; i++)
	{
		BFS(i);
	}
	printf("%d\n", max);
	return 0;
}
