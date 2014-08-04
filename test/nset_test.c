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

  nstringset_add_cstr(stringset, "Charlotte");
  nstringset_add_cstr(stringset, "Shauna");
  nstringset_add_cstr(stringset, "Linton");

  if (nstringset_include_cstr(stringset, "Sonny"))
    printf("sonny is there\n");
  else
    printf("sonny is not there\n");

  if (nstringset_include_cstr(stringset, "Charlotte"))
    printf("charlotte is there\n");
  else
    printf("charlotte is not there\n");

  nset_free(set);
  nstringset_free(stringset);
  libn_finish();
  return EXIT_SUCCESS;
}
