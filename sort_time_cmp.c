#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Max 1000000

void insertion_sort(int array[]){
        int i,j,tmp;
        clock_t start,finish;
        double result;
        start=clock();
        for(i=1;i<Max;i++){
                tmp=array[i];
                for(j=i;j>0 && tmp<array[j-1] ;j--){

                        array[j]=array[j-1];

                }
                array[j]=tmp;
        }
        finish=clock();
        result=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("insertion:\n%fseconds\n",result/1);
}
void selection_sort(int array[]){
        int i,j,tmp,min,k=1;
        clock_t start,finish;
        double result;
        start=clock();
        for(i=0;i<Max;i++){
                min=i;
                for(j=i+1;j<Max;j++){
                        if(array[min]>array[j]){
                                min=j;
                        }
                }
                if(min!=i){
                        tmp=array[min];
                        array[min]=array[i];
                        array[i]=tmp;
                }
        }
        finish=clock();
        result=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("\nselection:\n%fseconds\n",result/1);
}
void bubble_sort(int array[]){
        int i,j,tmp;
        clock_t start,finish;
        double result;
        start=clock();
        for(i=0;i<Max;i++){
                for(j=0;j<Max-1-i;j++){
                        if(array[j]>array[j+1]){
                                tmp=array[j];
                                array[j]=array[j+1];
                                array[j+1]=tmp;
                        }
                }
        }
        finish=clock();
        result=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("\nBubble:\n%fseconds\n",result);
}
int compare(const void *w1,const void *w2){
        int     value;
        value=*(int*)(w1)-*(int*)(w2);
        if(value>0) return 1;
        if(value<0) return -1;
        return 0;
}

int main()
{

        int i,k=1000;
        int array[Max],BeforeArray[Max];
        clock_t start,finish;
        double result;


        //random
        srand(time(NULL));
        for(i=0;i<Max;i++){
                array[i]=rand();
                BeforeArray[i]=array[i];

        }

/*      insertion_sort(array);
        //      printf("Insertion Sort\n");
        //      printf("Before                          After\n");
        for(i=0;i<Max;i++){
                //              printf("%d               %d\n",BeforeArray[i],array[i]);
                array[i]=BeforeArray[i];
        }

        selection_sort(array);
        //      printf("Selection Sort\n");
        //      printf("Before                          After\n");
        for(i=0;i<Max;i++){
                //              printf("%d               %d\n",BeforeArray[i],array[i]);
                array[i]=BeforeArray[i];
        }


        bubble_sort(array);
        //      printf("Bubble Sort\n");
        //      printf("Before                          After\n");
        for(i=0;i<Max;i++){
                //              printf("%d               %d\n",BeforeArray[i],array[i]);
                array[i]=BeforeArray[i];
        }
        start=clock();*/
        while(k--){
        mergesort(array,Max,sizeof(int),compare);
        }
        finish=clock();
        result=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("\nmergesort:\n%fseconds\n",result/1000);
        //      printf("Merge Sort\n");
        //      printf("Before                          After\n");
        for(i=0;i<Max;i++){
                //              printf("%d               %d\n",BeforeArray[i],array[i]);
                array[i]=BeforeArray[i];
        }
        k=1000;
        start=clock();
        while(k--){
        qsort(array,Max,sizeof(int),compare);
        }
        finish=clock();
        result=(double)(finish-start)/CLOCKS_PER_SEC;
        printf("\nqsort:\n%fseconds\n",result/1000);
        //      printf("Qsort\n");
        //      printf("Before                          After\n");
        for(i=0;i<Max;i++){
                //              printf("%d               %d\n",BeforeArray[i],array[i]);
                array[i]=BeforeArray[i];
        }

        return 0;
}
