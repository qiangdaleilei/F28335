/*
 * PID.h
 *
 *  Created on: 2017-3-21
 *      Author: sland
 */

#ifndef PID_H_
#define PID_H_

#include <stdio.h>
#include <string.h>

#define G2 1.1412136  //根号2

struct _pid
{
	double SetSpeed;     //定义设定值
	double ActualSpeed;  //定义实际值
	double err;          //定义偏差值
	double err_last;     //定义上一个偏差值
	double Kp,Ki,Kd;     //定义比例、积分、微分系数
	double voltage;      //控制执行器的变量
	double integral;     //定义积分值
}pid

#endif /* PID_H_ */
