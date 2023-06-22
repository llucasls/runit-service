#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char compose_file_path[256];
	const char* home_dir = getenv("HOME");

	if (home_dir == NULL) {
		fprintf(stderr, "Error: HOME environment variable not set\n");
		return 1;
	}

	snprintf(compose_file_path, sizeof(compose_file_path), "%s/docker/mongo/mongo.yml", home_dir);

	char* const argv[] = { "/usr/bin/docker-compose", "-f", compose_file_path, "down", NULL };
	execv("/usr/bin/docker-compose", argv);

	perror("mongo");
	return 1;
}
