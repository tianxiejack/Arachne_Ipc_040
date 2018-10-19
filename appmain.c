#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include"Arachne_Ipc_Message.h"

void recv_printf(IPC_msg value, int n) {
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("msg_type:%ld\n", value.msg_type);
	printf("video_switch :%d\n", value.payload.sen_mes.video_switch);
	printf("sen_mes.Infrared_state: %d\n",
			value.payload.sen_mes.Infrared_state);
	printf("Laser_state: %d\n", value.payload.sen_mes.Laser_state);
	printf("character_color: %d\n", value.payload.sen_mes.character_color);
	printf("mage_Enhance: %d\n", value.payload.sen_mes.Image_Enhance);
	printf("character_state: %d\n", value.payload.sen_mes.character_state);
	printf("Sensor_Tv_Angle: %0.1f\n", value.payload.Sensor_Tv_Angle);
	printf("laser_state : %d\n", value.payload.Laser_Mes.laser_state);
	printf("laser_mes_d: %d\n", value.payload.Laser_Mes.laser_mes_d);
	printf("laser_code: %d\n", value.payload.Laser_Mes.laser_code);
	printf("cur_mode: %d\n", value.payload.Work_Pattern.cur_mode);
	printf("Comp_SelfCheck: %d\n", value.payload.Work_Pattern.Comp_SelfCheck);
	printf("LMC: %d\n", value.payload.Work_Pattern.LMC);
	printf("Shaft_Start : %d\n", value.payload.Work_Pattern.Shaft_Start);
	printf("Shart_Exit: %d\n", value.payload.Work_Pattern.Shart_Exit);
	printf("HighOrder_Hor: %d\n", value.payload.Track_Search.HighOrder_Hor);
	printf("HighOrder_Ver: %d\n", value.payload.Track_Search.HighOrder_Ver);
	printf("MulTarget_Detect: %d\n",
			value.payload.Track_Search.MulTarget_Detect);
	printf("LowOrder_Hor: %d\n", value.payload.Track_Search.LowOrder_Hor);
	printf("LowOrder_Ver: %d\n", value.payload.Track_Search.LowOrder_Ver);
	printf("move_track_hor: %d\n", value.payload.Track_Trim.move_track_hor);
	printf("move_track_ver: %d\n", value.payload.Track_Trim.move_track_ver);
	printf("move_cross_hor: %d\n", value.payload.Track_Trim.move_cross_hor);
	printf("move_cross_ver: %d\n", value.payload.Track_Trim.move_cross_ver);
	printf(" Target_Distance: %d\n", value.payload.Target_Distance);
	printf(" TurretAngle_Hor: %0.2f\n", value.payload.TurretAngle_Hor);
	printf("TurretAngle_Ver: %0.2f\n", value.payload.TurretAngle_Ver);
	printf("time_flag: %d\n", value.payload.Td.time_flag);
	printf("time_date: %d\n", value.payload.Td.time_date);
	printf("Mul_Number: %d\n", value.payload.MulTarget_Num.Mul_Number);
	printf("TV_SizeChage: %d\n", value.payload.MulTarget_Num.TV_SizeChage);
	printf(" bomen_size: %d\n", value.payload.MulTarget_Num.bomen_size);
	printf("White_Black: %d\n", value.payload.MulTarget_Num.White_Black);
	printf(" Roam_Bomen_Switch: %d\n",
			value.payload.Sensor_Image_EN.Roam_Bomen_Switch);
	printf("track_grade: %d\n", value.payload.Sensor_Image_EN.track_grade);
	printf("En_AutoFocus : %d\n", value.payload.Sensor_Image_EN.En_AutoFocus);
	printf("Infrared_Change : %d\n",
			value.payload.Sensor_Image_EN.Infrared_Change);
	printf("Sensor_Thermal: %d\n",
			value.payload.Sensor_Image_EN.Sensor_Thermal);
	printf("Sensor_Tv_Enhance : %d\n",
			value.payload.Sensor_Image_EN.Sensor_Tv_Enhance);
	printf("interface_rate: %d\n", value.payload.Video_C.interface_rate);
	printf("video_transfer: %d\n", value.payload.Video_C.video_transfer);
	printf("video_frame: %d\n", value.payload.Video_C.video_frame);
	printf("Thermal_frame: %d\n", value.payload.Video_C.Thermal_frame);
	printf("Sensor_Thermal_Angle: %0.1f\n", value.payload.Sensor_Thermal_Angle);
	printf("#####################################################\n");
	sleep(n);
}

int main(int argc, char* argv[]) {
	IPC_msg recv_msg;
	Return_pack send_msg;

	InitIPCModule();
	send_msg.CycleTime = 33;
	send_msg.payload.message_id = 0x65;
	send_msg.payload.Track_Deviation_X = 0x1;
	send_msg.payload.Track_Deviation_Y = 0x1;
	send_msg.payload.Track_Thermal = 0x1;
	send_msg.payload.Track_Tv = 0x1;
	send_msg.payload.current_video = 0x1;
	send_msg.payload.Senser_Aim_CurX = 0x1;
	send_msg.payload.Senser_Aim_CurY = 0x1;
	send_msg.payload.Self_Tr_S.self_state = 0x1;
	send_msg.payload.Self_Tr_S.video_input = 0x1;
	send_msg.payload.Self_Tr_S.roam_boot = 0x1;
	send_msg.payload.Self_Tr_S.mul_target_AVT = 0x1;
	send_msg.payload.Self_Tr_S.track_state = 0x1;
	send_msg.payload.Compress_Transfer = 0x1;
	send_msg.payload.Power_On = 0x1;
	send_msg.payload.r_interface_rate = 0x1;
	send_msg.payload.r_thermal_frame = 0x1;
	send_msg.payload.r_tv_frame = 0x1;
	SetReturnPack(&send_msg);
	while (1) {
		recv_msg = GetMessage();
		recv_printf(recv_msg, 5);
	}
	return 0;
}
