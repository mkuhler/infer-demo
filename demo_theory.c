#include <stdlib.h>

/* 
* HOW TO RUN TESTS:
* infer run -- gcc -c demo_theory.c
*/

/* 
* SECTION 1: SEPARATION LOGIC
* In this example, a pointer is being
* accessed before it is assigned in memory,
* and not properly freed after execution.
*
* The caller test_null_dereference contains
* examples of infer bugs and bugfixes, while
* the callee make_unsafe_ptr is annotated 
* with Infer separation logic triples.
*/
int* make_unsafe_ptr(int x) {
  // precondition: {true}
  int* ptr = NULL;
  // postcondition: {ptr -> null}
  
  /*
  * branch: x <= 0
  * precondition: {x <= 0 ∧ ptr -> null}
  * postcondition: {result -> null}
  */

  // branch: x > 0
  if (x > 0) {
    // precondition: {x > 0 ∧ ptr -> null}
    ptr = malloc(sizeof(int));
    // postcondition: {ptr -> ?} // here ? means allocated but uninitialized

    // precondition: {ptr -> ?}
    if (ptr != NULL) { *ptr = x; }
    // {ptr -> x ∨ ptr -> null} // ptr points to x if allocation succeeded, or null if failed
  } 

  // postcondition: {result -> x ∨ result -> null}
  return ptr;
}

void test_null_dereference() {
  int x = 42;
  int* ptr = make_unsafe_ptr(x);
  *ptr = x;

  /* 
  * FIX 1: NULL DEREFERENCE
  * since make_unsafe_ptr can return a null pointer,
  * we must check if n = NULL 
  */
  //if (ptr != NULL) { *ptr = x; }

  /* 
  * FIX 2: MEMORY LEAK
  * We dynamically allocate n with malloc,
  * but this memory is not freed after use.
  */
  //free(ptr);
}