/*
BOJ 5766번: 할아버지는 유명해!

시간 제한: 1초
메모리 제한: 256 MB

문제
"그 뉴스" 를 보고 온 가족이 들떴습니다. 모두들 할아버지께서 수 십년간 굉장히 실력있는  브릿지(카드게임의 일종) 선수였다는 것은 알고 있었지만, 할아버지가 역대 최고의 bridge 선수로서 기네스북에 오른다는 소식은 정말이지 놀라웠죠!
IBA(국제 브릿지 협회)는 수 년간, 매주 가장 실력있는 선수들의 랭킹 정보를 기록해왔습니다.  매주 랭킹에 선수의 이름이 오를 때마다 선수의 포인트가 1포인트씩 오르는데, 할아버지께서 가장 많은 포인트를 얻어서 최고의 브릿지 선수로 선정되었습니다.
할아버지께는 그와 브릿지 순위를 경쟁하는 친구들이 많이 있었기 때문에, 할아버지는 어떤 선수(들)가 2등을 했는지 정말 궁금하셨습니다.  
IBA 랭킹 정보는 이제 온라인에 올라와 있고, 할아버지께서 당신에게 도움을 요청했습니다. 당신은 매주마다의 랭킹 정보 리스트를 인풋으로 받아 2등 선수가 누구인지 알아내는 프로그램을 짜야 합니다.

입력
각 선수는 1~10000까지의 정수(선수 번호)로 식별됩니다. 인풋은 여러 테스트 케이스들로 구성됩니다.
테스트 케이스의 첫 행에는 두 정수 N과 M이 주어지는데, 다음 행부터 N(2<=N<=500)주 동안의 매주 상위 M(2<=M<=500)명의 랭킹 정보가 주어짐을 의미합니다.
그 다음 N행의 인풋이 주어지는데 각 행은 한 주의 랭킹 정보입니다. 각 행은 공백으로 구분되는 M개의 정수들이 주어집니다.  
 각 테스트 케이스에는 최고점의 선수가 단 한 명만 존재합니다.
 매주마다의 랭킹 정보에는 서로 다른 M개의 선수 번호가 주어집니다.
N과 M이 모두 0으로 주어지는 행이 인풋의 마지막입니다.

출력
각 테스트 케이스마다,  당신의 프로그램은 한 행에 2등인 선수(들)의 번호를 출력해야 합니다. 2등인 선수가 두 명 이상인 경우(동점자 발생), 각 선수 번호를 공백으로 구분하여 오름차순으로 출력해야 합니다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000
int n,m;
int num;
int cnt[MAX+1];
int second;
vector<pair<int,int> > v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true) {
		second = 0;
		memset(cnt, 0, sizeof(cnt));
		v.clear();
		
		cin >> n >> m;
		
		if(n == 0 && m == 0) break;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> num;
				
				cnt[num]++;
			}
		}
		
		for(int i=1; i<=MAX; i++) {
			if(cnt[i] >= 1) {
				v.push_back(make_pair(cnt[i], i));
			}
		}
		
		sort(v.begin(), v.end());
		
		second = v[v.size()-2].first;
		
		for(int i=0; i<v.size(); i++) {
			if(v[i].first == second) {
				cout << v[i].second << " ";
			}
		}
		
		cout << "\n";
	}
	
	return 0;
}

/*
구현 
*/
