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
  nstringset *stringset;

  libn_start();
  set = nset_new();
  stringset = nstringset_new();

  nset_free(set);
  nstringset_free(stringset);
  libn_finish();
  return EXIT_SUCCESS;
}
