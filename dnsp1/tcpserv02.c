#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(6000);

	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(listenfd, 0);

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
         
		if ( (childpid = fork()) == 0) {	/* child process */
			close(listenfd);	/* close listening socket */
			//str_echo(connfd);	/* process the request */
			int	n;
	char		buffer[80];


	while ( (n = read(connfd, buffer, 80)) > 0){
		
		puts(buffer);
	        char *buf;
	        char* a;
	        buf=strtok(buffer," ");
	        a=strtok(NULL," ");
	        strcpy(buf,buffer);
		FILE *fp=fopen("resolve1.txt","r");
 char s1[80];
 char s2[80];
int flag;
 while(!feof(fp))
{
fscanf(fp,"%s",s1);
fscanf(fp,"%s",s2);
if((strcmp(s1,buf))==0)
{
//printf("\nThe IP address of Server is : %s\n",s2);
write(connfd,s2, strlen(s2));
flag=1;
}

bzero(s1,80);
bzero(s2,80);
}

flag=0;
bzero(buf,80);
fclose(fp); 


		//Writen(sockfd, buf, n);
		}
			
			exit(0);
		}
		close(connfd);			/* parent closes connected socket */
	}
}


