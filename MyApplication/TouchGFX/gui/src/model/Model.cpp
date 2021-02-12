#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "app_sensapi.h"

osStatus_t status;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	//SCD30MSG msg;

    status = osMessageQueueGet(scd30_MsgQueue, &model_scd_ret, NULL, 0U);   // wait for message
    if (status == osOK) {

    	//model_scd_ret = msg;
    	modelListener->dataChangedScd();

    }

}
