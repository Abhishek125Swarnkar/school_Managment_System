#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
// ********************* photo *******************************
void photo(){
int x,y,k;
int gd=DETECT,gm;
initgraph(&gd,&gm, "C:\\turboc3\\bgi");
setcolor(YELLOW);

for(x=60;x<=600;x++){
bar3d(50,70,x,70,1,1);
}

setcolor(CYAN);
for(y=70;y<=400;y++){
bar3d(50,70,600,y,1,1);
}
setcolor(BROWN);
for(k=1;k<=20;k++)
{
bar3d(50,70,600,400,k,1);
}
setcolor(0);
for(k=0;k<13;k++){
bar3d(50,390,590,390,k,1);
}
setcolor(1);
for(k=0;k<13;k++){
bar3d(50,380,590,380,k,1);
}
setcolor(2);
for(k=0;k<13;k++){
bar3d(50,370,590,370,k,1);
}
setcolor(3);
for(k=0;k<13;k++){
bar3d(50,360,590,360,k,1);
}
setcolor(4);
for(k=0;k<13;k++){
bar3d(50,350,590,350,k,1);
}
setcolor(5);
for(k=0;k<13;k++){
bar3d(50,340,590,340,k,1);
}
setcolor(6);
for(k=0;k<13;k++){
bar3d(50,330,590,330,k,1);
}

setcolor(7);
for(k=0;k<13;k++){
bar3d(50,320,590,320,k,1);
}
for(k=0;k<=30;k++){
setcolor(4);
bar3d(55,250,200,300,k,0);
setcolor(0);
bar3d(55,200,200,250,k,1);
}
setcolor(4);
rectangle(55,200,200,250);
settextstyle(10,0,2);
outtextxy(60,205,"School");
setcolor(8);
settextstyle(4,0,5);
outtextxy(90,85,"Welcome");
outtextxy(240,130,"to");
outtextxy(280,175,"Aapna");
outtextxy(420,219,"School");
setcolor(0);
bar3d(410,85,570,210,5,1);
settextstyle(10,0,2);
setcolor(3);
outtextxy(430,90,"Eduation");
setcolor(2);
outtextxy(460,125,"For");
setcolor(4);
outtextxy(500,160,"All...");
getch();
closegraph();
}
//#####################################################################

//********************** logo  ********************************
void logo(){
int i;
int gd=DETECT,gm;
initgraph(&gd,&gm, "C:\\turboc3\\bgi");
for(i=0;i<1000;i++){
cleardevice();
arc(300,200,i,-80-i,60);
setcolor(CYAN);
arc(300,200,-i,80-i,50);
setcolor(RED);
arc(300,200,i,80+i,40);
setcolor(GREEN);
arc(300,200,-i,80-i,30);
setcolor(BLUE);
arc(300,200,i,80+i,20);
setcolor(DARKGRAY);
arc(300,200,-i,100-i,10);
setcolor(WHITE);
outtextxy(275,270,"Loading...");
}
cleardevice();
outtextxy(290,200,"lets go");
getch();
cleardevice();
closegraph();
}
 //************************** end *******************************


typedef struct teach{//structure for teachers
	int  id;
    char name[50];
    char dob[20];
    char adress[100];
    char email_id[50];
    char father_name[50];
    char qualificaion[300];
    char exprience[6];
}teacher;
teacher t;
// t-->teachers
typedef struct stud{// structure for students
    int  id;
    char name[50];
    char dob[30];
    char adress[100];
    char father_name[50];
    char phonef[15]; //father phone number
    char mother_name[50];
    char phone_m[15];

}student;
student s;

// s-->student

//  1. insert the student data  *************************

void insert_s(){
FILE *fp;
fp=fopen("s.txt","ab+");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
printf("\nRoll No.         : ");
scanf("%d",&s.id);
fflush(stdin);//it can solve buffer
printf("\nName.            : ");//name of student
scanf("%[^\n]%*c",s.name);
printf("\nD.O.B(dd-mm-yy)  : ");//date of birth of student
scanf("%[^\n]%*c",s.dob);
printf("\nAdress           : ");//adress of student
scanf("%[^\n]%*c",s.adress);
printf("\nFather Name      : ");//father name
scanf("%[^\n]%*c",s.father_name);
printf("\nFather Phone No  : ");//father phone number
scanf("%[^\n]%*c",s.phonef);
printf("\nMother Name      : ");//mother name
scanf("%[^\n]%*c",s.mother_name);
printf("\nMother Phone No. : ");//mother phone number
scanf("%[^\n]%*c",s.phone_m);
fwrite(&s,sizeof(s),1,fp);
fclose(fp);
printf(" **** Data uploaded successfully");
getch();
}
//*************************************************************************

//  2. insert the teacher data  **********************
void insert_t(){

FILE *fp1;
fp1=fopen("t.txt","ab+");
if(fp1==NULL){
	printf(" file is not exit ");
	return;
    }
printf("\nId No.           : ");//teacher id number
scanf("%d",&t.id);
fflush(stdin);//it can solve the buffer
printf("\nName.            : ");//teacher name
scanf("%[^\n]%*c",t.name);
printf("\nD.O.B(dd-mm-yy)  : ");//date of birth of teacher
scanf("%[^\n]%*c",t.dob);
printf("\nAdress           : ");//teacher adress
scanf("%[^\n]%*c",t.adress);
printf("\nEmail Id         : ");//Email id
scanf("%[^\n]%*c",t.email_id);
printf("\nFather Name      : ");//father name of teacher
scanf("%[^\n]%*c",t.father_name);
printf("\nQualiffication   : ");// qualifications
scanf("%[^\n]%*c",t.qualificaion);
printf("\nExprience        : ");//exprience
scanf("%[^\n]%*c",t.exprience);

fwrite(&t,sizeof(t),1,fp1);
fclose(fp1);
printf(" **** Data uploaded successfully");
getch();

 }
//*************************************************************************

//  3. display the data of whole students *********************************
void display_all_student_data(){

FILE *fp;
fp=fopen("s.txt","rb+");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
printf("**************\t\t STUDENT DATA\t\t*************\n\n");
while(fread(&s,sizeof(s),1,fp)!=0)
{printf("\nRoll No.         : ");
printf("%d",s.id);
printf("\nName.            : ");//name of student
puts(s.name);
printf("\nD.O.B(dd-mm-yy)  : ");//date of birth of student
puts(s.dob);
printf("\nAdress           : ");//adress of student
puts(s.adress);
printf("\nFather Name      : ");//father name
puts(s.father_name);
printf("\nFather Phone No  : ");//father phone number
puts(s.phonef);
printf("\nMother Name      : ");//mother name number
puts(s.mother_name);
printf("\nMother Phone No. : ");//mother phone number
puts(s.phone_m);
printf("\n******************************************\n");
}
fclose(fp);
getch();
    }
 //************************************************************************

 // 4. DISPLAY TEACHER ALL DATA *****************************
void display_all_teacher_data(){

 FILE *fp1;
fp1=fopen("t.txt","rb+");
if(fp1==NULL){
	printf(" file is not exit ");
	return;
    }
printf("**************\t\t TEACHER DATA\t\t*************\n\n");
while(fread(&t,sizeof(t),1,fp1)!=0){
printf("\nId No.           : ");//teacher id number
printf("%d",t.id);
printf("\nName.            : ");//teacher name
puts(t.name);
printf("\nD.O.B(dd-mm-yy)  : ");//date of birth of teacher
puts(t.dob);
printf("\nAdress           : ");//teacher adress
puts(t.adress);
printf("\nEmail Id         : ");//Email id
puts(t.email_id);
printf("\nFather Name      : ");//father name of teacher
puts(t.father_name);
printf("\nQualiffication   : ");// qualifications
puts(t.qualificaion);
printf("\nExprience        : ");//exprience
puts(t.exprience);
printf("\n******************************************\n");
}
fclose(fp1);
getch();
}
//***********************************************************

// 5. Detete student data **********************************
void delete_student(){
int i;

FILE *fp,*ft;
fp=fopen("s.txt","rb");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
printf("\nRoll No\t : ");
scanf("%d",&i);
ft=fopen("s1.txt","ab+");
while(fread(&s,sizeof(s),1,fp)==1){
    if(i!=s.id){
	printf("\nDelete student record successfully\n");
	fwrite(&s,sizeof(s),1,ft);
	}

    }
fclose(fp);
fclose(ft);
remove("s.txt");
rename("s1.txt","s.txt");
printf("\n student data updated \n");
getch();
}
//***************************************************************

// 6. Delete teacher data *************************************
void delete_teacher(){
int i;
FILE *fp1,*ft1;
fp1=fopen("t.txt","rb");
if(fp1==NULL){
	printf(" file is not exit ");
	return;
    }
printf("\nId No\t : ");
scanf("%d",&i);
ft1=fopen("t1.txt","ab+");
while(fread(&s,sizeof(t),1,fp1)==1){
if(i!=t.id){
	printf("\nDelete teacher record successfully\n");
	fwrite(&t,sizeof(t),1,ft1);
	}
    }
fclose(fp1);
fclose(ft1);
remove("t.txt");
rename("t1.txt","t.txt");
printf("\n teacher data updated \n");
getch();
}
//********************************************************************************

// ************************  accounttant id ***************************
void account(){
char school_id[10]="school";//school account passward
char login[10];
int i;

printf("\n\n\n\t\t\tEnter Your Login Id  :  ");
fflush(stdin);
scanf("%[^\n]%*c",login);
if(strcmp(school_id,login)==0){
	printf("\n\n\t\t\tlogin succesfully");
	getch();
	system("cls");
	logo();
	getch();
	system("cls");
	do{
	printf("\n**********\t Follow instruction \t*********\n");
	printf("\n\t\t 1. Insert student data");
	printf("\n\t\t 2. Insert teacher data");
	printf("\n\t\t 3. Display all student data");
	printf("\n\t\t 4. Display all teacher data");
	printf("\n\t\t 5. Delete the student data");
	printf("\n\t\t 6. Delete the teacher data");
	printf("\n\t\t 7. Exit");
	printf("\n choose one of them  :  ");
    scanf("%d",&i);
	switch(i){
		case 1: system("cls");
			insert_s();//insert the student data
			system("cls");
			break;
		case 2: system("cls");
			insert_t();// insert the teacher data
			system("cls");
			break;
		case 3: system("cls");
			display_all_student_data();// it display the all student data
			system("cls");
			break;
		case 4: system("cls");
			display_all_teacher_data();// it display the all teacher data
			system("cls");
			break;
		case 5: system("cls");
			delete_student();// it can delete the student data;
			system("cls");
			break;
		case 6: system("cls");
			delete_teacher();// it can delete the teacher data;
			system("cls");
			break;
		case 7: system("cls");
			break;
	}

}while(i!=7);
}
else{
	printf("\n\n\t\t\twrong passward\n\n");
}
printf("**********************  exit  from accountnent  *******************");
getch();
}
//*************************************************************************************************



// A. display teacher data **************************
void display_teach(){
int i,flag=0;
char passward[10];
FILE *fp1;
fp1=fopen("t.txt","rb");
if(fp1==NULL){
	printf(" file is not exit ");
	return;
    }
printf("\nId No\t : ");
scanf("%d",&i);
while(fread(&s,sizeof(t),1,fp1)!=0)
{
   if(i==t.id){
     flag=1;
     printf("\npassward :");
     fflush(stdin);
     gets(passward);
     system("cls");
     printf("**************\t\t TEACHER DATA\t\t*************\n\n");
     if(strcmp(passward,t.dob)==0){
       printf("\nId No.           : ");//teacher id number
       printf("%d",t.id);
       printf("\nName.            : ");//teacher name
       puts(t.name);
       printf("\nD.O.B(dd-mm-yy)  : ");//date of birth of teacher
       puts(t.dob);
       printf("\nAdress           : ");//teacher adress
       puts(t.adress);
       printf("\nEmail Id         : ");//Email id
       puts(t.email_id);
       printf("\nFather Name      : ");//father name of teacher
       puts(t.father_name);
       printf("\nQualiffication   : ");// qualifications
       puts(t.qualificaion);
       printf("\nExprience        : ");//exprience
      puts(t.exprience);}
      else{
	printf("\nwrong passward\n");
	getch();
	    }
      }
}
fclose(fp1);
if(flag==0){
    printf("\nRoll No. not exits");
    }
printf("\n******************************************\n");
getch();
}

// B. modify the teacher data*************************
void d_t(){
int i;
unsigned flag=0;
FILE *fp1,*ft1;
fp1=fopen("t.txt","rb");
if(fp1==NULL){
	printf(" file is not exit ");
	return;
    }
printf("\nId No\t : ");
scanf("%d",&i);
ft1=fopen("t1.txt","ab+");
while(fread(&s,sizeof(t),1,fp1)==1){
if(i!=t.id){
      //  printf("\nDelete teacher record successfully\n");
	fwrite(&t,sizeof(t),1,ft1);
	break;
	}
    else{
	flag=1;
	}
    }
fclose(fp1);
fclose(ft1);
remove("t.txt");
rename("t1.txt","t.txt");
}
// B. modify the teacher data*************************
void modify_teach(){
d_t();
system("cls");
printf("\t****** modify ourself **************\t\n");
insert_t()   ;
getch();
    }
//*********************************************************************

// C. teacher give the marks to the student
typedef struct re{
    int id;
    char h[5];//hindi
    char e[5];//english
    char sci[5];//science
    char sst[5];
    char maths[5];
    }marks;
marks r;
void give_result(){
    FILE *res;
res=fopen("rresult_of_stu_dec.txt","ab+");
if(res==NULL){
	printf(" file is not exit ");
	return;
}
while(fread(&r,sizeof(r),1,res)!=0){
//it can solve buffer
printf("\n******* Student Marks *******\n");
printf("\n Roll No         :  ");
printf("%d",r.id);
printf("\nHindi            : ");
puts(r.h);
printf("\nEnglish          : ");
puts(r.e);
printf("\nScience          : ");
puts(r.sci);
printf("\nS.s.t            : ");
puts(r.sst);
printf("\nMaths            : ");
puts(r.maths);
}
printf("\n************************\n");
printf("\nRoll No.         : ");
scanf("%d",&r.id);
fflush(stdin);//it can solve buffer
printf("\nHindi            : ");
scanf("%[^\n]%*c",r.h);
printf("\nEnglish            : ");
scanf("%[^\n]%*c",r.e);
printf("\nScience            : ");
scanf("%[^\n]%*c",r.sci);
printf("\nS.s.t            : ");
scanf("%[^\n]%*c",r.sst);
printf("\nMaths            : ");
scanf("%[^\n]%*c",r.maths);
fwrite(&r,sizeof(r),1,res);
fclose(res);
printf(" **** marks uploaded successfully");
getch();
    }
//*************************************************

//**************** Teacher account******************************************
void teac_account(){
  char teacher_id[20]="teacher";
  char lLogin[20];
  int i;
  printf("\n\n\n\t\t\tEnter Your Login Id  :  ");
  fflush(stdin);
  scanf("%[^\n]%*c",lLogin);
if(strcmp(teacher_id,lLogin)==0){
    printf("\n\n\t\t\tlogin succesfully");
	getch();
	system("cls");
	logo();
	getch();
	system("cls");
	do{
    printf("\n**********\t Follow instruction \t*********\n");
	printf("\n\t\t 1. Display Teacher Data");
	printf("\n\t\t 2. Modify Teacher Data");
	printf("\n\t\t 3. Give Marks To The Student");
	printf("\n\t\t 4. Exit  ");
	printf("\n choose one of them  :  ");
	scanf("%d",&i);
	switch(i){
	case 1: system("cls");
		display_teach();//display paticular data
		system("cls");
		break;
	case 2: system("cls");
		modify_teach();//modify teacher data
		system("cls");
		break;
	case 3: system("cls");
		give_result();//give marks to the student
		system("cls");
		break;
	case 4: system("cls");
			break;           //exit
	}
}while(i!=4);
}
else{
	printf("\n\n\t\t\twrong passward\n\n");
    }
printf("*******************  exit  from teacher account ****************");
getch();
    }
//*****************************************************************************************************************

// A. display particular student data ******************
void display_stud(){
int i,flag=0;
char passward[10];
FILE *fp;
fp=fopen("s.txt","rb");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
printf("\nRoll No\t : ");
scanf("%d",&i);
while(fread(&s,sizeof(s),1,fp)!=0)
{
    if(i==s.id){
	flag=1;
	printf("\npassward :");
	fflush(stdin);
	gets(passward);
	system("cls");
	printf("**************\t\t STUDENT DATA\t\t*************\n\n");
	flag=1;
if(strcmp(passward,s.dob)==0){

  int gd=DETECT,gm;

   int i;
initgraph(&gd,&gm, "C:\\turboc3\\bgi");
rectangle(30,50,600,360);
for(i=50;i<360;i+=40){
line(30,i,600,i);
 }
line(170,90,170,360);
setcolor(6);
outtextxy(250,70,"Student Data");
setcolor(4);
outtextxy(40,110," Name");
outtextxy(40,150," Dob");
outtextxy(40,190," Adress");
outtextxy(40,230," Father Name");
outtextxy(40,270,"Father Phone No");
outtextxy(40,310,"Mother Name");
outtextxy(40,350,"Mother Phone No");
setcolor(3);
outtextxy(180,110,s.name);
outtextxy(180,150,s.dob);
outtextxy(180,190,s.adress);
outtextxy(180,230,s.father_name);
outtextxy(180,270,s.phonef);
outtextxy(180,310,s.mother_name);
outtextxy(180,350,s.phone_m);
getch();
cleardevice();
closegraph();
 }
 else{
printf("\nwrong passward\n");
getch();
}
}}
fclose(fp);
if(flag==0){
    printf("\nRoll No. not exits");
    getch();
    }
}
//************************************************************

// B. modify student data  ************************

void d_s(){
int i;
unsigned flag=0;
FILE *fp,*ft;
fp=fopen("s.txt","rb");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
printf("\nRoll No\t : ");
scanf("%d",&i);
ft=fopen("s1.txt","ab+");
while(fread(&s,sizeof(s),1,fp)==1){
    if(i!=s.id){
	//printf("\nDelete student record successfully\n");
	fwrite(&s,sizeof(s),1,ft);
	break;
	}
    else{
	flag=1;
	}
    }
fclose(fp);
fclose(ft);
remove("s.txt");
rename("s1.txt","s.txt");
}
// B. modify student data  ************************
void modify_student(){
d_s();
system("cls");
printf("modify ourself");
insert_s();
getch();
}
//*************************************************************

// C.  Display Result ****************************************
void display_result(){
FILE *fp,*res;
int i;
int gd =DETECT,gm;
printf("\nRoll No.         : ");
scanf("%d",&i);
system("cls");
fp=fopen("s.txt","rb");
if(fp==NULL){
	printf(" file is not exit ");
	return;
}
initgraph(&gd,&gm, "C:\\turboc3\\bgi"  );
cleardevice();
while(fread(&s,sizeof(s),1,fp)!=0){//school name of student
  if(i==s.id){
cleardevice();
setcolor(RED);
outtextxy(280,155,"RESULT");
setcolor(CYAN);
outtextxy(35,125,"Adress : ");
outtextxy(97,125,s.adress);
outtextxy(35,70,"Name : ");
outtextxy(85,70,s.name);
outtextxy(305,70,"Father Name : ");
outtextxy(410,70,s.father_name);
outtextxy(305,98,"Mother Name : ");
outtextxy(410,98,s.mother_name);
outtextxy(35,98,"Dob : ");
outtextxy(85,98,s.dob);
break;
    }}
  res=fopen("rresult_of_stu_dec.txt","rb");
  if(res==NULL){
	printf(" file is not exit ");
	return;
}

while(fread(&r,sizeof(r),1,res)!=0){//school marks
if(i==r.id)
{//it can solve buffer
outtextxy(55,210,r.h);
outtextxy(144+25,210,r.e);
outtextxy(258+25,210,r.maths);
outtextxy(486+25,210,r.sci);
outtextxy(372+25,210,r.sst);
break;
}
}
fclose(fp);
fclose(res);
outtextxy(55,180,"Hindi ");
outtextxy(144+25,180,"English");
outtextxy(258+25,180,"Maths");
outtextxy(372+25,180,"S.s.t");
outtextxy(486+25,180,"Science");

rectangle(30,50,600,400);
line(300,50,300,80);
line(30,80,600,80);
line(300,80,300,110);
line(30,110,600,110);
line(30,140,600,140);
line(30,170,600,170);
line(30,200,600,200);
line(30,230,600,230);
line(144,170,144,200);//subject line
line(258,170,258,200);
line(372,170,372,200);
line(486,170,486,200);

line(144,200,144,230);//marks line
line(258,200,258,230);
line(372,200,372,230);
line(486,200,486,230);
setcolor(WHITE);
getch();
cleardevice() ;
closegraph();
    }
 //***********************************************************************

// *************  student account ***********
void stud_account(){
    char student_id[20]="student";//student passward
    char  Login[20];
    int i;
    printf("\n\n\n\t\t\tEnter Your Login Id  :  ");
    fflush(stdin);
    scanf("%[^\n]%*c",Login);
if(strcmp(student_id,Login)==0){
    printf("\n\n\t\t\tlogin succesfully");
	getch();
	system("cls");
	logo();
	getch();
	system("cls");
	do{
    printf("\n**********\t Follow instruction \t*********\n");
	printf("\n\t\t 1. Display Student Data");
	printf("\n\t\t 2. Modify Student Data");
	printf("\n\t\t 3. Display Result");
	printf("\n\t\t 4. Exit  ");
	printf("\n choose one of them  :  ");
	scanf("%d",&i);
	switch(i){
	case 1: system("cls");
		display_stud();//display paticular data
		system("cls");
		break;
	case 2: system("cls");
		modify_student();//modify student data
		system("cls");
		break;
	case 3: system("cls");
		display_result();//display result
		system("cls");
		break;
	case 4: system("cls");
			break;           //exit
	}
}while(i!=4);
}
else{
	printf("\n\n\t\t\twrong passward\n\n");
    }
printf("*******************  exit  from student account ****************");
getch();
}
//************************************************************************************

// ************************* Main function  *********
int main(){
int i;
photo();
logo();

do{
	printf("\n**********\t Follow instruction \t*********\n");
	printf("\n\t\t1. Accountant ");
	printf("\n\t\t2. Teacher ");
	printf("\n\t\t3. Student");
	printf("\n\t\t4. Exit");
	printf("\n choose one of them  :  ");
	scanf("%d",&i);
	switch(i){
		case 1: system("cls");
			account();      // school account
			system("cls");
			break;
		case 2: system("cls");
			teac_account();  //teacher account
			system("cls");
			break;
		case 3: system("cls");
			stud_account();  //student account
			system("cls");
			break;
		case 4: system("cls");
			break;           //exit
	}
}while(i!=4);
return 0;
}
