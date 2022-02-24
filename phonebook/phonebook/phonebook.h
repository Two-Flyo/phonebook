#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_SIZE 3

#define NAME_LENGTH 20
#define SEX_LENGTH 5
#define TEL_LENGTH 12
#define ADDRESS_LENGTH 30

#define CAPACITY 1000
struct PeopleInfo //ͨѶ¼��һ����Ҫ�洢����Ϣ
{
	char name[NAME_LENGTH];
	int age;
	char sex[SEX_LENGTH];
	char tel[TEL_LENGTH];
	char address[ADDRESS_LENGTH];
};

//ͨѶ¼ ��̬�����İ汾
struct PhoneBook
{
	struct PeopleInfo* data;
	int num_people;//ͨѶ¼�е�ǰ�洢������
	int capacity;//ͨѶ¼�ĵ�ǰ�������
};

//struct PhoneBook //ͨѶ¼ ��̬��
//{
//	struct PeopleInfo data[CAPACITY];//�ɴ��1000�˵���Ϣ
//	int num_people;//��¼��ǰͨѶ¼�д�ŵ�����
//};

//��ʼ��ͨѶ¼
void InitPhoneBook(struct PhoneBook* pb);

//�����ϵ��
void AddPeople(struct PhoneBook* pb);

//չʾ��ϵ����Ϣ
void ShowPhoneBook(const struct PhoneBook* pb);

//ɾ����ϵ��
void DelPeople(struct PhoneBook *pb);

//������ϵ��
void SearchPeople(const struct PhoneBook* pb);

//�޸�ָ����ϵ��
void ModifyPeople(struct PhoneBook* pb);

//����ͨѶ¼
void DestoryPhoneBook(struct PhoneBook* pb);

