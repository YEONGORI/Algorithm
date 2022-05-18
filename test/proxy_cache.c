#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define PORT_NUM 39999
#define BUFFER_SIZE 1024

int check_url(int *hit_cnt, int *miss_cnt, char *tokenized_req);
void chld_handler(void);
void alrm_handler(void);
char *getIPAddr(char *addr);

int main()
{
    int sock_fd_serv, sock_fd_client;
    int cnt_hit, cnt_miss, opt_val;

    struct sockaddr_in addr_serv, addr_client;

    pid_t pid;

    cnt_hit = 0;
    cnt_miss = 0;
    opt_val = 1;

    sock_fd_serv = socket(PF_INET, SOCK_STREAM, 0); // create socket for IPv4, TCP
    if (sock_fd_serv < 0)
    {
        printf("Server : Can't open stream socket\n");
        return (0);
    }

    bzero((char *)&addr_serv, sizeof(addr_serv)); // define socket addr of server side
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_serv.sin_port = htons(PORT_NUM);

    setsockopt(sock_fd_serv, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val));

    int is_bind = bind(sock_fd_serv, (struct sockaddr *)&addr_serv, sizeof(addr_serv)); // asscociate an address with a socket
    if (is_bind < 0)
    {
        printf("Server : Can't bind local address\n");
        close(sock_fd_serv);
        return (0);
    }

    listen(sock_fd_serv, 5);
    signal(SIGCHLD, (void *)chld_handler); // prevent ended children becoming zombie state
    signal(SIGALRM, (void *)alrm_handler);

    while (1)
    {
        int len, is_hit;
        char *tok = NULL;
        char http_request[BUFFER_SIZE];
        char tmp[BUFFER_SIZE] = {
            0,
        };
        char url[BUFFER_SIZE] = {
            0,
        };
        char method[BUFFER_SIZE] = {
            0,
        };
        char response_header[BUFFER_SIZE] = {
            0,
        };
        char response_message[BUFFER_SIZE] = {
            0,
        };

        bzero((char *)&addr_client, sizeof(addr_client));

        len = sizeof(addr_client);
        sock_fd_client = accept(sock_fd_serv, (struct sockaddr *)&addr_client, &len);
        if (sock_fd_client < 0)
        {
            printf("Server : accept failed\n");
            close(sock_fd_serv);
        }

        memset(response_header, 0, sizeof(response_header));
        memset(response_message, 0, sizeof(response_message));

        printf("[%s : %d] client was connected\n", inet_ntoa(addr_client.sin_addr), addr_client.sin_port);

        pid = fork();
        if (pid < 0)
        {
            printf("Server : fork failed\n");
            close(sock_fd_client);
        }

        if (pid == 0)
        {
            read(sock_fd_client, http_request, BUFFER_SIZE);
            strcpy(tmp, http_request);
            puts("===================================================");
            printf("Request from [%s : %d]\n", inet_ntoa(addr_client.sin_addr), addr_client.sin_port);
            puts(http_request);
            puts("===================================================");

            tok = strtok(tmp, " ");
            strcpy(method, tok);
            if (strcmp(method, "GET") == 0)
            {
                tok = strtok(NULL, " ");
                strcpy(url, tok);
            }

            is_hit = check_url(&cnt_hit, &cnt_miss, url);

            if (is_hit == 1)
            {
                sprintf(response_message,
                        "<h1>HIT</h1><br>"
                        "Hello %s:%d<br>"
                        "%s<br>"
                        "kw2018202076",
                        inet_ntoa(addr_client.sin_addr), addr_client.sin_port, url);
            }
            else
            {
                sprintf(response_message,
                        "<h1>MISS</h1><br>"
                        "Hello %s:%d<br>"
                        "%s<br>"
                        "kw2018202076",
                        inet_ntoa(addr_client.sin_addr), addr_client.sin_port, url);

                int sock_fd = socket(PF_INET, SOCK_STREAM, 0); // create socket for IPv4, TCP
                if (sock_fd < 0)
                {
                    printf("Server : Can't open stream socket\n");
                    return (0);
                }

                char buf[BUFFER_SIZE] = {
                    0,
                };
                char *tmp2 = strtok(url, "://");
                tmp2 = strtok(NULL, "/");
                char *IPAddr = getIPAddr(tmp2);
                struct sockaddr_in addr_sock;
                bzero((char *)&addr_sock, sizeof(addr_sock)); // define socket addr of server side
                addr_sock.sin_family = AF_INET;
                addr_sock.sin_addr.s_addr = inet_addr(IPAddr);
                addr_sock.sin_port = htons(80);

                int is_connect = connect(sock_fd, (struct sockaddr *)&addr_sock, sizeof(addr_sock));
                if (is_connect < 0)
                {
                    printf("Server : connect failed\n");
                    close(sock_fd);
                }
                alarm(10);
                sleep(15);
                if (read(sock_fd, buf, BUFFER_SIZE) > 0)
                    alarm(0);
            }
            sprintf(response_header,
                    "HTTP/1.0 200 ok\r\n"
                    "Server:2018 simple web server\r\n"
                    "Content-length:%lu\r\n"
                    "Content-type:text/html\r\n\r\n",
                    strlen(response_message));
            write(sock_fd_client, response_header, strlen(response_header));
            write(sock_fd_client, response_message, strlen(response_message));

            printf("[%s : %d] client was disconnected\n\n", inet_ntoa(addr_client.sin_addr), addr_client.sin_port);

            bzero(http_request, sizeof(http_request));
            bzero(tmp, sizeof(tmp));
            bzero(url, sizeof(url));

            close(sock_fd_client);
        }

        close(sock_fd_client);
    }
}

void chld_handler(void)
{
    while ((waitpid(-1, NULL, WNOHANG)) > 0)
        ;
}

void alrm_handler(void)
{
    printf("\n\n========No Response========\n\n");
}

char *getIPAddr(char *addr)
{
    struct hostent *hent;
    char *haddr;
    int len = strlen(addr);

    if ((hent = (struct hostent *)gethostbyname(addr)) != NULL)
    {
        haddr = inet_ntoa(*((struct in_addr *)hent->h_addr_list[0]));
    }
    return haddr;
}