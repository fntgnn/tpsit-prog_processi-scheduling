#include <stdio.h>
#include <stdlib.h>
#define N_PROCESSI 4

struct s_proc{
  int pid;
  int cpuBurst;
  int timeArrival;
};
typedef struct s_proc proc;

void stampa(proc*);
proc* sjf(proc*);
int cmpfunc(const void * a, const void * b);

int main(){
  proc *processi;
  processi=(proc*)malloc(N_PROCESSI*sizeof(proc));
  freopen("processi.dat","r",stdin);
  int i=0;
  for(i=0; i<N_PROCESSI; i++){
    scanf("%d,%d,%d\n",&(processi[i].pid),&(processi[i].cpuBurst),&(processi[i].timeArrival));
  }
  stampa(processi);
  stampa(sjf(processi));
  return 0;
}

proc* sjf(proc *processi){
  proc *pnew;//=(proc*)malloc(N_PROCESSI*sizeof(proc));
  int i=0;
  int j=0;

  qsort(processi,N_PROCESSI,sizeof(proc),cmpfunc);

  return processi;
}

int cmpfunc (const void * a, const void * b){
  const proc *elem1=a;
  const proc *elem2=b;
  return (*elem1).cpuBurst - (*elem2).cpuBurst;

}

void stampa(proc *processi){
  printf("PID\tCPU Burst\tTimeArrival\n");
  int i=0;
  for(i=0;i<N_PROCESSI; i++){
    printf("%d\t%d\t\t%d\n",processi[i].pid,processi[i].cpuBurst,processi[i].timeArrival);
  }
  printf("\n");
}
