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
struct PeopleInfo //通讯录中一个人要存储的信息
{
	char name[NAME_LENGTH];
	int age;
	char sex[SEX_LENGTH];
	char tel[TEL_LENGTH];
	char address[ADDRESS_LENGTH];
};

//通讯录 动态增长的版本
struct PhoneBook
{
	struct PeopleInfo* data;
	int num_people;//通讯录中当前存储的人数
	int capacity;//通讯录的当前最大容量
};

//struct PhoneBook //通讯录 静态版
//{
//	struct PeopleInfo data[CAPACITY];//可存放1000人的信息
//	int num_people;//记录当前通讯录中存放的人数
//};

//初始化通讯录
void InitPhoneBook(struct PhoneBook* pb);

//添加联系人
void AddPeople(struct PhoneBook* pb);

//展示联系人信息
void ShowPhoneBook(const struct PhoneBook* pb);

//删除联系人
void DelPeople(struct PhoneBook *pb);

//查找联系人
void SearchPeople(const struct PhoneBook* pb);

//修改指定联系人
void ModifyPeople(struct PhoneBook* pb);

//销毁通讯录
void DestoryPhoneBook(struct PhoneBook* pb);

