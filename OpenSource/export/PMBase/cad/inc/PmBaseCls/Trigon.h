#pragma once
/**
 * @brief  :���������μ�����׶������
 *
 *          �ڲ��ĽǶ�����: dAngC ����ʾC�߶���ĽǶȣ���AB�ߵļн�
 * @author :ׯ����
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */
namespace Trigon
{
	/**
	* @brief   ��������Ƿ�����ܳɹ�����һ��������
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI BOOL IsLegal(double dA,double dB,double dC);

	/**
	* @brief   ���������
	*
	*          Ҫ������֮�ʹ��ڵ����ߣ����򷵻�0
	* @note  : ԭ��Ϊ�����׶���: s=sqrt(p*(p-a)*(p-b)*(p-c)) ,����p=(a+b+c)/2�����ܳ���һ��
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetArea(double dA,double dB,double dC);

	/**
	* @brief   ��֪����1���н�,���������
	*
	*          �������Ҷ���:c*c = a*a+b*b-2*a*b*cos(dAngAB)
	* @note  : 
	* @param : dAngC ΪAB�ߵļн�
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetC(double dA,double dB,double dAngC);


	/**
	* @brief   ��֪���ߣ�����һ��AB�н�
	*
	*          �������Ҷ���:c*c = a*a+b*b-2*a*b*cos(dAngAB)
	* @note  : 
	* @param : 
	* @return: Ҫ������֮�ʹ��ڵ����ߣ����򷵻�0
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetAng(double dA,double dB,double dC);

	/**
	* @brief   ���ɶ���
	*
	*          ������ֱ�ߣ������ҳ�
	* @note  : 
	* @param : dChord :��ʾ�ҳ� ,dA,dBΪֱ�Ǳ�
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetChord(double dA,double dB);
	PMBASECLASSAPI double GetB(double dChord,double dA);

	/**
	* @brief   ��ȡ���Բ�뾶
	*
	*          �������Ҷ���:a/sin(dAngA) = b/sin(dAngB) = c/sin(dAngC) = 2*R
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetOuterCircleRadius(double dA,double dAngA);

	/**
	* @brief   ��ȡ����Բ�뾶
	*
	*          ��������Բ���������:S=(a+b+c)*r/2
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetInnerCircleRadius(double dA,double dB,double dC);

	/**
	* @brief   ���㴹������ǵ�ľ���
	*
	*          
	* @note  : 
	* @param : ��֪һ���ǣ�ĳ�����ýǵ����ߵĴ�ֱ����
	* @return: 
	* @author: ׯ����
	* @date  : [3/25/2014]
	*/
	PMBASECLASSAPI BOOL GetDistToAngPt(double dAng,double dPerp1,double dPerp2,double & dist1,double & dist2);

	/**
	* @brief   ����̨��dAngC��Ӧ�������ϵ�������
	*
	*          1��������dTc��ʾ��ά��c�߶�Ӧ�����,dTa��ʾa�߶�Ӧ�����,dTb��ʾb�߶�Ӧ�����
	*		   planeC(��C��Ϊ�ױߵ�����),planeA(��A��Ϊ�ױߵ�����),planeB(��B��Ϊ�ױߵ�����),plane0(����)
	*		   2�����ù�ʽ: cosTcA = cos(c1)*cos(dAngTc) ,����c1ΪTcA�Ƕ���ƽ���ϵ�ͶӰ�ĽǶ� ,dAngTcΪ ��Tc��XYƽ��ļн�
	*		   3�����ù�ʽ:cos����+�£�=cos��cos��-sin��sin��
	*                      sin����+�£�=sin��cos��+cos��sin��
	*		   4��һ��ֱ����ƽ����ƽ�����ɽ�Ϊ�� ,�н���p,ͨ��p��������ֱ�ߣ�����ԭʼֱ�����ɽǷ�ΧΪ[��,PI-��],�Դ�ֱƽ��Ϊ�Ƕȵķֽ���
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [29/8/2013]
	*/

	PMBASECLASSAPI BOOL GetPyramidAng(double dAngC,double dAngOfPlaneA,double dAngOfPlaneB,double & dAngTcA,double & dAngTcB);
};
