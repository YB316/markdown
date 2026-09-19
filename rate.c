/*rate.c*/
#include <stdio.h>
#include <string.h>
#define N 3

double zong(int a,int b,int c);
void pai(double xu[N],char names[N][20]);

int main()
{
    int x1,x2,x3;
    int y1,y2,y3;
    int z1,z2,z3;
    double zh1,zh2,zh3;

    printf("请输入小明的三项成绩(顺序为A B C,以一个空格为间隔):");
    scanf("%d %d %d",&x1,&x2,&x3);
    printf("请输入小强的三项成绩(顺序为A B C,以一个空格为间隔):");
    scanf("%d %d %d",&y1,&y2,&y3);
    printf("请输入小林的三项成绩(顺序为A B C,以一个空格为间隔):");
    scanf("%d %d %d",&z1,&z2,&z3);

    zh1 = zong(x1,x2,x3);

    zh2 = zong(y1,y2,y3);

    zh3 = zong(z1,z2,z3);

    double xu[N] = {zh1,zh2,zh3};
    char names[N][20] = {"小明","小强","小林"};

    pai(xu,names);

    printf("%s>%s>%s\n",names[0],names[1],names[2]);

    return 0;
}
double zong(int a,int b,int c)
{
    double avg,p1,f1;
    p1 = (a + b + c)/3.00;
    f1 = ((p1-a)*(p1-a)+(p1-b)*(p1-b)+(p1-c)*(p1-c))/3.00;
    avg = 3*p1-f1/3.00;

    return avg;
}
void pai(double xu[N],char names[N][20])
{
    int i,j;
    double temp;

    for(i=0;i<N-1;i++)
        for(j=0;j<N-1-i;j++)
        {
            if(xu[j]<xu[j+1])
            {
                temp=xu[j];
                xu[j]=xu[j+1];
                xu[j+1]=temp;

                char temp_name[20];
                strcpy(temp_name,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp_name);
            }
        }
}
