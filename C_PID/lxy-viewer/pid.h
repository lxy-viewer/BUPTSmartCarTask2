#pragma once
#ifndef _PID_H
#define _PID_H

typedef struct {

	float
		output,           
		target,           
		current,          
		error,            
		error_sum,        
		error_last,       
		error_llast,      
		error_sum_max,   
		Kp, Ki, Kd;       

}PID;

PID* PID_Init();              
PID* PID_SetParameter(PID* popid);      
void PID_PostionalPID(PID* pid);      
void PID_IncrementalPID(PID* pid);   

#endif