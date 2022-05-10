// PMDataEncodeFun.h: interface for the CPMDataEncodeFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_)
#define AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

 
//namespace PMDataEncodeFun  
//{
//	namespace PMAES
//	{
//		#define Bits128	16  //密钥长度
//		#define Bits192	24
//		#define Bits256	32
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:01
//			备注:将16进制格式加密信息 解密
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL DecodingHEXInfo(int iPWDLength,UCHAR * pPWD,char * pMiWenInfo,char *& pMingWenInfo);
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:00
//			备注:将信息加密成16进制格式
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL EncodingHEXInfo(int iPWDLength,UCHAR * pPWD,char * pMingWenInfo,char *& pMiWenInfo);
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:02
//			备注:将二进制信息加密信息 解密
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL DecodingByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMiWenInfo,int iMiWenLength,UCHAR *& pMingWenInfo,int & iMingWenLength);
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:01
//			备注:将信息加密成二进制 信息
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL EncodingByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMingWenInfo,int iMingWenLength,UCHAR *& pMiWenInfo,int & iMiWenLength);
//	};
//
//	namespace PMMD5
//	{
//		extern PMBASECLASSAPI TCHAR * CreateMD5Code(TCHAR * strInfo);
//
//		extern PMBASECLASSAPI TCHAR * CreateMD5Code(unsigned char *InputValue,int iLength);
//
//	};
//
//	namespace PMDES
//	{
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:02
//			备注:将16进制信息 解密
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL DecodeHEX2Info(char * pPWD,TCHAR * strHEXInfo, BYTE *&pByte, LONG &lSize);
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:04
//			备注:将信息 加密成 16进制信息
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL EncodeInfo2HEX(char * pPWD,BYTE *pByte, LONG lSize, TCHAR*&strHEXInfo);
//	};
//	
//	namespace PMBase64
//	{
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:02
//			备注:将Base64字符串进行解密
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL DecodeBase64(char * pInfo, BYTE *&pByte, LONG &lSize);
//
//		/********************************************************************
//		王建业
//			时间:2010:9:9   11:04
//			备注:将信息进行Base64 加密 Base64字符串进行解密
//		*********************************************************************/
//		extern PMBASECLASSAPI BOOL EncodeBase64(BYTE *pByte, LONG lSize,char *& pInfo);
//	};
//};

#endif // !defined(AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_)
