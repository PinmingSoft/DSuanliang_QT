#pragma once
/**
 * @brief  :�������
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[8/28/2018]
 * @note   :
 */
namespace pmcommon{
//����[Lower,Upper]
class PMBASECLASSAPI CRange
{
public:
	CRange();
	//���bottom����top�����Զ���ת����ֵ
	CRange(double dBottomBG,double dTopBG);
	CRange(const CRange & fbfw);
	void operator=(const CRange & fbfw);

	/**
	* @brief   �������䷶Χ
	*
	*			���bottom����top�����Զ���ת����ֵ
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	void Set(double dBottomBG,double dTopBG);

	//��ȡ�������������ֵ
	double GetLower() const{return m_dBottomBG;}
	double GetUpper() const{return m_dTopBG;};	

	//�Ƿ��ڷ�Χ��
	BOOL IsIn(double dBG) const;
	BOOL IsIn(const CRange & fbfw) const;

	//�Ƿ���ͬ
	BOOL IsSame(const CRange & fbfw,double kTol=1) const;

	//�����Ƿ��ཻ
	BOOL IsInsect(const CRange & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;
	BOOL GetInsect(const CRange & fbfw,CRange & insectfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//�ϲ����䣬�����Ƿ����ཻ��ǿ�ƺϲ�
	void Combine(const CRange &fbfw);

	//��ȡ���䳤��
	double GetLen()const;

private:
	//��ߵ�ֲ���Χ--�Ѽ�ȥ��ʼ����
	double m_dTopBG;
	//��͵�ֲ���Χ--�Ѽ�����ʼ����
	double m_dBottomBG;
};

/**
 * @brief  :���伯���ڲ������ȷ�����䷶Χ���ظ�����ȷ������������
 *
 *          ����ʱ�Ĳ���Ҫ�󣺷�Χ�䲻Ҫ�ظ�
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

	//�ֲ���Χ
	CArray<CRange,CRange> m_arrFbfw;

	/**
	* @brief   ���÷ֲ���Χ(ע��:Ҫ��Χ�䲻Ҫ�ظ�)�����Զ��������������
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

	//�Ƿ��ڷ�Χ��[A,B]
	BOOL IsIn(double data) const;

	//��data�����з���
	BOOL SplitAt(double data);

	//��ȡ���䳤��
	double GetLen() const;

	//����
	void Sort();

	//�ϲ�����
	void CombineRange(const CRange &range);

	//��������
	void SubtractRange(const CRange &range,double kTol=1);
	void SubtractRange(const CRanges &ranges,double kTol=1);
};

//���伯
class PMBASECLASSAPI CXYRange
{
public:
	CXYRange(){m_bVirtual=FALSE;}
	CXYRange(const CRange & rangeX,const CRange & rangeY);
	CXYRange(const CXYRange & ranges);
	void operator=(const CXYRange & fbfw);

	//�鷶Χ
	void SetVirtual(BOOL bVirtual);
	void SetRange(const CRange & rangeX,const CRange & rangeY);

	//�Ƿ��ڷ�Χ��[A,B]
	BOOL IsIn(const CXYRange & data) const;

	//�Ƿ���ͬ
	BOOL IsSame(const CXYRange & fbfw,double kTol=1) const;

	//�����Ƿ��ཻ
	BOOL IsInsect(const CXYRange & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//��ȡ�������
	double GetArea()const;

	/**
	* @brief   �����Ƿ��ཻ��ǿ�ƺϲ����䣬X����ǿ�ƺϲ�,Y����ǿ�ƺϲ�
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
	* @brief   �ཻ����
	*
	*			������ཻ�����򷵻��ཻ����
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
	//�鷶Χ����ʾ���۳��ķ�Χ��Ĭ������ʵ��Χ��ΪTRUE
	BOOL m_bVirtual;
};

//XY����
class PMBASECLASSAPI CXYRanges
{
public:
	CXYRanges(const CXYRange & range);
	CXYRanges(const CXYRanges & ranges);
	void operator=(const CXYRanges & fbfw);

	//�ֲ���Χ
	CArray<CXYRange,CXYRange> m_arrFbfw;

	//�Ƿ��ڷ�Χ��[A,B]
	BOOL IsIn(const CXYRange & data) const;

	//�Ƿ���ͬ
	BOOL IsSame(const CXYRanges & fbfw,double kTol=1) const;

	//�����Ƿ��ཻ
	BOOL IsInsect(const CXYRanges & fbfw,BOOL bInsectPriority=TRUE,double tol=1) const;

	//��ȡ�������
	double GetArea()const;

	/**
	* @brief   �ϲ����䣬ȥ���ظ�����
	*
	*			ȥ���ظ����߼��ǣ�һ������ԭ״������һ��ȥ���ظ�����
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	BOOL CombineRange(const CXYRange &range,double kTol=1);
	BOOL CombineRange(const CXYRanges &range,double kTol=1);

	/**
	* @brief   �ཻ����
	*
	*			������ཻ�����򷵻��ཻ����
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/28/2018]
	*/
	BOOL GetInsectRange(const CXYRange &range,CXYRanges & rangeInsect,double kTol=1);
	BOOL GetInsectRange(const CXYRanges &range,CXYRanges & rangeInsect,double kTol=1);

	//��������
	void SubtractRange(const CXYRange &range,double kTol=1);
	void SubtractRange(const CXYRanges &ranges,double kTol=1);

private:

};
}