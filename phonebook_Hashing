#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxTable 10
struct Hnode
{
        char key[100];
        int cnt;
        struct Hnode *next;
};
unsigned int hv33(char*);
int Hinsert(char*,struct Hnode**);
void Hdelete(char*,struct Hnode**);
void Hfind(char*,struct Hnode**);
unsigned int hv33(char tmp[])
{
        unsigned int hv=0;
        int i=0;
        for(i=0;i<(int)strlen(tmp);i++){
                hv=((hv<<5)+hv)+(unsigned int)tmp[i];
        }
//      printf("hv==%u\n",hv);
        return hv;
}

int Hinsert(char* tmp,struct Hnode *Htable[])
{
        unsigned int hv;
        struct Hnode *ptr=NULL,*p=NULL;
        hv=hv33(tmp)%maxTable;
        if(Htable[hv]==NULL)
        {
                p=(struct Hnode*)malloc(sizeof(struct Hnode));
                strcpy(p->key,tmp);
                p->cnt=1;
                p->next=NULL;
                Htable[hv]=p;
        }
        else
        {
                ptr=Htable[hv];
                while(ptr!=NULL)
                {
                        if(strcmp(ptr->key,tmp)==0)
                        {
                                ptr->cnt++;
                                hv=0;
                                return 0;
                        }
                        else
                        {
                                ptr=ptr->next;
                        }
                }
                p=(struct Hnode*)malloc(sizeof(struct Hnode));
                strcpy(p->key,tmp);
                p->cnt=1;
                p->next=Htable[hv];
                Htable[hv]=p;

        }
        hv=0;
        return 1;
}
void Hdelete(char* tmp,struct Hnode *Htable[])
{
        unsigned int hv;
        struct Hnode *ptr=NULL;

        hv=hv33(tmp)%maxTable;

        ptr=Htable[hv];

        while(ptr!=NULL)
        {
                if(strcmp(ptr->key,tmp)==0)
                {
                        if(ptr->cnt>0){
                                ptr->cnt--;
                        }
                        hv=0;
                        return;
                }
                else
                {
                        ptr=ptr->next;
                }
        }
        hv=0;

}
void Hfind(char* tmp,struct Hnode *Htable[])
{
        unsigned int hv;
        struct Hnode *ptr=NULL;

        hv=hv33(tmp)%maxTable;

        ptr=Htable[hv];

        while(ptr!=NULL)
        {
                if(strcmp(ptr->key,tmp)==0)
                {
                        if(ptr->cnt>0){
                                printf("%s\t%d\n",ptr->key,ptr->cnt);
                                printf("----------\n");
                                hv=0;
                                return;
                        }
                        break;
                }
                else
                {
                        ptr=ptr->next;
                }
        }
        printf("Not     found!\n");
        printf("----------\n");
        hv=0;
        return;
}
int main()
{
        struct Hnode *Htable[maxTable],*ptr,*qtr;

        char operation[10],tmp[100];
        int i=0;

        //init Htable
        for(i=0; i<maxTable; i++)
        {
                Htable[i]=NULL;
        }

        //scan operation
        while(scanf("%s",operation)!=EOF)
        {

                if(strcmp(operation,"insert")==0)
                {
                        scanf("%s",tmp);
                        Hinsert(tmp,Htable);
                }

                else if(strcmp(operation,"delete")==0)
                {
                        scanf("%s",tmp);
                        Hdelete(tmp,Htable);
                }

                else if(strcmp(operation,"find")==0)
                {
                        scanf("%s",tmp);
                        printf("find    %s\n",tmp);
                        printf("----------\n");
                        Hfind(tmp,Htable);
                }

        }
        for(i=0;i<maxTable;i++){
                if(Htable[i]!=NULL){
                        ptr=Htable[i];
                        while(ptr!=NULL){
                                qtr=ptr;
                                ptr=ptr->next;
                                free(qtr);
                        }
                }
        }
        return 0;
}
