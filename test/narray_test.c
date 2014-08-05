/*
 * narray_test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <libn.h>

void
sep(void)
{
  printf("---\n");
}


void
array_test(void)
{
  narray *array;

  array = narray_new();
  narray_insert(array, 2, "blahdeblah");
  narray_insert(array, 0, "--hahah");
  printf("%s\n", narray_inspect(array));
  printf("0 => %s\n", narray_get(array, 0));

  narray_free(array);
}


void
array_test2(void)
{
  narray *array;

  array = narray_new();
  narray_push_many(array,
    "some data", "some more data", "even moar dataaa", NULL);
  printf("%s\n", narray_inspect(array));
  
  narray_free(array);
}


int
main(void)
{
  libn_start();
  array_test();
  sep();
  array_test2();
  libn_finish();
  return EXIT_SUCCESS;
}
