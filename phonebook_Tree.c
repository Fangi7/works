#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define OFF 0
#define ON 1
        struct student{
                char studentID[10];
                char name[30];
                char phone[10];
                int  age;
        };

void Insert(struct student *stu,struct student *tmp,int MaxStu)
{
        strcpy(stu[MaxStu].studentID,tmp.studentID);
        strcpy(stu[MaxStu].name,&tmp.name);
        strcpy(stu[MaxStu].phone,&tmp.phone);
        stu[MaxStu].age=atoi(tmp.age);
        printf("%s,%s,%s,%d\n",stu[MaxStu].studentID,stu[MaxStu].name,stu[MaxStu].phone,stu[MaxStu].age);
}

void List(struct student *stu,int MaxStu)
{
        int i;
        for(i=0;i<MaxStu;i++){
                printf("%s,%s,%s,%d\n",stu[i].studentID,stu[i].name,stu[i].phone,stu[i].age);
        }
}

int main()
{
        int insert=OFF;
        int list=OFF;
        int exist=OFF;
        int i;
        int MaxStu=0;
        char *ptr;
        char line[1000];
        struct student stu[1000];
        struct student tmp;

        printf("Please input command(i/d/u/f/l/s/w) and data.\n");
        while(fgets(line,1000,stdin)!=NULL){
                ptr=line;
                insert=OFF;
                list=OFF;
                switch(*ptr){
                        case 'i':
                                insert=ON;
                                break;
                        case 'l':
                                list=ON;
                                break;
                }
                if(insert==ON){
                        for(ptr=line;*ptr!=EOF;ptr++){
                                if(*ptr==',') *ptr='\0';
                        }
                        ptr=line;
                        ptr++;
                        ptr++;
                        sscanf(ptr,"%s,",&tmp.studentID);

                        for(i=0;i<MaxStu;i++){
                                if(strcmp(&tmp.studentID,stu[i].studentID)==0){
                                        printf("Insert error! studentID is exists!\n");
                                        exist=ON;
                                        break;
                                }
                        }
                        if(exist==OFF){
                                ptr+=strlen(&tmp.studentID);
                                ptr++;
                                sscanf(ptr,"%s",&tmp.name);

                                ptr+=strlen(&tmp.name);
                                ptr++;
                                sscanf(ptr,"%s",&tmp.phone);
                                ptr+=strlen(&tmp.phone);
                                ptr++;
                                sscanf(ptr,"%d",&tmp.age);

                                Insert(stu,&tmp,MaxStu);

                                MaxStu++;
                        }
                }
                if(list==ON){
                        List(stu[0],MaxStu);
                }

        }
        return 0;
}
