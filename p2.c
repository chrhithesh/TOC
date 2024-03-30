#include <stdio.h>
#include <stdbool.h>
int transition(int state, char input) {
    if (state == 0 && input == '0')
        return 1;
    else if (state == 1 && input != '0')
        return 2;
    else if (state == 2 && input == '1')
        return 3;
    else
        return 2;
}
bool simulateDFA(char *input) {
    int currentState = 0;
    int i = 0;
    while (input[i] != '\0') {
        currentState = transition(currentState, input[i]);
        i++;
    }
    return currentState == 3;
}

int main() {
    char input[100];
    int l,i;
    printf("Enter a string: ");
    scanf("%s", input);
    l=strlen(input);
int flag=1;
for(i=0;i<l;i++)
{
if(input[i]!='0' && input[i]!='1')
{
 flag=0;
}
}
if(flag!=1)
printf("string is Not Valid\n");
if(flag==1)
{
    if (simulateDFA(input)==1)
        printf("Accepted\n");
    else
        printf("Rejected\n");
}
    return 0;
}
