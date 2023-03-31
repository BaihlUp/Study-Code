#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <assert.h>

static int GetThreadPolicyFunc(pthread_attr_t *pAttr)
{
    int iPlicy;
    int igp=pthread_attr_getschedpolicy(pAttr,&iPlicy);

    assert(igp==0);

    switch (iPlicy)
    {
    case SCHED_FIFO:
        printf("Policy is --> SCHED_FIFO.\n");
        break;

    case SCHED_RR:
        printf("Policy is --> SCHED_RR.\n");
        break;

    case SCHED_OTHER:
        printf("Policy is --> SCHED_OTHER.\n");
        break;
    
    default:
    printf("Policy is --> Unknown.\n");
        break;
    }

    return iPlicy;
}

static void PrintThreadPriorityFunc(pthread_attr_t *pAttr,int iPolicy)
{
    int iPriority=sched_get_priority_max(iPolicy); 
    assert(iPriority!=-1);
    printf("Max_priority is : %d\n",iPriority);

    iPriority=sched_get_priority_min(iPolicy); 
    assert(iPriority!=-1);
    printf("Min_priority is : %d\n",iPriority);
}

static int GetThreadPriorityFunc(pthread_attr_t *pAttr)
{
    struct sched_param sParam;
    int irs=pthread_attr_getschedparam(pAttr,&sParam);

    assert(irs==0);

    printf("Priority=%d\n",sParam.__sched_priority);

    return sParam.__sched_priority;
}

static void SetThreadPolicyFunc(pthread_attr_t *pAttr,int iPolicy)
{
    int irs=pthread_attr_setschedpolicy(pAttr,iPolicy);

    assert(irs==0);

    GetThreadPolicyFunc(pAttr);
}

int main(int argc,char *argv[])
{
    pthread_attr_t pAttr;
    struct sched_param sched;

    int irs=pthread_attr_init(&pAttr);
    assert(irs==0);

    int iPlicy=GetThreadPolicyFunc(&pAttr);

    printf("\nExport current Configuration of priority.\n");
    PrintThreadPriorityFunc(&pAttr,iPlicy);

    printf("\nExport SCHED_FIFO of prioirty.\n");
    PrintThreadPriorityFunc(&pAttr,SCHED_FIFO);

    printf("\nExport SCHED_RR of prioirty.\n");
    PrintThreadPriorityFunc(&pAttr,SCHED_RR);


    printf("\nExport priority of current thread.\n");
    int iPriority=GetThreadPriorityFunc(&pAttr);
    printf("Set thread policy.\n");

    printf("\nSet SCHED_FIFO policy.\n");
    SetThreadPolicyFunc(&pAttr,SCHED_FIFO);

    printf("\nSet SCHED_RR policy.\n");
    SetThreadPolicyFunc(&pAttr,SCHED_RR);

    printf("\nRestore current policy.\n");
    SetThreadPolicyFunc(&pAttr,iPlicy);

    irs=pthread_attr_destroy(&pAttr);
    assert(irs==0);

    return 0;
}


