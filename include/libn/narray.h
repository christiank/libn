/*
 * narray.h
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#ifndef NARRAY_H
#define NARRAY_H

#include <stdarg.h>
#include <mruby.h>

struct narray {
  mrb_value _array;
};
typedef struct narray narray;

narray *narray_new(void);
void narray_free(narray *array);
void narray_push(narray *array, ...);
void narray_pop(narray *array, ...);
void narray_shift(narray *array);
void narray_unshift(narray *array);
void narray_set(const narray *array, const unsigned int index, ...);
void narray_get(const narray *array, const unsigned int index);
void narray_delete(narray *array, const unsigned int index);
char *narray_inspect(const narray *array);

#endif /* NARRAY_H */
