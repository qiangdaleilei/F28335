#include <stdio.h>
#include "PID.h"

//装载初始参数
void PID_init(struct _pid *Current)
{
	Current->SetSpeed=0.0;
	Current->ActualSpeed=0.0;
	Current->err=0.0;
	Current->err_last=0.0;
	Current->voltage=0.0;
	Current->integral=0.0;
	Current->Kp=0.15;
	Current->Ki=80;
	Current->Kp=0.0;
}
