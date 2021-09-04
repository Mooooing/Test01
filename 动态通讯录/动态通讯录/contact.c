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
			printf("���ݳɹ�\n");

		}
		else {
			printf("����ʧ��\n");
		}
	}
}


void AddContact(struct Contact* ps) {
	
	//��⵱ǰͨѶ¼������
	//1.�������ӿռ�
	//2.δ����ʲô���鶼���ɡ�
	CheckCapacity(ps);
	//��������
	printf("���������֣�");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
}


void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("ͨѶ¼Ϊ��\n");
	}
	else {
		int i = 0;
		printf("%-20s \t%-4s \t%-5s \t%-12s \t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ���Ԫ�ؿ���ɾ����\n");
	}
	else {
		char name[MAX_NAME];
		printf("������Ҫɾ���˵����֣�");
		scanf("%s",name);
	//1.����Ҫɾ��������ʲôλ��
		//�ҵ��˷���Ԫ�ص��±꣬���û�ҵ�-1��
		int i = FindByName(ps, name);
		if (i == -1) {
			printf("Ҫɾ�����˲�����\n");
		}
		//2.ɾ��
		else {
			int j = 0;
			for (j = i; j < ps->size - 1 ; j++) {
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("ɾ���ɹ�\n");
		}



	}

}

void SearchContact(const struct Contact* ps) {
	
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("��û���ҵ����ҵ���\n");
	}
	else {
		printf("%-20s \t%-4s \t%-5s \t%-12s \t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵����֣�");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1) {
		printf("��û���ҵ��޸ĵ���\n");
	}
	//�޸ĵĻ���ֱ�ӽ����һ�顣
	else {
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		
		printf("�޸ĳɹ�\n");
	}
}
void DestroyContact(struct Contact* ps) {
	free(ps -> data);
	ps->data = NULL;


}