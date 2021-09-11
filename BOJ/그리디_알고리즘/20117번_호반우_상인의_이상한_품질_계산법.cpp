/*
BOJ 20117번: 호반우 상인의 이상한 품질 계산법

시간 제한: 1초
메모리 제한: 256 MB

문제
경북대 특산품 호반우는 품질에 따라 등급이 숫자로 매겨진다. 호반우 상인들은 N개의 호반우를 파려고 한다. 호반우는 개별적으로 팔 수도 있지만 묶음으로 팔 수도 있다. 이 때 묶음이라 함은 호반우들의 어떤 부분집합을 말한다.
하나의 호반우를 팔 때 기존의 계산법으로는 품질만큼의 가격으로 팔리게 된다.
따라서 묶어파나 개별적으로 파나 상인이 벌 수 있는 총 금액은 차이가 없었다.
하지만 호반우 상인들은 욕심쟁이여서 돈을 더 많이 받을 방법을 놓고 회의를 열게 된다. 그러던 와중 호반우 상인들은 새로운 품질 계산법을 개발해냈다!
호반우를 묶음으로 팔 때는 모든 호반우의 품질을 묶음의 '중앙값'으로 결정하게 된다. 이 때 묶음이 짝수인 경우 묶음 안에 있는 호반우를 품질을 기준으로 정렬했을 때 (묶음 개수/2+1)번째 호반우를 중앙값으로 정의하고 홀수인 경우 ((묶음 개수+1)/2)번째 호반우를 중간값으로 정의한다.
계산법을 새로 만드는 데는 성공했지만 호반우가 너무 많아 어떻게 묶어야 할 지 혼란이 오기 시작한 호반우 상인들은 장사에서 최대의 이익을 얻지 못 하고 있었다. 호반우 상인들을 위해 호반우들을 팔아서 얻을 수 있는 최대 이익을 계산하는 프로그램을 만들어주자!

입력
첫 번째 줄에 호반우의 개수 N (1 ≤ N ≤ 100,000)이 주어집니다.
두 번째 줄에 공백으로 구분된 N개의 정수 a1, a2, ..., an (1 ≤ ai ≤ 1,000)가 주어지는데 이 숫자는 각 호반우의 품질을 나타냅니다.

출력
모든 호반우를 팔았을 때 얻을 수 있는 최대 이익을 출력합니다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[100000];
int mid;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	sort(arr+0, arr+n);
	
	for(int i=n-1; i>=n/2; i--) {
		ans += arr[i] * 2;
	}
	
	if(n % 2 != 0) {
		ans -= arr[n/2];
	}
	
	cout << ans;
}

/*
greedy

묶음 개수가 2일 경우 품질은 묶음의 최댓값이 되므로,
모든 호반우를 오름차순 정렬 후 사용하지 않은 가장 왼쪽 값과 가장 오른쪽 값을 묶는다, 
그러면 묶음은 항상 최댓값이 되므로, 그리디하게 최댓값을 구할 수 있다.
호반우가 홀수개일 경우 중앙값을 하나 빼 주면 됨. 
*/
