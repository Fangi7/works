/*
   bignumber calculatr
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 100000
struct dataform{
	char ID[10];
	char num1[Max];
	char num2[Max];
	struct dataform *next;
};
struct dataform *start,*endp,*form;

int cnt=0;
char fileName[100];

void openFile()
{
	FILE *fp;
	printf("Please input the file name:");
	scanf("%s",&fileName);

	fp=fopen(fileName,"r");
	if(fp==NULL) printf("No such file!\n");
	else{
		/*store data*/
		char line[200];
		char *tp;
		/*link list*/
		struct dataform *newp;
		while(fgets(line,200,fp)!=NULL)
		{
			newp=(struct dataform*)malloc(sizeof(struct dataform));
			/*cut the string*/
			tp=strtok(line,",");
			strcpy(newp->ID,tp);

			tp=strtok(NULL,",");
			strcpy(newp->num1,tp);

			tp=strtok(NULL,",");
			strcpy(newp->num2,tp);
			*(newp->num2+strlen(newp->num2)-2)='\0';
			/*is head or not*/
			if(cnt==0){
				start=newp;
				endp=newp;
			}
			else{
				endp->next=newp;
				endp=newp;
			}
			cnt++;
		}
		//test
		int i=0;
		form=start->next;
		printf("%s reads successfully\n",fileName);
		fclose(fp);
	}
}

void showFile()
{
	int i=0;
	char *scinum;
	int tmp=0;
	int carry=0;
	form=start;
	form=form->next;
	printf("Here is your records\n");
	for(i=1;i<cnt;i++){

		printf("NO.%s,",form->ID);
		//print scient num1
		tmp=strlen(form->num1);
		scinum=form->num1;

		//judge carry or not
		if(*(scinum+3)-'0'>=5 && tmp>3) carry=*(scinum+2)-'0'+1;
		else carry=*(scinum+2)-'0';

		if(tmp==1){
			printf("%d.00e+000 , ",(*scinum)-'0');
		}
		else {
			printf("%d.%d%de+%03d , ",(*scinum)-'0',(*(scinum+1))-'0',carry,tmp-1);
		}
		//print scient num2
		scinum=form->num2;

		//judge carry or not
		if(*(scinum+3)-'0'>=5 && tmp>3) carry=*(scinum+2)-'0'+1;
		else carry=*(scinum+2)-'0';
		scinum=form->num2;
		if(tmp==1){
			printf("%c.00e+000\n",*scinum);
		}
		else {
			printf("%c.%c%de+%03d\n",*scinum,*(scinum+1),carry,tmp-1);
		}
		form=form->next;
	}
}
void insert()
{
	char *tp;
	struct dataform *newp;
	FILE *fp;
	newp=(struct dataform*)malloc(sizeof(struct dataform));

	if(cnt==0){
		printf("You should input a file first!\n");
	}
	else{
		char buffer[10];
		endp->next=newp;
		endp=newp;
		sprintf(buffer,"%d",cnt);
		strcpy(newp->ID,buffer);

		printf("NO.%d\n",cnt);
		printf("Number1:");
		scanf("%s",&newp->num1);
		printf("nu1=%s\n",newp->num1);
		printf("Number2:");
		scanf("%s",&newp->num2);
		printf("nu2=%s\n",newp->num2);

		fp=fopen(fileName,"a");
		fprintf(fp,"%d,",cnt);
		fprintf(fp,"%s,",newp->num1);
		fprintf(fp,"%s",newp->num2);
		fprintf(fp,"\n");
		fclose(fp);

	}

	cnt++;
}
struct dataform* Lfind(){
	int No=0;
	int i=0;
	int IDi=0;
	scanf("%d",&No);
	if(cnt==0){
		printf("Must read csv file first!\n");
		return 0;
	}
	else{
		form=start;
		form=form->next;
		for(i=0;i<cnt;i++){
			IDi=atoi(form->ID);
			if(IDi==No){
				return form;
				break;
			}
			form=form->next;
		}
	}
}

struct dataform* input_way()
{
	printf("=========================================\n");
	printf("=                                       =\n");
	printf("= Which items do you want to choose?    =\n");
	printf("= (1)Load the existing numbers by ID    =\n");
	printf("= (2)Input two numbers to calculate     =\n");
	printf("= (0)Quit                               =\n");
	printf("=                                       =\n");
	printf("=========================================\n");
	int c=0;
	struct dataform *newp;
	FILE *fp;
	fp=fopen("result.txt","a");
while(1){
	scanf("%d",&c);
	switch(c){
		case 0:
			return 0;
		case 1:
			printf("What index do you want to read?\n");
			newp=Lfind();
			if(newp==0) return 0;
			fprintf(fp,"\nLoad the record of ID=%s\n",newp->ID);
			fclose(fp);
			return newp; 
		case 2:
			fprintf(fp,"\nInput two numbers to calculate\n");
			fclose(fp);
			newp=(struct dataform*)malloc(sizeof(struct dataform));
			*(newp->ID)='\0';
			printf("First number:");
			scanf("%s",&newp->num1);
			printf("Second number:");
			scanf("%s",&newp->num2);
			return newp;
//		default: 
//			continue;
	}
}
}
void add(struct dataform* add)
{
	char add1[Max];
	char add2[Max];
	int sum[Max];
	int textlen=0;
	int maxlen=0;
	int tmp=0;
	int i=0;

	memset(add1,0,Max);
	memset(add2,0,Max);
	memset(sum,0,Max);
	strcpy(add1,add->num1);
	strcpy(add2,add->num2);
	//reverse add1
	textlen=strlen(add1);
	maxlen=textlen;

	for(i=0;i<textlen/2;i++){
		tmp=add1[i];
		add1[i]=add1[textlen-1-i]-'0';
		add1[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) add1[(textlen/2)]-='0';

	//compare add1,add2,and find maxlen
	if(textlen<strlen(add2)) maxlen=strlen(add2);

	//reverse add2
	textlen=strlen(add2);
	for(i=0;i<textlen/2;i++){
		tmp=add2[i];
		add2[i]=add2[textlen-1-i]-'0';
		add2[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) add2[(textlen/2)]-='0';

	//add1+add2
	for(i=0;i<=maxlen;i++){

		if((sum[i]+add1[i]+add2[i])<=9) {
			sum[i]+=add1[i]+add2[i];
		}

		else{

			sum[i]=(sum[i]+add1[i]+add2[i])%10;
			sum[i+1]=1;
		}
	}
	printf("Sum:");
	for(i=maxlen;i>=0;i--){
//		if(sum[maxlen]==0) i--;
		printf("%d",sum[i]);
	}

	FILE *fp;
	fp=fopen("result.txt","a");
	fprintf(fp,"Sample input:\n+\n");
	fprintf(fp,"%s\n%s\nSameple output:\n",add->num1,add->num2);
	for(i=maxlen;i>=0;i--){
//		if(sum[maxlen]==0) i--;
		fprintf(fp,"%d",sum[i]);
	}
	fprintf(fp,"\n");
	fclose(fp);

	printf("\n");
}

void sub(struct dataform* sub)
{
	char sub1[Max];
	char sub2[Max];
	int sum[Max];
	int textlen=0;
	int maxlen=0;
	int tmp=0;
	int i=0;

	memset(sub1,0,Max);
	memset(sub2,0,Max);
	memset(sum,0,Max);
	strcpy(sub1,sub->num1);
	strcpy(sub2,sub->num2);
	//reverse sub1
	textlen=strlen(sub1);
	maxlen=textlen;
	for(i=0;i<textlen/2;i++){
		tmp=sub1[i];
		sub1[i]=sub1[textlen-1-i]-'0';
		sub1[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) sub1[(textlen/2)]-='0';

	//compare sub1,sub2,and find maxlen
	int flag=0;

	if(textlen<strlen(sub2)){
		flag++;
		maxlen=strlen(sub2);
	}

	//reverse sub2
	textlen=strlen(sub2);
	for(i=0;i<textlen/2;i++){
		tmp=sub2[i];
		sub2[i]=sub2[textlen-1-i]-'0';
		sub2[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) sub2[(textlen/2)]-='0';
	//compare sub1,sub2
	if(strlen(sub1)==strlen(sub2)){
		for(i=strlen(sub2);i>0;i--){
			if(sub1[i]-sub2[i]<0){
				flag++;
				break;
			}
		}
	}
	//sub2>sub1
	if(flag>0){
		//sub2-sub1
		for(i=0;i<=maxlen;i++){
			if((sum[i]+sub2[i]-sub1[i])>=0) {
				sum[i]=sum[i]+sub2[i]-sub1[i];
			}
			else{
				sub2[i]+=10;
				sum[i]=(sum[i]+sub2[i]-sub1[i])%10;
				sum[i+1]=-1;
			}
		}
	}
	//sub1>ub2
	else{
		//sub1-sub2
		for(i=0;i<=maxlen;i++){
			if((sum[i]+sub1[i]-sub2[i])>=0) {
				sum[i]=sum[i]+sub1[i]-sub2[i];
			}
			else{
				sub1[i]+=10;
				sum[i]=(sum[i]+sub1[i]-sub2[i])%10;
				sum[i+1]=-1;
			}
		}
	}
	printf("Sub:");
	for(i=maxlen-1;i>=0;i--){
	if(sum[maxlen-1]==0) i--;
		printf("%d",sum[i]);
	}

	FILE *fp;
	fp=fopen("result.txt","a");
	fprintf(fp,"Sample input:\n-\n");
	fprintf(fp,"%s\n%s\nSampale output:\n",sub->num1,sub->num2);
	for(i=maxlen-1;i>=0;i--){
	if(sum[maxlen-1]==0) i--;
		fprintf(fp,"%d",sum[i]);
	}
	fprintf(fp,"\n");
	fclose(fp);


	printf("\n");
}
void mui(struct dataform* mui)
{
	char mui1[Max];
	char mui2[Max];
	int sum[Max*10];
	int textlen=0;
	int maxlen=0;
	int tmp=0;
	int i=0,j=0;

	memset(mui1,0, Max);
	memset(mui2,0, Max);
	memset(sum,0, Max*10);
	strcpy(mui1,mui->num1);
	strcpy(mui2,mui->num2);
	//reverse add1
	textlen=strlen(mui1);
	maxlen=strlen(mui1)+strlen(mui2)-1;

	for(i=0;i<textlen/2;i++){
		tmp=mui1[i];
		mui1[i]=mui1[textlen-1-i]-'0';
		mui1[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) mui1[(textlen/2)]-='0';

	//reverse mui2
	textlen=strlen(mui2);
	for(i=0;i<textlen/2;i++){
		tmp=mui2[i];
		mui2[i]=mui2[textlen-1-i]-'0';
		mui2[textlen-1-i]=tmp-'0';
	}
	if(textlen%2!=0) mui2[(textlen/2)]-='0';

	//mui1*mui2
	for(i=0;i<maxlen;i++){
		if(mui1[i]==0) continue;
		for(j=0;i+j<=maxlen;j++){
			sum[i+j]+=mui1[i]*mui2[j];
		}
	}
	//carry
	int carry=0;
	for(i=0;i<=maxlen;i++){
		sum[i]+=carry;
		carry=sum[i]/10;
		sum[i]=sum[i]%10;
	}
	//print
	printf("Mul:");
	for(i=maxlen;i>=0;i--){
		if(sum[maxlen]==0) i--;
		printf("%d",sum[i]);
	}

	FILE *fp;
	fp=fopen("result.txt","a");
	fprintf(fp,"Sample input\n*\n");
	fprintf(fp,"%s\n%s\nSample output:\n",mui->num1,mui->num2);

	for(i=maxlen;i>=0;i--){
		if(sum[maxlen]==0) i--;
		fprintf(fp,"%d",sum[i]);
	}
	fprintf(fp,"\n");
	fclose(fp);
	printf("\n");
}

void calculate(){

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("= Which operators do you want to choose?    =\n");
	printf("= (+)Addition                               =\n");
	printf("= (-)Subtraction                            =\n");
	printf("= (*)Multiplication                         =\n");
	printf("= (q)Quit                                   =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	struct dataform *value;
	char c=0;
while(1){	
		scanf("%c",&c);
		switch(c){
			case '+':
				value=input_way();
				if(value==0) return;
				add(value);
				break;

			case '-':
				value=input_way();
				if(value==0) return;
				sub(value);
				break;
			case '*':
				value=input_way();
				if(value==0) return;
				mui(value);
				break;

			case 'q':
				return;

//			default:
//				continue;
		}
	}
}

int main(){

	while(1){

		printf("What do you want to do?\n");
		printf("1)Read numbers from a file\n");
		printf("2)Show the input numbers\n");
		printf("3)Write numbers to a file\n");
		printf("4)Calculate the big numbers\n");
		printf("0)Exit\n");

		int c=0;
		scanf("%d",&c);
		switch(c){
			case 1:
				openFile();
				break;
			case 2:
				showFile();
				break;
			case 3:
				insert();
				break;
			case 4:
				calculate();
			case 0:
				return 0;
			default:
				continue;
		}
	}
	return 0;
}
