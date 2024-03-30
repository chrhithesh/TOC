#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 5

int main() {
    int num_states, num_symbols, num_final;
    int final_states[MAX_STATES];
    int transitions[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
    int present_state[MAX_STATES];
    int symbol[MAX_SYMBOLS];
    char input[20];

    printf("How many states in the NFA: ");
    scanf("%d", &num_states);

    printf("How many symbols in the input alphabet: ");
    scanf("%d", &num_symbols);

    printf("Enter the symbols in the input alphabet:\n");
    for (int i = 0; i < num_symbols; i++) {
        scanf("%d", &symbol[i]);
    }

    printf("How many final states: ");
    scanf("%d", &num_final);

    printf("Enter the final states:\n");
    for (int i = 0; i < num_final; i++) {
        scanf("%d", &final_states[i]);
    }

    // Initialize transitions to -1
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < MAX_SYMBOLS; j++) {
            for (int k = 0; k < MAX_STATES; k++) {
                transitions[i][j][k] = -1;
            }
        }
    }

    // Get transitions
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            printf("How many transitions from state %d for the input %d: ", i, symbol[j]);
            scanf("%d", &transitions[i][j][0]);
            printf("Enter the transition states:\n");
            for (int k = 0; k < transitions[i][j][0]; k++) {
                scanf("%d", &transitions[i][j][k + 1]);
            }
        }
    }

    printf("Enter the input string: ");
    scanf("%s", input);

    // Initialize present state
    present_state[0] = 0;
    int prev_trans = 1;

    // Process input string
    for (int i = 0; input[i] != '\0'; i++) {
        int inp = -1;
        for (int j = 0; j < num_symbols; j++) {
            if (input[i] - '0' == symbol[j]) {
                inp = j;
                break;
            }
        }

        if (inp == -1) {
            printf("Invalid input\n");
            return 1;
        }

        int new_trans = 0;
        int next_state[MAX_STATES];

        for (int j = 0; j < prev_trans; j++) {
            int p = present_state[j];
            for (int k = 1; k <= transitions[p][inp][0]; k++) {
                next_state[new_trans++] = transitions[p][inp][k];
            }
        }

        prev_trans = new_trans;
        for (int j = 0; j < new_trans; j++) {
            present_state[j] = next_state[j];
        }
    }

    // Check if any of the present states are final states
    int flag = 0;
    for (int i = 0; i < prev_trans; i++) {
        for (int j = 0; j < num_final; j++) {
            if (present_state[i] == final_states[j]) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }

    printf("Try with another input\n");

    return 0;
}
