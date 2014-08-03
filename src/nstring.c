/*
 * nstring.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdlib.h>
#include <mruby.h>
#include <mruby/string.h>
#include "libn/nstring.h"
#include "libn/global.h"
#include "libn/narray.h"

nstring *
nstring_new(const char *str)
{
  nstring *string;

  string = malloc(sizeof(nstring));
  string->_string = mrb_str_new_cstr(__LIBN_R, str);

  return string;
}


void
nstring_free(nstring *str)
{
  free(str);
}


/*
 * XXX This modifies and returns str1, is that what we intend?
 */
nstring *
nstring_cat(nstring *str1, nstring *str2)
{
  mrb_str_append(__LIBN_R, str1->_string, str2->_string);
  return str1;
}


/*
 * XXX This modifies and returns str1, is that what we intend?
 */
nstring *
nstring_cat_cstr(nstring *str1, const char *str2)
{
  mrb_str_append(__LIBN_R, str1->_string, mrb_str_new_cstr(__LIBN_R, str2));
  return str1;
}


char *
nstring_cstr(const nstring *str)
{
  return mrb_str_to_cstr(__LIBN_R, str->_string);
}


char *
nstring_inspect(const nstring *str)
{
  return mrb_str_to_cstr(__LIBN_R, mrb_inspect(__LIBN_R, str->_string));
}


int
nstring_cmp(const nstring *str1, const nstring *str2)
{
  return mrb_str_cmp(__LIBN_R, str1->_string, str2->_string);
}


#if 0
narray *
nstring_split(const nstring *str, const char *splitter)
{
}
#endif
