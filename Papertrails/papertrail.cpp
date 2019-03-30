#include "papertrail.h"



void logging(const char *message, PaperTrailLogHandler paperTrailLogHandler) {
    char data[500];
    //Timestamp gets corrected by papertrails.
    //Not needed to implement time in arduino <-- not so easy
    snprintf(data, sizeof(data), "<22>1 2014-06-18T09:56:21Z %s Spotty-gatherer - - - %s", paperTrailLogHandler.sender , message);
    send(paperTrailLogHandler.host, paperTrailLogHandler.port, data);
    #ifdef SERIAL
    Serial.println(message);
    #endif
}

void logging(String message, PaperTrailLogHandler paperTrailLogHandler) {
    logging(message.c_str(), paperTrailLogHandler);
}

PaperTrailLogHandler logger(const char* host, int port,const char *sender) {
    PaperTrailLogHandler paperTrailLogHandler;
    paperTrailLogHandler.host = host;
    paperTrailLogHandler.port = port;
    //make sure sender DOES NOT CONTAIN SPACES
    paperTrailLogHandler.sender = sender;
    logging("logging started", paperTrailLogHandler);
    return paperTrailLogHandler;
}

int send(const char *url, int port, const char data[500]) {
    WiFiUDP Udp;
    Udp.begin(443);
    Serial.println(Udp.beginPacket(url, port));
    Udp.write(data);
    Udp.endPacket();
    return 1;
}
