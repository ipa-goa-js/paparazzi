#ifndef LINK_IMU_H
#define LINK_IMU_H

#include <inttypes.h>

#include "6dof.h"

/* angles are transmitted as int16 : PI -> 16384 */
/* rates are transmitted as int16 : 1 PI s-1 -> 16384 */
#define ANGLE_PI 0X3FFF
#define RATE_PI_S 0X3FFF

#define IMU_UNINIT  0
#define IMU_RUNNING 1
#define IMU_CRASHED 2

struct imu_state {
  int16_t rates[AXIS_NB];
  int16_t eulers[AXIS_NB];
  uint8_t status;
  uint8_t pad;
  uint16_t crc;
};


extern struct imu_state link_imu_state;
extern void link_imu_init ( void );

#ifdef IMU

extern void link_imu_send( void );

#endif /* IMU */


#ifdef CONTROLLER

extern uint32_t link_imu_nb_err;
extern void link_imu_event_task( void );

#endif /* CONTROLLER */


#endif /* LINK_IMU_H */
