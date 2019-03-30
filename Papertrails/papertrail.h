#ifndef papertrail
#define papertrail

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

typedef struct {
    const char *host;
    int port;
    const char *sender;
} PaperTrailLogHandler;

char* papertrim(char *data);

void logging(const char *message, PaperTrailLogHandler paperTrailLogHandler);

PaperTrailLogHandler logger(const char* host, int port,const char *sender);

int send(const char *url,int port, const char data[500]);

void logging(String message, PaperTrailLogHandler paperTrailLogHandler);


#endif
