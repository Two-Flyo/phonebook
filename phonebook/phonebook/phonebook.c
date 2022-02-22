#define _CRT_SECURE_NO_WARNINGS 1
#include"phonebook.h"


void InitPhoneBook(struct PhoneBook* pb)
{
	pb->num_people = 0;
	memset(pb->data, 0, sizeof(pb->data));
}

void AddPeople(struct PhoneBook* pb)
{
	if (pb->num_people == CAPACITY)
		printf("通讯录空间不足!\n");
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

void ShowPhoneBook(const struct PhoneBook* pb)
{
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tel", "address");
	for (int i = 0; i < pb->num_people; i++)
	{
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",pb->data[i].name,pb->data[i].age, 
			pb->data[i].sex, pb->data[i].tel, pb->data[i].address);
	}
}
