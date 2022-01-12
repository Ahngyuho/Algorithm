#include<stdio.h>

#define INF 1000000
int C[100001];
int d[2];

int main() {
	int N;
	scanf("%d", &N);

	d[0] = 2;
	d[1] = 5;

	for (int i = 1; i <= N; i++) {
		C[i] = INF;
		for (int j = 0; j < 2; j++) {
			if (i - d[j] >= 0) 
			{
				if(C[i - d[j]] + 1 < C[i])
				C[i] = C[i - d[j]] + 1;
			}
		}
	}

	
	if (C[N] == INF)
		printf("-1");
	else
	printf("%d", C[N]);
}