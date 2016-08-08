#include<stdio.h>
#include<conio.h>

void main()
{
FILE *f,*f2;
char input[50];
int ch,length,k,i,value[50];
clrscr();
printf("Enter key: ");
scanf("%d",&k);
printf("Enter choice ");
printf("1.Encrpt\n 2.Decrpyt\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
f=fopen("plain.txt","r");
if(f==NULL)
  printf("File not present");

while(fgets(input,50,f)!=NULL)
//  printf("%s",input);

length=strlen(input);

for(i=0;i<length;i++)
{
  value[i]=input[i]+k;
  if(value[i]>90 || value[i]<65)
    value[i]=65+value[i]-90;
}
f2=fopen("cipher.txt","w");
for(i=0;i<length;i++)
  fprintf(f2,"%c",value[i]);

fclose(f);
fclose(f2);
break;

case 2:
f=fopen("cipher.txt","r");
if(f==NULL)
  printf("File not present");

while(fgets(input,50,f)!=NULL)
  printf("%s",input);

length=strlen(input);

for(i=0;i<length;i++)
{
  value[i]=input[i]-k;
  if(value[i]>90 || value[i]<65)
    value[i]=90+value[i]-65;
}
f2=fopen("plain2.txt","w");
for(i=0;i<length;i++)
  fprintf(f2,"%c",value[i]);

fclose(f);
fclose(f2);
break;

}
getch();
}