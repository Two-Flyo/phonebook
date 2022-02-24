#define _CRT_SECURE_NO_WARNINGS 1
#include"phonebook.h"

//��̬�汾
void InitPhoneBook(struct PhoneBook* pb)
{
	pb->num_people = 0;
	pb->data = malloc(DEFAULT_SIZE * sizeof(struct PeopleInfo));
	pb->capacity = DEFAULT_SIZE;
}

//��̬�汾
//void InitPhoneBook(struct PhoneBook* pb)
//{
//	pb->num_people = 0;
//	memset(pb->data, 0, sizeof(pb->data));
//}

//��̬�汾
void AddPeople(struct PhoneBook* pb)
{
	if (pb->num_people == pb->capacity)
	{
		struct PeopleInfo* tmp = (struct PeopleInfo*)realloc(pb->data, (pb->capacity + 2) * sizeof(struct PeopleInfo));
		if (tmp!= NULL)
		{
			pb->data = tmp;
			pb->capacity += 2;
			printf("���ݳɹ�!\n");
		}
		else 
		{
			return;
		}
	}
	else
	{
		printf("����������:>");
		scanf("%s", pb->data[pb->num_people].name);
		printf("����������:>");
		scanf("%d", &pb->data[pb->num_people].age);
		printf("�������Ա�:>");
		scanf("%s", pb->data[pb->num_people].sex);
		printf("������绰:>");
		scanf("%s", pb->data[pb->num_people].tel);
		printf("�������ַ:>");
		scanf("%s", pb->data[pb->num_people].address);
		
		printf("��ӳɹ�!\n");
		pb->num_people++;
}
}

//��̬�汾
//void AddPeople(struct PhoneBook* pb)
//{
//	if (pb->num_people == CAPACITY)
//		printf("ͨѶ¼�ռ䲻��!\n");
//	else
//	{
//		printf("����������:>");
//		scanf("%s", pb->data[pb->num_people].name);
//		printf("����������:>");
//		scanf("%d", &pb->data[pb->num_people].age);
//		printf("�������Ա�:>");
//		scanf("%s", pb->data[pb->num_people].sex);
//		printf("������绰:>");
//		scanf("%s", pb->data[pb->num_people].tel);
//		printf("�������ַ:>");
//		scanf("%s", pb->data[pb->num_people].address);
//
//		printf("��ӳɹ�!\n");
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
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	char name[NAME_LENGTH] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//����ɾ����
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����!\n");
	}
	//ɾ��
	else
	{
		for (int i = pos; i <= pb->num_people - 1; i++)
		{
			pb->data[i] = pb->data[i + 1];
		}
		pb->num_people--;
		printf("ɾ���ɹ�!\n");
	}
}

void SearchPeople(const struct PhoneBook* pb)
{
	char name[NAME_LENGTH] = { 0 };
	printf("����Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
		printf("����ϵ�˲�����!\n");
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
	printf("����Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindPeopleByName(pb, name);
	if (pos == -1)
		printf("����ϵ�˲�����!\n");
	else 
	{
		printf("������������:>");
		scanf("%s", pb->data[pos].name);
		printf("����������:>");
		scanf("%d", &pb->data[pos].age);
		printf("�������Ա�:>");
		scanf("%s", pb->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pb->data[pos].tel);
		printf("�������ַ:>");
		scanf("%s", pb->data[pos].address);

		printf("�޸ĳɹ�!\n");
	}
}

void DestoryPhoneBook(struct PhoneBook* pb)
{
	free(pb->data);
	pb->data = NULL;
}