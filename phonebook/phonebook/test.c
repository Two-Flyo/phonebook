#include"phonebook.h"
void menu()
{
	printf("*********************************\n");
	printf("**********1.�½���ϵ��************\n");
	printf("**********2.ɾ����ϵ��************\n");
	printf("**********3.������ϵ��************\n");
	printf("**********4.�޸���ϵ��************\n");
	printf("**********5.��ʾ��Ϣ*************\n");
	printf("**********6.����*****************\n");
	printf("**********0.�˳�*****************\n");
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
	//����һ��ͨѶ¼
	struct PhoneBook phonebook;
	InitPhoneBook(&phonebook);
	do 
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddPeople(&phonebook);
			break;
		case DEL:
			break;
		case SHOW:
			ShowPhoneBook(&phonebook);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}