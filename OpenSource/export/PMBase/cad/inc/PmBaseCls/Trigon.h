#pragma once
/**
 * @brief  :常见三角形及三棱锥的运算
 *
 *          内部的角度描述: dAngC ，表示C边对面的角度，即AB边的夹角
 * @author :庄峰毅
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */
namespace Trigon
{
	/**
	* @brief   检测三边是否合理，能成功构成一个三角形
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI BOOL IsLegal(double dA,double dB,double dC);

	/**
	* @brief   三角形面积
	*
	*          要求两边之和大于第三边，否则返回0
	* @note  : 原理为：海伦定理: s=sqrt(p*(p-a)*(p-b)*(p-c)) ,其中p=(a+b+c)/2，即周长的一半
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetArea(double dA,double dB,double dC);

	/**
	* @brief   已知两边1个夹角,计算第三边
	*
	*          利用余弦定理:c*c = a*a+b*b-2*a*b*cos(dAngAB)
	* @note  : 
	* @param : dAngC 为AB边的夹角
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetC(double dA,double dB,double dAngC);


	/**
	* @brief   已知三边，计算一个AB夹角
	*
	*          利用余弦定理:c*c = a*a+b*b-2*a*b*cos(dAngAB)
	* @note  : 
	* @param : 
	* @return: 要求两边之和大于第三边，否则返回0
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetAng(double dA,double dB,double dC);

	/**
	* @brief   勾股定理
	*
	*          两个垂直边，计算弦长
	* @note  : 
	* @param : dChord :表示弦长 ,dA,dB为直角边
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetChord(double dA,double dB);
	PMBASECLASSAPI double GetB(double dChord,double dA);

	/**
	* @brief   求取外接圆半径
	*
	*          利用正弦定理:a/sin(dAngA) = b/sin(dAngB) = c/sin(dAngC) = 2*R
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetOuterCircleRadius(double dA,double dAngA);

	/**
	* @brief   求取内切圆半径
	*
	*          利用内切圆的面积特性:S=(a+b+c)*r/2
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/
	PMBASECLASSAPI double GetInnerCircleRadius(double dA,double dB,double dC);

	/**
	* @brief   计算垂足点距离角点的距离
	*
	*          
	* @note  : 
	* @param : 已知一个角，某点距离该角的两边的垂直距离
	* @return: 
	* @author: 庄峰毅
	* @date  : [3/25/2014]
	*/
	PMBASECLASSAPI BOOL GetDistToAngPt(double dAng,double dPerp1,double dPerp2,double & dist1,double & dist2);

	/**
	* @brief   三棱台的dAngC对应的立体上的两个角
	*
	*          1、我们以dTc表示三维上c边对应的棱边,dTa表示a边对应的棱边,dTb表示b边对应的棱边
	*		   planeC(以C边为底边的棱面),planeA(以A边为底边的棱面),planeB(以B边为底边的棱面),plane0(底面)
	*		   2、利用公式: cosTcA = cos(c1)*cos(dAngTc) ,其中c1为TcA角度在平面上的投影的角度 ,dAngTc为 边Tc与XY平面的夹角
	*		   3、利用公式:cos（α+β）=cosαcosβ-sinαsinβ
	*                      sin（α+β）=sinαcosβ+cosαsinβ
	*		   4、一个直线与平面与平面所成角为α ,有交点p,通过p做的无数直线，其与原始直线所成角范围为[α,PI-α],以垂直平面为角度的分界面
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [29/8/2013]
	*/

	PMBASECLASSAPI BOOL GetPyramidAng(double dAngC,double dAngOfPlaneA,double dAngOfPlaneB,double & dAngTcA,double & dAngTcB);
};
