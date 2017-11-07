#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#define PORT 9734
/*struct send
{
	int pid;
	char opr;
	int op1;
	int op2;
};*/

int main(int argc,int *argv[])
{
	//struct sockaddr_in address;
//	struct send s;
	int sock,valread,i;
	char *hello;
	int ret;
	hello=(char*)malloc(sizeof(char)*100);
	struct sockaddr_in serv_addr;
	char buff[1024];
	sock=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family =AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serv_addr.sin_port=htons(PORT);
	ret=connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("ret is %d\n",ret);
	printf("Enter the String\n");
/*	s.opr='+';
	s.op1=12;
	s.op2=13;
	s.pid=getpid();*/

	fgets(hello,100,stdin);
	write(sock,hello,100);
//	for(i=0;i<3;i++)
//	{
//	}
	printf("Message sent\n");
	
	valread=read(sock,buff,100);
	printf("%s\n",buff);
	fgets(hello,100,stdin);
	write(sock,hello,100);

	close(sock);
	return 0;
}



