/*
 * nstring_test.c
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


int
main(void)
{
  libn_start();
  string_test();
  sep();
  string_test2();
  libn_finish();
  return EXIT_SUCCESS;
}
