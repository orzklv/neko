//
// Created by Sokhibjon Orzikulov on 13/02/23.
//

#ifndef NEKO_HTTP_H
#define NEKO_HTTP_H

#include <stdio.h>
#include <string.h>

extern char *method, // "GET" or "POST"
        *uri,        // "/index.html" things before '?'
        *qs,         // "a=1&b=2"   things after '?'
        *prot,       // "HTTP/1.1"
        *payload;    // for POST

extern int payload_size;

void serve_forever(const char *PORT);
char *request_header(const char *name);

typedef struct {
    char *name;
    char *value;
} header_t;

static header_t reqhdr[17] = {{ "\0", "\0" }};
header_t *request_headers(void);

void route();

// Response
#define RESPONSE_PROTOCOL "HTTP/1.1"

#define HTTP_200 printf("%s 200 OK\n\n", RESPONSE_PROTOCOL)
#define HTTP_201 printf("%s 201 Created\n\n", RESPONSE_PROTOCOL)
#define HTTP_404 printf("%s 404 Not found\n\n", RESPONSE_PROTOCOL)
#define HTTP_500 printf("%s 500 Internal Server Error\n\n", RESPONSE_PROTOCOL)

// Some interesting macro for route();
#define ROUTE_START() \
  if (0) {
    #define ROUTE(METHOD, URI)                                                     \
  }                                                                                \
  else if (strcmp(URI, uri) == 0 && strcmp(METHOD, method) == 0) {
    #define GET(URI) ROUTE("GET", URI)
    #define POST(URI) ROUTE("POST", URI)
    #define ROUTE_END()                                                            \
  }                                                                                \
  else HTTP_500;


#endif //NEKO_HTTP_H
