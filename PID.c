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

//单步更新函数 输入为误差  输出为调制比
//在PID调节过程中 误差小增大积分函数消除静差
//                误差大减小积分函数防止饱和
double PID_realize(struct _pid *Current,double It)
{
	int index=0;
	Current->SetSpeed=It;
	Current->err=Current->SetSpeed-Current->ActualSpeed;
	if(abs(pid.err)>500)
		index=0;
	else
		index=1;
	Current->integral+=Current->err*index;
	Current->voltage=Current->Kp*Current->err+Current->Ki*Current->integral
			+Current->Kd*((Current->err*index)-Current->err_last);
	Current->err_last=index*Current->err;
	//pid.ActualSpeed=pid.voltage*1.0;
	return Current->voltage;
}
