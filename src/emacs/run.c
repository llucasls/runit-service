#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
	dup2(1, 2);

	void *lib_handle = dlopen("./libconf.so", RTLD_LAZY);
	if (lib_handle) {
		int status = 0;
		int (*conf)(void) = dlsym(lib_handle, "conf");

		if (conf)
			status = conf();

		dlclose(lib_handle);

		if (status != 0) {
			perror("emacs conf");
			return status;
		}

	}

	const char *home_dir = getenv("HOME");
	if (!home_dir) {
		perror("HOME environment variable not set");
		return 1;
	}

	int chdir_status = chdir(home_dir);
	if (chdir_status) {
		perror("failed to change directory");
		return 1;
	}

	char *args[] = {"emacs", "--fg-daemon", "--debug-init", NULL};
	execv("/usr/bin/emacs", args);

	perror("emacs");
	return 1;
}
