#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <syslog.h>
#include <sys/wait.h>

extern int sockfd,
           enchufe;
extern pthread_t tid;

void ISRsw(int sig){
  int estado;
  pid_t pid;
  if(sig == SIGCHLD){
    pid = wait(&estado);
    syslog(LOG_INFO, "Proceso con pid: %d terminado y retorno %d\n",pid, estado>>8);
  }
  if(sig == SIGINT){
    enchufe = 0;
    pthread_join(tid, NULL);
    close (sockfd);
    syslog(LOG_INFO, "Apagando servidor\n");
    closelog( );
    exit(0);
  }
}
