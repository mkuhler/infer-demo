#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* make_two_nodes(int a, int b) {
    Node* n1 = malloc(sizeof(Node));
    Node* n2 = malloc(sizeof(Node));

    if (n1 == NULL || n2 == NULL) {
        return NULL;
    }

    n1->val = a;
    n1->next = n2;

    n2->val = b;
    n2->next = NULL;

    return n1;
}

void free_first_only(Node* head) {
    if (head != NULL) {
        free(head);
    }
}

void test_leak() {
    Node* list = make_two_nodes(10, 20);
    free_first_only(list);
}

