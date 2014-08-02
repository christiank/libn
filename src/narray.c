/*
 * narray.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdarg.h>
#include <stdlib.h>
#include <mruby.h>
#include <mruby/array.h>
#include <mruby/string.h>
#include "libn/narray.h"
#include "libn/global.h"

narray *
narray_new(void)
{
  narray *array;

  array = malloc(sizeof(narray));
  array->_array = mrb_ary_new(__LIBN_R);

  return array;
}


void
narray_free(narray *array)
{
  free(array);
}


void
narray_push(narray *array, const void *item)
{
}


void
narray_push_many(narray *array, ...)
{
}


void *
narray_pop(narray *array)
{
}


void
narray_unshift(narray *array, const void *item)
{
}


void
narray_unshift_many(narray *array, ...)
{
}


void *
narray_shift(narray *array)
{
}


void
narray_insert(narray *array, const unsigned int index, const void *item)
{
}


void *
narray_get(const narray *array, const unsigned int index)
{
}


void
narray_delete(narray *array, const unsigned int index)
{
}


char *
narray_inspect(const narray *array)
{
  return mrb_str_to_cstr(__LIBN_R, mrb_inspect(__LIBN_R, array->_array));
}
