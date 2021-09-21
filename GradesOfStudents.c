#include <stdio.h>
#include <stdlib.h>
#define NC 3
#define NS 2

struct course{
int cid;
int credits;};

struct student{
int sid;
int ncourses;
struct course courses[8];
float grades[8];};

void FillCourse(struct course Listcourse[], int cs){
    for(int i=0; i<cs;i++){
            printf("\nenter a cid and the number of credits: ");
           scanf("%d%d",&Listcourse[i].cid,&Listcourse[i].credits);
           }
           }

int FindCourse(struct course Listcourse[], int cs, int cid){
    for(int i=0; i<cs;i++){
            if(cid==Listcourse[i].cid) return i;
    }
                                                  return -1;
            }

void FillStudent(struct course Listcourse[], int cs,struct student Liststudent[], int ss){
    int c;
    for(int i=0;i<ss;i++){
            printf("\nenter a sid: ");
            scanf("%d",&Liststudent[i].sid);
            printf("enter the number of courses the student enrolls: ");
            scanf("%d",&Liststudent[i].ncourses);
    for(int j=0;j<Liststudent[i].ncourses;j++){
            do {
                printf("\tenter a cid: ");
                scanf("%d",&Liststudent[i].courses[j].cid);
    c=FindCourse(Listcourse,cs,Liststudent[i].courses[j].cid);
    }while(c==-1);
    Liststudent[i].courses[j].credits=Listcourse[c].credits;
    printf("\tenter the corresponding grade: ");
    scanf("%f",&Liststudent[i].grades[j]);
    }
    }
    }

float StudentAverage(struct student S1){
    float sumG=0;
    int sumC=0;
    for(int i=0; i<S1.ncourses;i++){
        sumG+=S1.grades[i]*S1.courses[i].credits;
        sumC+=S1.courses[i].credits;
        }
        return sumG/sumC;
    }

void main(){
    struct student older;
    struct course Listcourse[NC];
    struct student Liststudent[NS];
    FillCourse(Listcourse, NC);
    FillStudent(Listcourse,NC,Liststudent,NS);
    for(int i=0; i<NS;i++)
        printf("student id:%d\t average:%f\n",Liststudent[i].sid,StudentAverage(Liststudent[i]));
}
