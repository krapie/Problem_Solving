/*
BOJ 2168번: 타일 위의 대각선

시간 제한: 1 초
메모리 제한: 128 MB

문제
한 변의 길이가 1cm인 정사각형 모양의 타일이 있다. 이 타일들을 가로가 xcm, 세로가 ycm인 직사각형 모양의 벽에 빈틈없이 붙였다. x와 y는 정수이다.
이 직사각형에 하나의 대각선을 그렸다. 직사각형에 붙어 있는 x*y개의 타일 중에는 대각선이 그려진 타일도 있고, 그렇지 않은 타일도 있다. x*y개의 타일 중에서 대각선이 그려져 있는 타일의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 가로의 길이 xcm와 세로의 길이 ycm가 주어진다. x와 y는 1,000,000,000 이하의 자연수이다. x와 y사이에는 빈칸이 하나 이상 있다.

출력
첫째 줄에 대각선이 그려져 있는 타일의 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a, b;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	if(a < b) {
		int temp = b;
		b = a;
		a = temp;
	}	
	
	cout << a + b - gcd(a,b);
	return 0;
}

/* 
수학
	문제: x*y개의 타일 중에서 대각선이 그려져 있는 타일의 개수 구하기
	아이디어: 대각선은 가로, 세로 모든 타일에 각 한 번씩 대응되고, 가로, 세로 길이의 최대공약수만큼 겹친다 
	규칙: x + y - gcd(x,y) 
	
최대 공약수: GCD
*/ 
