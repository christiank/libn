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
string_test2(void)
{
  nstring *str;

  str = nstring_new("");
  printf("%s\n", nstring_inspect(str));
  nstring_cat_cstr(str, "abc");
  printf("%s\n", nstring_inspect(str));
  nstring_cat_cstr(str, "def");
  printf("%s\n", nstring_inspect(str));

  nstring_free(str);
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

  string_test(); sep();
  string_test2(); sep();
  stringhash_test(); sep();
  array_test(); sep();
  array_test2();

  libn_finish();
  return EXIT_SUCCESS;
}
