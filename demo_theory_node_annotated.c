#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* make_two_nodes(int a, int b) {
    Node* n1 = malloc(sizeof(Node));
    Node* n2 = malloc(sizeof(Node));

    // Symbolic Heap
        /*
        Case A: n1 -> {val = ?, next = ?} * n2 -> {val = ?, next = ?}
        Case B: n1 -> NULL and n2 -> {val = ?, next = ?}
        Case C: n1 -> {val = ?, next = ?} and n2 -> NULL
        Case D: n1 -> NULL and n2 -> NULL (empty heap case)
        */

    if (n1 == NULL || n2 == NULL) {
        // For a safe exit, we need to make sure all allocated memory is freed 
        // or given to the caller.

        // In Case B, n2 is allocated.
        // But we don't return any memory to the caller.
        // Infer will deduce that n2 is an unfreed, 
        // inaccessible node that will cause a memory leak.

        return NULL;
    }

    n1->val = a;
    n1->next = n2;

    n2->val = b;
    n2->next = NULL;

    return n1;

    // Infer concludes that this is a safe exit.
    // Current Heap State (postcondition): Previous Heap State (empty in this case) 
    // * n1 -> {val = a, next = n2} 
    // * n2 -> {val = b, next = NULL} 
    // Required Heap State (precondition): empty
}

void free_first_only(Node* head) {
    if (head != NULL) {
        free(head);
    }

    // Infer will consider the case when head == NULL v/s non-NULL
    // If head == NULL, no precondition or postcondition.
    // If head is non-NULL, precondition head -> {val = ?, next = ?}, 
    // postcondition, head is freed the rest remains untouched.
}

void test_leak() {
    
    // When making a function call, Infer looks back at the heap 
    // preconditions and posconditions it summarized for each function.

    // Current Heap: empty

    Node* list = make_two_nodes(10, 20);

    // Current Heap: list -> {val = 10, next = n2} * n2 -> {val = 20, next = NULL}
    // Also possible, Current Heap: empty, since make_two_nodes can return NULL.

    free_first_only(list);

    // Current Heap: n2 -> {val = 20, next = NULL}
    // Triggers another memory leak.
}

