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

int main(){
  proc processi[4];
  freopen("processi.dat","r",stdin);
  int i=0;
  for(i=0; i<N_PROCESSI; i++){
    scanf("%d,%d,%d\n",&(processi[i].pid),&(processi[i].cpuBurst),&(processi[i].timeArrival));
  }
  stampa(processi);
  return 0;
}

void stampa(proc *processi){
  printf("PID\tCPU Burst\tTimeArrival\n");
  int i=0;
  for(i=0;i<N_PROCESSI; i++){
    printf("%d\t%d\t\t%d\n",processi[i].pid,processi[i].cpuBurst,processi[i].timeArrival);
  }
}
