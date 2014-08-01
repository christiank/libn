/*
 * nhash.h
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#ifndef NHASH_H
#define NHASH_H

#include <mruby.h>

/*
 * nhash is an opaque structure.
 */
struct nhash {
  mrb_value _hash;
};
typedef struct nhash nhash;

nhash *nhash_new(void);
void nhash_free(nhash *hash);

/* */

/*
 * nstringhash is an opaque structure.
 */
struct nstringhash {
  mrb_value _hash;
};
typedef struct nstringhash nstringhash;

nstringhash *nstringhash_new(void);
void nstringhash_free(nstringhash *hash);
void nstringhash_set(nstringhash *hash, const char *key, const char *value);
char *nstringhash_get(nstringhash *hash, const char *key);
void nstringhash_delete(nstringhash *hash, const char *key);
char *nstringhash_inspect(const nstringhash *hash);

#endif /* NHASH_H */
