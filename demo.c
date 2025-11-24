#include <stdlib.h>

/* HOW TO RUN TESTS:
   infer run -- gcc -c demo.c
*/

void test_null_dereference() {
  /*
  TEST 1: NULL DEREFERENCE
  In this example, a pointer is being
  accessed before it is assigned in memory.
  */
  // int* ptr = NULL;
  // *ptr = 42;

  /*
  TEST 1: FIX
  To resolve this error, we simply insert
  a null pointer check. Infer will now report
  no issues found!
  */
  // int* ptr_fix = NULL;
  // if (ptr_fix != NULL) {
  //   *ptr_fix = 42;
  // }
}