
#ifndef MOTOR_H
#define MOTOR_H


/****************** Include Files ********************/
#include "xbasic_types.h"
#include "xstatus.h"
#include "xil_io.h"
#include "car.h"

#define MOTOR_S00_AXI_SLV_REG0_OFFSET 0
#define MOTOR_S00_AXI_SLV_REG1_OFFSET 4
#define MOTOR_S00_AXI_SLV_REG2_OFFSET 8
#define MOTOR_S00_AXI_SLV_REG3_OFFSET 12



typedef struct {
	u32 BaseAddress;
	u32 IsReady;
} Motor;



/**************************** Type Definitions *****************************/
/**
 *
 * Write a value to a MOTOR register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the MOTORdevice.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void MOTOR_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Data)
 *
 */
#define MOTOR_mWriteReg(BaseAddress, RegOffset, Data) \
  	Xil_Out32((BaseAddress) + (RegOffset), (Xuint32)(Data))

/**
 *
 * Read a value from a MOTOR register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the MOTOR device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	Xuint32 MOTOR_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define MOTOR_mReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))

/************************** Function Prototypes ****************************/
/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the MOTOR instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus MOTOR_Reg_SelfTest(void * baseaddr_p);

int Motor_Initialize(Motor *InstancePtr,u32 EffectiveAddr);	

void Motor_SetDirection(Motor *InstancePtr,unsigned Motor_Channel,u32 Direction);	

u32 Motor_GetDirection(Motor *InstancePtr,unsigned Motor_Channel);

void Motor_SetPWMDuty(Motor *InstancePtr,unsigned Motor_Channel,u32 PWM_Duty);

u32 Motor_GetPWMDuty(Motor *InstancePtr,unsigned Motor_Channel);


#endif // MOTOR_H
