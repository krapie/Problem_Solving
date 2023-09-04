/*
baekjoon 14916��: �Ž�����

�ð� ����: 2��
�޸� ����: 512 MB

����
�����̴� ������ ī���Ϳ��� ���Ѵ�.
�մ��� 2��¥���� 5��¥���θ� �Ž������� �޶�� �Ѵ�. 2��¥�� ������ 5��¥�� ������ ������ ���� ������ �ִ�. ������ ������ �ּҰ� �ǵ��� �Ž��� �־�� �Ѵ�. �Ž������� n�� ���, �ּ� ������ ������ �� ������ �˷��ִ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, �Ž������� 15���̸� 5��¥�� 3����, �Ž������� 14���̸� 5��¥�� 2���� 2��¥�� 2���� �� 4����, �Ž������� 13���̸� 5��¥�� 1���� 2��¥�� 4���� �� 5���� �־�� ������ ������ �ּҰ� �ȴ�.

�Է�
ù° �ٿ� �Ž����� �׼� n(1 �� n �� 100,000)�� �־�����.

���
�Ž����� ������ �ּ� ������ ����Ѵ�. ���� �Ž��� �� �� ������ -1�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	cnt = n / 5;
	n = n % 5;
	
	if(cnt >= 1 && n % 2 != 0) {
		cnt--;
		n += 5;
	}
	
	cnt += n / 2;
	n = n % 2;

	if(n == 0) {
		cout << cnt;
	}
	else {
		cout << "-1";
	}
}

/*
greedy

cin n

cnt = n / 5;
n = n % 5;

if cnt >= 1 & n % 2 != 0
	cnt--
	n += 5

n = n % 2	
cnt += n / 2

if n != 0
	cout cnt	
else
	cout -1		
*/
