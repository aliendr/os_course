#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[20];
	FILE *fp = fopen("/dev/random", "r");
	fscanf(fp, "%s", str);
	printf("%s", str);
	fclose(fp);
	return 0;
}
