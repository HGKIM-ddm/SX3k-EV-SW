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

void FDL_Write(void)
{
	G_Timer1msFlag.FdlErrorCheckFlag = 0U;
	G_Timer1ms.FdlErrorCheck = 0U;
	close_memory_write = step_position_close;
	open_memory_write = step_position_open;
	now_step_memory_write = step_position;
	Initial_memory_write = evrdy_on_flag;
	limit_memory_write = limit_step_position;

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

	w_buff[18] = FW_VERSION & 0x00FFU;
	w_buff[19] = (FW_VERSION & 0xFF00U) >> 8U;   // 0x00

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

	ret = function_FDL_write(w_buff, 0U, 10U); // KR

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

	ret = function_FDL_read(r_buff, 0U, 5U);

	G_Timer1msFlag.FdlErrorCheckFlag = 1U;

	if (ret < (char)0) // error
	{
		//초기화
		close_memory_read           = 0U;
        open_memory_read            = 0U;
        now_step_memory_read        = 0U;
        position_memory_read        = UNKOWN_POSITION;
        Initial_memory_read         = OFF;
        limit_memory_read           = 0U;
        position_status_memory_read = Unknown_Status;
        AAFx_InitStatus_memory_read = DURING_INITIALIZATION;
        DTC_memory_read             = 0U;
        power_chk_memory_read       = Shutdown_Check;
        First_Powerchk_memory_read  = 0U;
        fw_version_memory_read      = 0xFFFFU;    

		while (1)
		{
			if (G_Timer1ms.FdlErrorCheck >= 100U)
			{
				fdl_fail += 1U;
				break;
			}
		}

		return;
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
	
	fw_version_memory_read = (unsigned int)(r_buff[4U] >> 16U) & 0xFFFFu; // 버전 읽기 (r_buff[4] 상위 16bit)

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
