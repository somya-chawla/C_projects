#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
int main(int argc,char argv[])
{
	int socket_fd,new_fd,valread,i,reuse,ret;
	int socket_fd2,new_fd1;
	socklen_t optlen = sizeof(reuse);
	char h='S';
	struct sockaddr_in address,client;
	char buff[1024];
	int client_len,client_len2;
	socket_fd=socket(AF_INET,SOCK_STREAM,0);
	reuse=1;
	address.sin_family =AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port=htons(9734);
//	ret=setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&reuse,optlen);
//	printf("ret is %d\n",ret);
	
	bind(socket_fd,(struct sockaddr*)&address,sizeof(struct sockaddr));
	listen(socket_fd,5);
	while(1)
	{
		client_len=sizeof(client);
		new_fd=accept(socket_fd,(struct sockaddr*)&client,&client_len);
		printf("accept fd is %d\n",new_fd);
	//	valread=read(new_fd,buff,1024);
	//	printf("recive msg == %s\n",buff);
		//close(new_fd);
		write(new_fd,&h,1);
		printf("%c\n",h);
		printf("Hello message sent\n");
		valread=read(new_fd,buff,1024);
		printf("recive msg == %s\n",buff);
		close(new_fd);

	}
	struct sockaddr_in address2,client2;
	socket_fd2=socket(AF_INET,SOCK_STREAM,0);
	address2.sin_family =AF_INET;
	address2.sin_addr.s_addr = inet_addr("127.0.0.1");
	address2.sin_port=htons(9735);
	
	bind(socket_fd2,(struct sockaddr*)&address,sizeof(struct sockaddr));
	listen(socket_fd2,5);
	while(1)
	{
		client_len2=sizeof(client2);
		new_fd1=accept(socket_fd2,(struct sockaddr*)&client2,&client_len2);
		printf("accept fd is %d\n",new_fd);
		valread=read(new_fd,buff,1024);
		printf("recive msg == %s\n",buff);
		close(new_fd1);
	}
}
