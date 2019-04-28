#include <stdio.h>
#include "common.h"

// main
int main()
{
	int pid, fd;
	SYMBOL term;

	// 프롬프트를 출력
	print_prompt();

	while (TRUE)
	{
		// 사용자 명령을 입력받아 분석한다.
		term = parse(&pid, FALSE, NULL);

		// 명령의 마지막 심볼이 &일 경우 백그라운드로 명령을 수행, wait를 하지 않는다.
		if (term != S_AMP && pid != 0)
		{
			// 백그라운드 명령이 아닌 경우 자식이 프로세스를 종료할때까지 기다린다.
			waitfor(pid);
		}

		// 마지막 문자가 줄바꿈 문자일 경우 새로운 프롬프트를 출력한다.
		if (term == S_NL)
		{
			print_prompt();
		}

		// 파일 디스크립터를 닫는다.
		for (fd=3; fd<MAXFD; fd++)
		{
			close(fd);
		}
	}
}

