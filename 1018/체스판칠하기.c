#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char w_board[8][8] = { {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"} };
char b_board[8][8] = { {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"} };
char arr[50][50];

int compare(int r, int c) {
	int w_cnt = 0, b_cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (w_board[i][j] != arr[r + i][c + j])
				w_cnt++; // �ٸ��� üũ
			if (b_board[i][j] != arr[r + i][c + j])
				b_cnt++; // �ٸ��� üũ
		}
	}
	if (w_cnt <= b_cnt)
		return w_cnt; // �� ���� ���� ����
	else return b_cnt;
}

int main() {
	int N, M;
	int result = 64;
	int b_cnt = 0, w_cnt = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]); // ü���� �Է¹���

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++)  // 8*8�� �߶󳻾� �ϱ� ������
			if (result > compare(i, j)) // �� ���� ������ result�� ����
				result = compare(i, j);
	}
	printf("%d", result);
	return 0;
}