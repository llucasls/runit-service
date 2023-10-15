#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	dup2(1, 2);

	const char *HOME = getenv("HOME");
	if (HOME == NULL)
		return 11;

	char *log_dir = ".cache/log/emacs";
	size_t dirname_size = strlen(HOME) + strlen(log_dir) + 2;
	char log_dir_path[dirname_size];
	snprintf(log_dir_path, dirname_size, "%s/%s", HOME, log_dir);

	char *args[] = {"svlogd", "-tt", log_dir_path, NULL};
	execv("/usr/bin/svlogd", args);

	return 1;
}
