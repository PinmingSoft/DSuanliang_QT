// GjParam.h: interface for the CGjParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_)
#define AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_
// ***************************************************************
//  GjParam   version:  1.0   ? date: 11/21/2007
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
//  ����:clz
// ***************************************************************
// �ļ�˵��:���ļ��������й������ݿ����������
//��һ�µ�ʹ������ľ�������,������ֱ��д�����ַ���
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// #ifdef PRJ_PMGJOPBASE
// 	#define PMDATASERVICEAPI __declspec(dllexport)
// #else
// 	#define PMDATASERVICEAPI __declspec(dllimport)
// 	#ifdef PM_FOR_R15
// 		#pragma comment(lib,"PmGjOpBase15.lib")
// 	#else
// 		#pragma comment(lib,"PmGjOpBase16.lib")
// 	#endif
// #endif

//������ϵ
struct PmSLGJDataServiceAPI GJRelation
{
	BOOL bDD;//���
	BOOL bChongDie;//�ص��Ƿ�Υ�� TRUE��Υ�� FALSE������
	CString strDJInfo;//�ۼ�
	CString strJSInfo;//����
};
struct PmSLGJDataServiceAPI GjParam  
{

	static const CString strLength;//������
	static const CString strWidth;//������
	static const CString strHigh;//������
//������
struct PmSLGJDataServiceAPI LiangParam 
{
	static const CString strTqd;//��ǿ��
	static const CString strDbg;//�����(mm)
	static const CString strJCLDbg;//����������ߣ�mm��
	static const CString strGzcd;//���߸��ó���
	static const CString strJDBG;//�������ױ��
	static const CString strJCTQD;	//��ǿ�� ---������
	static const CString strDCTQD;//�����ǿ�� --- ������
	
	//�ֽ�
	static const CString strcomponenttype;//������
	static const CString strjm;//���棨Bb*Hb��
	static const CString strkj;//����
	static const CString strstcj;//��ͨ����
	static const CString strxbtcj;//��ͨ����
	static const CString strcmyj;//����
	static const CString strcmlj;//��������
	static const CString strqtgj;//��������

	static const CString strljpz;//��������
	static const CString strxtl;//����������ѡ��
	static const CString strzljt;//�����۽Ǵ��Ƿ����ý���
	
	static const CString strjdwdj; //�²����ڽڵ�����
	static const CString strldkjxs;//����Ϊ֧��һ��Ĺ����Ƿ����
	static const CString strdtlx; //���ݽ��ڶ�֧�����Ƿ���û�еê��
	static const CString strjmsz ;//����Ϊ��������ǽʱ�������Ƿ����

	static const CString strDJ;//����
};
	
//��
struct PmSLGJDataServiceAPI ZhuParam 
{
	static const CString strDbg;//�����(mm)
	static const CString strDibg;//�ױ��(mm)	
	static const CString strTqd;//��ǿ��
	static const CString strMaterial;//����
	static const CString strSjdj;//ɰ���ȼ�
	static const CString strZdj;//ש�ȼ�
	
	static const CString strcomponenttype;//������
	static const CString strjm;//����ߴ磨b*h��D��
	static const CString strqbzj;//ȫ���ݽ�
	static const CString strjj;//�ǽ�
	static const CString strbzbj;//ˮƽ��B����һ���в���
	static const CString strhzbj;//��ֱ��H����һ���в���
	static const CString strkj;//����
	static const CString strkjzh;//����֫��
	static const CString strqtgj;//��������
	static const CString strjdygj; //�ڵ��򹿽�

	static const CString strzdjqj;//���׼�ǿ�����Ƿ����
	static const CString strdtlx;//�������ݽ��ͷ�Ƿ���û�еê��
};

// ��ע׮
struct PmSLGJDataServiceAPI GZHParam 
{
	static const CString strDbg;//�����(mm)
	static const CString strDibg;//�ױ��(mm)	
	static const CString strTqd;//��ǿ��
	static const CString strMaterial;//����
	static const CString strSjdj;//ɰ���ȼ�
	static const CString strZdj;//ש�ȼ�

	static const CString strcomponenttype;//������
	//static const CString strjm;//����ߴ磨b*h��D��
	static const CString strd;//׮��
	static const CString strkccd1;//���׶˳���1
	static const CString strkccd2;//���׶˳���2
	static const CString strl;//׮��
	static const CString strhc1;//���׶˸߶�
	static const CString strhc2;//���׶˸߶�
	static const CString strhb;//���׶˸߶ȹ�����ʸ��
	static const CString strtczj;//ͨ������
	static const CString strjqzj; //��ǿ����

	static const CString strlxgj;//��������
	static const CString strjqgj;//��ǿ����
};



//ǽ�����
struct PmSLGJDataServiceAPI WallParam 
{
	static const CString strQh; //ǽ��
	static const CString strDbg;//�����(mm)
	static const CString strDibg;//�ױ��(mm)
	static const CString strMaterial;//����
	static const CString strTqd;//��ǿ��
	static const CString strSjdj;//ɰ���ȼ�
	static const CString strZdj;//ש�ȼ�
	static const CString strCJGFJS;//�Ž��Ƿ��Զ�����
	static const CString strSjyrfqkj;  //����ǽ���˷�ǽ�Ƿ���ཻ��λ����ֽ�
};


//��
struct PmSLGJDataServiceAPI Ban 
{
	static const CString strBh;//���(mm)
	static const CString strDbg;//�����(mm)
	static const CString strTqd;//��ǿ��
	static const CString strTjmc;//ͼ������
};

//���
struct PmSLGJDataServiceAPI BanJin
{
	static const CString strBh;//���(mm)
	static const CString strDbg;//�����(mm)
	static const CString strTqd;//��ǿ��
	static const CString strBDGJ;//�������

	static const CString strGJMS;//�ֽ�����
	static const CString strfbjms;//�ֲ��ֽ�
	static const CString strzwz;//���ע(mm)
	static const CString strywz;//�ұ�ע(mm)
	static const CString strGJMSXD;//X��׽�
	static const CString strGJMSYD;//Y��׽�
	static const CString strGJMSXM;//X�����
	static const CString strGJMSYM;//Y�����
	
	static const CString strBZWZ;//��帺����֧���ڵı�עλ��
	static const CString strBZWZ_BX;//��帺����֧���ڵı�עλ�� ��ע������
	static const CString strBZWZ_ZX;//��帺����֧���ڵı�עλ�� ��ע������
	static const CString strBZWZ_WB;//��帺����֧���ڵı�עλ�� ��ע�����
	static const CString strZBZWZ;//�м�֧��������֧���ڵı�עλ��
	static const CString strZBZWZ_BX;//�м�֧��������֧���ڵı�עλ�� ��ע������
	static const CString strZBZWZ_ZX;//�м�֧��������֧���ڵı�עλ�� ��ע������
	static const CString strzzfjcd;//֧�������·ֲ���ȼ���
	static const CString strzzfjcd_fjdj;//֧�������·ֲ���ȼ��� ��֧��������
	static const CString strzzfjcd_fjcd;//֧�������·ֲ���ȼ��� ��֧������ĳ��Ȳ��ü���
	
	static const CString strBDK;//�����(mm)
	static const CString strBDH;//�����(mm)
	static const CString strSBPJ;//�ϲ�������
	static const CString strXBPJ;//�²�������
};

struct PmSLGJDataServiceAPI BanDong
{
	static const CString strBdjqj ;///�嶴��ǿ��
};

////////////////////////////////////////////
/// ֣���� [2014��5��14��]
/// ˵��:��������
///  
struct PmSLGJDataServiceAPI Dkw
{
	static const CString strDbg;//�����(mm)
	static const CString strDibg;//�ױ��(mm)
	static const CString strGzmk;//�������(mm)
	static const CString strFpxs;//����ϵ��(mm)

};

////////////////////////////////////////////
/// ֣���� [2014��5��20��]
/// ˵��:���� �����ҷ�Χ
///  
struct PmSLGJDataServiceAPI Dxsfw
{
	static const CString strDbg;//�����(mm)
	static const CString strDibg;//�ױ��(mm)
};

//����
struct PmSLGJDataServiceAPI Jc 
{
	static const CString strJdbg;//�����׾��Ա��
	static const CString strJctqd;//������ǿ��
	static const CString strSjdj;//ɰ���ȼ�
	static const CString strZdj;//ש�ȼ�
	static const CString strDctqd;//�����ǿ��

//�������޸�[1/7/2008 10:28]//Ŀ�ģ�
	static const CString strHd;//��̨/���û��� ���(mm)(�������ֶΣ�ʹ����������)
	static const CString strCTHd;//��̨��� 
	static const CString strMTJHd;//���û��� ��� 
//�����޸�	[1/7/2008 10:28]

	static const CString strDingBg;//�����
};

//�Ŵ���
struct PmSLGJDataServiceAPI Mcd 
{
	static const CString strKh;//���(mm)
	static const CString strDibg;//�ױ��(mm)
	static const CString strTqd;//��ǿ��
	static const CString strBksd;//�������(mm)
	static const CString strLdgd;//��ظ߶�(mm)

	///ע�ͣ�����ҫ [2009��8��19��]                                  
	///�ֽ��� Ҫ�õ��� 
	static const CString strDkjj ;
};

//װ��
struct PmSLGJDataServiceAPI Zs 
{
	static const CString strLdm;//¥����
	static const CString strTjx;//�߽���
	static const CString strNqm;//��ǽ��
	//��� ������ [21/5/2008]//���ã�
	static const CString strTnqm;//��ǽ��(��)
	static const CString strZnqm;//��ǽ��(ש)
	static const CString strQnqm;//��ǽ��(����
	//��� ����
	static const CString strZm;//����װ��
	static const CString strTp;//����
	static const CString strQq;//ǽȹ
	static const CString strDibg;//�ױ��(mm)
	static const CString strJdbg;//�����(mm)
	static const CString strScdibg;//�ײ�ױ��(mm)
	static const CString strDyfj;//��Ӧ����
	static const CString strHigh;//�߶�(mm)/ǽȹ��(mm)
	static const CString strHd;//���(mm)
};


//���ǹ���
struct  PmSLGJDataServiceAPI Lxgj
{
	static const CString strCtbhd;//��������(mm)
	static const CString strLbhd;//������(mm)
	static const CString strLbgd;//����߶�(mm)
	static const CString strDibg;//�ױ��(mm)
	static const CString strTqd;//��ǿ��
	static const CString strMaterial;//����
	static const CString strLggd;//���˸߶�(mm)
	static const CString strJj;//���(mm)
	static const CString strDctqd;//�����ǿ��
	static const CString strSjdj;//ɰ���ȼ�
	static const CString strZdj;//ש�ȼ�
	static const CString strJdbg;//�����(mm)
	static const CString strDbg; //�����(mm)//add by zll 2008.12.22 ��ǽ�ڵ�
	
	static const CString strSx_wzcd;//��������ֽ�����۳���
	static const CString strX_wzcd;//��ǽ�ڵ�˲����۳���
};

//�߹���
struct PmSLGJDataServiceAPI Qt
{
	static const CString strX_wzcd;//�߹����˲����۳���
};

//Ԥ�ƹ���
struct PmSLGJDataServiceAPI Yzgj
{
	static const CString strYztqd;//Ԥ����ǿ��
};

};//GjParam end

const int IN_VALIDE_COM_TYPE = -1;		
const int IN_VALID_COM_ID = -1;//��Чcomid


#endif // !defined(AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_)
