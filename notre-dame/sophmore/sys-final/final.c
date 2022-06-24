/* http_client.c: simple HTTP client */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

FILE *socket_dial(const char *host, const char *port) {
    /* Lookup server address information */
    struct addrinfo *results;
    struct addrinfo  hints = {
        .ai_family   = AF_UNSPEC,   /* Return IPv4 and IPv6 choices */
        .ai_socktype = SOCK_STREAM, /* Use TCP */
    };
    int status;
    if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
    	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
	return NULL;
    }

    /* For each server entry, allocate socket and try to connect */
    int client_fd = -1;
    for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
	if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
	    fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
	    continue;
	}

	/* Connect to host */
	if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
	    close(client_fd);
	    client_fd = -1;
	    continue;
	}
    }

    /* Release allocate address information */
    freeaddrinfo(results);

    if (client_fd < 0) {
	fprintf(stderr, "Unable to connect to %s:%s: %s\n", host, port, strerror(errno));
    	return NULL;
    }

    /* Open file stream from socket file descriptor */
    FILE *client_file = fdopen(client_fd, "w+");
    if (!client_file) {
        fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
        close(client_fd);
        return NULL;
    }

    return client_file;
}

int main(int argc, char *argv[]) {
    char *host = "xavier.h4x0r.space";
    int high_port = 9499;
    int low_port  = 9400;

    /* Parse command line arguments */
    if (argc > 1) host = argv[1];

    /* Connect to remote machine */
    FILE *client_file = NULL;

    for(int port = low_port; port <= high_port && !client_file; port++)
    {
        char sport[BUFSIZ];
        sprintf(sport, "%d", port);
        client_file = socket_dial(host, sport);
    }


    
    
    /* Send HTTP Request */
    fprintf(client_file, "GET / HTTP/1.0\r\n");
    fprintf(client_file, "Host: %s\r\n", host);
    fprintf(client_file, "\r\n");                   // Must end Request with empty line

    /* Send HTTP Request */
    /// find /escnfs/home/pbui/pub/oracle/tokens/*$srodri25 | grep "srodri25"
    char tok_path[] = "/escnfs/home/pbui/pub/oracle/tokens/d7474d2e/741a7585/199b941b/d066ca20/25bd2ccf/srodri25.token";
    
    struct stat *statbuff;

    stat(tok_path, statbuff);

    fprintf(client_file, "PUT /srodri25%s HTTP/1.0\r\n", tok_path);
    fprintf(client_file, "Host: %s\r\n", host);
    fprintf(client_file, "Content-Type: text/plain\r\n");
    fprintf(client_file, "Content-Length: %ld\r\n", statbuff->st_size);
    
    system("cat final.c");

    fprintf(client_file, "\r\n");                   // Must end Request with empty line

    /* Read HTTP Response */
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, client_file)) {
        fputs(buffer, stdout);
    }

    /* Close socket */
    fclose(client_file);
    return EXIT_SUCCESS;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
