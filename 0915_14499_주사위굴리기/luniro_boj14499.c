#include <stdio.h>

int dy[] = {0, 0, 0, -1, 1};
int dx[] = {0, 1, -1, 0, 0};

int a[22][22], dice[6];
int N, M, x, y, K;

void input(void)
{
    int i, j;
    
    scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= M; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void init(void)
{
    int i, j;
    
    x++;
    y++;
    
    for (i = 0; i <= N + 1; ++i)
    {
        a[i][0] = a[i][M+1] = -1;
    }
    for (j = 0; j <= M + 1; ++j)
    {
        a[0][j] = a[N+1][j] = -1;
    }
}

void rolldice(int k)
{
    int tmp;
    
    if (k == 1)
    {
        tmp = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    }
    else if (k == 2)
    {
        tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = tmp;
    }
    else if (k == 3)
    {
        tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = tmp;
    }
    else if (k == 4)
    {
        tmp = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[0];
        dice[0] = tmp;
    }
}

int movedice(int k)
{
    if (a[y+dy[k]][x+dx[k]] < 0) return 0;
    
    y += dy[k];
    x += dx[k];
    
    rolldice(k);
    
    if (!a[y][x])
    {
        a[y][x] = dice[5];
    }
    else
    {
        dice[5] = a[y][x];
        a[y][x] = 0;
    }
    
    return 1;
}

void operation(void)
{
    int t, i;
    for (i = 0; i < K; ++i)
    {
        scanf("%d", &t);
        if (movedice(t) ) printf("%d\n", dice[2]);
    }
}

int main(void)
{
    input();
    init();
    operation();
    
    return 0;
}
