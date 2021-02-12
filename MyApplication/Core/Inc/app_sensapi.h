/**
  ******************************************************************************
  * File Name          : app_sensapi.h
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

#include "sps30.h"
#include "scd30.h"
#include "iaq.h"
#include "ds1307.h"
#include "cmsis_os.h"


extern osMessageQueueId_t scd30_MsgQueue;                // message queue id

void SensInit(void);
void SensError(void);

/************************ (C) COPYRIGHT *****END OF FILE****/
