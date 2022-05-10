// PMLogicGraphic.h: interface for the CPMLogicGraphic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMLOGICGRAPHIC_H__D0A1EC9D_42E1_4701_825A_9A2EF6090DF3__INCLUDED_)
#define AFX_PMLOGICGRAPHIC_H__D0A1EC9D_42E1_4701_825A_9A2EF6090DF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPMGeMatrix2d;
class CPMGeVector2d;

class PMLogicDataOprAPI CPMGePoint2d  
{
public:
	CPMGePoint2d();
	
	CPMGePoint2d(double xx,double yy);
	
	CPMGePoint2d(CPoint pt);
	
	CPMGePoint2d(const CPMGePoint2d &pt);
	
	~CPMGePoint2d();
	
	void SetPoint(double xx,double yy);
	
	CPMGePoint2d operator +  (const CPMGeVector2d& vec) const;
	
	CPMGePoint2d operator -  (const CPMGeVector2d& vec) const;

	CPMGeVector2d operator -  (const CPMGePoint2d& pnt) const;
	
    BOOL operator ==  (const CPMGePoint2d & pnt) const;

	double distance(const CPMGePoint2d & point2d);
	
	CPMGePoint2d  &transformBy(const CPMGeMatrix2d& leftSide);

	double x;
	double y;
} ;

/**
* @brief ��ѧ����   
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [10/4/2012]
*/
class PMLogicDataOprAPI CPMGeVector2d  
{
public:
	CPMGeVector2d();
	CPMGeVector2d(double xx,double yy);
	
	CPMGeVector2d(const CPMGePoint2d &startpt,const CPMGePoint2d &endpt);
	CPMGeVector2d(const CPoint &startpt,const CPoint &endpt);
	virtual ~CPMGeVector2d();

	//�������������ĵ��
	double dotProduct(const  CPMGeVector2d &v);

	//�������������Ĳ����<0 ʱ�ӱ�������ʼ��v�������������������180�� > 0ʱ���ü�180�ȣ������ж����������ļн��Ƿ�180�� ��
	double CrossProduct (const  CPMGeVector2d &v);
	
	//ȡ���������� ����ʱ�뷽����ת������
	CPMGeVector2d perpVector();

	//����ȡ��
	CPMGeVector2d negate();
	
	CPMGeVector2d operator *  (double scl) const;
	
	BOOL operator == (const CPMGeVector2d& vec) const;

	CPMGeVector2d operator +  (const CPMGeVector2d& vec) const;

    CPMGeVector2d normal();

	double length();
	
	//ȡ��������x��ĽǶ� ��Χ0-2pi
	double angle();
	
	CPMGeVector2d rotateBy(double angle);
	
	double x,y;
};

/**
* @brief  ��ѧ���� 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [10/4/2012]
*/
class PMLogicDataOprAPI CPMGeMatrix2d  
{
public:
	CPMGeMatrix2d();
	virtual ~CPMGeMatrix2d();


public:
	//ȡ��ָ���������ת��������
	static CPMGeMatrix2d rotation(double angle,const CPMGePoint2d center = CPMGePoint2d(0,0));

	//ȡ��ƽ�ƶ������
	static CPMGeMatrix2d translation(const CPMGeVector2d& vec);

	static CPMGeMatrix2d scaling(double scaleAll,const CPMGePoint2d center = CPMGePoint2d(0,0));

	static CPMGeMatrix2d mirroring( const CPMGePoint2d& pt1,const CPMGePoint2d& pt2);


	//����˷�����
	CPMGeMatrix2d operator *(const CPMGeMatrix2d& mat) const;
	
	double entry[3][3];
};

class PMLogicDataOprAPI CPMLogicGraphic  
{
public:
	CPMLogicGraphic();
	virtual ~CPMLogicGraphic();

	/**
	* @brief ����� �ƶ�����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/4/2012]
	*/
	static BOOL TransformBy_PointArr(CArray<CPMGePoint2d*,CPMGePoint2d*&> & ptArr,const CPMGeMatrix2d & moveVer);
};

namespace UIFunction  
{

	//��ջص�����
	typedef BOOL(*BuildOwnGanJinVector_T)(const CArray<CPMGePoint2d*,CPMGePoint2d*&> & ,const CArray<double,double> &,BOOL ,const CStringArray & ,const CStringArray & ,CMemFile *);

	class PMLogicDataOprAPI PM_LogicCallBackFun
	{
	public:
		//ע���ȡ��ע��
		static BOOL RegistBuildOwnGanJinVectorCallBack(BuildOwnGanJinVector_T pCalBackFun);
		static BOOL UnRegistBuildOwnGanJinVectorCallBack();

		static BOOL Do_BuildOwnGanJinVector(const CArray<CPMGePoint2d*,CPMGePoint2d*&> & ptArr,const CArray<double,double> & bulgeArr,BOOL bNeedClose,\
			const CStringArray & strParmInfoArr,const CStringArray & strAngleInfoArr,CMemFile * pMemFile);

	private:
		static BuildOwnGanJinVector_T s_pBuildOwnGangJinVector;
	};
}

#endif // !defined(AFX_PMLOGICGRAPHIC_H__D0A1EC9D_42E1_4701_825A_9A2EF6090DF3__INCLUDED_)
