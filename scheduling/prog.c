#include <stdio.h>
#include <stdlib.h>
#define N_PROCESSI 4
#define TIME_SLICE 4

struct s_proc{
  int pid;
  int cpuBurst;
  int timeArrival;
};
typedef struct s_proc proc;


//Algoritmi di scheduling
proc* sjf(proc*);
void rr(proc*);

int terminato(proc);
int tuttiTerminati(proc*);
proc* copia(proc*);
void stampa(proc*);
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
  printf("Shortest Job First:\n");
  stampa(sjf(processi));
  printf("\nRound Robin:\n");
  rr(processi);
  return 0;
}

proc* sjf(proc *processi){
  proc *pnew;
  pnew=copia(processi);//=(proc*)malloc(N_PROCESSI*sizeof(proc));
  int i=0;
  int j=0;

  qsort(pnew,N_PROCESSI,sizeof(proc),cmpfunc);

  return pnew;
}

void rr(proc *processi){
  while(1){
    for(int i=0; i<N_PROCESSI; i++){
      if(!terminato(processi[i])){
        printf("%d\t%d\n",processi[i].pid,processi[i].cpuBurst);
        if(processi[i].cpuBurst-TIME_SLICE<=0)
          processi[i].cpuBurst=0;
        else
          processi[i].cpuBurst-=TIME_SLICE;
      }
    }
    if(!tuttiTerminati(processi))
      break;
    }
    printf("\n");
}
int terminato(proc p){
  if(p.cpuBurst==0)
    return 1;
  else
    return 0;
}

int tuttiTerminati(proc* processi){
  int i=0;
  int flag=0;
  for(i=0; i<N_PROCESSI; i++){
    if(processi[i].cpuBurst!=0){
      flag=1;
    }
  }
  return flag;
}










int cmpfunc (const void * a, const void * b){
  const proc *elem1=a;
  const proc *elem2=b;
  return (*elem1).cpuBurst - (*elem2).cpuBurst;

}

proc* copia(proc* processi){
  proc* nuovo;
  nuovo=(proc*)malloc(N_PROCESSI*sizeof(proc));
  int i=0;
  for(int i=0; i<N_PROCESSI; i++){
    nuovo[i]=processi[i];
  }
  return nuovo;
}

void stampa(proc *processi){
  printf("PID\tCPU Burst\tTimeArrival\n");
  int i=0;
  for(i=0;i<N_PROCESSI; i++){
    printf("%d\t%d\t\t%d\n",processi[i].pid,processi[i].cpuBurst,processi[i].timeArrival);
  }
  printf("\n");
}
