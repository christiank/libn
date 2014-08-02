/*
 * nhash.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdlib.h>
#include <mruby.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <mruby/value.h>
#include "libn/nhash.h"
#include "libn/global.h"

nhash *
nhash_new(void)
{
  nhash *h;

  h = malloc(sizeof(nhash));
  h->_hash = mrb_hash_new(__LIBN_R);

  return h;
}


void nhash_free(nhash *hash)
{
  free(hash);
}


void
nhash_set(nhash *hash, const char *key, const void *ptr)
{
  mrb_hash_set(__LIBN_R, hash->_hash, mrb_str_new_cstr(__LIBN_R, key),
    mrb_cptr_value(__LIBN_R, (void*)ptr));
}


void *
nhash_get(const nhash *hash, const char *key)
{
  return mrb_hash_get(__LIBN_R,
    hash->_hash, mrb_str_new_cstr(__LIBN_R, key)).value.p;
}


void
nhash_delete(nhash *hash, const char *key)
{
  mrb_hash_delete_key(__LIBN_R, hash->_hash,
    mrb_str_new_cstr(__LIBN_R, key));
}


char *
nhash_inspect(const nhash *hash)
{
  return mrb_str_to_cstr(__LIBN_R, mrb_inspect(__LIBN_R, hash->_hash));
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
nstringhash_get(const nstringhash *hash, const char *key)
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
