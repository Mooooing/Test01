#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//求整数中1的个数

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
//	//不好用
//	//while (a) {
//	//	if (1 == (a & 1)) {
//	//		count++;
//	//	}
//	//	a = a >> 1;
//	//}
//
//	//经典算法这个有点难
//	/*
//	n = n &(n-1)
//	n = 13为例
//	1101 n
//	1100 n-1
//	1100 新的n
//
//	1100 n
//	1011 n - 1
//	1000 新的n
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
//	//二进制中a(补码)有几个1；
//	int count = count_bit_one(a);
//	printf("%d\n", count);
//	return 0;
//}

//
////两个整数的二进制中不同位的个数
//
//int get_diff_bit(int m, int n) {
//	int  i = 0;
//	int count = 0;
//
//	//异或之后调用求整数二进制数中为1的个数
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

//输入乘法口诀表
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