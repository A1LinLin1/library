#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNode(Node** head, int data) {
    Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        Node* prev = NULL;
        while (curr != NULL && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            node->next = *head;
            *head = node;
        } else {
            node->next = prev->next;
            prev->next = node;
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* A = NULL;
    Node* B = NULL;
    Node* C = NULL;
    int n, m, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&A, data);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&B, data);
    }
    // Find common elements
    Node* currA = A;
    Node* currB = B;
    while (currA != NULL && currB != NULL) {
        if (currA->data < currB->data) {
            currA = currA->next;
        } else if (currB->data < currA->data) {
            currB = currB->next;
        } else {
            // Check if the element is already in C
            Node* currC = C;
            int found = 0;
            while (currC != NULL) {
                if (currC->data == currA->data) {
                    found = 1;
                    break;
                }
                currC = currC->next;
            }
            // Add the element to C if it's not already there
            if (!found) {
                insertNode(&C, currA->data);
            }
            currA = currA->next;
            currB = currB->next;
        }
    }
    // Print common elements
    printList(C);
    return 0;
}
