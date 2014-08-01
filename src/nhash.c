/*
 * nhash.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdlib.h>
#include <mruby.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include "libn/nhash.h"
#include "libn/global.h"

nhash *
nhash_new(void)
{
}


void nhash_free(nhash *hash)
{
}


nstringhash *
nstringhash_new(void)
{
  nstringhash *hash;

  hash = malloc(sizeof(nstringhash));
  hash->_hash = mrb_hash_new(__LIBN_R);

  return hash;
}


void
nstringhash_free(nstringhash *hash)
{
  free(hash);
}


void
nstringhash_set(nstringhash *hash, const char *key, const char *value)
{
  mrb_hash_set(__LIBN_R, hash->_hash, mrb_str_new_cstr(__LIBN_R, key),
    mrb_str_new_cstr(__LIBN_R, value));
}


char *
nstringhash_get(nstringhash *hash, const char *key)
{
  return mrb_str_to_cstr(__LIBN_R,
    mrb_hash_get(__LIBN_R, hash->_hash, mrb_str_new_cstr(__LIBN_R, key)));
}


void
nstringhash_delete(nstringhash *hash, const char *key)
{
  mrb_hash_delete_key(__LIBN_R, hash->_hash,
    mrb_str_new_cstr(__LIBN_R, key));
}


char *
nstringhash_inspect(const nstringhash *hash)
{
  return mrb_str_to_cstr(__LIBN_R, mrb_inspect(__LIBN_R, hash->_hash));
}
