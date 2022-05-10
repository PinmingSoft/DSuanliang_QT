#ifndef PMWBQD_LOADEXCEL_H
#define PMWBQD_LOADEXCEL_H

#include <QWidget>
#include <QDialog>
#include "ui_DlgWbqd_LoadExcel.h"
#include "WbqdStandardItemModel.h"

class CDlgWbqd_LoadExcel : public QDialog
{
	Q_OBJECT

public:
	CDlgWbqd_LoadExcel(QString excelFile,QWidget *parent = 0);
	~CDlgWbqd_LoadExcel();

	//获取表格数据
	const CWbqd_LoadExcelItemModel * GetModelData() const;

	//是否覆盖
	bool IsCover() const;

public slots:
	void On_ComboBoxSheet_CurrentIndexChanged(QString curSel);
	void On_tableViewContent_DataChanged(QStandardItem * item);
	void On_pushButtonSave_Clicked();
	virtual void accept();
	virtual void reject();

private:
	//初始化
	void Init();

	//填充表格内容
	void FillSheetContent(QString sheetName);

	/**
	* @brief   纠正头部文字，分离
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/8/2019]
	*/
	void CorrectHeadText(CWbqd_LoadExcelItemModel * pContentModel);

	//分离出项目名称与项目特征
	void SplitColumn_XMMCAndXMTZ(CWbqd_LoadExcelItemModel * pContentModel);

private:
	Ui::CDlgWbqd_LoadExcel ui;

	//
	QString m_strExcelFile;

	//
	bool m_bFillSheet;

	//excel每页的内容
	std::map<CString,NDataModelDataSet *> m_mapSheetToContents;
};

#endif // PMWBQD_LOADEXCEL_H
