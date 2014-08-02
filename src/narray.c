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
  mrb_ary_push(__LIBN_R, array->_array,
    mrb_cptr_value(__LIBN_R, (void*)item));
}


void
narray_push_many(narray *array, ...)
{
  va_list ap;
  void *arg;

  va_start(ap, array);

  while ((arg = va_arg(ap, void*)) != NULL)
    narray_push(array, arg);

  va_end(ap);
}


void *
narray_pop(narray *array)
{
  return mrb_ary_pop(__LIBN_R, array->_array).value.p;
}


void
narray_unshift(narray *array, const void *item)
{
  mrb_ary_unshift(__LIBN_R, array->_array,
    mrb_cptr_value(__LIBN_R, (void*)item));
}


void
narray_unshift_many(narray *array, ...)
{
  va_list ap;
  void *arg;

  va_start(ap, array);

  while ((arg = va_arg(ap, void*)) != NULL)
    narray_unshift(array, arg);

  va_end(ap);
}


void *
narray_shift(narray *array)
{
  return mrb_ary_shift(__LIBN_R, array->_array).value.p;
}


void
narray_insert(narray *array, const unsigned int index, const void *item)
{
  mrb_ary_set(__LIBN_R, array->_array, index,
    mrb_cptr_value(__LIBN_R, (void*)item));
}


void *
narray_get(const narray *array, const unsigned int index)
{
  return mrb_ary_ref(__LIBN_R, array->_array, index).value.p;
}


/*
 * XXX TODO
 */
void
narray_delete(narray *array, const unsigned int index)
{
}


char *
narray_inspect(const narray *array)
{
  return mrb_str_to_cstr(__LIBN_R, mrb_inspect(__LIBN_R, array->_array));
}
