#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    FILE *fp = fopen("//home//kim//clang//codingschool//filepointer//source.txt", "r");
    if (fp == NULL)
    {
        puts("파일 열기 실패!!");
    }
    Init_score(sa, n, fp);
    Set_Rank(sa, n);
    Output_score(sa, n, fp, "** 성적 출력 **\n");

    fclose(fp);

    return 0; 
    

}

void Init_score(Student *sa_, int n_, FILE *fp_)
{

    int i;
    for (int i = 0; i < n_; i++)
    {
        fscanf(fp_, "%s%d%d%d", (sa_ + i)->name, &((sa_ + i)->kor), &((sa_ + i)->eng), &((sa_ + i)->mat));

        sa_[i].tot = sa_[i].kor + sa_[i].eng + sa_[i].mat;
        sa_[i].avg = sa_[i].tot / 3.0; //3.0으로 하면 실수의 값으로 저장
    }
}
void Output_score(Student *sa_, int n_, FILE *fp_, char *msg_)
{
    FILE *fp;

    fputs(msg_, stdout);
    fputs("==================================================\n", stdout);
    for (int i = 0; i < n_; i++)
    {

        fprintf(stdout, "[%2d] %8s %5d %5d %5d %5d %6.1f %4d등 \n", i + 1, (sa_ + i)->name, (sa_ + i)->kor, (sa_ + i)->eng,
                (sa_ + i)->mat, (sa_ + i)->tot, (sa_ + i)->avg, (sa_ + i)->rank);
    }
    fputs("==================================================\n", stdout);

    Get_Average(sa_, n_, stdout);

    fputs("==================================================\n", stdout);

    //파일 출력

    fp = fopen("//home//kim//clang//codingschool//filepointer//report.txt", "w");
    if (fp == NULL)
    {
        fputs("파일 열기 실패!", stdout);
    }
    fputs(msg_, fp);
    fputs("==================================================\n", fp);
    for (int i = 0; i < n_; i++)
    {

        fprintf(fp, "[%2d] %8s %5d %5d %5d %5d %6.1f %4d  등 \n", i + 1, (sa_ + i)->name, (sa_ + i)->kor, (sa_ + i)->eng,
                (sa_ + i)->mat, (sa_ + i)->tot, (sa_ + i)->avg, (sa_ + i)->rank);
    }
    fputs("==================================================\n", fp);

    Get_Average(sa_, n_, fp);

    fputs("==================================================\n", fp);

    fclose(fp);
}
void Set_Rank(Student *sa_, int n_)
{
    for (int i = 0; i < n_; i++)
    {

        (sa_ + i)->rank = 1;
        for (int j = 0; j < n_; j++)
        {

            if ((sa_ + i)->tot < (sa_ + j)->tot)
                (sa_ + i)->rank++;
        }
    }
}
void Get_Average(Student *sa_, int n_, FILE *fp_)
{

    int kortot = 0, engtot = 0, mattot = 0, totaltot = 0;
    float koravg = 0.0, engavg = 0.0, matavg = 0.0, totalavg = 0.0;
    // 각 과목 총점
    for (int i = 0; i < n_; i++)
    {
        kortot = kortot + (sa_ + i)->kor;
        engtot = engtot + (sa_ + i)->eng;
        mattot = mattot + (sa_ + i)->mat;
    }
    // 각 과목 평균
    koravg = kortot / (float)n_;
    engavg = engtot / (float)n_;
    matavg = mattot / (float)n_;
    // 전체 평균
    totalavg = (kortot + engtot + mattot) / 3.0;
    
    fprintf(fp_, "평균 ==> %12.1f %5.1f %5.1f %10.1f \n",
            koravg, engavg, matavg, totalavg / 10.0);
}



