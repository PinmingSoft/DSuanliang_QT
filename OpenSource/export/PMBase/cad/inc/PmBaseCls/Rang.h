#pragma once
/**
 * @brief  :区间计算
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[8/28/2018]
 * @note   :
 */
namespace pmcommon{
//区间[Lower,Upper]
class PMBASECLASSAPI CRange
{
public:
	CRange();
	//如果bottom大于top，会自动翻转两个值
	CRange(double dBottomBG,double dTopBG);
	CRange(const CRange & fbfw);
	void operator=(const CRange & fbfw);

	/**
	* @brief   设置区间范围
	*
	*			如果bottom大于top，会自动翻转两个值
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	void Set(double dBottomBG,double dTopBG);

	//获取区间的左右两个值
	double GetLower() const{return m_dBottomBG;}
	double GetUpper() const{return m_dTopBG;};	

	//是否在范围内
	BOOL IsIn(double dBG) const;
	BOOL IsIn(const CRange & fbfw) const;

	//是否相同
	BOOL IsSame(const CRange & fbfw,double kTol=1) const;

	//区间是否相交
	BOOL IsInsect(const CRange & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;
	BOOL GetInsect(const CRange & fbfw,CRange & insectfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//合并区间，无论是否右相交都强制合并
	void Combine(const CRange &fbfw);

	//获取区间长度
	double GetLen()const;

private:
	//最高点分布范围--已减去起始距离
	double m_dTopBG;
	//最低点分布范围--已加上起始距离
	double m_dBottomBG;
};

/**
 * @brief  :区间集，内部运算会确保区间范围不重复，并确保区间是有序
 *
 *          传入时的参数要求：范围间不要重复
 * @author :zfy
 * @version:v1.0
 * @date   :[8/28/2018]
 * @note   :
 */
class PMBASECLASSAPI CRanges
{
public:
	CRanges();
	CRanges(const CRange & fbfw);
	CRanges(const CRanges & fbfw);
	~CRanges();
	void operator=(const CRanges & fbfw);
	void operator=(const CRange & fbfw);

	//分布范围
	CArray<CRange,CRange> m_arrFbfw;

	/**
	* @brief   设置分布范围(注意:要求范围间不要重复)，并自动对区间进行排序
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/13/2018]
	*/
	void Set(const CArray<CRange,CRange> & arrFbfw);
	void Get(CArray<CRange,CRange> & arrFbfw);

	//是否在范围内[A,B]
	BOOL IsIn(double data) const;

	//在data处进行分裂
	BOOL SplitAt(double data);

	//获取区间长度
	double GetLen() const;

	//排序
	void Sort();

	//合并区间
	void CombineRange(const CRange &range);

	//剪切区间
	void SubtractRange(const CRange &range,double kTol=1);
	void SubtractRange(const CRanges &ranges,double kTol=1);
};

//区间集
class PMBASECLASSAPI CXYRange
{
public:
	CXYRange(){m_bVirtual=FALSE;}
	CXYRange(const CRange & rangeX,const CRange & rangeY);
	CXYRange(const CXYRange & ranges);
	void operator=(const CXYRange & fbfw);

	//虚范围
	void SetVirtual(BOOL bVirtual);
	void SetRange(const CRange & rangeX,const CRange & rangeY);

	//是否在范围内[A,B]
	BOOL IsIn(const CXYRange & data) const;

	//是否相同
	BOOL IsSame(const CXYRange & fbfw,double kTol=1) const;

	//区间是否相交
	BOOL IsInsect(const CXYRange & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//获取区间面积
	double GetArea()const;

	/**
	* @brief   无论是否相交，强制合并区间，X区间强制合并,Y区间强制合并
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/26/2019]
	*/
	void CombineRange(const CXYRange &range);

	/**
	* @brief   相交区间
	*
	*			如果有相交区域，则返回相交区域
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	BOOL GetInsectRange(const CXYRange &range,CXYRange & rangeInsect,double kTol=1) const;

	CRange m_rangeX;
	CRange m_rangeY;

private:
	//虚范围，表示被扣除的范围。默认是真实范围，为TRUE
	BOOL m_bVirtual;
};

//XY区间
class PMBASECLASSAPI CXYRanges
{
public:
	CXYRanges(const CXYRange & range);
	CXYRanges(const CXYRanges & ranges);
	void operator=(const CXYRanges & fbfw);

	//分布范围
	CArray<CXYRange,CXYRange> m_arrFbfw;

	//是否在范围内[A,B]
	BOOL IsIn(const CXYRange & data) const;

	//是否相同
	BOOL IsSame(const CXYRanges & fbfw,double kTol=1) const;

	//区间是否相交
	BOOL IsInsect(const CXYRanges & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//获取区间面积
	double GetArea()const;

	/**
	* @brief   合并区间，去除重复部分
	*
	*			去除重复的逻辑是：一个保持原状，另外一个去除重复部分
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	BOOL CombineRange(const CXYRange &range,double kTol=1);
	BOOL CombineRange(const CXYRanges &range,double kTol=1);

	/**
	* @brief   相交区间
	*
	*			如果有相交区域，则返回相交区域
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	BOOL GetInsectRange(const CXYRange &range,CXYRanges & rangeInsect,double kTol=1);
	BOOL GetInsectRange(const CXYRanges &range,CXYRanges & rangeInsect,double kTol=1);

	//剪切区间
	void SubtractRange(const CXYRange &range,double kTol=1);
	void SubtractRange(const CXYRanges &ranges,double kTol=1);

private:

};
}