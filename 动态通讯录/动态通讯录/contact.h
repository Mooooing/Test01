#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30


#include<stdlib.h>


struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact {

	int size;
	struct PeoInfo* data;
	int capacity;//当前通讯录的最大容量，如果size==capacity就需要扩容了。
};

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


void InitContact(struct Contact * ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact *ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void DestroyContact(struct Contact*ps);





