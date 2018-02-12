/*
 * nset.c
 * Charlotte Koch <cfkoch@edgebsd.org>
 */

#include <stdbool.h>
#include <stdlib.h>
#include <mruby.h>
#include <mruby/hash.h>
#include <mruby/value.h>
#include "libn/global.h"
#include "libn/nstring.h"
#include "libn/nset.h"

nset *
nset_new(void)
{
  nset *set;
  
  set = malloc(sizeof(nset));
  set->_set = mrb_hash_new(__LIBN_R);

  return set;
}


void
nset_free(nset *set)
{
  free(set);
}


nstringset *
nstringset_new(void)
{
  nstringset *set;

  set = malloc(sizeof(nstringset));
  set->_set = mrb_hash_new(__LIBN_R);

  return set;
}


void nstringset_free(nstringset *set)
{
  free(set);
}


void
nstringset_add(nstringset *set, const nstring *str)
{
  mrb_hash_set(__LIBN_R, set->_set, str->_string, mrb_true_value());
}


void
nstringset_add_cstr(nstringset *set, const char *str)
{
  mrb_hash_set(__LIBN_R, set->_set, mrb_str_new_cstr(__LIBN_R, str),
    mrb_true_value());
}


bool
nstringset_include(const nstringset *set, const nstring *str)
{
  mrb_value val;

  val = mrb_hash_fetch(__LIBN_R, set->_set, str->_string, mrb_nil_value());

  return mrb_nil_p(val) ? false : true;
}


bool
nstringset_include_cstr(const nstringset *set, const char *str)
{
  mrb_value val;

  val = mrb_hash_fetch(__LIBN_R, set->_set, mrb_str_new_cstr(__LIBN_R, str),
    mrb_nil_value());

  return mrb_nil_p(val) ? false : true;
}
