// ExcelOpr.h

#pragma once
/**
 * @brief  :����NPOI ���� Excel����
 *
 *				Ŀǰ��NPOI �ǻ���.net4.0�ġ�����β�����cad2016��ʼ���޷�����.net4.5��NPOI,ԭ��δ֪�������Ե���.net4.0�İ汾��NPOI
 *			����ֱ�ӵ���ZfyNPOI::ExcelToDataSet����ʧ�ܣ�����ֻ���÷�����Ƶ��òſ��Գɹ�
 *				zfy note 2020.01.13,֮�����޷�����PmBimToolBar2016.dll������.net4.5), ����Ϊ�����ļ��Ǵ�vs2008�����������ģ����ǻ���.net4.0�ģ��޷�����.net4.5����Ȼ������.net3.5
 *			��vs2008��excelopr�ܵ���.net4.0��NPOI,��ͬ���Ĳ���.net4.0��excelopr�޷�����.net4.5��ribbontoolbar��������ɹ����ã���Ҫ���½�clr���̵ķ�ʽ��
 *			�����½����̣�Ȼ������ļ��������½������ľ��ǻ���.net4.5�Ĺ����ļ��ˣ������ɵ���.net4.5��npoi��ribbon.
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
		* @brief   ��excel��ȡ�󵼳���dataset
		*
		*			��֪��Ϊʲô,debug��listSheetName.Add(sheetName);�����������CStringArray��Ϊ��������CString str = "aaaa";Ҳ�ᱨ��
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [11/6/2019]
		*/
		BOOL ExportToDataSet(CStringArray & listSheetName,CArray<NDataModelDataSet *> & arrDataset);

		/**
		* @brief   ��ȡexcel�е����е�ҳ��
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
		* @brief   ˢ��ribbon������������ ToolBarConfig_Action.xml �ļ�
		*			��runModeΪ 0ʱ������ToolBarConfig_SL.xml
		*			��runModeΪ 1ʱ������ToolBarConfig_GJ.xml
		*			��runMode��Ϊ0Ҳ��Ϊ1ʱ���ȳ��Է���ToolBarActionXML\runMode\comtype.xml����������������ToolBarConfig_Action.xml
		*			
		* @note  : 
		* @param : runMode :0 ���� ��1 �ֽ�
		* @param : comtype :����comtype���޹���ʱΪ <= 0
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [1/8/2020]
		*/
		static void UpdateToolBar(int runMode,int comtype);

		//����ǰ����·������ribbon������
		static void SetProjectPath(CString projectPath);

		//����ribbon����
		static void LockRibbon();

		//����ribbon����
		static void UnLockRibbon();

		/**
		* @brief   �ָ�Ĭ�ϵ�ribbon������
		*
		*			
		* @note  : 
		* @param : runMode :0 ���� ��1 �ֽ�
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [1/8/2020]
		*/
		static void LoadDefault(int runMode);

	private:
		static void UpdateToolBarCommon(int runMode,int comtype,bool bOnAction);
	};
}
