#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
////��������
//int main() {
//	char arr1[5] = "abc";
//	char arr2[] = "hell";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

////����ʵ���ڴ濽�����캯��(�ڴ治�ص�)
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count) {
//
//	char* ret = dest;
//	assert(dest && src);
//	int i = count;
//	while (i--) {
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//Ϊʲô���ú���++����Ϊǿ������ת�����ȼ��ͣ����õĻ��������ǿ������ת����
//		++(char*)src;
//	}
//	return ret;
//}
//
//
//int main() {
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	int i = 0;
//	//printf("%d\n", sizeof(arr1));
//	//arr1�е����ֿ�����arr2��
//	//memcpy(arr2,arr1,sizeof(arr1));
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++) {
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


////����ʵ��memmove���ڴ��ص�������½��п�����
//
//void* my_memmove(void* dest, void* src, size_t count)
//{
//	void* ret = dest;
////��ȥ�ж�Ŀ�ĵ��׵�ַ��ԭ���׵�ַ���ĸ���ǰ�Ǹ��ں�Ȼ����ȥ�жϴ�ǰ���󿽱����ǴӺ���ǰ������
//	if (dest < src) {
//		//��ǰ���󿽱�
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else {
//		//�Ӻ���ǰ����
//		while (count--) {
//			*((char*)dest + count) = *((char*)src + count);//���count�Ѿ�����1�����������һ���ֽڵĵ�ַ
//			
//		}
//	}
//	return ret;
//
//}
//int main() {
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//printf("%d\n", sizeof(arr1));
//	//arr1�е����ֿ�����arr2��
//	
//	my_memmove(arr3 , arr3 + 2, 20);
//
//	for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++) {
//		printf("%d ", arr3[i]);
//	}
//	return 0;
//}

//����ʵ��memcmp
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,4,4,5 };
	int ret = memcmp(arr1, arr2, 9);//���һ�����ֽ�����
	printf("%d\n", ret);

	return 0;
}