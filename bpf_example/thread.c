
#include <pthread.h>
#include <unistd.h>

typedef void* (*thread_cb_t)(void *arg);

void *thread_entry(void *arg) {

	while(1) {
	
		usleep(1);

	}

}

void start_thread(pthread_t *tid, thread_cb_t cb) {
	
	pthread_create(tid, NULL, cb, NULL);

}

void* wait_cb(pthread_t tid) {

	void *retval;
	pthread_join(tid, &retval);

	return retval;
}


void func(int count) {

	pthread_t tid;

        start_thread(&tid, thread_entry);

	wait_cb(tid);

}


int main() {

	int count = 5;
	func(count);

}

