// IniFile.cpp:  Implementation of the CIniFile class.
// Written by:   Adam Clauss
// Email: cabadam@tamu.edu
// You may use this class/code as you wish in your programs.  Feel free to distribute it, and
// email suggested changes to me.
//
// Rewritten by: Shane Hill
// Date:         21/08/2001
// Email:        Shane.Hill@dsto.defence.gov.au
// Reason:       Remove dependancy on MFC. Code should compile on any
//               platform. Tested on Windows/Linux/Irix
//////////////////////////////////////////////////////////////////////

#ifndef CIniFile_H
#define CIniFile_H

#ifdef _DEBUG
#define _DEBUG_ZLL_WAS_DEFINED
#undef _DEBUG
#pragma message ("		����MFC��STD��run-timing��Release")
#endif

// C++ Includes
#include <string>
#include <vector>
#include <locale>

// C Includes
#include <stdlib.h>

#ifdef _DEBUG_ZLL_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_ZLL_WAS_DEFINED
#endif

#define MAX_KEYNAME    128
#define MAX_VALUENAME  128
#define MAX_VALUEDATA 2048

#include "Parms.h"

namespace PmFile
{

//�滻����׼��string,�ڴ�������!
//typedef CString string;
	

//using namespace std;
//#ifdef _UNICODE
//	typedef std::wstring string;
//#else
	typedef std::string  string;	//ʼ��ʹ��ascii���
//#endif
	using std::vector;


//key  �൱�ڶ�������
//valuename �൱�ڹؼ�����

////////////////////////////////////////////
/// ����ҫ [2014��4��17��]
/// ˵��:
/// ���֧������·����
/// �޸�ע�͵������ʽ���������������д�뵽���� 

class PMBASECLASSAPI CIniFile  
{
public:
  bool   caseInsensitive;
  string path;
  struct PMBASECLASSAPI key {
    vector<string> names;
    vector<string> values; 
    vector<string> comments;
	vector<int> idxs ;  /// ��ʶ�����˳��
  };

  vector<key>    keys; 
  vector<string> names; 
  vector<string> comments;
  string CheckCase(const string & s) const;

  /// ��Ч����
  vector<string> invalidline ; 

  // trim from start 
  static int(__cdecl is_space)(int c)  
  {  
	  return (c >= -127 && c <= 127 && isspace(c) != 0);  
  }  

  //-------------------------------------------------------------------------  

  static void trim(std::string &s)  
  {  
	  //// trim from start (in place)  
	  //s.erase(s.begin(), std::find_if(s.begin(), s.end(),  
		 // std::not1(std::ptr_fun<int, int>(is_space))));  
	  //// trim from end (in place)  
	  //s.erase(std::find_if(s.rbegin(), s.rend(),  
		 // std::not1(std::ptr_fun<int, int>(is_space))).base(), s.end());
	  if (s.empty()) 
	  {
		  return ;
	  }
	  s.erase(0, s.find_first_not_of(" "));
	  s.erase(s.find_last_not_of(" ") + 1);
  } 

public:
	//������
  enum errors{ noID = -1};

  CIniFile( string const iniPath = "");

  virtual ~CIniFile()                            {}

  // Sets whether or not keynames and valuenames should be case sensitive.
  // The default is case insensitive.
  void CaseSensitive()                           {caseInsensitive = false;}
  void CaseInsensitive()                         {caseInsensitive = true;}

  // Sets path of ini file to read and write from.
  //���ö�ȡ·��
  void Path(string const newPath)                {path = newPath;}
  void SetPath(string const newPath)             {Path( newPath);}

  //�������Ҽ��ٽṹ
  void BuildMap(std::map<std::pair<CString, CString>, CString> & values_map);
  

  //�õ����õ�·��
  string Path() const                            {return path;}

  // Reads ini file specified using path.
  // Returns true if successful, false otherwise.
  virtual bool ReadFile();
  
  // Writes data stored in class to ini file.
  virtual bool WriteFile(); 
  
  // Deletes all stored ini data.
  //�������
  void Erase();
  void Clear()                                   {Erase();}
  void Reset()                                   {Erase();}

  // Returns index of specified key, or noID if not found.
  //ͨ����������0Ϊ��ʼ�����,�ļ���ʼ�Ķ�Ϊ0
  long FindKey( const string & keyname) const;

  // Returns index of specified value, in the specified key, or noID if not found.
  //���ݶ����,�������Ĺؼ���,�õ��ùؼ��ֵ����
  long FindValue( unsigned const keyID, const string & valuename) const;

  // Returns number of keys currently in the ini.
  //�õ�������
  unsigned NumKeys() const                       {return (unsigned)names.size();}
  unsigned GetNumKeys() const                    {return NumKeys();}

  // Add a key name.
  //���Ӷ�
  unsigned AddKeyName( string const keyname);

  // Returns key names by index.
  string KeyName( unsigned const keyID) const;
  string GetKeyName( unsigned const keyID) const {return KeyName(keyID);}

  // Returns number of values stored for specified key.
  unsigned NumValues( unsigned const keyID);
  unsigned GetNumValues( unsigned const keyID)   {return NumValues( keyID);}
  unsigned NumValues( string const keyname);
  unsigned GetNumValues( string const keyname)   {return NumValues( keyname);}

  // Returns value name by index for a given keyname or keyID.
  string ValueName( unsigned const keyID, unsigned const valueID) const;
  string GetValueName( unsigned const keyID, unsigned const valueID) const {
    return ValueName( keyID, valueID);
  }
  string ValueName( string const keyname, unsigned const valueID) const;
  string GetValueName( string const keyname, unsigned const valueID) const {
    return ValueName( keyname, valueID);
  }

  // Gets value of [keyname] valuename =.
  // Overloaded to return string, int, and double.
  // Returns defValue if key/value not found.
  string GetValue( unsigned const keyID, unsigned const valueID, string const defValue = "") const;

  //ʹ�ø�����,����ʹ��string,��Ϊ��ģ��Ļ����������
  CString GetValue(const CString &keyname, const CString &valuename, const CString &defValue = _T("")) const; 
  CString GetValueStr(const CString &keyname, const CString &valuename, const CString &defValue = _T("")) const; 
  int    GetValueI(const CString &keyname, const CString &valuename, int const defValue = 0) const;
  bool   GetValueB(const CString &keyname, const CString &valuename, bool const defValue = false) const;
  double   GetValueF(const CString &keyname, const CString &valuename, double const defValue = 0.0) const;

 protected:
  //ͨ������,����, ȡ��ֵ,�����������,ʹ��Ĭ��ֵ
  string GetValueFun(string const keyname, string const valuename, string const defValue = "") const; 
  int    GetValueI(string const keyname, string const valuename, int const defValue = 0) const;
  bool   GetValueB(string const keyname, string const valuename, bool const defValue = false) const;
  double   GetValueF(string const keyname, string const valuename, double const defValue = 0.0) const;
public:

  // This is a variable length formatted GetValue routine. All these voids
  // are required because there is no vsscanf() like there is a vsprintf().
  // Only a maximum of 8 variable can be read.
  unsigned GetValueV( string const keyname, string const valuename, char *format,
		      void *v1 = 0, void *v2 = 0, void *v3 = 0, void *v4 = 0,
  		      void *v5 = 0, void *v6 = 0, void *v7 = 0, void *v8 = 0,
  		      void *v9 = 0, void *v10 = 0, void *v11 = 0, void *v12 = 0,
  		      void *v13 = 0, void *v14 = 0, void *v15 = 0, void *v16 = 0);

  // Sets value of [keyname] valuename =.
  // Specify the optional paramter as false (0) if you do not want it to create
  // the key if it doesn't exist. Returns true if data entered, false otherwise.
  // Overloaded to accept string, int, and double.
  bool SetValue( unsigned const keyID, unsigned const valueID, string const value);
  
public:
	//ͨ������,����, ȡ��ֵ,�����������,ʹ��Ĭ��ֵ
	bool SetValue(const CString &keyname, const CString &valuename, const CString &value, bool const create = true);
	bool SetValueI(const CString &keyname, const CString &valuename, int const value, bool const create = true);
	bool SetValueB(const CString &keyname, const CString &valuename, bool const value, bool const create = true)
	{
		return SetValueI( keyname, valuename, int(value), create);
	}
	bool SetValueF(const CString &keyname, const CString &valuename, double const value, bool const create = true);
	
	
protected:

  //ͨ������,����, ȡ��ֵ,�����������,ʹ��Ĭ��ֵ
  bool SetValue( string const keyname, string const valuename, string const value, bool const create = true);
  bool SetValueI( string const keyname, string const valuename, int const value, bool const create = true);
  bool SetValueB( string const keyname, string const valuename, bool const value, bool const create = true)
  {
    return SetValueI( keyname, valuename, int(value), create);
  }
  bool SetValueF( string const keyname, string const valuename, double const value, bool const create = true);

public:
	
  bool SetValueV( string const keyname, string const valuename, char *format, ...);

  // Deletes specified value.
  // Returns true if value existed and deleted, false otherwise.
  //ɾ��ĳ���µ�ֵ��
  bool DeleteValue( string const keyname, string const valuename);
  
  // Deletes specified key and all values contained within.
  // Returns true if key existed and deleted, false otherwise.
  //ɾ��������
  bool DeleteKey(string keyname);

  // Header comment functions.
  // Header comments are those comments before the first key.
  //
  // Number of header comments.
  unsigned NumHeaderComments()                  {return (unsigned)comments.size();}
  // Add a header comment.
  void     HeaderComment( string const comment);
  // Return a header comment.
  string   HeaderComment( unsigned const commentID) const;
  // Delete a header comment.
  bool     DeleteHeaderComment( unsigned commentID);
  // Delete all header comments.
  void     DeleteHeaderComments()               {comments.clear();}

  // Key comment functions.
  // Key comments are those comments within a key. Any comments
  // defined within value names will be added to this list. Therefore,
  // these comments will be moved to the top of the key definition when
  // the CIniFile::WriteFile() is called.
  //
  // Number of key comments.
  unsigned NumKeyComments( unsigned const keyID) const;
  unsigned NumKeyComments( string const keyname) const;
  // Add a key comment.
  bool     KeyComment( unsigned const keyID, string const comment);
  bool     KeyComment( string const keyname, string const comment);
  // Return a key comment.
  string   KeyComment( unsigned const keyID, unsigned const commentID) const;
  string   KeyComment( string const keyname, unsigned const commentID) const;
  // Delete a key comment.
  bool     DeleteKeyComment( unsigned const keyID, unsigned const commentID);
  bool     DeleteKeyComment( string const keyname, unsigned const commentID);
  // Delete all comments for a key.
  bool     DeleteKeyComments( unsigned const keyID);
  bool     DeleteKeyComments( string const keyname);
};

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2014��4��17��]
 * @note  
 */
 class PMBASECLASSAPI CIniFileEx  :public CIniFile
 {
 public:
 	CIniFileEx() ;
 	virtual ~CIniFileEx() ; 
 
 public:
	 void SetTPath( CString const newPath) ;

	 /// ���ļ���ʱ�򲻼������Ϣ
	 bool ReadFileNoCheck();
 	
	 /**
	 * @brief   ��ȡ���жε�����,
	 *
	 *          
	 * @note  : 
	 * @param : 
	 * @return: ���ض�����
	 * @author: zfy
	 * @date  : [8/1/2014]
	 */
	 unsigned GetSegName(CStringArray & arrSegName) const;

	 /**
	 * @brief   ��ȡĳ���ڵ����м�ֵƥ���
	 *
	 *          ����Ϊparm��name ,ֵ��Ϊparm��value ,comment ��Ϊparm ��description
	 * @note  : ͬһ������ ������Ҫ�ظ�
	 * @param : 
	 * @return: 
	 * @author: zfy
	 * @date  : [8/1/2014]
	 */
	 void GetKeyValue(CString segName,CParms & parms) const;
 public:

	  long FindKeyT( CString const keyname) const;

	  long FindValueT( unsigned const keyID, CString const valuename) const;

	  CString GetValueT( const CString & strKeyName , const CString & strValueName ) const ;

	  void GetInvalidLine( CStringArray & aryInvalidLine ) ;

	  BOOL HasInvalidLine( ) ;
 };

//std::string ת UNICODE/ASCII ��CString
BOOL PMBASECLASSAPI StdString2CString(const std::string &strSrc, CString &strDes);
//std::wstring ת UNICODE/ASCII ��CString
BOOL PMBASECLASSAPI StdwString2CString(const std::wstring &strSrc, CString &strDes);

//������Ӧ��ת��
BOOL PMBASECLASSAPI CString2StdString(const CString &strSrc, std::string &strDes);

BOOL PMBASECLASSAPI CString2StdwString(const CString &strSrc, std::wstring &strDes);


}//namespace PmFile


#endif
