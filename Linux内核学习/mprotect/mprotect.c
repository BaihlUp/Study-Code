#include <unistd.h>
#include <signal.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#define handle_error(msg) do{ perror(msg); exit(EXIT_FAILURE);}while(0)

static char *buffer;

static void handler(int sig,siginfo_t *si,void *unused)
{
    printf("Get SIGSEGV at address : %p\n",si->si_addr);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[])
{
    int pagesize;
    struct sigaction sa;

    sa.sa_flags=SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction=handler;

    if(sigaction(SIGSEGV,&sa,NULL)==-1)
        handle_error("siaction");

    pagesize=sysconf(_SC_PAGE_SIZE);
    if(pagesize==-1)
        handle_error("sysconf");

    buffer=memalign(pagesize,4*pagesize);
    if(buffer==NULL)
        handle_error("memalign");

    printf("start of region : %p\n",buffer);

    if(mprotect(buffer+pagesize*2,pagesize,PROT_READ)==-1)
        handle_error("mprotect");

        for(char *p=buffer;;)
        *(p++)='A';

        printf("for completed.\n");
        exit(EXIT_SUCCESS);

    return 0;
}