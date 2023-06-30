#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char *home_dir = getenv("HOME");
	int chdir_status = chdir(home_dir);

	if (chdir_status != 0) {
		perror("failed to change directory");
		return 1;
	}

	char *args[] = {"emacs", "--fg-daemon", NULL};
	execv("/usr/bin/emacs", args);

	perror("emacs");
	return 1;
}
