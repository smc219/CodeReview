#include <stdio.h>

#define INF 987654321

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int b[6][22][22];
int N, cnt, max;
int s[4];

void chkMax(void)
{
    int i, j;
    
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            if (max >= b[5][i][j]) continue;
            max = b[5][i][j];
        }
    }
}

void func(int i, int n, int k)
{
    int j = s[k];
    int j2 = j - dx[k];
    int tmp;
    
    while (b[n][i][j] != INF)
    {
        if (j == j2) j2 -= dx[k];
        while (!b[n][i][j2])
        {
            j2 -= dx[k];
        }
        if (b[n][i][j2] == INF) return;
        
        if (!b[n][i][j])
        {
            tmp = b[n][i][j2];
            b[n][i][j2] = 0;
            b[n][i][j] = tmp;
        }
        else if (b[n][i][j] == b[n][i][j2])
        {
            b[n][i][j] <<= 1;
            b[n][i][j2] = 0;
            j -= dx[k];
        }
        else
        {
            j -= dx[k];
            tmp = b[n][i][j2];
            b[n][i][j2] = 0;
            b[n][i][j] = tmp;
        }
    }
}

void func2(int j, int n, int k)
{
    int i = s[k];
    int i2 = i - dy[k];
    int tmp;
    
    while (b[n][i][j] != INF)
    {
        if (i == i2) i2 -= dy[k];
        while (!b[n][i2][j])
        {
            i2 -= dy[k];
        }
        if (b[n][i2][j] == INF) return;
        
        if (!b[n][i][j])
        {
            tmp = b[n][i2][j];
            b[n][i2][j] = 0;
            b[n][i][j] = tmp;
        }
        else if (b[n][i][j] == b[n][i2][j])
        {
            b[n][i][j] <<= 1;
            b[n][i2][j] = 0;
            i -= dy[k];
        }
        else
        {
            i -= dy[k];
            tmp = b[n][i2][j];
            b[n][i2][j] = 0;
            b[n][i][j] = tmp;
        }
    }
}

void move(int n, int k)
{
    int i, j;
    
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            b[n+1][i][j] = b[n][i][j];
        }
    }
    n++;
    
    if (k & 1)
    {
        for (i = 1; i <= N; ++i)
        {
            func(i, n, k);
        }
    }
    else
    {
        for (j = 1; j <= N; ++j)
        {
            func2(j, n, k);
        }
    }
}

void dfs(int n)
{
    int k;
    
    if (n >= 5)
    {
        chkMax();
        return;
    }
    
    cnt++;
    
    for (k = 0; k < 4; ++k)
    {
        move(n, k);
        dfs(n + 1);
    }
}

int main(void)
{
    int i, j;
    
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            scanf("%d", &b[0][i][j]);
        }
    }
    
    s[0] = s[1] = N;
    s[2] = s[3] = 1;
    for (i = 0; i <= N + 1; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            b[j][i][0] = b[j][i][N+1] = b[j][0][i] = b[j][N+1][i] = INF;
        }
    }
    
    dfs(0);
    printf("%d\n", max);
    
    return 0;
}
