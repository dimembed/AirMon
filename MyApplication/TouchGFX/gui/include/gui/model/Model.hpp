#ifndef MODEL_HPP
#define MODEL_HPP

#include "scd30.h"


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    SCD30MSG getDataScd() { return model_scd_ret; }

protected:
    ModelListener* modelListener;
    SCD30MSG model_scd_ret;
};

#endif // MODEL_HPP
