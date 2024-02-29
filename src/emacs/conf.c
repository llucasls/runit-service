#include <stdlib.h>
#include <stdbool.h>

int setenv(const char *name, const char *value, int overwrite);

int conf(void) {
	int status = 0;

	status = setenv("VISUAL", "emacsclient", true);

	return status;
}
