/*
baekjoon 9934��: ���� ���� Ʈ��

�ð� ����: 1��
�޸� ����: 128 MB

����
����̴� ���κ��Ͼ��� ���� Donji Andrijevci�� �����ϰ� �ִ�. �� ������ ���δ� ���̰� K�� ���� ���� Ʈ���� �̷�� �ִ�. ���̰� K�� ���� ���� Ʈ���� �� 2K-1���� ���� �̷���� �ִ�. (�Ʒ� �׸�) �� ��忡�� �� ���� ��ġ�� ������ ��ȣ�� �ٿ��� �ִ�. ��, ���� ������ ������ ������ ��� ���� ���� �ڽİ� ������ �ڽ��� ���´�.
����̴� ���ÿ� �ִ� ��� ������ ����, �� ������� ��ȣ�� ���̿� ���� ���Ҵ�. �ѱ����� ���ƿ� ����̴� ���ð� ��� ������� �׸��� �׷������� �Ͽ�����, ��Ȯ�ϰ� ����� ���� �ʾ� �����ߴ�. ������, � ������ ���ø� �湮�ߴ��� ����س´�.

1. ���� ó���� ����̴� Ʈ���� ��Ʈ�� �ִ� ���� �տ� ���ִ�.
2. ���� ������ ���� �ڽĿ� �ִ� ������ ���� ���� �ʾҴٸ�, ���� �ڽ����� �̵��Ѵ�.
3. ���� �ִ� ��尡 ���� �ڽ��� ������ ���� �ʰų� ���� �ڽĿ� �ִ� ������ �̹� ���ٸ�, ���� ��忡 �ִ� ������ ���� ���̿� ��ȣ�� ���´�.
4. ���� ������ �̹� ���� �� �����̰�, ������ �ڽ��� ������ �ִ� ��쿡�� ������ �ڽ����� �̵��Ѵ�.
5. ���� ������ ����, ������ �ڽĿ� �ִ� ������ ��� �湮�ߴٸ�, �θ� ���� �̵��Ѵ�.

���� �׸��� �����ִ� �����̶��, ����̴� 2-1-3 ������� ������ ���� ���̰�, ������ �׸��� ��쿡�� 1-6-4-3-5-2-7 ������ ���� ���̴�. ����̰� ���̿� ���� ������ ��� �־����� ��, �� ������ �ִ� ������ ��ȣ�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� K (1 �� K �� 10)�� �־�����.
��° �ٿ��� ����̰� �湮�� ������ ��ȣ�� �� ������� �־�����. ��� ������ ��ȣ�� �ߺ����� ������, ���� [1,2K)�� ���Եȴ�.

���
�� K���� �ٿ� ���ļ� ������ ����Ѵ�. i��° �ٿ��� ������ i�� ������ ��ȣ�� ����Ѵ�. ����� ���ʿ������� ������ ������� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k;
int input[2049];
int arr[2049];

void buildBinaryTree(int level, int l, int r) {
	if(l > r) return;
	
	arr[level] = input[(l+r)/2];
	buildBinaryTree(2*level, l, ((l+r)/2)-1);
	buildBinaryTree(2*level+1, ((l+r)/2)+1, r);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	for(int i=0; i<pow(2,k)-1; i++) {
		cin >> input[i];
	} 
	
	buildBinaryTree(1, 0, pow(2,k)-2);

	int cnt = 0;
	int power = 0;
	for(int i=1; i<=pow(2,k)-1; i++) {
		cout << arr[i] << " ";
		cnt++;
		
		if(cnt == pow(2,power)) {
			cout << "\n";
			cnt = 0;
			power++;
		}
	}
}

/*
����Ʈ��, ������ȸ
������ȸ�� Ư¡: ������ȸ ��� �迭�� �߰� ���� Ʈ���� �θ�(��Ʈ)�̴�
��������� ������ȸ ��� �迭�� �߰����� �ش� (��)Ʈ���� �θ�� ���� 
*/
