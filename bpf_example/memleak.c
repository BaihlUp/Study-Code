
#include <stdlib.h>

int main() {

	void *p1 = malloc(10);
	void *p2 = malloc(20);
	void *p3 = malloc(30);

	free(p1);
	free(p2);

}
