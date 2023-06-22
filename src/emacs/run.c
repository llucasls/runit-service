#include <stdio.h>
#include <unistd.h>

int main() {
	char *args[] = {"emacs", "--fg-daemon", NULL};
	execv("/usr/bin/emacs", args);

	perror("emacs");
	return 1;
}
