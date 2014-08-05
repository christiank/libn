/*
 * nstringhash_test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <libn.h>

void
stringhash_test(void)
{
  nstringhash *person;

  person = nstringhash_new();
  nstringhash_set(person, "name", "Mildred Haversham");
  nstringhash_set(person, "occupation", "part-time detective");

  printf("%s\n", nstringhash_inspect(person));
  nstringhash_delete(person, "occupation");
  printf("%s\n", nstringhash_inspect(person));

  nstringhash_free(person);
}


int
main(void)
{
  libn_start();
  stringhash_test();
  libn_finish();
  return EXIT_SUCCESS;
}
