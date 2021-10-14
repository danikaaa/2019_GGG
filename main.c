#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100  // 최대 학점 기록 수

struct scholarship
{
    char s_search[20];    //장학금검색용
    char s_compare[20];   //장학금 기준과 비교하기위함
};

typedef struct scholarship sch;

struct score {    // 학점 구조체
int grade;
int semester;
float score;
};
typedef struct score SCR;
SCR arr[MAX];  // 학점 테이블
int num = 0;   // 현재 학점 기록 수

void insert(void); // 학점입력하는 함수
void delete(void); // 입력된 학점을 지우는 함수
void calculate(void); // 학점을 계산하는 함수
void num_sorting(void); // 학년과 학기별로 정렬하는 함수
void list(void); // 학점리스트를 보여주는 함수
char s_search(char search[50]); // 장학금검색을 하는 함수
int Academic_Calendar(void); //학사일정을 검색하는 함수
int s_show(void); // 장학금을 보여주는 함수
int open_calculate(void); // 계산기를 여는 함수
int scholarship(void); // 장학금을 여는 함수

/*
char s_keyword_search(char search[20])  //키워드로 검색하는 함수
{
    char s[38][10] =
    {
    "슈퍼","수석","성적","입학","우대","우수","보훈",
    "군","북한","교직원","학원","재해","가족","장애",
    "특수","나눔","이사장","목회자","사정관","근로","복음",
    "알리미","미디어","도우미","해외","문화","추천","섬김",
    "고시","알오티시","ROTC","다문화","만학도","star",
    "편입","재단","기독교","rotc"
    };  //검색될 키워드

    int i , result;

    for(i = 0; i < 38; i++)
    {
        result = strcmp(search, s[i]); //키워드와 입력된 값 비교

        if(result == 0)  //i에 맞는 키워드에 관련된 파일을 불러오게 만들기
        {
        	printf("%s", s[i]);
        	printf("%d", i);
            break;
        }
    }
    if(result != 0)
        printf("잘못입력하셨습니다. \n");
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
        printf("1. 성적계산기 \n");
        printf("2. 장학금 \n");
        printf("3. 학사일정 \n");
        printf("4. 종료\n\n");
        printf("번호를 입력하세요 : ");
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
printf("나의 학점(학년 학기 성적) 입력\n");
printf("학년 학기 성적\n");
scanf("%d %d %f", &arr[num].grade, &arr[num].semester, &arr[num].score);
num++;  // 학점 기록 수 1 증가
fflush(stdin);
system("pause");
system("cls");
   return;
}
void delete(void)
{
   int i, grade, semester;
printf("삭제할 학점의 학년 학기 입력:");
scanf("%d %d", &grade, &semester);
fflush(stdin);
for (i = 0; i < num; i++) {   // 배열의 모든 원소에 대하여 반복처리
 if (arr[i].grade == grade){  // 동일한 학기 찾기
    system("pause");
   system("cls");
     break;
  }
}
if (i >= num){   // 배열 끝에 도달
 printf("존재하지 않음\n");
 system("pause");
system("cls");
}
else {
       for(; i < num-1; i++) // 해당 원소를 없애고 그 후 원소들을 모두 앞으로 한칸씩 이동
           arr[i] = arr[i+1];
     num--;  // 학점 기록 수 1 감소
     return;
}
}
//  성적 계산기
void calculate(void)
{
   int i, max;
   float total, score;
   printf("총 몇과목을 듣는지 입력해주세요 = ");
   scanf("%d", &max);
   fflush(stdin);
   for(i = 0; i < max; i++)
   {
       printf("학점을 입력해주세요 = ");
       scanf("%f", &score);
       fflush(stdin);
       total += score;
   }
   printf("평균성적은 : %0.2f \n", total/max);
   system("pause");
   system("cls");
}

// 학년 학기순 오름차순 정렬 함수  num : 학생수
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
   printf("======= 리스트 =======\n");
   printf("  학년   학기   성적\n");
for(i = 0; i < num; i++)
 printf("%6d %6d %6.2f\n", arr[i].grade, arr[i].semester, arr[i].score);
printf("\n");
system("pause");
system("cls");
}

char s_search(char search[50]) //해당단어를 이용하여 검색하기
{
	char buf[9000];	//파일의 내용을 담기위함
	FILE * fp = NULL;
	fp = fopen("장학금이름.txt", "r");	//장학금이란 파일을 읽기모드로 열기
	if(fp == NULL)
	{
		printf("불러오지 못했습니다. \n");
		system("pause");
		return 1;
	}

	while(fgets(buf, 9000, fp))	//파일안에서 해당 단어로 검색하기
	{
		if(strstr(buf, search)) //buf와 search의 값을 비교하여 같으면 실행 다르면 바로 넘어가기
		{
			printf("\n");
			printf("%s", buf);
		}
	}
	fclose(fp);
	printf("\n");
	system("PAUSE");  //아무키나 누르면 처음으로 돌아가기
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

    printf("====== 학사 일정 검색하기 ====== \n");
    printf("검색할 날짜(yyyy-mm-dd)를 입력하시오  : ");
    scanf("%s", word);
    fflush(stdin);

    if((fp=fopen("학사일정.txt", "r"))==NULL)
    {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
    	system("PAUSE");
        return 0;
    }
   while(fgets(buffer, 256, fp))	//파일안에서 해당 단어로 검색하기
	{
		if(strstr(buffer, word)) //buffer와 word의 값을 비교하여 같으면 실행 다르면 바로 넘어가기
		{
			printf("%s", buffer); // 맞으면 값 출력
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
            printf("====== 장학금 리스트 ======\n");
            printf("1. 전체보기\n");
            printf("2. 신입생\n");
            printf("3. 재학생\n");
            printf("4. 신입생및재학생\n");
            printf("5. 편입생\n");
            printf("6. 돌아가기\n\n");

            printf("번호를 입력하세요 : ");

            scanf("%d", &choice);
            fflush(stdin);

            system("cls");

        if(choice==1)
        {

            FILE* fp = fopen("장학금.txt","r");
        int ch;

        if(fp == NULL)
        {
            printf("불러오지 못했습니다. \n");
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

            FILE* fp = fopen("신입생.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("불러오지 못했습니다. \n");
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
            FILE* fp = fopen("재학생.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("불러오지 못했습니다. \n");
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
            FILE* fp = fopen("신입생및재학생.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("불러오지 못했습니다. \n");
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
            FILE* fp = fopen("편입생.txt","r");
            int ch;

            if(fp == NULL)
            {
                printf("불러오지 못했습니다. \n");
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
FILE *fp;     // 파일 포인터
while(1) {
      system("cls");
                  // 메뉴출력
printf("====== 성적계산기 ======\n");

 printf("1.계산 \n2.입력 \n3.삭제 \n4.리스트 \n5.정렬 \n6.저장 \n7.파일읽기 \n8.돌아가기\n\n");
 printf("번호를 입력하세요 : ");
                  // 메뉴선택
 scanf("%d", &select);
 fflush(stdin);  // 입력버퍼 비우기
 switch (select) {
  case 1 :     // 성적 계산기 불러오기
               calculate();
               break;
  case 2 :    // 한 학기 학점을 맨 뒤에 추가
      insert();
   break;
  case 3 :    // 학기에 해당하는 학점 삭제
               delete();
   break;
  case 4 :     // 배열 내의 학점 나열 출력
   list();
   break;
  case 5:      // 학점정보 정렬 처리
               num_sorting();
               list();
               break;
   case 6 :     // 파일에 학점정보를 저장
   fp = fopen("학점저장.txt", "w");
   if (fp == NULL)
  {
      printf("파일열기 실패\n");
      system("PAUSE");
      return -1;
   }

   for(i = 0; i < num; i++) // 배열 상에서 이동
   {
      fprintf(fp,"%d %d %f\n", arr[i].grade, arr[i].semester, arr[i].score);
   }
   fclose(fp);
      system("cls");

  case 7 :    // 파일로부터 학점정보 읽기
  fp = fopen("학점저장.txt", "r");
   if (fp == NULL) {
    printf("파일열기 실패\n");
    system("PAUSE");
    return -1;
   }
   num = 0;
   for(i = 0; i < MAX; i++) { // 파일로부터 학생정보를 하나씩 반복해서 읽음
    fscanf(fp,"%d %d %f", &arr[i].grade, &arr[i].semester, &arr[i].score); // 파일에 끝에 도달하면
    fflush(stdin);
    if(arr[i].grade == 0 && arr[i].semester == 0 && arr[i].score == 0)
       break;


   system("cls");
    num++;   // 학생 수 증가
   }
   fclose(fp);
   open_calculate();

  case 8 :   //종료
   return 0;

 }
}
}

int scholarship(void)
{
	system("cls"); // 화면초기화
    int menu = 1, menu2; // 첫번째 메뉴선택과 두번째 메뉴선택
    sch sch;

    printf("====== 장학금 ======\n");
    printf("1. 장학금 검색하기 \n");
    printf("2. 장학금 기준에 맞나 확인하기 \n");
    printf("3. 장학금 종류 \n");
    printf("4. 돌아가기 \n\n");
    printf("번호를 입력하세요 : ");
    scanf("%d", &menu); //첫번쨰 메뉴값 입력받기
    fflush(stdin);
    system("cls");

    if(menu == 1)
    {
		printf("검색할 장학금을 입력하세요. :");
	    scanf("%s", sch.s_search);
	    fflush(stdin);
	    s_search(sch.s_search); //함수실행
	}
    else if(menu == 2)
    {
        printf("1. 평균학점과 비교 \n");//기준에 맟춰 보여주기
        printf("2. 취득학점과 비교 \n\n");//취득학점은 12점 이상이어야 한다고 보여주기
        printf("입력해주세요 : ");

        scanf("%d", &menu2);
        fflush(stdin);

        if(menu2 == 1)
        {
            float score;
            FILE *fp = NULL;
            char ch;

            printf("본인의 전학기 평균학점을 입력해주세요:");
            scanf("%f", &score);
            fflush(stdin);
            printf("\n");

            if(score >= 3.5)
            {
                fp = fopen("3.5학점.txt", "r");
                if(fp == NULL)
                {
                    printf("불러오지 못했습니다. \n");
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
                fp = fopen("3학점.txt", "r");
                if(fp == NULL)
                {
                    printf("불러오지 못했습니다. \n");
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
                fp = fopen("2.5학점.txt", "r");
                if(fp == NULL)
                {
                    printf("불러오지 못했습니다. \n");
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
                fp = fopen("2학점.txt", "r");
                if(fp == NULL)
                {
                    printf("불러오지 못했습니다. \n");
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
            printf("--------취득학점은 항상 12학점 이상이어야 합니다.-------- \n");
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
        printf("잘못된 입력입니다. \n");
        system("PAUSE");
        scholarship(); // 함수를 다시실행
    }

}
