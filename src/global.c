/*
 * global.c
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <mruby.h>
#include "libn/global.h"

mrb_state *__LIBN_R;

void
libn_start(void)
{
  __LIBN_R = mrb_open();
}


void
libn_finish(void)
{
  mrb_close(__LIBN_R);
}
