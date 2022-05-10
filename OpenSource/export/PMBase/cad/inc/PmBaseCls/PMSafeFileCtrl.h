// PMSafeFileCtrl.h: interface for the CPMSafeFileCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_)
#define AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/****************************************************************
  功能描述：双文件缓冲控制类
	参数：
	返 回 值：
	算法：
	注意事项：
			1、文件在 打开前 复制出一个零时文件。
				1、打开文件时要检查 FileInfo中 之前的打开状态。
			2、保存时，将修改保存到零时文件中，在保存返回正确的标志后，将文件覆盖会原文件中。
			3、对于 复合文档、DWG图纸要有两个新的派生，重写 打开和保存 关闭的函数。
			4、在FileInfo.ini文件中，要保存文件的控制状态，如：文件是打开，读取，保存，覆盖。

			2012:2:28   wjy：去除临时文件 多线程复制，文件复制本身是硬盘线性控制。
							多线程 不能提高效率，反而可能在 线程退出时 文件没有复制完成。
								进程被结束了。
	作    者：王建业
	时    间：[2011:8:21   14:03]
*****************************************************************/
#define PMFileInfoFileName	_T("FileInfo.ini")

class PMBASECLASSAPI CPMSafeFileCtrl  
{
public:

	enum PMFileRunMode
	{
		NoOpen = 0,
		Opening = 1,
		Reading = 2,
		Writing = 3,
		Cover = 4,	
	};

	enum PMFileReturnMode
	{
		PMFile_OK = 0,
		PMFile_NoFile = 1,
		PMFile_Opened = 2,
		PMFile_IniFileError = 3,
		PMFile_CoverError = 4,
		PMFile_ArrError = 5,
		PMFile_SaveError = 6
	};
	CPMSafeFileCtrl();
	virtual ~CPMSafeFileCtrl();

	/****************************************************************
	  功能描述：检查当前是否能执行保存，主要是 担心在多线程下，覆盖文件可能失败
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:8:23   9:15]
	*****************************************************************/
	BOOL CheckIsCanSave();

	/****************************************************************
	  功能描述：打开指定 文件
		参数：
		返 回 值：
		算法：
		注意事项：
			1、要进行重写这个函数 才能打开特定的文件
			2、在派生类中 OpenSafeFile 要先使用基类函数才能 继续 派生类的 函数执行
		作    者：王建业
		时    间：[2011:8:21   15:24]
	*****************************************************************/
	virtual PMFileReturnMode OpenSafeFile(const CString & strFilePath);

	/****************************************************************
	  功能描述：保存指定 文件
		参数：
		返 回 值：
		算法：
		注意事项：
			1、要进行重写这个函数 才能保存特定的文件
			2、在派生类中 SaveSafeFile 要先执行派生类的 代码，在 执行基类的 实现
		作    者：王建业
		时    间：[2011:8:21   15:27]
	*****************************************************************/
	virtual PMFileReturnMode SaveSafeFile();

	/****************************************************************
	  功能描述：关闭 指定 文件
		参数：bNeedSave  是否在 关闭的时候 保存
		返 回 值：
		算法：
		注意事项：
			1、要进行重写这个函数 才能保存特定的文件
			2、在派生类中 CloseSafeFile 要先使用基类函数才能 继续 派生类的 函数执行
		作    者：王建业
		时    间：[2011:8:21   15:28]
	*****************************************************************/
	virtual PMFileReturnMode CloseSafeFile(BOOL bNeedSave);

	/****************************************************************
	  功能描述： 获取运行文件 路径
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:8:22   9:27]
	*****************************************************************/
	CString GetRunFilePath();

	CString GetFileName();

	CString GetFilePath();

	CString GetIniFilePath();

	//void SetThreadRunMode(PMFileReturnMode fileReturnMode)
	//{
	//	m_ThreadFunRunMode = fileReturnMode;
	//}

	/*CRITICAL_SECTION * GetRunRitiCal_Section()
	{
		return & m_CoverFunThreadSection;
	}*/

protected:
	
	/****************************************************************
	  功能描述：检查 指定文件是否可以操作。
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:8:21   14:11]
	*****************************************************************/
	PMFileReturnMode CheckFileIsNormal(const CString & strFilePath);

	/****************************************************************
	  功能描述：根据 文件的运行状态 来检查 文件的恢复方式
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:8:21   14:06]
	*****************************************************************/
	PMFileReturnMode CheckFile_CloseError();

	/****************************************************************
	  功能描述：覆盖 主文件。
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:8:21   14:13]
	*****************************************************************/
	PMFileReturnMode CoverMainFile();
	
	static void CoverMainFile_Thread(CPMSafeFileCtrl * pPMSafeCtrl);

	PMFileRunMode m_FileRunMode;//文件运行 状态 
	CString m_strFileName;//文件名称 现作为 Ini配置的 主键使用
	CString m_strFilePath;//原始文件 路径名称
	CString m_strTemRunFilePath;//运行零时 文件 路径名称
	CString m_strFileCtrlIniPath;//文件 运行状态 文件 路径

//	PMFileReturnMode m_ThreadFunRunMode;//线程函数 运行结果

//	CRITICAL_SECTION m_CoverFunThreadSection;
};

#endif // !defined(AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_)
