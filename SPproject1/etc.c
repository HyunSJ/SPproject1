#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "common.h"

/* fatal 오류 처리*/
void fatal(char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(1);
}

/*  일반 에러 처리*/
void syserr(char *message)
{
	fprintf(stderr, "Error: %s (%d", message, errno);
	exit(1);
}

/* wait 함수*/
void waitfor(int pid)
{
	int wpid, status;

	/* wait를 이용하여 프로세스를 기다린다.*/
	while ((wpid = wait(&status)) != pid && wpid != ERROR);
}

/*  프롬프트 출력.
	[Hshell:현재경로]>>
*/
void print_prompt()
{
	char *path;
	path = (char*)malloc(1024);
	getcwd(path, 1024);
	printf("[Hshell:%s]>>",path);
			
}

BOOLEAN shellcmd(int ac, char *av[], int sourcefd, int destfd)
{
	char *path;

	// cd
	if(!strcmp(av[0], "cd"))
	{
		my_cd(ac, av);
	}
	// ls
	else if(!strcmp(av[0], "ls"))
	{
		my_ls(ac, av);
	}
	// cp
	else if(!strcmp(av[0], "cp"))
	{
		my_cp(ac, av);
	}
	// rm
	else if(!strcmp(av[0], "rm"))
	{
		my_rm(ac, av);
	}
	// mv
	else if(!strcmp(av[0], "mv"))
	{
		my_mv(ac, av);
	}
	// mkdir
	else if(!strcmp(av[0], "mkdir"))
	{
		my_mkdir(ac, av);
	}
	// rmdir
	else if(!strcmp(av[0], "rmdir"))
	{
		my_rmdir(ac, av);
	}
	// cat
	else if(!strcmp(av[0], "cat"))
	{
		my_cat(ac, av);
	}
	// exit
	else if(!strcmp(av[0], "exit"))
	{
		my_exit();
	}
	else
	{
		return FALSE;
	}

	if (sourcefd != 0 || destfd != 1)
	{
		fprintf(stderr, "Ilegal redirection or pipeline.\n");
	}

	return TRUE;
}

