#include <stdio.h>

int dp[12];
int answer(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	
	if (dp[n] != 0) return dp[n];
		
	return answer(n - 1) + answer(n - 2) + answer(n - 3);
}

int main(void) {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", answer(n));
	}
}

/*
1=> 1

2=> 1+1
	2

3=> 1+1+1
	2+1
	1+2
	3

4=> 
    끝자리 수(1,2,3)에 맞게 정렬
	-------------------------------------------
	1로   끝나는 경우의 수: (n-1) 경우의수 + 1
	2로   끝나는 경우의 수: (n-2) 경우의수 + 2
	3으로 끝나는 경우의 수: (n-3) 경우의수 + 3
	-------------------------------------------
	1+1+1+1
	1+2+1
	2+1+1
	3+1
	-------------------------------------------
	1+1+2
	2+2
	-------------------------------------------
	1+3
*/