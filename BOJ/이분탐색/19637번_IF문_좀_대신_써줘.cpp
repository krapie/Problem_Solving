/*
BOJ 19637번: IF문 좀 대신 써줘

시간 제한: 1 초 (추가 시간 없음)
메모리 제한: 1024 MB

문제
게임 개발자인 밀리는 전투력 시스템을 만들어, 캐릭터가 가진 전투력을 기준으로 칭호를 붙여주려고 한다.
예를 들어, 전투력 10,000 이하의 캐릭터는 WEAK, 10,000 초과 그리고 100,000 이하의 캐릭터는 NORMAL, 100,000 초과 그리고 1,000,000 이하의 캐릭터는 STRONG 칭호를 붙여준다고 하자. 이를 IF문으로 작성한다면 아래와 같이 구현할 수 있다.

if power <= 10000
 print WEAK
else if power <= 100000
 print NORMAL
else if power <= 1000000
 print STRONG
 
혼자서 게임을 개발하느라 매우 바쁜 밀리를 대신해서, 캐릭터의 전투력에 맞는 칭호를 출력하는 프로그램을 작성하자.

입력
첫 번째 줄에는 칭호의 개수 N (1 ≤ N ≤ 105)과 칭호를 출력해야 하는 캐릭터들의 개수 M (1 ≤ M ≤ 105)이 빈칸을 사이에 두고 주어진다. (1 ≤ N, M ≤ 105)
두 번째 줄부터 N개의 줄에 각 칭호의 이름을 나타내는 길이 1 이상, 11 이하의 영어 대문자로만 구성된 문자열과 해당 칭호의 전투력 상한값을 나타내는 109 이하의 음이 아닌 정수가 주어진다. 칭호는 전투력 상한값의 비내림차순으로 주어진다. 
N + 2번째 줄부터 M개의 각 줄에는 캐릭터의 전투력을 나타내는 음이 아닌 정수가 주어진다. 해당하는 칭호가 없는 전투력은 입력으로 주어지지 않는다.

출력
M개의 줄에 걸쳐 캐릭터의 전투력에 맞는 칭호를 입력 순서대로 출력한다. 어떤 캐릭터의 전투력으로 출력할 수 있는 칭호가 여러 개인 경우 가장 먼저 입력된 칭호 하나만 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n, m;
int num; string str;
int idx;
vector<int> power;
vector<string> title;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	title.reserve(n);
	power.reserve(n);
	
	for(int i=0; i<n; i++) {
		cin >> str >> num;
		
		if(!power.empty() && power.back() == num) {
			continue; 
		}
		
		power.push_back(num);
		title.push_back(str);
	}
	
	for(int i=0; i<m; i++) {
		cin >> num;
		
		idx = lower_bound(power.begin(),power.end(),num) - power.begin();
		
		cout << title[idx] << "\n";
	}
	
	return 0;
}

/*
이분탐색
vector, 중복 제거, lower_bound 사용 

다른 버전: 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n, m;
int num;
string str;
pair<int, string> arr[MAX];
int l, r, mid;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> str >> num;
		arr[i] = make_pair(num, str);
	}
	
	for(int i=0; i<m; i++) {
		cin >> num;
		
		l = 0; r = n-1;
		while(l <= r) {
			mid = (l+r) / 2;
			
			if(num <= arr[mid].first) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		if(r < 0) {
			cout << arr[l].second << "\n";
		}
		else {
			cout << arr[l].second << "\n";
		}
	}
	
	return 0;
}
*/
