#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void remove_duplicates(struct Node* A, struct Node* B, struct Node* C) {
    struct Node* curr_A = A;
    struct Node* prev_A = NULL;

    while (curr_A != NULL) {
        struct Node* curr_B = B;
        struct Node* curr_C = C;
        int found = 0;

        while (curr_B != NULL) {
            if (curr_A->data == curr_B->data) {
                found = 1;
                break;
            }
            curr_B = curr_B->next;
        }

        if (!found) {
            while (curr_C != NULL) {
                if (curr_A->data == curr_C->data) {
                    found = 1;
                    break;
                }
                curr_C = curr_C->next;
            }
        }

        if (found) {
            if (prev_A == NULL) {
                A = curr_A->next;
                free(curr_A);
                curr_A = A;
            } else {
                prev_A->next = curr_A->next;
                free(curr_A);
                curr_A = prev_A->next;
            }
        } else {
            prev_A = curr_A;
            curr_A = curr_A->next;
        }
    }
}

void remove_blanks(struct Node* A) {
    struct Node* curr_A = A;
    struct Node* prev_A = NULL;

    while (curr_A != NULL) {
        if (curr_A->data == 0) {
            if (prev_A == NULL) {
                A = curr_A->next;
                free(curr_A);
                curr_A = A;
            } else {
                prev_A->next = curr_A->next;
                free(curr_A);
                curr_A = prev_A->next;
            }
        } else {
            prev_A = curr_A;
            curr_A = curr_A->next;
        }
    }
}

int main() {
    struct Node* A = (struct Node*)malloc(sizeof(struct Node));
    struct Node* B = (struct Node*)malloc(sizeof(struct Node));
    struct Node* C = (struct Node*)malloc(sizeof(struct Node));

    A->data = 1;
    A->next = (struct Node*)malloc(sizeof(struct Node));
    A->next->data = 2;
    A->next->next = (struct Node*)malloc(sizeof(struct Node));
    A->next->next->data = 3;
    A->next->next->next = NULL;

    B->data = 2;
    B->next = (struct Node*)malloc(sizeof(struct Node));
    B->next->data = 4;
    B->next->next = NULL;

    C->data = 3;
    C->next = (struct Node*)malloc(sizeof(struct Node));
    C->next->data = 5;
    C->next->next = NULL;

    remove_duplicates(A, B, C);
    remove_blanks(A);

    struct Node* curr_A = A;
    while (curr_A != NULL) {
        printf("%d ", curr_A->data);
        curr_A = curr_A->next;
    }
    return 0;
}
