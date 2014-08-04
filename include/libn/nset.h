/*
 * nset.h
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#ifndef NSET_H
#define NSET_H

#include <mruby.h>

/*
 * Internally, _set is actually a Ruby hash. We just only use their keys,
 * not their key/value pairs.
 */
struct nset {
  mrb_value _set;
};
typedef struct nset nset;

nset *nset_new(void);
void nset_free(nset *set);

/* */

struct nstringset {
  mrb_value _set;
};
typedef struct nstringset nstringset;

nstringset *nstringset_new(void);
void nstringset_free(nstringset *set);

#endif /* NSET_H */
