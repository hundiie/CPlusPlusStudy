#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int board[15];
// �������� �Ǵ��ϴ� �Լ�
int promising(int cdx) {

	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen �˰��� ����
void nqueen(int cdx) {

	// cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
	if (cdx == n) {
		count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.	
		// ���� �� �࿡ �� �Ϳ� ���� �������� �Ǵ��Ѵ�.
		if (promising(cdx)) { // �� �ڸ��� �ξ �����Ҵٸ�,
			nqueen(cdx + 1); // �� ���� �࿡ ���� ���� ���� ���� �� ����.
		}
	}
}

int main() {
	scanf("%d", &n);
	nqueen(0);
	printf("%d", count);
	
}