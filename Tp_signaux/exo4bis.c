#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include <sys/wait.h> 

struct sigaction actionfils;

sigset_t ens2;
pid_t pid;
int somme;


void handfils(int sig){

	if(sig == SIGINT){
		printf("Somme : %d\n",somme);
		exit(sig);
	}
	
	return;

}

int main(void){
	
	pid = fork();
	if(pid == 0){
		actionfils.sa_handler = handfils;
		sigaction(SIGINT, &actionfils, NULL);
		somme = 0;
		srand(time(NULL));
		while(1){
			somme+=rand()%11;
			sleep(1);
		}
	}
	else{
		sigemptyset(&ens2);
		sigaddset(&ens2,SIGINT);
		sigprocmask(SIG_SETMASK, &ens2, NULL);
		wait(NULL);
	}
	return 0;
	
}
