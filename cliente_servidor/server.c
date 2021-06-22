#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
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
		bzero(buff, MAX);
		// read the message from client and copy it in buffer
		read(sockfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		printf("From client: %s\t To client : ", buff);
		bzero(buff, MAX);
		n = 0;
		// copy server message in the buffer
		while ((buff[n++] = getchar()) != '\n')
			;

		// and send that buffer to client
		write(sockfd, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}

		// if msg contains "sumita" then client do the addition
		if ((strncmp(buff, "sumita", 6)) == 0) {
			bzero(buff, MAX);
			// read the message from client and copy it in buffer
			read(sockfd, buff, sizeof(buff));
			//aa=buff;
			strcpy(aa,buff);
			//strcpy(destino, origen);//asignacion de valores de tipo string

			// print buffer which contains the client contents
			printf("From client: %s\n To client : ", buff);
			bzero(buff, MAX);
			n = 0;
			// copy server message in the buffer
			while ((buff[n++] = getchar()) != '\n')
				;
			// and send that buffer to client
			write(sockfd, buff, sizeof(buff));

			bzero(buff, MAX);
			// read the message from client and copy it in buffer
			read(sockfd, buff, sizeof(buff));
			//bb=buff;
			strcpy(bb,buff);
			//strcpy(destino, origen);//asignacion de valores de tipo string

			// print buffer which contains the client contents
			printf("From client: %s\n To client : ", buff);
			bzero(buff, MAX);
			n = 0;
			// copy server message in the buffer
			while ((buff[n++] = getchar()) != '\n')
				;
			// and send that buffer to client
			write(sockfd, buff, sizeof(buff));

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
	printf("\n El resultado es: ");
    for( k=0; k<len; k++)
        printf("%d",c[k]);

printf("\n\n");
//88888888888888888888
//33333333333333333333
//122222222222222222221
}




// Driver function
int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
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
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
