#include<stdio.h>
#include "pid.h"

int main()
{
	PID* pid = PID_Init();
	int i, k;
	printf("������ѭ������:\n");
	scanf("%d", &i);
	printf("ѡ��λ��ʽPID����1��ѡ������ʽPID����2:\n");
	scanf("%d", &k);
	PID_SetParameter(pid);

	while (i > 0)
	{
		i--;
		if (k == 1)
			PID_PostionalPID(pid);
		else if (k == 2)
			PID_IncrementalPID(pid);
	}

	return 0;
}