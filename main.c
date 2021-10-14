#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100  // �ִ� ���� ��� ��

struct scholarship
{
    char s_search[20];    //���бݰ˻���
    char s_compare[20];   //���б� ���ذ� ���ϱ�����
};

typedef struct scholarship sch;

struct score {    // ���� ����ü
int grade;
int semester;
float score;
};
typedef struct score SCR;
SCR arr[MAX];  // ���� ���̺�
int num = 0;   // ���� ���� ��� ��

void insert(void); // �����Է��ϴ� �Լ�
void delete(void); // �Էµ� ������ ����� �Լ�
void calculate(void); // ������ ����ϴ� �Լ�
void num_sorting(void); // �г�� �б⺰�� �����ϴ� �Լ�
void list(void); // ��������Ʈ�� �����ִ� �Լ�
char s_search(char search[50]); // ���бݰ˻��� �ϴ� �Լ�
int Academic_Calendar(void); //�л������� �˻��ϴ� �Լ�
int s_show(void); // ���б��� �����ִ� �Լ�
int open_calculate(void); // ���⸦ ���� �Լ�
int scholarship(void); // ���б��� ���� �Լ�

/*
char s_keyword_search(char search[20])  //Ű����� �˻��ϴ� �Լ�
{
    char s[38][10] =
    {
    "����","����","����","����","���","���","����",
    "��","����","������","�п�","����","����","���",
    "Ư��","����","�̻���","��ȸ��","������","�ٷ�","����",
    "�˸���","�̵��","�����","�ؿ�","��ȭ","��õ","����",
    "���","�˿�Ƽ��","ROTC","�ٹ�ȭ","���е�","star",
    "����","���","�⵶��","rotc"
    };  //�˻��� Ű����

    int i , result;

    for(i = 0; i < 38; i++)
    {
        result = strcmp(search, s[i]); //Ű����� �Էµ� �� ��

        if(result == 0)  //i�� �´� Ű���忡 ���õ� ������ �ҷ����� �����
        {
        	printf("%s", s[i]);
        	printf("%d", i);
            break;
        }
    }
    if(result != 0)
        printf("�߸��Է��ϼ̽��ϴ�. \n");
}
*/


int main()
{
    int menu;
    while(1)
    {
        system("cls");
        printf("Get \n");
        printf("Good \n");
        printf("Grade \n");
        printf("======================\n");
        printf("1. �������� \n");
        printf("2. ���б� \n");
        printf("3. �л����� \n");
        printf("4. ����\n\n");
        printf("��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &menu);
        fflush(stdin);

        switch(menu)
        {
        case 1 :
            open_calculate();
            break;

        case 2 :
            scholarship();
            break;

        case 3 :
            Academic_Calendar();
            break;
        
        case 4 :
        	return 0;
        }
    }
}

void insert(void)
{
printf("���� ����(�г� �б� ����) �Է�\n");
printf("�г� �б� ����\n");
scanf("%d %d %f", &arr[num].grade, &arr[num].semester, &arr[num].score);
num++;  // ���� ��� �� 1 ����
fflush(stdin);
system("pause");
system("cls");
   return;
}
void delete(void)
{
   int i, grade, semester;
printf("������ ������ �г� �б� �Է�:");
scanf("%d %d", &grade, &semester);
fflush(stdin);
for (i = 0; i < num; i++) {   // �迭�� ��� ���ҿ� ���Ͽ� �ݺ�ó��
 if (arr[i].grade == grade){  // ������ �б� ã��
    system("pause");
   system("cls");
     break;
  }
}
if (i >= num){   // �迭 ���� ����
 printf("�������� ����\n");
 system("pause");
system("cls");
}
else {
       for(; i < num-1; i++) // �ش� ���Ҹ� ���ְ� �� �� ���ҵ��� ��� ������ ��ĭ�� �̵�
           arr[i] = arr[i+1];
     num--;  // ���� ��� �� 1 ����
     return;
}
}
//  ���� ����
void calculate(void)
{
   int i, max;
   float total, score;
   printf("�� ������� ����� �Է����ּ��� = ");
   scanf("%d", &max);
   fflush(stdin);
   for(i = 0; i < max; i++)
   {
       printf("������ �Է����ּ��� = ");
       scanf("%f", &score);
       fflush(stdin);
       total += score;
   }
   printf("��ռ����� : %0.2f \n", total/max);
   system("pause");
   system("cls");
}

// �г� �б�� �������� ���� �Լ�  num : �л���
void num_sorting(void)
{
   int i, j;
   for(i=num-2; i>=0; i--){
       for(j=0; j<=i; j++){
           if(arr[j].grade > arr[j+1].grade || arr[j].semester > arr[j+1].semester) {
               SCR tmp;
               tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;

           }
       }
    }
    for(i=num-2; i>=0; i--){
       for(j=0; j<=i; j++){
           if(arr[j].grade > arr[j+1].grade) {
               SCR tmp;
               tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;

           }
       }
    }
  system("pause");
   system("cls");
}

void list(void)
{
   int i;
   printf("======= ����Ʈ =======\n");
   printf("  �г�   �б�   ����\n");
for(i = 0; i < num; i++)
 printf("%6d %6d %6.2f\n", arr[i].grade, arr[i].semester, arr[i].score);
printf("\n");
system("pause");
system("cls");
}

char s_search(char search[50]) //�ش�ܾ �̿��Ͽ� �˻��ϱ�
{
	char buf[9000];	//������ ������ �������
	FILE * fp = NULL;
	fp = fopen("���б��̸�.txt", "r");	//���б��̶� ������ �б���� ����
	if(fp == NULL)
	{
		printf("�ҷ����� ���߽��ϴ�. \n");
		system("pause");
		return 1;
	}

	while(fgets(buf, 9000, fp))	//���Ͼȿ��� �ش� �ܾ�� �˻��ϱ�
	{
		if(strstr(buf, search)) //buf�� search�� ���� ���Ͽ� ������ ���� �ٸ��� �ٷ� �Ѿ��
		{
			printf("\n");
			printf("%s", buf);
		}
	}
	fclose(fp);
	printf("\n");
	system("PAUSE");  //�ƹ�Ű�� ������ ó������ ���ư���
	scholarship();
}

int Academic_Calendar(void)
{
    FILE *fp;
    char fname[256];
    char buffer[256];
    char word[256];
    int line = 0;

    system("cls");

    printf("====== �л� ���� �˻��ϱ� ====== \n");
    printf("�˻��� ��¥(yyyy-mm-dd)�� �Է��Ͻÿ�  : ");
    scanf("%s", word);
    fflush(stdin);

    if((fp=fopen("�л�����.txt", "r"))==NULL)
    {
        fprintf(stderr, "������ �� �� �����ϴ�.\n");
    	system("PAUSE");
        return 0;
    }
   while(fgets(buffer, 256, fp))	//���Ͼȿ��� �ش� �ܾ�� �˻��ϱ�
	{
		if(strstr(buffer, word)) //buffer�� word�� ���� ���Ͽ� ������ ���� �ٸ��� �ٷ� �Ѿ��
		{
			printf("%s", buffer); // ������ �� ���
		}
	}
	printf("\n");
	printf("\n");
	system("pause");
    system("cls");
    fclose(fp);
    return;
}

int s_show(void)
{
    int choice;
            start:
    while(1)
    {
            printf("====== ���б� ����Ʈ ======\n");
            printf("1. ��ü����\n");
            printf("2. ���Ի�\n");
            printf("3. ���л�\n");
            printf("4. ���Ի������л�\n");
            printf("5. ���Ի�\n");
            printf("6. ���ư���\n\n");

            printf("��ȣ�� �Է��ϼ��� : ");

            scanf("%d", &choice);
            fflush(stdin);

            system("cls");

        if(choice==1)
        {

            FILE* fp = fopen("���б�.txt","r");
        int ch;

        if(fp == NULL)
        {
            printf("�ҷ����� ���߽��ϴ�. \n");
            system("PAUSE");
        }
        while((ch= fgetc(fp)) != EOF)
        {
            putchar(ch);
        }

            fclose(fp);

        printf("\n");
        printf("\n");
        system("pause");
        system("cls");

        goto start;
        }
        else if(choice==2)
        {

            FILE* fp = fopen("���Ի�.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("�ҷ����� ���߽��ϴ�. \n");
                system("PAUSE");
            }
            while((ch= fgetc(fp)) != EOF)
            {
                putchar(ch);
            }

            fclose(fp);
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
            goto start;
        }
        else if(choice==3)
        {
            FILE* fp = fopen("���л�.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("�ҷ����� ���߽��ϴ�. \n");
                system("PAUSE");
                
            }
            while((ch= fgetc(fp)) != EOF)
            {
                putchar(ch);
            }

            fclose(fp);
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
            goto start;
        }
        else if(choice==4)
        {
            FILE* fp = fopen("���Ի������л�.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("�ҷ����� ���߽��ϴ�. \n");
                system("PAUSE");
            }
            while((ch= fgetc(fp)) != EOF)
            {
                putchar(ch);
            }

            fclose(fp);
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
            goto start;
        }
        else if(choice==5)
        {
            FILE* fp = fopen("���Ի�.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("�ҷ����� ���߽��ϴ�. \n");
                system("PAUSE");
            }
            while((ch= fgetc(fp)) != EOF)
            {
                putchar(ch);
            }

            fclose(fp);
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
            goto start;
        }
        else if(choice==6)
        {
            scholarship();
        }
        else
            goto start;
        break;
    }
}

int  open_calculate(void)
{
int i;
int select;
FILE *fp;     // ���� ������
while(1) {
      system("cls");
                  // �޴����
printf("====== �������� ======\n");

 printf("1.��� \n2.�Է� \n3.���� \n4.����Ʈ \n5.���� \n6.���� \n7.�����б� \n8.���ư���\n\n");
 printf("��ȣ�� �Է��ϼ��� : ");
                  // �޴�����
 scanf("%d", &select);
 fflush(stdin);  // �Է¹��� ����
 switch (select) {
  case 1 :     // ���� ���� �ҷ�����
               calculate();
               break;
  case 2 :    // �� �б� ������ �� �ڿ� �߰�
      insert();
   break;
  case 3 :    // �б⿡ �ش��ϴ� ���� ����
               delete();
   break;
  case 4 :     // �迭 ���� ���� ���� ���
   list();
   break;
  case 5:      // �������� ���� ó��
               num_sorting();
               list();
               break;
   case 6 :     // ���Ͽ� ���������� ����
   fp = fopen("��������.txt", "w");
   if (fp == NULL)
  {
      printf("���Ͽ��� ����\n");
      system("PAUSE");
      return -1;
   }

   for(i = 0; i < num; i++) // �迭 �󿡼� �̵�
   {
      fprintf(fp,"%d %d %f\n", arr[i].grade, arr[i].semester, arr[i].score);
   }
   fclose(fp);
      system("cls");

  case 7 :    // ���Ϸκ��� �������� �б�
  fp = fopen("��������.txt", "r");
   if (fp == NULL) {
    printf("���Ͽ��� ����\n");
    system("PAUSE");
    return -1;
   }
   num = 0;
   for(i = 0; i < MAX; i++) { // ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
    fscanf(fp,"%d %d %f", &arr[i].grade, &arr[i].semester, &arr[i].score); // ���Ͽ� ���� �����ϸ�
    fflush(stdin);
    if(arr[i].grade == 0 && arr[i].semester == 0 && arr[i].score == 0)
       break;


   system("cls");
    num++;   // �л� �� ����
   }
   fclose(fp);
   open_calculate();

  case 8 :   //����
   return 0;

 }
}
}

int scholarship(void)
{
	system("cls"); // ȭ���ʱ�ȭ
    int menu = 1, menu2; // ù��° �޴����ð� �ι�° �޴�����
    sch sch;

    printf("====== ���б� ======\n");
    printf("1. ���б� �˻��ϱ� \n");
    printf("2. ���б� ���ؿ� �³� Ȯ���ϱ� \n");
    printf("3. ���б� ���� \n");
    printf("4. ���ư��� \n\n");
    printf("��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &menu); //ù���� �޴��� �Է¹ޱ�
    fflush(stdin);
    system("cls");

    if(menu == 1)
    {
		printf("�˻��� ���б��� �Է��ϼ���. :");
	    scanf("%s", sch.s_search);
	    fflush(stdin);
	    s_search(sch.s_search); //�Լ�����
	}
    else if(menu == 2)
    {
        printf("1. ��������� �� \n");//���ؿ� ���� �����ֱ�
        printf("2. ��������� �� \n\n");//��������� 12�� �̻��̾�� �Ѵٰ� �����ֱ�
        printf("�Է����ּ��� : ");

        scanf("%d", &menu2);
        fflush(stdin);

        if(menu2 == 1)
        {
            float score;
            FILE *fp = NULL;
            char ch;

            printf("������ ���б� ��������� �Է����ּ���:");
            scanf("%f", &score);
            fflush(stdin);
            printf("\n");

            if(score >= 3.5)
            {
                fp = fopen("3.5����.txt", "r");
                if(fp == NULL)
                {
                    printf("�ҷ����� ���߽��ϴ�. \n");
                    system("PAUSE");
                    return 1;
                }

                while((ch = fgetc(fp)) != EOF)
                    putchar(ch);


                fclose(fp);
                printf("\n");
                printf("\n");
                system("PAUSE");
            }
            else if(score >= 3.0)
            {
                fp = fopen("3����.txt", "r");
                if(fp == NULL)
                {
                    printf("�ҷ����� ���߽��ϴ�. \n");
                    system("PAUSE");
                    return 1;
                }
                while((ch = fgetc(fp)) != EOF)
                    putchar(ch);

                fclose(fp);
                printf("\n");
                printf("\n");
                system("PAUSE");
            }
            else if(score >= 2.5)
            {
                fp = fopen("2.5����.txt", "r");
                if(fp == NULL)
                {
                    printf("�ҷ����� ���߽��ϴ�. \n");
                    system("PAUSE");
                    return 1;
                }
                while((ch = fgetc(fp)) != EOF)
                    putchar(ch);

                fclose(fp);
                printf("\n");
                printf("\n");
                system("PAUSE");
            }
            else if(score >= 2.0)
            {
                fp = fopen("2����.txt", "r");
                if(fp == NULL)
                {
                    printf("�ҷ����� ���߽��ϴ�. \n");
                    system("PAUSE");
                    return 1;
                }
                while((ch = fgetc(fp)) != EOF)
                    putchar(ch);

                fclose(fp);
                printf("\n");
                printf("\n");
                system("PAUSE");
            }
        }
        else if(menu2 == 2)
        {
            system("cls");
            printf("--------��������� �׻� 12���� �̻��̾�� �մϴ�.-------- \n");
            printf("\n");
            system("PAUSE");
        }

        printf("\n");
        scholarship();
    }
    else if(menu == 3)
    {
        s_show();
    }

    else if(menu == 4)
    {
        return;
    }
    else if(menu >= 5)
    {
        printf("�߸��� �Է��Դϴ�. \n");
        system("PAUSE");
        scholarship(); // �Լ��� �ٽý���
    }

}
