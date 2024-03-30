#include<stdio.h>
#include<string.h>
void main()
{
char s[100];
int i,flag,flag1,a,b;
int l,count1,count2;
printf("enter a string to check:");
scanf("%s",s);
l=strlen(s);
flag=1;
for(i=0;i<l;i++)
{
if(s[i]!='0' && s[i]!='1')
{
 flag=0;
}
}
if(flag!=1)
printf("string is Not Valid\n");
if(flag==1)
{
i=0;count1=0,count2=0;
while(s[i]=='0') // Count the no of 0s in the front
{
count1++;
i++;
}
while(s[i]=='1')
{
count2++;
i++;
}
if(i!=l)
{
printf("The string does not satisfy the condition 0n1n\n");
printf("String Not Accepted\n");
}
else
{
if(count1==count2)
{
printf("The string satisfies the condition 0n1n\n");
printf("String Accepted\n");

}

}
}
}
