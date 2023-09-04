/*
baekjoon 11048��: �̵��ϱ�

�ð� ����: 1��
�޸� ����: 256 MB

����
�رԴ� N��M ũ���� �̷ο� �����ִ�. �̷δ� 1��1ũ���� ������ �������� �ְ�, �� �濡�� ������ ������ �ִ�. �̷��� ���� ���� �� ���� (1, 1)�̰�, ���� ������ �Ʒ� ���� (N, M)�̴�.
�رԴ� ���� (1, 1)�� �ְ�, (N, M)���� �̵��Ϸ��� �Ѵ�. �ر԰� (r, c)�� ������, (r+1, c), (r, c+1), (r+1, c+1)�� �̵��� �� �ְ�, �� ���� �湮�� ������ �濡 �������ִ� ������ ��� ������ �� �ִ�. ��, �̷� ������ ���� ���� ����.
�ر԰� (N, M)���� �̵��� ��, ������ �� �ִ� ���� ������ �ִ��� ���Ͻÿ�.

�Է�
ù° �ٿ� �̷��� ũ�� N, M�� �־�����. (1 �� N, M �� 1,000)
��° �ٺ��� N�� �ٿ��� �� M���� ���ڰ� �־�����, r��° ���� c��° ���� (r, c)�� ������ �ִ� ������ �����̴�. ������ ������ 0���� ũ�ų� ����, 100���� �۰ų� ����.

���
ù° �ٿ� �ر԰� (N, M)���� �̵��� ��, ������ �� �ִ� ���� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,m;
int arr[1001][1001];
int dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + arr[i][j];
		}
	}
	
	cout << dp[n][m];
} 

// dp, dp[y][x] = max(dp[y-1][x],dp[y][x-1],dp[y-1][x-1]) + arr[y][x]
