#include <stdio.h>

typedef struct _bitset
{
  long long b[2];
} bs;

int tc, T;
int N;
int arr[22][22];
bs chk[2][22][22];
int max;

void func(int y, int x);
{
  if (!y) return;

  
}

int main(void)
{
  int i, j, k;

  scanf("%d", T);
  for (tc = 1; tc <= T; ++tc)
  {
    max = 0;
    for (k = 0; k < 2; ++k)
    {
      for (i = 1; i <= N; ++i)
      {
        for (j = 1; j <= N; ++j)
        {
          chk[k][i][j] = 0;
        }
      }
    }

    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
    {
      for (j = 1; j <= N; ++j)
      {
        scanf("%d", &a[i][j]);
      }
    }

    for (i = 1; i <= N; ++i)
    {
      for (j = 1; j <= N; ++j)
      {
        makechk();
      }
    }

    for (i = 1; i < N-1; ++i)
    {
      if ((N-i)<<1 <= max) break;
      for (j = 2; j < N; ++j)
      {
        func(i, j);
      }
    }

    printf("#%d %d\n", tc, max);
  }

  return 0;
}
