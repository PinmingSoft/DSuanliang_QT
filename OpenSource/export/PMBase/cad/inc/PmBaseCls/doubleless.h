// doubleless.h: interface for the doubleless class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOUBLELESS_H__7C699C6F_70A8_4102_A2B9_D167FF34722A__INCLUDED_)
#define AFX_DOUBLELESS_H__7C699C6F_70A8_4102_A2B9_D167FF34722A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <math.h>

//精度控制,目前控制6位
// #define  E  0.000001
// 因E与boost冲突，需要改名字
#define  EZERO 0.0000000001   
// QC19838 将EZERO由6位改成7位  dwg 2015.12.25  // QC22230 将EZERO由7位改成8位  dwg 2016.9.19
//QC23732 //将EZERO改为9位 //QC24423 将EZERO改为10位


inline bool doubleLess(const double &x,const double &y, double dTol = EZERO)
{
    if (fabs(x - y) < dTol) //由于在排序操作时，将进行两次循环判断是否less，因此在这里当相等时，也返回为false
    {
		return false;
    }
	return x<y;
}
inline bool doubleLessOrEqual(const double &x,const double &y, double dTol = EZERO)
{
    if (fabs(x - y) < dTol)
    {
		return true;
    }
	return x<y;
}
inline bool doubleIsEqual(const double &x,const double &y, double dTol = EZERO)
{
    if (fabs(x - y) < dTol)
    {
		return true;
    }
	return false;
}

#endif // !defined(AFX_DOUBLELESS_H__7C699C6F_70A8_4102_A2B9_D167FF34722A__INCLUDED_)
