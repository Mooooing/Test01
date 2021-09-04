#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"contact.h"
#include<string.h>

static int FindByName( struct Contact* ps, char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == strcmp(ps->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}


void InitContact(struct Contact* ps) {
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ; 
}

void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity) {
		struct PeoInfo * ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");

		}
		else {
			printf("增容失败\n");
		}
	}
}


void AddContact(struct Contact* ps) {
	
	//检测当前通讯录的容量
	//1.满了增加空间
	//2.未满则什么事情都不干、
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字：");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
}


void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("通讯录为空\n");
	}
	else {
		int i = 0;
		printf("%-20s \t%-4s \t%-5s \t%-12s \t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++) {
			//printf("1111111111111111111111111\n");
			//printf("%20s \t", ps->data[i].age);
			printf("%-20s \t%-4d \t%-5s \t%-12s \t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr
			);
		}
	}
}


void DelContact(struct Contact* ps) {
	if (0 == ps->size) {
		printf("通讯录为空，无元素可以删除。\n");
	}
	else {
		char name[MAX_NAME];
		printf("请输入要删除人的名字：");
		scanf("%s",name);
	//1.查找要删除的人在什么位置
		//找到了返回元素的下标，如果没找到-1；
		int i = FindByName(ps, name);
		if (i == -1) {
			printf("要删除的人不存在\n");
		}
		//2.删除
		else {
			int j = 0;
			for (j = i; j < ps->size - 1 ; j++) {
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("删除成功\n");
		}



	}

}

void SearchContact(const struct Contact* ps) {
	
	char name[MAX_NAME];
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("并没有找到查找的人\n");
	}
	else {
		printf("%-20s \t%-4s \t%-5s \t%-12s \t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s \t%-4d \t%-5s \t%-12s \t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr
		);
	}
}


void ModifyContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要修改人的名字：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("并没有找到修改的人\n");
	}
	//修改的话，直接将其改一遍。
	else {
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);
		
		printf("修改成功\n");
	}
}
void DestroyContact(struct Contact* ps) {
	free(ps -> data);
	ps->data = NULL;


}