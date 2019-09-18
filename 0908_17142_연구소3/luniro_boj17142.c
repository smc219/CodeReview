#include <stdio.h>

typedef struct _point
{
    int y, x;
} P;
P virus[10], Q[2501];
int head, tail;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int N, M;
int a[52][52], v[52][52];
int chk[10], v_max, min = 9999;
int top = 100000000, step = 10000;
int cnt, blank;

void input(void)
{
    int i, j;
    
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) continue;
            v[i][j] = top;
            if (a[i][j] == 2)
            {
                virus[v_max].y = i;
                virus[v_max].x = j;
                v_max++;
            }
            else blank++;
        }
    }
}

void clr(void)
{
    int i, j;
    
    head = tail = 0;
    top -= step;
    cnt = 0;
    for (i = 0; i < v_max; ++i)
    {
        a[virus[i].y][virus[i].x] = 2;
    }
}

int bfs(void)
{
    P c, n;
    int k, tmp = 0;
    
    while (head != tail && cnt < blank)
    {
        c = Q[head++];
        
        for (k = 0; k < 4; ++k)
        {
            n.y = c.y + dy[k];
            n.x = c.x + dx[k];
            tmp = v[c.y][c.x] + 1;
            
            if (tmp >= v[n.y][n.x]) continue;
            v[n.y][n.x] = tmp;
            Q[tail++] = n;
            if (!a[n.y][n.x]) cnt++;
        }
    }
    return tmp;
}

void check(int n)
{
    int tmp;
    
    if (cnt < blank) return;
    tmp = n % step;
    if (tmp < min) min = tmp;
}

void func(int idx, int s)
{
    int i;
    
    if (s >= M)
    {
        for (i = 0; i < v_max; ++i)
        {
            if (!chk[i]) continue;
            Q[tail++] = virus[i];
            v[virus[i].y][virus[i].x] = top - step;
        }
        check(bfs() );
        clr();
        return;
    }
    
    for (i = idx; i < v_max; ++i)
    {
        if (chk[i]) continue;
        chk[i]++;
        func(i + 1, s + 1);
        chk[i]--;
    }
}

int main(void)
{
    input();
    if (!blank)
    {
        printf("0\n");
        return 0;
    }
    func(0, 0);
    printf("%d\n", min == 9999 ? -1 : min);
    return 0;
}
