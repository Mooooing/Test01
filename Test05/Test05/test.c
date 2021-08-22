#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
////杨氏三角
//int main() {
//	char arr1[5] = "abc";
//	char arr2[] = "hell";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

////自我实现内存拷贝构造函数(内存不重叠)
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count) {
//
//	char* ret = dest;
//	assert(dest && src);
//	int i = count;
//	while (i--) {
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//为什么不用后置++？因为强制类型转换优先级低，后置的话不会进行强制类型转换。
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
//	//arr1中的数字拷贝到arr2中
//	//memcpy(arr2,arr1,sizeof(arr1));
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++) {
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


////自我实现memmove（内存重叠的情况下进行拷贝）
//
//void* my_memmove(void* dest, void* src, size_t count)
//{
//	void* ret = dest;
////先去判断目的的首地址和原的首地址，哪个在前那个在后，然后再去判断从前往后拷贝还是从后往前拷贝。
//	if (dest < src) {
//		//从前往后拷贝
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else {
//		//从后往前拷贝
//		while (count--) {
//			*((char*)dest + count) = *((char*)src + count);//这个count已经减过1了正好是最后一个字节的地址
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
//	//arr1中的数字拷贝到arr2中
//	
//	my_memmove(arr3 , arr3 + 2, 20);
//
//	for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++) {
//		printf("%d ", arr3[i]);
//	}
//	return 0;
//}

//自我实现memcmp
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,4,4,5 };
	int ret = memcmp(arr1, arr2, 9);//最后一个是字节数。
	printf("%d\n", ret);

	return 0;
}