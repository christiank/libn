/*
 * nset.h
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#ifndef NSET_H
#define NSET_H

#include <stdbool.h>
#include <mruby.h>
#include "libn/nstring.h"

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
void nstringset_add(nstringset *set, const nstring *str);
void nstringset_add_cstr(nstringset *set, const char *str);
bool nstringset_include(const nstringset *set, const nstring *str);
bool nstringset_include_cstr(const nstringset *set, const char *str);


#endif /* NSET_H */
