#include "Fdl.h"
#include "Service.h"

void FDL_Init(void)
{
	FDL_Open();
	ret = function_FDL_init();

	G_Timer1msFlag.FdlErrorCheckFlag = 1U;
	if (ret < (char)0) // error
	{
		while (1)
		{
			if (G_Timer1ms.FdlErrorCheck >= 100U)
			{
				fdl_fail += 1U;
				break;
			}
		}
	}

	G_Timer1msFlag.FdlErrorCheckFlag = 0U;
	G_Timer1ms.FdlErrorCheck = 0U;
}

static uint8_t FDL_GetMicrostepDivider(uint8_t microstep)
{
    uint8_t divider;

    switch (microstep)
    {
    case CONFIG_MICROSTEP_FULL_71:
        divider = 1U;
        break;

    case CONFIG_MICROSTEP_1_2:
        divider = 2U;
        break;

    case CONFIG_MICROSTEP_1_4:
        divider = 4U;
        break;

    case CONFIG_MICROSTEP_1_8:
        divider = 8U;
        break;

    case CONFIG_MICROSTEP_1_16:
        divider = 16U;
        break;

    case CONFIG_MICROSTEP_1_32:
        divider = 32U;
        break;

    default:
        divider = 8U;
        break;
    }

    return divider;
}

static unsigned int FDL_ConvertStepToDefaultMicrostep(unsigned int step_count)
{
    unsigned long converted_value;
    unsigned long current_divider;
    unsigned long default_divider;

    current_divider = (unsigned long)FDL_GetMicrostepDivider(motor_microstep_current);
    default_divider = (unsigned long)FDL_GetMicrostepDivider(CONFIG_MOTOR_MICROSTEP_DEFAULT);

    converted_value =
        (((unsigned long)step_count * default_divider) +
         (current_divider / 2UL)) /
        current_divider;

    if (converted_value > 0xFFFFUL)
    {
        converted_value = 0xFFFFUL;
    }

    return (unsigned int)converted_value;
}



void FDL_Write(void)
{
	// close_memory_write = step_position_close;
	// open_memory_write = step_position_open;
	// now_step_memory_write = step_position;
	// Initial_memory_write = evrdy_on_flag;
	// limit_memory_write = limit_step_position;

	close_memory_write = FDL_ConvertStepToDefaultMicrostep(step_position_close);
	open_memory_write = FDL_ConvertStepToDefaultMicrostep(step_position_open);
	now_step_memory_write = FDL_ConvertStepToDefaultMicrostep(step_position);
	Initial_memory_write = evrdy_on_flag;
	limit_memory_write = FDL_ConvertStepToDefaultMicrostep(limit_step_position);

	if ((AAF_LINOut == 0x00U) && (IGN_Chk == 2U))
	{
		position_memory_write = AAF_Tx_Position_Temporary;
		position_status_memory_write = AAFx_Position_Status_Temporary;
		AAFx_InitStatus_memory_write = AAFx_InitStatus_Temporary;
	}
	else
	{
		position_memory_write = AAF_Tx_Position;
		position_status_memory_write = AAFx_Position_Status;
		AAFx_InitStatus_memory_write = AAFx_InitStatus;
	}

	DTC_memory_write |= DTC_Status;
	power_chk_memory_write = power_chk;
	First_Powerchk_memory_write = First_Powerchk;
	//only sx3k
	// OBD1_Close_Check_memory_write = OBD1_Close_Check;
	// OBD1_Open_Check_memory_write = OBD1_Open_Check;
	// OBD2_Close_Check_memory_write = OBD2_Close_Check;
	// OBD2_Open_Check_memory_write = OBD2_Open_Check;
	// OBD3_Close_Check_memory_write = OBD3_Close_Check;
	// OBD3_Open_Check_memory_write = OBD3_Open_Check;

	w_buff[0] = close_memory_write & 0x00FFU; // write 2byte read 4byte ?븯?쐞
	w_buff[1] = (close_memory_write & 0xFF00U) >> 8U;

	w_buff[2] = open_memory_write & 0x00FFU; // write 2byte read 4byte ?긽?쐞
	w_buff[3] = (open_memory_write & 0xFF00U) >> 8U;

	w_buff[4] = now_step_memory_write & 0x00FFU; // write 2byte read 4byte
	w_buff[5] = (now_step_memory_write & 0xFF00U) >> 8U;

	w_buff[6] = position_memory_write & 0xFFU; // write 2byte read 4byte position+evrdy
	w_buff[7] = (Initial_memory_write & 0xFFU);

	w_buff[8] = limit_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	w_buff[9] = (limit_memory_write & 0xFF00U) >> 8U;

	w_buff[10] = position_status_memory_write & 0x0FU; // write 2byte read 4byte limitstep
	w_buff[11] = (AAFx_InitStatus_memory_write & 0x0FU);

	w_buff[12] = DTC_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	w_buff[13] = (DTC_memory_write & 0xFF00U) >> 8U;

	w_buff[14] = power_chk_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	w_buff[15] = (power_chk_memory_write & 0xFF00U) >> 8U;

	w_buff[16] = First_Powerchk_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	w_buff[17] = (First_Powerchk_memory_write & 0xFF00U) >> 8U;

	// w_buff[18] = OBD1_Close_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[19] = (OBD1_Close_Check_memory_write & 0xFF00U) >> 8U;

	// w_buff[20] = OBD1_Open_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[21] = (OBD1_Open_Check_memory_write & 0xFF00U) >> 8U;

	// w_buff[22] = OBD2_Close_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[23] = (OBD2_Close_Check_memory_write & 0xFF00U) >> 8U;

	// w_buff[24] = OBD2_Open_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[25] = (OBD2_Open_Check_memory_write & 0xFF00U) >> 8U;

	// w_buff[26] = OBD3_Close_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[27] = (OBD3_Close_Check_memory_write & 0xFF00U) >> 8U;

	// w_buff[28] = OBD3_Open_Check_memory_write & 0x00FFU; // write 2byte read 4byte limitstep
	// w_buff[29] = (OBD3_Open_Check_memory_write & 0xFF00U) >> 8U;

	ret = function_FDL_erease(0U, 1U);

	G_Timer1msFlag.FdlErrorCheckFlag = 1U;

	if (ret < (char)0) // error
	{
		while (1)
		{
			if (G_Timer1ms.FdlErrorCheck >= 100U)
			{
				fdl_fail += 1U;
				break;
			}
		}
	}

	ret = function_FDL_write(w_buff, 0U, 9U); // KR

	G_Timer1msFlag.FdlErrorCheckFlag = 1;

	if (ret < 0) // error
	{
		while (1)
		{
			if (G_Timer1ms.FdlErrorCheck >= 100U)
			{
				fdl_fail += 1U;
				break;
			}
		}
	}

	G_Timer1msFlag.FdlErrorCheckFlag = 0U;
	G_Timer1ms.FdlErrorCheck = 0U;
}

void FDL_Read(void)
{

	ret = function_FDL_read(r_buff, 0U, 15U);

	G_Timer1msFlag.FdlErrorCheckFlag = 1U;

	if (ret < (char)0) // error
	{
		while (1)
		{
			if (G_Timer1ms.FdlErrorCheck >= 100U)
			{
				fdl_fail += 1U;
				break;
			}
		}
	}

	G_Timer1msFlag.FdlErrorCheckFlag = 0U;
	G_Timer1ms.FdlErrorCheck = 0U;

	close_memory_read = (unsigned int)r_buff[0U] & 0xFFFFu;
	open_memory_read = (unsigned int)(r_buff[0U] >> 16U) & 0xFFFFu;

	now_step_memory_read = (unsigned int)r_buff[1U] & 0xFFFFu;

	position_Initial_combined_read = (unsigned int)(r_buff[1U] >> 16U) & 0xFFFFu;
	position_memory_read = (unsigned int)position_Initial_combined_read & 0xFFu;
	Initial_memory_read = (unsigned int)(position_Initial_combined_read >> 8U) & 0xFFu;

	limit_memory_read = (unsigned int)r_buff[2U] & 0xFFFFu;

	position_Initstatus_combined_read = (unsigned int)(r_buff[2U] >> 16U) & 0xFFFFu;
	position_status_memory_read = (unsigned int)position_Initstatus_combined_read & 0x0Fu;
	AAFx_InitStatus_memory_read = (unsigned int)(position_Initstatus_combined_read >> 8U) & 0x0Fu;

	DTC_memory_read = (unsigned int)(r_buff[3U]) & 0xFFFFu;

	power_chk_memory_read = (unsigned int)(r_buff[3U] >> 16U) & 0xFu;
	First_Powerchk_memory_read = (unsigned int)(r_buff[4U]) & 0xFu;
	//only sx3k
	//OBD1_Close_Check_memory_read = (unsigned int)(r_buff[4U] >> 16U) & 0xFFFFu;
	//OBD1_Open_Check_memory_read = (unsigned int)(r_buff[5U]) & 0xFFFFu;
	//OBD2_Close_Check_memory_read = (unsigned int)(r_buff[5U] >> 16U) & 0xFFFFu;
	//OBD2_Open_Check_memory_read = (unsigned int)(r_buff[6U]) & 0xFFFFu;
	//OBD3_Close_Check_memory_read = (unsigned int)(r_buff[6U] >> 16U) & 0xFFFFu;
	//OBD3_Open_Check_memory_read = (unsigned int)(r_buff[7U]) & 0xFFFFu;
	
	if (position_status_memory_read >= Memory_Range_Break)
	{
		position_status_memory_read = Memory_Range_Init;
	}
	if (AAFx_InitStatus_memory_read >= Memory_Range_Break)
	{
		AAFx_InitStatus_memory_read = Memory_Range_Init;
	}
}


void Position_Temporary_write(void)
{
    AAF_Tx_Position_Temporary = AAF_Tx_Position;
    AAFx_Position_Status_Temporary = AAFx_Position_Status;
    AAFx_InitStatus_Temporary = AAFx_InitStatus;

    AAF_Tx_Position = UNKOWN_POSITION;
    AAFx_Position_Status = Unknown_Status;
    AAFx_InitStatus = DURING_INITIALIZATION;
}

void Position_Temporary_read(void)
{
    AAF_Tx_Position = AAF_Tx_Position_Temporary;
    AAFx_Position_Status = AAFx_Position_Status_Temporary;
    AAFx_InitStatus = AAFx_InitStatus_Temporary;
}