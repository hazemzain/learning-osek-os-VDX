#include "tp.h"
#include "tpl_os.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void) {
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC1_Init_START_SEC_CODE
#include "tpl_memmap.h"
void SWC1_Init_Internal(void) {
  unsigned int l_Counter = 0;

  ledOn(RED);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC1_Init) {
  SWC1_Init_Internal();
  ledOff(RED);
  ActivateTask(SWC1_MainTask);
  TerminateTask();
}
#define APP_Task_SWC1_Init_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/

#define APP_Task_SWC2_Init_START_SEC_CODE
#include "tpl_memmap.h"
void SWC2_Init_Internal(void) {
  unsigned int l_Counter = 0;
  ledOn(ORANGE);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC2_Init) {
  SWC2_Init_Internal();
  ledOff(ORANGE);
  TerminateTask();
}
#define APP_Task_SWC2_Init_STOP_SEC_CODE
#include "tpl_memmap.h"






/******************************************************************/


#define APP_Task_SWC1_MainTask_START_SEC_CODE
#include "tpl_memmap.h"
void SWC1_MainTask_Internal(void) {
  unsigned int l_Counter = 0;
  ledOn(BLUE);
  for (l_Counter = 0; l_Counter < 6000000; l_Counter++) {
  }
}

TASK(SWC1_MainTask) {

  for(;;){
  SWC1_MainTask_Internal();
  if(BUTTON_ON==readButton())
  {
    SetEvent(SWC2_MainTask,event1);
    ledOff(BLUE);
  }
 
  }
  TerminateTask();
}
#define APP_Task_SWC1_MainTask_STOP_SEC_CODE
#include "tpl_memmap.h"

/******************************************************************/
#define APP_Task_SWC2_MainTask_START_SEC_CODE
#include "tpl_memmap.h"
void SWC2_MainTask_Internal(void) {
  unsigned int l_Counter = 0;
  ledOn(BLUE);
  ledOn(ORANGE);
  ledOn(RED);
  for (l_Counter = 0; l_Counter < 1000000; l_Counter++) {
  }
}

TASK(SWC2_MainTask) {
  EventMaskType ReciveEvent;

  for(;;){
    (void)WaitEvent(event1|event2);
    (void)GetEvent(SWC2_MainTask,&ReciveEvent);
    (void)ClearEvent(ReciveEvent&(event1));
    if((ReciveEvent&event1)!=(EventMaskType)0){
      SWC2_MainTask_Internal();


    }
  
 
 
  }
  TerminateTask();
}
#define APP_Task_SWC1_MainTask_STOP_SEC_CODE
#include "tpl_memmap.h"
/******************************************************************/

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t *file, uint32_t line) {}

FUNC(void, OS_CODE) PreTaskHook() {}

FUNC(void, OS_CODE) PostTaskHook() {}

FUNC(void, OS_CODE) ShutdownHook(StatusType Error) {
  if (E_OK == Error) {
    /* Normal Shutdown */
    ledOff(RED);
    ledOff(GREEN);
    ledOff(ORANGE);
    ledOff(BLUE);
  } else {
    /* Abnormal Shutdown */
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
