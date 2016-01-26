#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

int
main()
{
	int sockfd,sockfd1;
	char a;
	char buf[80];
	struct sockaddr_in servaddr,servaddr1;
	printf("\nEnter Name to lookup : ");
	gets(buf);
        printf("\nEnter Recursive(r)/Iterative(i)");
	
	scanf("%c",&a);
	//getchar(); 
	//if(a=='r')
	//strcat(buf," r");
	//else if(a=='i')
	//strcat(buf," i");
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
	
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	inet_pton(AF_INET,"127.0.0.1", &servaddr.sin_addr);
	
	bzero(&servaddr1, sizeof(servaddr1));
	servaddr1.sin_family = AF_INET;
	servaddr1.sin_port = htons(6000);
	inet_pton(AF_INET,"127.0.0.1", &servaddr1.sin_addr);

	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
        char recvline[80]; 
		 write(sockfd, buf, strlen(buf));
	//str_cli(buf, sockfd); 	/* do it all */
		if(read(sockfd, recvline, 80) != 0)
		{if(strcmp(recvline,"n")!=0)
		 {printf("%s\n",recvline);
		 fflush(stdout);}
		 else if(strcmp(recvline,"n")==0)
		 {printf("n");
		  //break;
		  }
		}
		
		//printf("Error");
		if(a=='i')
		{connect(sockfd1, (struct sockaddr *) &servaddr1, sizeof(servaddr1));
		 write(sockfd1, buf, strlen(buf));
		 if(read(sockfd, recvline, 80) != 0)
		     {  if(strcmp(recvline,"n")!=0)
		 	{printf("%s\n",recvline);
		 	fflush(stdout);}
		 	else if(strcmp(recvline,"n")==0)
		 	{printf("n");
		 	//break;
		 	}
		 	}
		}
		 
	}

	

