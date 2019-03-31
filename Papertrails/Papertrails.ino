#include "papertrail.h"

const char* papertrailHost = "logs.papertrailapp.com";
//no spaces insender name
const char* sender = "Example";
int port = 3333;

PaperTrailLogHandler paperTrailLogHandler = logger(papertrailHost,port,sender);

void setup() {
  // make a wifi coneection here


  // If the arduino experienced a fatal ecption and rebooted, this will 
  // send info about that exception on next startup!
  struct  rst_info  *rtc_info = system_get_rst_info();
  if(rtc_info->reason){
  logging(String("[RESET REASON]\n"),paperTrailLogHandler); 
  logging(reasons[rtc_info->reason],paperTrailLogHandler);
  if(rtc_info->reason == REASON_WDT_RST || rtc_info->reason == REASON_EXCEPTION_RST || rtc_info->reason == REASON_SOFT_WDT_RST){
    if(rtc_info->reason ==  REASON_EXCEPTION_RST) {
      logging("[FATAL EXCEPTION]",paperTrailLogHandler);
      logging(String(rtc_info->exccause),paperTrailLogHandler);
    }
    Serial.printf("epc1=0x%08x,  epc2=0x%08x,  epc3=0x%08x,  excvaddr=0x%08x,  depc=0x%08x\n",rtc_info->epc1,  rtc_info->epc2, rtc_info->epc3, rtc_info->excvaddr,  rtc_info->depc);
    //The address of  the last  crash is  printed,  which is  used  to  debug garbled output.
  }
  }
   

}

void loop() {
  logging("Example message",paperTrailLogHandler);

  delay(1000);
}
