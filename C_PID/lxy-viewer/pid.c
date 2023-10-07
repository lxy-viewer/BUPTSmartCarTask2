#include<stdlib.h>
#include<string.h>
#include "pid.h"
#include<stdio.h>

PID* PID_Init() {
	PID* pid;
	pid = malloc(sizeof(PID));
	return pid;
}

PID* PID_SetParameter(PID* pid) {
	memset(pid, 0, sizeof(PID));
	printf("��ʼֵΪ0�����룺\nĿ��ֵ Kp Ki Kd �����޷�\n");
	scanf("%f %f %f %f %f", &pid->target, &pid->Kp, &pid->Ki, &pid->Kd, &pid->error_sum_max);
	return pid;
}


void PID_PostionalPID(PID* pid) {

	pid->error = pid->target - pid->current;
	pid->error_sum > +pid->error_sum_max ? +pid->error_sum_max : pid->error_sum + pid->error;
	pid->error_sum < -pid->error_sum_max ? -pid->error_sum_max : pid->error_sum + pid->error;
	pid->current = pid->output += (pid->Kp * pid->error + pid->Ki * pid->error_sum + pid->Kd * (pid->error - pid->error_last));
	pid->error_last = pid->error;
	printf("E:%f\n", pid->output);
	return;

}


void PID_IncrementalPID(PID* pid) {

	float ep, ei, ed;

	pid->error = pid->target - pid->current;
	ep = pid->error - pid->error_last;
	ei = pid->error;
	ed = pid->error - 2 * pid->error_last + pid->error_llast;
	pid->output = pid->current = pid->Kp * ep + pid->Ki * ei + pid->Kd * ed;
	pid->error_llast = pid->error_last;
	pid->error_last = pid->error;
	printf("E:%f\n", pid->output);
	return;

}