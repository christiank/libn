/*
 * hello.c
 * libn example
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
string_test(void)
{
  nstring *firstname;
  nstring *lastname;

  firstname = nstring_new("Shauna");
  lastname = nstring_new("Wickle");

  printf("first: %s\n", nstring_cstr(firstname));
  printf("last: %s\n", nstring_cstr(lastname));

  nstring_free(firstname);
  nstring_free(lastname);
}


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


void
array_test(void)
{
  narray *array;

  array = narray_new();
  printf("%s\n", narray_inspect(array));

  narray_free(array);
}


int
main(void)
{
  libn_start();

  string_test(); sep();
  stringhash_test(); sep();
  array_test();

  libn_finish();
  return EXIT_SUCCESS;
}
