#include"use.h"

/* 프로그램명: 고등학교 성적 관리 프로그램*/
/* 작성자: 정지성 */
/* 제작일자: 2021-07-09*/
/* Version: 1.0*/

//학생의 수를 카운팅
int student_count = 0;
//int score_count = 0;

/*st_가 붙어있으면 구조체라는 의미*/
void print_student();
void print_grade();
void init();
void choice();
void add_student();
void set_student(int grade);
void add_score();
void all();

/*---------------------*/
/*30명의 학생*/
typedef struct s_student {
   int s_grade;      //학년
   int s_group;      //반
   char s_name[20];   //학생 이름
   int s_student_num;   //학생 번호
   struct score* sc;
}s_student;


/*---------------------*/

//성적
typedef struct score {
   int kor;
   int math;
   int eng;
   int sum;
   int avg;
   //int record;
}score;

//30명의 성적, 모든곳에서 사용하기 위해 전역 구조체배열로 선언
s_student st_student[HEAD];   //30명의 학생 정보를 입력받을 구조체 배열 생성
score st_score[HEAD];         //30명의 성적 정보를 기록할 구조체 배열 생성
   
int main() {
   init();         //시작 전 초기화
   choice();      //시작

   return 0;
}

//초기화
void init() {
   
   //학생 각각에 성적 구조체를 생성해줌
   for (int i = 0; i < HEAD; i++) {
      st_student[i].sc = &st_score[i];
   }

   /*사용자 편의를 위한 더미 데이터 생성*/
   st_student[0].s_grade = 1;
   st_student[0].s_group = 1;
   st_student[0].s_student_num = 0;
   strcpy(st_student[0].s_name, "정지성");
   st_student[0].sc->kor = 50;
   st_student[0].sc->math = 50;
   st_student[0].sc->eng = 50;
   st_student[0].sc->avg = 50;
   st_student[0].sc->sum = 150;
   student_count++;

   st_student[1].s_grade = 1;
   st_student[1].s_group = 1;
   st_student[1].s_student_num = 1;
   strcpy(st_student[1].s_name, "최지훈");
   st_student[1].sc->kor = 30;
   st_student[1].sc->math = 30;
   st_student[1].sc->eng = 30;
   st_student[1].sc->avg = 30;
   st_student[1].sc->sum = 90;
   student_count++;
   /*사용자 편의를 위한 더미 데이터 생성*/

}

//메뉴를 선택
void choice(){

   int pick = 0;
   while (1) {
      printf("(1)학생 정보 추가 (2)학생 성적 추가 (3)학생 정보 출력 (4)학년 정보 출력 (5)전체 학생 정보 출력 (9)종료\n\n");
      line_cut();
      printf("메뉴를 선택하세요: ");
      scanf("%d",&pick);
      getchar();     //getchar()를 사용하며 enter를 제거 하지만 원치 않은 공백 한줄이 생긴다. 오류 해결 못함
      line_cut();
      if (pick == 1) {
         add_student();       //학생 정보 추가
      }
      else if (pick == 2) {
         add_score();         //학생 점수 추가
      }
      else if (pick == 3) {
         print_student();     //학생 정보 출력
      }
      else if (pick == 4) {
         print_grade();       //학년 정보 출력
      }
      else if (pick == 5) {
         all();               //전체 학생 정보 출력
      }
      else if (pick == 9) {   //종료
         printf("종료합니다.");
         break;
      }

      else
         err_print("선택오류");
   }
}

//학생 추가
void add_student() {
   
   int grade = 0;

   while (1) {
      printf("몇학년에 추가할까요?:");
      scanf("%d",&grade);
      getchar();
      if (grade >= 1 && grade <= 3) {     //1학년부터 3학년까지 입력 가능
         if (grade == 1) {
            set_student(1); //1학년
            return;
         }
         else if (grade == 2) {
            set_student(2);
            return;
         }
         else if (grade == 3) {
            set_student(3);
            return;
         }
      }
      else {
         err_print("범위를 벗어난 학년입니다.");
      }

   }
}

//학생 검색
void print_student(){
   char name[20];
   printf("찾고자 하는 학생의 이름을 입력해주세요:");
   scanf("%s",name);
   getchar();
   for (int i = 0; i < HEAD; i++) {       //찾고자 하는 학생의 이름이 존재하는지 검사
      if (!strcmp(name, st_student[i].s_name)) {
         printf("학생 %s의 성적을 출력합니다.\n",name);
         line_cut();
         printf("국어성적 %d, ", st_student[i].sc->kor);
         printf("수학성적 %d, ", st_student[i].sc->math);
         printf("영어석정 %d, ",st_student[i].sc->eng);
         printf("총 합%d, ",st_student[i].sc->sum);
         printf("평균 %d\n",st_student[i].sc->avg);
         line_cut();
         return;
      }
   }
   err_print("찾고자 하는 사람의 이름이 없습니다.");
   line_cut();
}

//학생 정보 입력
void set_student(int grade) {
   
   char name[20];
   int group=-1;            //몇반인지

   while(1){
      printf("학생 정보 추가 메뉴입니다.\n");
      line_cut();
      printf("반을 입력하세요:");
      scanf("%d", &group);
      getchar();
      
      while (1) {
            if (group >= 1 && group <= 10) {       //1반부터 10반까지만 존재함
               group = group;
               break;
            }
            else{
               err_print("반을 잘못 입력하셨습니다.");
               break;
            }
         }
         printf("이름을 입력하세요:");
         scanf("%s", name);
         getchar();
         line_cut();

         st_student[student_count].s_student_num = student_count + 1;
         st_student[student_count].s_grade = grade;
         st_student[student_count].s_group = group;
         strcpy(st_student[student_count].s_name, name);    //문자 배열은 strcpy를 사용해서 저장할 수 있음
                                                            //char*를 사용할 경우 값 저장 가능 
         printf("학생 번호: %d\n", st_student[student_count].s_student_num);
         printf("학생 학년: %d\n", st_student[student_count].s_grade);
         printf("학생   반: %d\n", st_student[student_count].s_group);
         printf("학생 이름: %s\n", st_student[student_count].s_name);
         line_cut();
         student_count++;     //학생 한명을 입력하고 나면 다음 학생을 가르키기 위해 증감
         break;
   }
   
}

//점수 추가
void add_score() {
   char name[20];
   int kor;
   int math;
   int eng;

      printf("성적을 추가하고 싶은 학생의 이름을 입력하세요:");
      scanf("%s",name);
      //데이터 이상 방지 getchar()
      getchar();
      //학생 구조체배열 전체에 존재하는지 검사
      for (int i = 0; i < HEAD;i++) {
         if(!strcmp(name, st_student[i].s_name)) {
            printf("%s학생의 성적을 추가합니다.\n",name);
            printf("성적은 0~100까지 입력할 수 있습니다.\n");
            printf("국어, 수학, 영어의 성적을 입력하세요:\n");
            scanf("%d %d %d",&kor,&math,&eng);
            //학생의 점수가 0~100점까지만 입력할 수 있게 제어
            if(kor>=0 && kor<=100 || math >= 0 && math <= 100 || eng >= 0 && eng <= 100){
               line_cut();
               printf("입력하신 점수는\n국어: %d, 수학:%d, 영어:%d 입니다.\n",kor,math,eng);
               line_cut();
               st_student[i].sc->kor = kor;
               st_student[i].sc->math = math;
               st_student[i].sc->eng = eng;
               st_student[i].sc->sum = (kor + math + eng);
               st_student[i].sc->avg = (kor + math + eng) / 3;
               break;
               return;
            }else
               err_print("성적 입력을 잘못 하였습니다.\n");
            line_cut();
            
         }
         
      }
}

void print_grade() {

   int grade = 0;
   printf("종료는 99\n");
   while (1) {
      
      printf("알고 싶은 학년을 입력해 주세요:");
      scanf("%d", &grade);
      getchar();
      line_cut();
      
      if (grade >= 1 && grade <= 3) {
         //학생의 정보가 누적되지 않게 계속 초기화 해줌
         int grade_sum = 0;
         int grade_avg = 0;
         int count = 0;
         for (int i = 0; i < GRADE; i++) {
            if (st_student[i].s_grade == grade) {
               grade_sum += st_student[i].sc->sum;
               grade_avg += st_student[i].sc->avg;
               count++;
            }
         }
         printf("%d학년은 총 %d 명입니다.\n",grade,count);
         printf("학년의 평균 성적은: %d 입니다.\n",grade_sum/(count*3));
         printf("학년의 총 성적은 %d 입니다.\n",grade_sum);
         line_cut();

      }
      else if (grade == 99) {
         break;
      }

      else{
         err_print("학년을 잘못 입력하셨습니다.");
      }
   }//end of while

}

void all() {
   printf("학생들의 모든 정보를 출력합니다.\n");
   line_cut();
   //st_student[i].sc->kor
   for (int i = 0; i < student_count; i++) {
      printf("%d번째 학생\n",i+1);
      
      printf("학년:%d ", st_student[i].s_grade);
      printf("반:%d ", st_student[i].s_group);
      printf("학번:%d\n", st_student[i].s_student_num+1);
      printf("이름: %s\n",st_student[i].s_name);
      printf("국어성적 %d, ", st_student[i].sc->kor);
      printf("수학성적 %d, ", st_student[i].sc->math);
      printf("영어성적 %d, ", st_student[i].sc->eng);
      printf("총 합%d, ", st_student[i].sc->sum);
      printf("평균 %d\n", st_student[i].sc->avg);

      line_cut();
   }
   printf("전체 출력 완료\n");
   line_cut();
}