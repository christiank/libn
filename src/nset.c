/*
 * nset.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdlib.h>
#include <mruby.h>
#include <mruby/hash.h>
#include "libn/global.h"
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
