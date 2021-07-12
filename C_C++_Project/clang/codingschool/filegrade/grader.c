#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{

    char name[20];
    int kor, eng, mat, tot, rank;
    float avg;

} Student;

void Init_score(Student *sa_, int n_, FILE *fp_);
void Output_score(Student *sa_, int n_, FILE *fp_, char *msg_);
void Set_Rank(Student *sa_, int n_);
void Get_Average(Student *sa_, int n_, FILE *fp_);

int main()
{
    Student sa[10];
    int n = sizeof(sa) / sizeof(Student);

    FILE *fp = fopen("/home/kim/Project/GitProject/C_C++_Project/clang/codingschool/filegrade/source.txt", "r");
    if (fp == NULL)
    {
        printf("파일 읽기 실패 ");
    }
    Init_score(sa, n, fp);
    Set_Rank(sa, n);
    Output_score(sa, n, fp, "원본출력");

    fclose(fp);

    return 0;
}

void Init_score(Student *sa_, int n_, FILE *fp_)
{

    for (int i = 0; i < n_; i++)
    {

        fscanf(fp_, "%s%d%d%d", (sa_ + i)->name, &((sa_ + i)->kor), &((sa_ + i)->eng), &((sa_ + i)->mat));
        (sa_ + i)->tot = ((sa_ + i)->kor) + ((sa_ + i)->eng) + ((sa_ + i)->mat);
        (sa_ + i)->avg = (((sa_ + i)->kor) + ((sa_ + i)->eng) + ((sa_ + i)->mat)) / 3.0;
    }
}

void Set_Rank(Student *sa_, int n_)
{

    for (int i = 0; i < n_; i++)
    {
        (sa_ + i)->rank = 1;

        for (int j = 0; j < n_; j++)
        {

            if ((sa_ + i)->tot < ((sa_ + j)->tot))
            {

                (sa_ + i)->rank++;
            }
        }
    }
}

void Output_score(Student *sa_, int n_, FILE *fp_, char *msg_)
{
    puts(" 이름    국어  영어  수학  총합  평균 순위");

    for (int i = 0; i < n_; i++)
    {

        printf("%s %5d %5d %5d %5d %6.1f %2d\n", (sa_ + i)->name, ((sa_ + i)->kor), ((sa_ + i)->eng),
               ((sa_ + i)->mat), ((sa_ + i)->tot), ((sa_ + i)->avg), ((sa_ + i)->rank));
    }

    fp_ = fopen("/home/kim/Project/GitProject/C_C++_Project/clang/codingschool/filegrade/report.txt", "w");

    if (fp_ == NULL)
    {
        puts("파일 읽기 실패");
    }
    fputs(" 이름    국어  영어   수학   총합   평균  순위\n",fp_);
    for (int i = 0; i < n_; i++)
    {
        fprintf(fp_, "%s %5d %5d %5d %5d %6.1f %4d\n", (sa_ + i)->name, ((sa_ + i)->kor), ((sa_ + i)->eng),
                ((sa_ + i)->mat), ((sa_ + i)->tot), ((sa_ + i)->avg), ((sa_ + i)->rank));
    }

}