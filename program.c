#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

int main() {
  const void *val = sqlite3_column_blob(NULL, 0);
  int size = sqlite3_column_bytes(NULL, 0);
  char dummy;
  printf("val=%p, size=%d\n", val, size);
  // size = 0; // will work as expected if uncomment this line
  memcpy(&dummy, val, size); // expected to be noop
  printf("val=%p, isnull=%d\n", val, val == NULL); // -> prints `val=0, isnull=0`, expected `val=0, isnull=1`
}
