// doubleless.h: interface for the doubleless class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOUBLELESS_H__7C699C6F_70A8_4102_A2B9_D167FF34722A__INCLUDED_)
#define AFX_DOUBLELESS_H__7C699C6F_70A8_4102_A2B9_D167FF34722A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <math.h>

//���ȿ���,Ŀǰ����6λ
// #define  E  0.000001
// ��E��boost��ͻ����Ҫ������
#define  EZERO 0.0000000001   
// QC19838 ��EZERO��6λ�ĳ�7λ  dwg 2015.12.25  // QC22230 ��EZERO��7λ�ĳ�8λ  dwg 2016.9.19
//QC23732 //��EZERO��Ϊ9λ //QC24423 ��EZERO��Ϊ10λ


inline bool doubleLess(const double &x,const double &y, double dTol = EZERO)
{
    if (fabs(x - y) < dTol) //�������������ʱ������������ѭ���ж��Ƿ�less����������ﵱ���ʱ��Ҳ����Ϊfalse
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
