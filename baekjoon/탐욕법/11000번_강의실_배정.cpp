/*
baekjoon 11000��: ���ǽ� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
������û�� ������ ������ �����Կ��� ���ο� ������ �־�����. 
������ ���������״� Si�� �����ؼ� Ti�� ������ N���� ������ �־����µ�, �ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ؾ� �Ѵ�. 
�����, ������ ���� ���Ŀ� ���� ������ ������ �� �ִ�. (��, Ti �� Sj �� ��� i ������ j ������ ���� ���� �� �ִ�.)
������û ������ �� �񸮸�, �������� ���͵帮��!

�Է�
ù ��° �ٿ� N�� �־�����. (1 �� N �� 200,000)
���� N���� �ٿ� Si, Ti�� �־�����. (0 �� Si < Ti �� 109)

���
���ǽ��� ������ ����϶�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int s,t;
vector<pair<int,int> > v;
int cnt;
int Max;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s >> t;
		v.push_back(make_pair(s,1));
		v.push_back(make_pair(t,-1));
	}
	
	sort(v.begin(), v.end());

	for(int i=0; i<2*n; i++) {
		cnt += v[i].second;
		Max = max(Max, cnt);
	}
	
	cout << Max;
}

/* 
greedy

cnt: ���� ���� ���� ������ ��
N���� ȸ�Ǹ� ��� ������ �� �ִ� �ּ� ���ǽ��� ���� = cnt�� �ִ�
���� ���� �� cnt++, ���� ���� �� cnt--
������ ������ pair<�ð�, +1> ���� pair<�ð�, -1>�� ���� �迭�� ���� �� �ð� ������ sort, ���� ������� �����鼭 cnt�� ���ϱ� (+1�̸� ���� ����, -1�̸� ���� ���̹Ƿ� cnt�� �����ָ� ��), �ִ� ã�� 

�߰�: ������ first, ������������, ������ second ������������ ����ǹǷ�, compare �Լ� ���ʿ��ϰ�, cnt�� ���ɶ����� "������ ���� ���Ŀ� ���� ������ ������ �� �ִ�"�� ���� ���͵� ������. 
*/ 
