/********************************************************/
//功能：创建两个进程，父进程和子进程之间通过管道传递数据，父进程向
//	   子进程发送字符串exit表示让子进程退出，并且等待子进程返回；
//	   子进程查询管道，当从管道读出字符串exit的时候结束。
/********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pid_t pid;
	int fd[2];
	char buff[64];
	char *cmd = "exit";
	
	if(pipe(fd))	//创建管道
	{
		perror("Create pipe fail!");
		return -1;
	}

	pid = fork();	//创建子进程
	if(-1 == pid)
	{
		perror("Create process fail!");
		return -1;	
	}
	else if(0 == pid)	//子进程
	{
		close(fd[1]);	//关闭管道写操作
		printf("Child process!Wait command from parent...\n");
		while(1)
		{
			read(fd[0],buff,64);
			if(0 == strcmp(buff,cmd))
			{
				printf("receive command:%s\n",buff);
				close(fd[0]);
				exit(0);
			}
			else
				printf("receive command:%s\n",buff);
			sleep(1);
		}
	}
	else	//父进程
	{
		printf("Parent process!Child process id:%d\n",pid);
		close(fd[0]);	//关闭管道读操作
		printf("Send command to child process...\n");
		sleep(2);
		write(fd[1],"This is a test.\n",strlen("This is a test.")+1);
		sleep(2);	
		write(fd[1],cmd,strlen(cmd)+1);
		close(fd[1]);
	}
	
	return 0;
}
