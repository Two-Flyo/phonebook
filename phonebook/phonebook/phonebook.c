#define _CRT_SECURE_NO_WARNINGS 1
#include"phonebook.h"

//动态版本
void InitPhoneBook(struct PhoneBook* pb)
{
	pb->num_people = 0;
	pb->data = malloc(DEFAULT_SIZE * sizeof(struct PeopleInfo));
	pb->capacity = DEFAULT_SIZE;
}

//静态版本
//void InitPhoneBook(struct PhoneBook* pb)
//{
//	pb->num_people = 0;
//	memset(pb->data, 0, sizeof(pb->data));
//}

//动态版本
void AddPeople(struct PhoneBook* pb)
{
	if (pb->num_people == pb->capacity)
	{
		struct PeopleInfo* tmp = (struct PeopleInfo*)realloc(pb->data, (pb->capacity + 2) * sizeof(struct PeopleInfo));
		if (tmp!= NULL)
		{
			pb->data = tmp;
			pb->capacity += 2;
			printf("增容成功!\n");
		}
		else 
		{
			return;
		}
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pb->data[pb->num_people].name);
		printf("请输入年领:>");
		scanf("%d", &pb->data[pb->num_people].age);
		printf("请输入性别:>");
		scanf("%s", pb->data[pb->num_people].sex);
		printf("请输入电话:>");
		scanf("%s", pb->data[pb->num_people].tel);
		printf("请输入地址:>");
		scanf("%s", pb->data[pb->num_people].address);
		
		printf("添加成功!\n");
		pb->num_people++;
}
}

//静态版本
//void AddPeople(struct PhoneBook* pb)
//{
//	if (pb->num_people == CAPACITY)
//		printf("通讯录空间不足!\n");
//	else
//	{
//		printf("请输入名字:>");
//		scanf("%s", pb->data[pb->num_people].name);
//		printf("请输入年领:>");
//		scanf("%d", &pb->data[pb->num_people].age);
//		printf("请输入性别:>");
//		scanf("%s", pb->data[pb->num_people].sex);
//		printf("请输入电话:>");
//		scanf("%s", pb->data[pb->num_people].tel);
//		printf("请输入地址:>");
//		scanf("%s", pb->data[pb->num_people].address);
//
//		printf("添加成功!\n");
//		pb->num_people++;
//	}
//}

void ShowPhoneBook(const struct PhoneBook* pb)
{
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tel", "address");
	for (int i = 0; i < pb->num_people; i++)
	{
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",pb->data[i].name,pb->data[i].age, 
			pb->data[i].sex, pb->data[i].tel, pb->data[i].address);
	}
}
int FindPeopleByName(const struct PhoneBook* pb, const char* name)
{
	for (int i = 0; i < pb->num_people; i++)
	{
		if (strcmp(pb->data[i].name, name)==0)
		{
			return i;
		}
	}
	return -1;
}

void DelPeople(struct PhoneBook* pb)
{
	if (pb->num_people == 0)
	{
		printf("通讯录为空!\n");
		return;
	}
	char name[NAME_LENGTH] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找删除人
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
	{
		printf("该联系人不存在!\n");
	}
	//删除
	else
	{
		for (int i = pos; i <= pb->num_people - 1; i++)
		{
			pb->data[i] = pb->data[i + 1];
		}
		pb->num_people--;
		printf("删除成功!\n");
	}
}

void SearchPeople(const struct PhoneBook* pb)
{
	char name[NAME_LENGTH] = { 0 };
	printf("输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
		printf("该联系人不存在!\n");
	else
	{
		printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tel", "address");
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n", pb->data[pos].name, pb->data[pos].age,
			pb->data[pos].sex, pb->data[pos].tel, pb->data[pos].address);
	}
}

void ModifyPeople(struct PhoneBook* pb)
{
	char name[NAME_LENGTH] = { 0 };
	printf("输入要修改的联系人的名字:>");
	scanf("%s", name);
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
		printf("该联系人不存在!\n");
	else 
	{
		printf("请输入新名字:>");
		scanf("%s", pb->data[pos].name);
		printf("请输入年领:>");
		scanf("%d", &pb->data[pos].age);
		printf("请输入性别:>");
		scanf("%s", pb->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pb->data[pos].tel);
		printf("请输入地址:>");
		scanf("%s", pb->data[pos].address);

		printf("修改成功!\n");
	}
}

void DestoryPhoneBook(struct PhoneBook* pb)
{
	free(pb->data);
	pb->data = NULL;
}