#pragma once
/**
 * @brief  :����ת���ã����಻�ṩָ��ӿڣ���Ϊ�䲻��ȫ(�������һ��Ҫ����)
 *
 *          1�������кܶ�warning��������ת������
 *			2����װ��ص��࣬�Ա㰲ȫ�Ľ�������ת��
 * @author :zfy
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */
#include "PmBaseVarTypeDef.h"

namespace  PmCast
{
	/**
	* @brief   �޷�������ת��Ϊ�з�������
	*
	*		   ����ʾ����
	*		   UINT lenArr = 0;
	*          for(UINT t = 0;t < lenArr - 1;t++) //��������ֽӽ�����ѭ������ΪlenArr - 1���Ǻܴ󣬶�lenArr�������鳤�ȣ���Ϊ0�����Ǻܳ�����
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [16/11/2012]
	*/
#ifdef _WIN64
	PMBASECLASSOPRAPI int ToInt(UINT val);
#endif

	///
	PMBASECLASSOPRAPI int ToInt(INT_PTR val);

	///
//	PMBASECLASSOPRAPI int ToInt(DWORD_PTR val);

// 	/// 
// 	PMBASECLASSOPRAPI int ToInt(LONG_PTR val);
// 
// 	/// 
// 	PMBASECLASSOPRAPI int ToInt( DWORD_PTR val);

	///����תΪ����
	PMBASECLASSOPRAPI int ToInt(double val);

	/// 64λintתΪint������32ϵͳ�»�Ѹ�32λ����
	PMBASECLASSOPRAPI int Int64ToInt(PmUInt64 val);

	///size_tתΪint
	PMBASECLASSOPRAPI int ToInt(size_t val);

	///����תΪlong
	PMBASECLASSOPRAPI long ToLong(double val);

	

};
