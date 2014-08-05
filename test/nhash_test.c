/*
 * nhash_test.c Example
 * Christian Koch <cfkoch@sdf.lonestar.org>
 */

#include <stdio.h>
#include <stdlib.h>
#include <libn.h>

int
main(void)
{
  nhash *myhash;
  FILE *fp;
  void *region;

  libn_start();
  myhash = nhash_new();

  nhash_set(myhash, "key", "__SOME_VALUE__"); 
  printf("%s => %s\n", "key", nhash_get(myhash, "key"));

  fp = fopen("/dev/urandom", "r");
  region = malloc(16);
  fread(region, 1, 16, fp);
  fclose(fp);
  nhash_set(myhash, "random", region);
  printf("%s\n", nhash_inspect(myhash));
  free(region);
  printf("%s\n", nhash_inspect(myhash));

  nhash_free(myhash);
  libn_finish();
  return EXIT_SUCCESS;
}
