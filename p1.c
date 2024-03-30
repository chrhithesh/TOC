#include <stdio.h>
#include <stdbool.h>
int transition(int state, char input) {
    if (state == 0 && input == 'a')
        return 1;
    else if (state == 1 && input != 'a')
        return 2;
    else if (state == 2 && input == 'a')
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

    if(currentState == 3)
    {
        return 1;
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", &input);

    if (simulateDFA(input)==1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
