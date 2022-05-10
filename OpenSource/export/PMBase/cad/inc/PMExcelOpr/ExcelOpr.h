// ExcelOpr.h

#pragma once
/**
 * @brief  :利用NPOI 导入 Excel操作
 *
 *				目前：NPOI 是基于.net4.0的。经多次测试在cad2016下始终无法调用.net4.5的NPOI,原因未知，但可以调入.net4.0的版本的NPOI
 *			另外直接调用ZfyNPOI::ExcelToDataSet总是失败，我们只能用反射机制调用才可以成功
 *				zfy note 2020.01.13,之所以无法调用PmBimToolBar2016.dll（基于.net4.5), 是因为工程文件是从vs2008升级自上来的，他是基于.net4.0的，无法调用.net4.5，虽然，基于.net3.5
 *			的vs2008的excelopr能调用.net4.0的NPOI,但同样的操作.net4.0的excelopr无法调用.net4.5的ribbontoolbar。所以想成功调用，需要用新建clr工程的方式，
 *			重新新建工程，然后添加文件，这样新建出来的就是基于.net4.5的工程文件了，可轻松调用.net4.5的npoi及ribbon.
 * @author :zfy
 * @version:v1.0
 * @date   :[11/29/2019]
 * @note   :
 */
namespace ExcelOpr {

	class PMEXCELOPRDLLEXPIMPORT CNPOIExcel
	{
	public:
		CNPOIExcel();
		void SetExcelFilePath(CString excelFilePath);

		/**
		* @brief   把excel读取后导出成dataset
		*
		*			不知道为什么,debug下listSheetName.Add(sheetName);会错，甚至不用CStringArray作为参数而用CString str = "aaaa";也会报错
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [11/6/2019]
		*/
		BOOL ExportToDataSet(CStringArray & listSheetName,CArray<NDataModelDataSet *> & arrDataset);

		/**
		* @brief   读取excel中的所有的页名
		*
		*			
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [11/8/2019]
		*/
		BOOL GetSheetNames(CStringArray & arrSheetName);

	private:
		CString m_strFilePath;
	};

	class PMEXCELOPRDLLEXPIMPORT CCADCommand
	{
	public:
		/**
		* @brief   刷新ribbon工具栏，根据 ToolBarConfig_Action.xml 文件
		*			当runMode为 0时，访问ToolBarConfig_SL.xml
		*			当runMode为 1时，访问ToolBarConfig_GJ.xml
		*			当runMode不为0也不为1时，先尝试访问ToolBarActionXML\runMode\comtype.xml，如果不存在则访问ToolBarConfig_Action.xml
		*			
		* @note  : 
		* @param : runMode :0 算量 ，1 钢筋
		* @param : comtype :构件comtype，无构件时为 <= 0
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [1/8/2020]
		*/
		static void UpdateToolBar(int runMode,int comtype);

		//将当前工程路径传入ribbon工具栏
		static void SetProjectPath(CString projectPath);

		//锁定ribbon界面
		static void LockRibbon();

		//解锁ribbon界面
		static void UnLockRibbon();

		/**
		* @brief   恢复默认的ribbon工具栏
		*
		*			
		* @note  : 
		* @param : runMode :0 算量 ，1 钢筋
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [1/8/2020]
		*/
		static void LoadDefault(int runMode);

	private:
		static void UpdateToolBarCommon(int runMode,int comtype,bool bOnAction);
	};
}
