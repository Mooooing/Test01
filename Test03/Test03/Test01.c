#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//��������1�ĸ���

//int count_bit_one(int a) {
//	int i = 1;
//	int count = 0;
//
//	//for (i = 0; i < 32; i++) {
//	//	if (((a >> i) & 1) == 1) {
//	//		count++;
//	//	}
//	//}
//
//	//������
//	//while (a) {
//	//	if (1 == (a & 1)) {
//	//		count++;
//	//	}
//	//	a = a >> 1;
//	//}
//
//	//�����㷨����е���
//	/*
//	n = n &(n-1)
//	n = 13Ϊ��
//	1101 n
//	1100 n-1
//	1100 �µ�n
//
//	1100 n
//	1011 n - 1
//	1000 �µ�n
//	*/
//
//	while (a) {
//		a = a & (a - 1);
//		count++;
//	}
//
//
//	return count;
//}
//
//
//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	//��������a(����)�м���1��
//	int count = count_bit_one(a);
//	printf("%d\n", count);
//	return 0;
//}

//
////���������Ķ������в�ͬλ�ĸ���
//
//int get_diff_bit(int m, int n) {
//	int  i = 0;
//	int count = 0;
//
//	//���֮���������������������Ϊ1�ĸ���
//	int temp = m ^ n;
//	for (i = 0; i < 32; i++) {
//		if (1 == ((temp >> i) & 1)) {
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int main() 
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d,%d", &m,&n);
//	
//	printf("%d\n", get_diff_bit(m, n));
//
//	return 0;
//}

//����˷��ھ���
void print_table(int n) {
	int i = 0;
	for (i = 1; i <= n; i++) {
		int j = 0;
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%-3d ", i, j, i * j);
		}
		printf("\n");

	}

}

int main() {
	int  n = 0;
	scanf("%d", &n);
	print_table(n);
	return 0;
}