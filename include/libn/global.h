/*
 * global.h - Global variables and other fun stuff
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#ifndef LIBN_GLOBAL_H
#define LIBN_GLOBAL_H

#include <mruby.h>

/*
 * This is the (mrb_state*) that will be shared by ALL nlib objects you
 * might create in your program. Altogether, it saves memory, because the
 * alternative is creating and maintaining a (mrb_state*) for EVERY nlib
 * object. Wasteful.
 */
extern mrb_state *__LIBN_R;

void libn_start(void);
void libn_finish(void);

#endif /* LIBN_GLOBAL_H */
