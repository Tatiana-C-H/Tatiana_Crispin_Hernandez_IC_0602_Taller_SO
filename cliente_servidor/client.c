#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int sockfd)
{
	char buff[MAX];
	int n;
	
	char aa[202],bb[202];

	// infinite loop for chat
	for (;;) {
		bzero(buff, sizeof(buff));
		printf("Enter the string : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		// read the message from server and copy it in buffer
		read(sockfd, buff, sizeof(buff));
		printf("From Server : %s", buff);
		// if msg contains "Exit" then server exit and chat ended.
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}

		// if msg contains "sumita" then client do the addition
		if ((strncmp(buff, "sumita", 6)) == 0) {
			bzero(buff, sizeof(buff));
			printf("Enter the first number : ");
			n = 0;
			while ((buff[n++] = getchar()) != '\n')
				;
			write(sockfd, buff, sizeof(buff));
			//aa=buff;
			strcpy(aa,buff);
			//strcpy(destino, origen);//asignacion de valores de tipo string

			bzero(buff, sizeof(buff));
			// read the message from server and copy it in buffer
			read(sockfd, buff, sizeof(buff));
			printf("From Server : %s", buff);


			printf("Enter the second number : ");
			n = 0;
			while ((buff[n++] = getchar()) != '\n')
				;
			write(sockfd, buff, sizeof(buff));
			//bb=buff;
			strcpy(bb,buff);
			//strcpy(destino, origen);//asignacion de valores de tipo string

			bzero(buff, sizeof(buff));
			// read the message from server and copy it in buffer
			read(sockfd, buff, sizeof(buff));
			printf("From Server : %s", buff);

			suma(aa,bb);
		}

	}
}

void suma(char aa[],char bb[]){
	//char aa[202],bb[202];
    int a[202],b[202],c[203];
    int i,j,k,ki;
    int m,n,len;
    m=strlen(aa);
    n=strlen(bb);
    len = ( m > n)? m:n ;

    for ( i=0; i<m; i++)
        a[i]=aa[i]-'0'; //i=m;
    for ( j=0; j<n; j++)
        b[j]=bb[j]-'0'; //j=n;

    for( i=m-1,j=n-1,k=len-1; i>=0 && j>=0; i--,j--,k--)
    {
        c[k] = a[i] + b[j];
    }

    for( ;i>=0; i--,k--)
        c[k] = a[i];
    for( ;j>=0; j--,k--)
        c [k] = b [j]; // Alto guardado

         // Cada décimo
    for( k=len-1; k>0; k--)
    {
        if( c[k] >9 )
        {
            c[k] = c[k]%10;
            c[k-1] += 1;
        }
    }
    printf("\n From server ");
	printf("\n El resultado es: ");
    for( k=0; k<len; k++)
        printf("%d",c[k]);

printf("\n\n");
//88888888888888888888
//33333333333333333333
//122222222222222222221
}


int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and varification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
	func(sockfd);

	// close the socket
	close(sockfd);
}
