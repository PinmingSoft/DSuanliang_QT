// PMDataEncodeFun.h: interface for the CPMDataEncodeFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_)
#define AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

 
namespace PMDataEncodeFun  
{
	namespace PMAES
	{
		#define Bits128	16  //��Կ����
		#define Bits192	24
		#define Bits256	32

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:01
			��ע:��16���Ƹ�ʽ������Ϣ ����
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL DecodingHEXInfo(int iPWDLength,UCHAR * pPWD,char * pMiWenInfo,char *& pMingWenInfo);

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:00
			��ע:����Ϣ���ܳ�16���Ƹ�ʽ
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL EncodingHEXInfo(int iPWDLength,UCHAR * pPWD,char * pMingWenInfo,char *& pMiWenInfo);

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:02
			��ע:����������Ϣ������Ϣ ����
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL DecodingByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMiWenInfo,int iMiWenLength,UCHAR *& pMingWenInfo,int & iMingWenLength);

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:01
			��ע:����Ϣ���ܳɶ����� ��Ϣ
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL EncodingByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMingWenInfo,int iMingWenLength,UCHAR *& pMiWenInfo,int & iMiWenLength);

		/********************************************************************
		����ҵ  PKCS
			ʱ��:2010:9:9   11:02
			��ע:����������Ϣ������Ϣ ����
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL DecodingPKCSByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMiWenInfo,int iMiWenLength,UCHAR *& pMingWenInfo,int & iMingWenLength);

		/********************************************************************
		����ҵ   PKCS
			ʱ��:2010:9:9   11:01
			��ע:����Ϣ���ܳɶ����� ��Ϣ
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL EncodingPKCSByteInfo(int iPWDLength,UCHAR * pPWD,UCHAR * pMingWenInfo,int iMingWenLength,UCHAR *& pMiWenInfo,int & iMiWenLength);

	};

	namespace PMMD5
	{
		extern KERNELBASECLASS_API TCHAR * CreateMD5Code(TCHAR * strInfo);

		extern KERNELBASECLASS_API TCHAR * CreateMD5Code(unsigned char *InputValue,int iLength);

	};

	namespace PMDES
	{
		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:02
			��ע:��16������Ϣ ����
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL DecodeHEX2Info(char * pPWD,TCHAR * strHEXInfo, BYTE *&pByte, LONG &lSize);

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:04
			��ע:����Ϣ ���ܳ� 16������Ϣ
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL EncodeInfo2HEX(char * pPWD,BYTE *pByte, LONG lSize, TCHAR*&strHEXInfo);
	};
	
	namespace PMBase64
	{
		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:02
			��ע:��Base64�ַ������н���
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL DecodeBase64(const char * pInfo, BYTE *&pByte, LONG &lSize);

		/********************************************************************
		����ҵ
			ʱ��:2010:9:9   11:04
			��ע:����Ϣ����Base64 ���� Base64�ַ������н���
		*********************************************************************/
		extern KERNELBASECLASS_API BOOL EncodeBase64(BYTE *pByte, LONG lSize,char *& pInfo);
	};


	namespace PMURL
	{
		//URL����
		extern KERNELBASECLASS_API CString URLEncode(const char *sIn);

		//URL����
		extern KERNELBASECLASS_API CString URLDecode(const char *sIn);
	};

};

#endif // !defined(AFX_PMDATAENCODEFUN_H__FF6893FD_2FCC_466E_BFA9_F0C3EFBFA696__INCLUDED_)
