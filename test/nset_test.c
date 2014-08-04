/*
 * nset_test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <libn.h>

int
main(void)
{
  nset *set;

  libn_start();
  set = nset_new();

  nset_free(set);
  libn_finish();
  return EXIT_SUCCESS;
}
