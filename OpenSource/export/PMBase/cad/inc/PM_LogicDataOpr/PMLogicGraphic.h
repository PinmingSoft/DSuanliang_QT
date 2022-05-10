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
* @brief 数学向量   
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
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

	//计算两个向量的点积
	double dotProduct(const  CPMGeVector2d &v);

	//计算两个向量的叉积当<0 时从本向量开始到v向量按照右手坐标大于180度 > 0时不用加180度（用于判断两个向量的夹角是否》180度 ）
	double CrossProduct (const  CPMGeVector2d &v);
	
	//取得正交向量 延逆时针方向旋转，正交
	CPMGeVector2d perpVector();

	//向量取反
	CPMGeVector2d negate();
	
	CPMGeVector2d operator *  (double scl) const;
	
	BOOL operator == (const CPMGeVector2d& vec) const;

	CPMGeVector2d operator +  (const CPMGeVector2d& vec) const;

    CPMGeVector2d normal();

	double length();
	
	//取得向量和x轴的角度 范围0-2pi
	double angle();
	
	CPMGeVector2d rotateBy(double angle);
	
	double x,y;
};

/**
* @brief  数学矩阵 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [10/4/2012]
*/
class PMLogicDataOprAPI CPMGeMatrix2d  
{
public:
	CPMGeMatrix2d();
	virtual ~CPMGeMatrix2d();


public:
	//取得指定点进行旋转操作矩阵
	static CPMGeMatrix2d rotation(double angle,const CPMGePoint2d center = CPMGePoint2d(0,0));

	//取得平移对象矩阵
	static CPMGeMatrix2d translation(const CPMGeVector2d& vec);

	static CPMGeMatrix2d scaling(double scaleAll,const CPMGePoint2d center = CPMGePoint2d(0,0));

	static CPMGeMatrix2d mirroring( const CPMGePoint2d& pt1,const CPMGePoint2d& pt2);


	//矩阵乘法运算
	CPMGeMatrix2d operator *(const CPMGeMatrix2d& mat) const;
	
	double entry[3][3];
};

class PMLogicDataOprAPI CPMLogicGraphic  
{
public:
	CPMLogicGraphic();
	virtual ~CPMLogicGraphic();

	/**
	* @brief 点阵的 移动向量  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/4/2012]
	*/
	static BOOL TransformBy_PointArr(CArray<CPMGePoint2d*,CPMGePoint2d*&> & ptArr,const CPMGeMatrix2d & moveVer);
};

namespace UIFunction  
{

	//清空回调类型
	typedef BOOL(*BuildOwnGanJinVector_T)(const CArray<CPMGePoint2d*,CPMGePoint2d*&> & ,const CArray<double,double> &,BOOL ,const CStringArray & ,const CStringArray & ,CMemFile *);

	class PMLogicDataOprAPI PM_LogicCallBackFun
	{
	public:
		//注册和取消注册
		static BOOL RegistBuildOwnGanJinVectorCallBack(BuildOwnGanJinVector_T pCalBackFun);
		static BOOL UnRegistBuildOwnGanJinVectorCallBack();

		static BOOL Do_BuildOwnGanJinVector(const CArray<CPMGePoint2d*,CPMGePoint2d*&> & ptArr,const CArray<double,double> & bulgeArr,BOOL bNeedClose,\
			const CStringArray & strParmInfoArr,const CStringArray & strAngleInfoArr,CMemFile * pMemFile);

	private:
		static BuildOwnGanJinVector_T s_pBuildOwnGangJinVector;
	};
}

#endif // !defined(AFX_PMLOGICGRAPHIC_H__D0A1EC9D_42E1_4701_825A_9A2EF6090DF3__INCLUDED_)
