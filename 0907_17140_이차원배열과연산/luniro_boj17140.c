#include <stdio.h>

typedef struct _count
{
    int cnt, n;
} count;
count chk[101], t[101];
int r, c, k;
int a[101][101];
int r_max, c_max, cnt;

void clr(void)
{
    int i;
    
    for (i = 0; i <= 100; ++i)
    {
        chk[i].n = i;
        chk[i].cnt = 0;
    }
}

void msort(int s, int e)
{
    int i, j, k, m;
    if (s + 1 >= e) return;
    m = (s + e) >> 1;
    i = k = s;
    j = m;
    
    msort(s, m);
    msort(m, e);
    
    while (i < m && j < e)
    {
        if (chk[i].cnt > chk[j].cnt) t[k++] = chk[j++];
        else t[k++] = chk[i++];
    }
    while (i < m)
    {
        t[k++] = chk[i++];
    }
    while (j < e)
    {
        t[k++] = chk[j++];
    }
    for (k = s; k < e; ++k)
    {
        chk[k] = t[k];
    }
}

int main(void)
{
    int i, j, idx, tmp;
    
    scanf("%d %d %d", &r, &c, &k);
    for (i = 1; i <= 3; ++i)
    {
        for (j = 1; j <= 3; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    c_max = r_max = 3;
    cnt = 0;
    
    while (cnt <= 100 && a[r][c] != k)
    {
        tmp = 0;
        if (r_max >= c_max)
        {
            for (i = 1; i <= r_max; ++i)
            {
                clr();
                for (j = 1; j <= c_max; ++j)
                {
                    chk[a[i][j]].cnt++;
                }
                msort(0, 101);
                
                idx = 1;
                for (j = 0; j <= 100 && idx <= 100; ++j)
                {
                    if (!(chk[j].n && chk[j].cnt) ) continue;
                    a[i][idx++] = chk[j].n;
                    a[i][idx++] = chk[j].cnt;
                }
                if (idx > tmp) tmp = idx - 1;
                while (idx <= c_max) a[i][idx++] = 0;
            }
            c_max = tmp;
        }
        else
        {
            for (j = 1; j <= c_max; ++j)
            {
                clr();
                for (i = 1; i <= r_max; ++i)
                {
                    chk[a[i][j]].cnt++;
                }
                msort(0, 101);
                
                idx = 1;
                for (i = 0; i <= 100 && idx <= 100; ++i)
                {
                    if (!(chk[i].n && chk[i].cnt) ) continue;
                    a[idx++][j] = chk[i].n;
                    a[idx++][j] = chk[i].cnt;
                }
                if (idx > tmp) tmp = idx - 1;
                while (idx <= r_max) a[idx++][j] = 0;
            }
            r_max = tmp;
        }
        cnt++;
    }
    printf("%d\n", cnt <= 100 ? cnt : -1);
    
    return 0;
}
