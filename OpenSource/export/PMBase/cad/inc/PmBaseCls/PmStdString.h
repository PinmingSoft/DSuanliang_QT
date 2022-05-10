
#ifndef _COMMON_PMBASECLASS_PMBASECLS_PMSTDSTRING_H_
#define _COMMON_PMBASECLASS_PMBASECLS_PMSTDSTRING_H_

/**
 * @brief 
 *	一些处理std::string的操作
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-4-1]
 * @note  
 */

#ifdef  UNICODE                    
	#ifndef _PM_T_DEFINED
		/// 		
		//typedef	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<unsigned int> > PMTSTRING , PmTString;
		typedef	std::wstring	PMTSTRING , PmTString;
		typedef std::wostringstream PMTSTRINGSTREAM , PmTStringStream ;
		typedef std::wostream	PMOSTREAM ,PmOStream ;
		#define _PM_T_DEFINED
		#define QStringTo(str)		std::wstring((const wchar_t *)str.utf16());
		#define QStringFrom(str)	QString::fromUtf16((const ushort *)str.c_str())
	#endif
#else
	#ifndef _PM_T_DEFINED
		typedef	std::string		PMTSTRING , PmTString ;
		typedef std::ostringstream PMTSTRINGSTREAM , PmTStringStream ;
		typedef std::ostream	PMOSTREAM ,PmOStream ;
		#define QStringTo(str)		std::string((const char *)str.utf16());
		#define QStringFrom(str)	QString::fromAscii(str.data(), int(str.size()))
		#define _PM_T_DEFINED
	#endif /* !_TCHAR_DEFINED */
#endif /*UNICODE*/


/// 定义str 到 str 的 map
typedef std::map<PmTString , PmTString> PmStr2StrMap ; 
typedef PmStr2StrMap::iterator	PmStr2StrMapIter ;
typedef PmStr2StrMap::const_iterator PmStr2StrMapConIter ; 

/// CString ---> CString
typedef std::map<CString , CString> PmCStr2CStrMap ; 
typedef PmCStr2CStrMap::iterator	PmCStr2CStrMapIter ;
typedef PmCStr2CStrMap::const_iterator PmCStr2CStrMapConIter ;

/// CString ---> int
typedef std::map<CString , int> PmCStr2IntMap ; 
typedef PmCStr2IntMap::iterator	PmCStr2IntMapIter ;
typedef PmCStr2IntMap::const_iterator PmCStr2IntMapConIter ;

/// int ---> CString
typedef std::map<int , CString> PmInt2CStrMap ; 
typedef PmInt2CStrMap::iterator	PmInt2CStrMapIter ;
typedef PmInt2CStrMap::const_iterator PmInt2CStrMapConIter ;

/// 定义str 到 int 的 map 
typedef std::map<PmTString , int> PmStr2IntMap ; 
typedef PmStr2IntMap::iterator	PmStr2IntMapIter ;
typedef PmStr2IntMap::const_iterator PmStr2IntMapConIter ; 

/// 定义 int 到 str的map
typedef std::map<int , PmTString> PmInt2StrMap ; 
typedef PmInt2StrMap::iterator	PmInt2StrMapIter ;
typedef PmInt2StrMap::const_iterator PmInt2StrMapConIter ; 

/// 定义PmTString的vector
typedef std::vector<PmTString> PmStrList ;
typedef PmStrList::iterator PmStrListIter ; 
typedef PmStrList::const_iterator PmStrListConIter ; 

/// 定义int 到 pmtstrlist 的map 
typedef std::map< int , PmStrList> PmInt2StrListMap ; 
typedef PmInt2StrListMap::iterator PmInt2StrListMapIter ;
typedef PmInt2StrListMap::const_iterator PmInt2StrListMapConIter ;

/// 定义PmTString 的 set 
typedef std::set< PmTString> PmStrSet ; 
typedef PmStrSet::iterator	PmStrSetIter ; 
typedef PmStrSet::const_iterator PmStrSetConIter ; 

/// 定义int 到 PmStrSet 的map 
typedef std::map< int , PmStrSet > PmInt2StrSetMap ; 
typedef PmInt2StrSetMap::iterator	PmInt2StrSetMapIter ; 
typedef PmInt2StrSetMap::const_iterator PmInt2StrSetMapConIter ;




namespace pmcommon
{
	/**
	* @brief   
	* 字符串的查找函数
	*          
	* @note  : 
	* @param : 
				CString & strFind 使用引用并不是为了改变它，而是为了执行效率
				因为需要调用它的成员函数GetBuffer,所以不能使用const 引用
	* @defenc: 
	* @return: 
				-1 为没有找到，其他为字符串strFind 在str中的位置

	* @author: 杨兴耀
	* @date  : [2012-4-1]
	*/
	PMBASECLASSAPI int find( const PMTSTRING & str ,  CString & strFind , const int iStartPos = 0 ) ;

	PMBASECLASSAPI int find( const PMTSTRING & str , const PMTSTRING & strFind , const int iStartPos = 0 ) ;
	/**
	* @brief  
	*			替换函数
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-4-1]
	*/
	PMBASECLASSAPI void replace( PMTSTRING & str ,  CString & strSrc , CString & strDes ) ;

	PMBASECLASSAPI void replace( PMTSTRING & str , const PMTSTRING & strSrc , const PMTSTRING & strDes ) ;

	/**
	* @brief   
	*			格式化
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-4-1]
	*/
	PMBASECLASSAPI void format( PMTSTRING & str , const TCHAR *_format, ... ) ;

	//ACSII 格式化
	PMBASECLASSAPI void format_A( std::string & str , const char *_format, ... ) ;
}

#endif /// _COMMON_PMBASECLASS_PMBASECLS_PMSTDSTRING_H_
