#pragma once
/**
 * @brief  :类型转化用，本类不提供指针接口，因为其不安全(这个规则一定要遵守)
 *
 *          1、我们有很多warning由于类型转化引起
 *			2、包装相关的类，以便安全的进行类型转化
 * @author :zfy
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */
#include "PmBaseVarTypeDef.h"

namespace  PmCast
{
	/**
	* @brief   无符号整形转化为有符号整形
	*
	*		   错误示例：
	*		   UINT lenArr = 0;
	*          for(UINT t = 0;t < lenArr - 1;t++) //本语句会出现接近无限循环，因为lenArr - 1会是很大，而lenArr代表数组长度，其为0，又是很常见的
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

	///浮点转为整数
	PMBASECLASSOPRAPI int ToInt(double val);

	/// 64位int转为int，其在32系统下会把高32位抛弃
	PMBASECLASSOPRAPI int Int64ToInt(PmUInt64 val);

	///size_t转为int
	PMBASECLASSOPRAPI int ToInt(size_t val);

	///浮点转为long
	PMBASECLASSOPRAPI long ToLong(double val);

	

};
