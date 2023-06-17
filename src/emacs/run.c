#include <unistd.h>

int main() {
	execl("/usr/bin/emacs", "emacs", "--fg-daemon", NULL);
}
