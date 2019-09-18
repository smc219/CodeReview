#include <stdio.h>
 
#define INF 98
#define QMAX 1001
 
int N, O, M, W;
int num[10], op[5], n[21];
char v[QMAX];
int Q[21][QMAX];
int arr[9][3];
int min, tc;
 
void init1(void)
{
    int i;
 
    for (i = 0; i < 10; ++i)
    {
        num[i] = 0;
    }
    for (i = 0; i < 5; ++i)
    {
        op[i] = 0;
    }
 
    min = -1;
}
 
void init2(void)
{
    int i, j, k, t;
 
    for (i = 0; i <= 20; ++i)
    {
        n[i] = 0;
    }
 
    for (i = 1; i < 10; ++i)
    {
        if (!num[i]) continue;
        Q[1][n[1]++] = i;
        v[i] = tc;
    }
    for (i = 0; i < n[1]; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if (!num[j]) continue;
            t = Q[1][i] * 10 + j;
            v[t] = tc;
            Q[2][n[2]++] = t;
        }
    }
    for (i = 0; i < n[2]; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if (!num[j]) continue;
            t = Q[2][i] * 10 + j;
            v[t] = tc;
            Q[3][n[3]++] = t;
        }
    }
    for (i = 0; i < n[1]; ++i)
    {
        for (j = i; j < n[1]; ++j)
        {
            if (op[1])
            {
                t = Q[1][j] + Q[1][i];
                if (v[t] < tc) { v[t] = tc; Q[4][n[4]++] = t; }
            }
            if (op[2])
            {
                t = Q[1][j] - Q[1][i];
                if (v[t] < tc) { v[t] = tc; Q[4][n[4]++] = t; } 
            }
            if (op[3])
            {
                t = Q[1][j] * Q[1][i];
                if (v[t] < tc) { v[t] = tc; Q[4][n[4]++] = t; }
            }
            if (op[4])
            {
                t = Q[1][j] / Q[1][i];
                if (v[t] < tc) { v[t] = tc; Q[4][n[4]++] = t; }
            }
        }
    }
    if (v[W] >= tc)
    {
        min = 4;
        return;
    }
    if (v[0] < tc)
    {
        if (op[4])
        {
            v[0] = tc;
            if (W == 0)
            {
                min = 5;
                return;
            }
        }
        else if (W == 0) return;
    }
    if (M == 4)
    {
        return;
    }
 
    for (i = 0; i < n[2]; ++i)
    {
        for (j = 0; j < n[1]; ++j)
        {
            if (op[1])
            {
                t = Q[2][i] + Q[1][j];
                if (v[t] < tc) { v[t] = tc; Q[5][n[5]++] = t; }
            }
            if (op[2])
            {
                t = Q[2][i] - Q[1][j];
                if (v[t] < tc) { v[t] = tc; Q[5][n[5]++] = t; }
            }
            if (op[3])
            {
                t = Q[2][i] * Q[1][j];
                if (v[t] < tc) { v[t] = tc; Q[5][n[5]++] = t; }
            }
            if (op[4])
            {
                t = Q[2][i] / Q[1][j];
                if (v[t] < tc) { v[t] = tc; Q[5][n[5]++] = t; }
            }
        }
    }
    if (v[W] >= tc)
    {
        min = 5;
    }
}
 
int chk1(int n)
{
    int cnt = 0;
 
    if (n == 0)
    {
        if (!num[0]) return 0;
        min = 1;
        return 1;
    }
 
    while (n)
    {
        if (!num[n % 10]) return 0;
        n /= 10;
        cnt++;
    }
 
    min = cnt;
 
    return 1;
}
 
int chk2(void)
{
    int i, t;
 
    if (W > 999 || W < 0) return 1;
 
    if (!op[2] && !op[4])
    {
        for (i = 0; i < 10; ++i)
        {
            if (!num[i]) continue;
            t = i;
            break;
        }
        if (W < t) return 1;
    }
    if (!op[1] && !op[3])
    {
        for (i = 9; i >= 0; --i)
        {
            if (!num[i]) continue;
            t = 111 * i;
            break;
        }
        if (W > t) return 1;
    }
     
    return 0;
}
 
void chk3(void)
{
    int i, j, k;
    int t, s;
 
    for (k = 6; k <= 8; ++k)
    {
        for (i = 0; i < n[arr[k][0]]; ++i)
        {
            s = Q[arr[k][0]][i];
            if (op[1])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s + Q[1][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s - Q[1][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s * Q[1][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    if (s <= Q[1][j]) break;
                    t = s / Q[1][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
 
        if (arr[k][0] == 3)
        {
            for (i = 0; i < n[4]; ++i)
            {
                s = Q[4][i];
                if (op[1])
                {
                    for (j = 0; j < n[1]; ++j)
                    {
                        t = s + Q[1][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[2])
                {
                    for (j = 0; j < n[1]; ++j)
                    {
                        t = s - Q[1][j];
                        if (t <= 0) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[3])
                {
                    for (j = 0; j < n[1]; ++j)
                    {
                        t = s * Q[1][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[4])
                {
                    for (j = 0; j < n[1]; ++j)
                    {
                        if (s <= Q[1][j]) break;
                        t = s / Q[1][j];
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
            }
        }
 
        for (i = 0; i < n[arr[k][1]]; ++i)
        {
            s = Q[arr[k][1]][i];
            if (op[1])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s + Q[2][j];
                    if (t >= 1000) break;
                    if (v[t] < tc ) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s - Q[2][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s * Q[2][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    if (s <= Q[2][j]) break;
                    t = s / Q[2][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
        if (arr[k][1] == 3)
        {
            for (i = 0; i < n[4]; ++i)
            {
                s = Q[4][i];
                if (op[1])
                {
                    for (j = 0; j < n[2]; ++j)
                    {
                        t = s + Q[2][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[2])
                {
                    for (j = 0; j < n[2]; ++j)
                    {
                        t = s - Q[2][j];
                        if (t <= 0) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[3])
                {
                    for (j = 0; j < n[2]; ++j)
                    {
                        t = s * Q[2][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[4])
                {
                    for (j = 0; j < n[2]; ++j)
                    {
                        if (s <= Q[2][j]) break;
                        t = s / Q[2][j];
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
            }
        }
 
        for (i = 0; i < n[arr[k][2]]; ++i)
        {
            s = Q[arr[k][2]][i];
            if (op[1])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s + Q[3][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s - Q[3][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s * Q[3][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    if (s <= Q[3][j]) break;
                    t = s / Q[3][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
 
        if (arr[k][2] == 3)
        {
            for (i = 0; i < n[4]; ++i)
            {
                s = Q[4][i];
                if (op[1])
                {
                    for (j = 0; j < n[3]; ++j)
                    {
                        t = s + Q[3][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[2])
                {
                    for (j = 0; j < n[3]; ++j)
                    {
                        t = s - Q[3][j];
                        if (t <= 0) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[3])
                {
                    for (j = 0; j < n[3]; ++j)
                    {
                        t = s * Q[3][j];
                        if (t >= 1000) break;
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
                if (op[4])
                {
                    for (j = 0; j < n[3]; ++j)
                    {
                        if (s <= Q[3][j]) break;
                        t = s / Q[3][j];
                        if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                    }
                }
            }
        }
 
        if (v[W] >= tc) { min = k; return; }
    }
}
 
void chk4(void)
{
    int i, j, k;
    int ck, t, s;
 
    for (k = 9; k <= M; ++k)
    {
        ck = (n[k-2] || n[k-3] || n[k-4]);
        if (!ck) return;
 
        for (i = 0; i < n[k-2]; ++i)
        {
            s = Q[k-2][i];
            if (op[1])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s + Q[1][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s - Q[1][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    t = s * Q[1][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[1]; ++j)
                {
                    if (s <= Q[1][j]) break;
                    t = s / Q[1][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
 
        for (i = 0; i < n[k-3]; ++i)
        {
            s = Q[k-3][i];
            if (op[1])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s + Q[2][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s - Q[2][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    t = s * Q[2][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[2]; ++j)
                {
                    if (s <= Q[2][j]) break;
                    t = s / Q[2][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
 
        for (i = 0; i < n[k-4]; ++i)
        {
            s = Q[k-4][i];
            if (op[1])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s + Q[3][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[2])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s - Q[3][j];
                    if (t <= 0) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[3])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    t = s * Q[3][j];
                    if (t >= 1000) break;
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
            if (op[4])
            {
                for (j = 0; j < n[3]; ++j)
                {
                    if (s <= Q[3][j]) break;
                    t = s / Q[3][j];
                    if (v[t] < tc) { v[t] = tc; Q[k][n[k]++] = t; }
                }
            }
        }
 
        if (v[W] >= tc) { min = k; return; }
    }
}
 
int main(void)
{
    int T;
    int i, t;
 
    arr[6][0] = 3;
    arr[6][1] = 2;
    arr[6][2] = 1;
    arr[7][0] = 5;
    arr[7][1] = 3;
    arr[7][2] = 2;
    arr[8][0] = 6;
    arr[8][1] = 5;
    arr[8][2] = 3;
 
    scanf("%d", &T);
    for (tc = 1; tc <= T; ++tc)
    {
        init1();
 
        scanf("%d %d %d", &N, &O, &M);
        for (i = 0; i < N; ++i)
        {
            scanf("%d", &t);
            num[t]++;
        }
        for (i = 0; i < O; ++i)
        {
            scanf("%d", &t);
            op[t]++;
        }
        scanf("%d", &W);
        if (!chk2() && !chk1(W) && M > 3)
        {
            init2();
            if (W)
            {
                if (min < 0) chk3();
                if (min < 0) chk4();
            }
        }
 
        printf("#%d %d\n", tc, min > M ? -1 : min);
    }
 
    return 0;
}

