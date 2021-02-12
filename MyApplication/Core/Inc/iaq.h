

#ifndef IAQ_H_
#define IAQ_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * Main config.
 */
#define IAQ_ADDRESS 0xB4


// iAQ_Core DATA. NOTE: The I2C master can request up to 9 bytes.
/**
  * @brief   STATUS FLAG. NOTE: If status is OK the data is valid. If the status is BUSY, the data integrity is not guaranteed for
  *                             variables of size > 8 bits, because the module may be updating a part of the variable. If the status
  *                             is ERROR constantly (or very frequently) this indicates that the module is reading non-realistic values,
  *                             and the sensor element is probably defective.
  */
typedef enum {
	iAQ_Core_STATUS_OK        =   0x00,         /*!<  Status Flag: OK      ( data valid )                               */
	iAQ_Core_STATUS_BUSY      =   0x01,         /*!<  Status Flag: BUSY    ( re-read multi byte data! )                 */
	iAQ_Core_STATUS_RUNIN     =   0x10,         /*!<  Status Flag: RUNIN   ( module in warm up phase )                  */
	iAQ_Core_STATUS_ERROR     =   0x80          /*!<  Status Flag: ERROR   ( if constant: replace sensor )              */
} iAQ_Core_status_flag_t;

typedef struct {
	uint16_t                pred;               /*!<  Prediction (CO2 eq. ppm),  Typical Value: 450                     */
	iAQ_Core_status_flag_t  status;             /*!<  Status,                    Typical Value: 0                       */
	int32_t                 resistance;         /*!<  Sensor resistance [Ohm],   Typical Value: 256431                  */
	uint16_t                Tvoc;               /*!<  Prediction (TVOC eq. ppb), Typical Value: 125                     */
} iAQ_Core_data_t;


/**
  * @brief   INTERNAL CONSTANTS
  */
typedef enum {
	iAQ_Core_SUCCESS    =       0,
	iAQ_Core_FAILURE    =       1,
	I2C_SUCCESS         =       0                           /*!<   I2C communication was fine                                                          */
} iAQ_Core_status_t;


void iAQ_Core_init(void);
iAQ_Core_status_t iAQ_Core_GetNewReading(uint16_t* pred, uint16_t* status,
                               uint32_t* resistance, uint16_t* Tvoc);

#ifdef __cplusplus
}
#endif
		
#endif /* IAQ_H_ */
