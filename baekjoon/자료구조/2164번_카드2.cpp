/*
baekjoon 2164��: ī��2

�ð� ����: 2��
�޸� ����: 128 MB

����
N���� ī�尡 �ִ�. ������ ī��� ���ʷ� 1���� N������ ��ȣ�� �پ� ������, 1�� ī�尡 ���� ����, N�� ī�尡 ���� �Ʒ��� ���·� ������� ī�尡 ���� �ִ�.
���� ������ ���� ������ ī�尡 �� �� ���� ������ �ݺ��ϰ� �ȴ�. �켱, ���� ���� �ִ� ī�带 �ٴڿ� ������. �� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.
���� ��� N=4�� ��츦 ������ ����. ī��� ���� ���������� 1234 �� ������ �����ִ�. 1�� ������ 234�� ���´�. ���⼭ 2�� ���� �Ʒ��� �ű�� 342�� �ȴ�. 3�� ������ 42�� �ǰ�, 4�� ������ �ű�� 24�� �ȴ�. ���������� 2�� ������ ����, ���� ī��� 4�� �ȴ�.

N�� �־����� ��, ���� �������� ���� �Ǵ� ī�带 ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(1 �� N �� 500,000)�� �־�����.

���
ù° �ٿ� ���� �Ǵ� ī���� ��ȣ�� ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<int> card;

int n;
int temp;

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		card.push(i);
	}

	while (card.size() != 1)
	{
		card.pop();
		temp = card.front();
		card.pop();
		card.push(temp);
	}

	cout << card.front();
}

/*
* ť�� �ܼ� ����
* 1. n �Է�
* 2. ť�� 1~n���� ���������� push
* 3. while(ť�� �ϳ��� ���ڸ��� ���� ������)
*		�� ���� ī�� ������ (pop)
*		�� ���� ī�� temp�� ���� �� ť�� �ٽ� ����ֱ� (top -> pop -> push)
* 4. ���������� ���� ���� ��� 
*/
