#include"phonebook.h"
void menu()
{
	printf("*********************************\n");
	printf("**********1.新建联系人***********\n");
	printf("**********2.删除联系人***********\n");
	printf("**********3.查找联系人***********\n");
	printf("**********4.修改联系人***********\n");
	printf("**********5.显示信息  ***********\n");
	printf("**********0.退出      ***********\n");
	printf("*********************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	//创建一个通讯录
	struct PhoneBook phonebook;
	InitPhoneBook(&phonebook);
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddPeople(&phonebook);
			break;
		case DEL:
			DelPeople(&phonebook);
			break;
		case SEARCH:
			SearchPeople(&phonebook);
			break;
		case MODIFY:
			ModifyPeople(&phonebook);
			break;
		case SHOW:
			ShowPhoneBook(&phonebook);
			break;
		case EXIT:
			SavePhoneBook(&phonebook);
			DestoryPhoneBook(&phonebook);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}

//文件版本
//1.退出通讯录的时候，保存信息到文件中
//2.运行起来通讯录的时候，加载文件中的信息到通讯录中