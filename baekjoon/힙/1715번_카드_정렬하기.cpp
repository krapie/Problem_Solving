/*
baekjoon 1715��: ī�� �����ϱ�

�ð� ����: 2��
�޸� ����: 128 MB

����
���ĵ� �� ������ ���� ī�尡 �ִٰ� ����. �� ������ ī���� ���� A, B�� �ϸ� ���� �� ������ ���ļ� �ϳ��� ����� ������ A+B ���� �񱳸� �ؾ� �Ѵ�. �̸��׸�, 20���� ���� ī�� ������ 30���� ���� ī�� ������ ��ġ���� 50���� �񱳰� �ʿ��ϴ�.
�ſ� ���� ���� ī�� ������ å�� ���� ���� �ִ�. �̵��� �� ������ ��� ���� ���ĳ����ٸ�, ���� ������ ���� �� Ƚ���� �ſ� �޶�����. ���� ��� 10��, 20��, 40���� ������ �ִٸ� 10��� 20���� ��ģ ��, ��ģ 30�� ������ 40���� ��ģ�ٸ� (10 + 20) + (30 + 40) = 100���� �񱳰� �ʿ��ϴ�. �׷��� 10��� 40���� ��ģ ��, ��ģ 50�� ������ 20���� ��ģ�ٸ� (10 + 40) + (50 + 20) = 120 ���� �񱳰� �ʿ��ϹǷ� �� ȿ������ ����̴�.
N���� ���� ī�� ������ ������ ũ�Ⱑ �־��� ��, �ּ��� �� ���� �񱳰� �ʿ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N �� 100,000) �̾ N���� �ٿ� ���� ���� ī�� ������ ������ ũ�Ⱑ �־�����. ���� ī�� ������ ũ��� 1,000���� �۰ų� ���� ���� �����̴�.

���
ù° �ٿ� �ּ� �� Ƚ���� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b, n;
int num;
priority_queue<int, vector<int>,greater<int>> pq;
int result, ans;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1)
	{
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		result = a + b;
		
		ans += result;
		pq.push(result);
	}

	cout << ans;
}

/*
�ּ� => �׻� ���� ���� ī�� ���� 2���� �̾Ƽ� ���ľ� ��
ex) 4,5,6,7,8�� ���, 4,5 ���� �̰� ��ġ�� 9�� �Ǵµ�, �� �� �ܼ��� 9�� 6�� ��ġ�� ��(15)���� 6�� 7�� ��ĥ��(13) ��������� �� ���� ��Ƚ���� ������, ��������� less�� �����ؼ� �տ� 2���� ���ļ� ����� ��: 9+15+22+30���� �׻� �������� ���� ���� 2���� ���� ���� �� ���ļ� ����� ��: 9+13+17+30�� �� ����

�������� �׻� ���� ���� ī�� ���� 2���� �̱� => �ּ� �� (�ܼ��� ���Ϳ� �ְ� �� ���긶�� �ð����⵵ O(nlogn)�� sort�� �ϸ� �� �ð����⵵: O((nlogn)!)���� �ð��ʰ�, �� ���긶�� ���� �����ϰ� �߰��Ҷ��� �ð����⵵�� O((logn)!)���� ���� sort���� �ξ� ����

cin n
for n
	cin num
	priority_queue greater<int>, push num

//������ ��Ʈ ���(���� ���� ī�� ����) 2�� �̱�
//�̾Ƽ� ���� �� result�� ans += �� ��, �ٽ� ���� �ֱ�
//���� �������� ����

while  pq size != 1 //ť�� �ϳ��� ���� = ��� ������
	a = pq front pop
	b = pq front pop

	result = a +b
	ans += result

	pq push result

cout result
*/
