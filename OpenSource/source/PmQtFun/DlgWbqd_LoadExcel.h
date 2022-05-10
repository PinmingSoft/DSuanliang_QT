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

	//��ȡ�������
	const CWbqd_LoadExcelItemModel * GetModelData() const;

	//�Ƿ񸲸�
	bool IsCover() const;

public slots:
	void On_ComboBoxSheet_CurrentIndexChanged(QString curSel);
	void On_tableViewContent_DataChanged(QStandardItem * item);
	void On_pushButtonSave_Clicked();
	virtual void accept();
	virtual void reject();

private:
	//��ʼ��
	void Init();

	//���������
	void FillSheetContent(QString sheetName);

	/**
	* @brief   ����ͷ�����֣�����
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/8/2019]
	*/
	void CorrectHeadText(CWbqd_LoadExcelItemModel * pContentModel);

	//�������Ŀ��������Ŀ����
	void SplitColumn_XMMCAndXMTZ(CWbqd_LoadExcelItemModel * pContentModel);

private:
	Ui::CDlgWbqd_LoadExcel ui;

	//
	QString m_strExcelFile;

	//
	bool m_bFillSheet;

	//excelÿҳ������
	std::map<CString,NDataModelDataSet *> m_mapSheetToContents;
};

#endif // PMWBQD_LOADEXCEL_H
