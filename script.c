#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char * benchmark;
	char * exec = "./Run.pl";
	char * args;
	char * res = "results/gcc1";
	char * dir = "/home/surya/Documents/ece587/simulator/ss3_1/sim-outorder";
	
	
	
	if(!strcmp("gcc", argv[1]))
		benchmark = "gcc";
		
	else if(!strcmp("perl", argv[1]))
		benchmark = "perl";
		
	else if(!strcmp("li", argv[1]))
		benchmark = "li";
		
	else if(!strcmp("go", argv[1]))
		benchmark = "go";
		
	else if(!strcmp("ijpeg", argv[1]))
		benchmark = "ijpeg";
		
	else
		benchmark = "gcc";
		
	if(!strcmp("comb", argv[2]))
		args = "-fastfwd 1000000 -max:inst 1000000 -bpred comb"; 
		
	else if(!strcmp("2lev", argv[2]))
		args = "-fastfwd 1000000 -max:inst 1000000 -bpred 2lev";
		
	else if(!strcmp("bimod", argv[2]))
		args = "-fastfwd 1000000 -max:inst 1000000 -bpred bimod";
		
	else if(!strcmp("taken", argv[2]))
		args = "-fastfwd 1000000 -max:inst 1000000 -bpred taken";
	
	else if(!strcmp("nottaken", argv[2]))
		args = "-fastfwd 1000000 -max:inst 1000000 -bpred nottaken";
		
	char * cmd[12] = {"./Run.pl", "-db", "./bench.db", "-dir", res, "-benchmark", benchmark, "-sim", dir, "-args", args, NULL};
	
	if(execvp(exec, cmd) < 0)
		printf("failed\n");
	
	return 0;
}
