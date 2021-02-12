/**
  ******************************************************************************
  * File Name          : app_sensapi.c
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

#include "app_sensapi.h"


extern I2C_HandleTypeDef hi2c1;

uint32_t slcnt = 0;

/**
 * Initialize TouchGFX application
 */
/*void MX_TouchGFX_Init(void)
{
  // Calling farward to touchgfx_init in C++ domain
  touchgfx_init();
}*/


/**
 * SensApi application thread
 */
void SensApi_Task(void *argument)
{
	SCD30MSG scdmsg;

		iAQ_Core_status_t aux;
	    uint16_t data_ready;
	    int16_t ret;

	    struct sps30_measurement m;
	    float co2_ppm, temperature, relative_humidity;
	    uint16_t pred, status, Tvoc;
	    uint32_t resistance;


		while(1)
		{

				aux = iAQ_Core_GetNewReading(&pred, &status, &resistance, &Tvoc);

				if(aux == 0)
				{
					if(status == 0)
					{
						printf("iaq comes with data\n");
					}
				}
				else
				{
					SensError();
				}



				ret = scd30_get_data_ready(&data_ready);
				if (ret == STATUS_OK) {
					if (data_ready) {
						ret = scd30_read_measurement(&co2_ppm, &temperature, &relative_humidity);
						if (ret != STATUS_OK) {
							SensError();
						}
						else
						{
							scdmsg.Co2_msg = co2_ppm;
							scdmsg.Temp_msg = temperature;
							scdmsg.Hum_msg = relative_humidity;

							osMessageQueuePut(scd30_MsgQueue, &scdmsg, 0U, 0U);

				            printf("scd30 measurement:\n");
						}
					}
				}
				else
				{
					SensError();
				}


				ret = sps30_read_data_ready(&data_ready);
				if (ret == STATUS_OK) {
					if (data_ready) {
						ret = sps30_read_measurement(&m);
						if (ret < 0) {
							SensError();
						}
						else
						{
							printf("sps30 success:\n");
						}
					}
				}
				else
				{
					SensError();
				}


		   //osMailPut(spsMail, pmsr);
		   //osMailPut(scdMail, dmsr);
		   //osMailPut(iaqcMail, qmsr);


		   osDelay(1000);

		}

}

void SensError(void)
{
	HAL_I2C_DeInit(&hi2c1);
	HAL_I2C_Init(&hi2c1);
}

/************************ (C) COPYRIGHT  *****END OF FILE****/
