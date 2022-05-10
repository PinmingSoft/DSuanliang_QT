#include "StdAfx.h"
#include "Wbqd_LoadExcel_Delegate.h"

QString WBQD::kXMBM;	//项目编码
QString WBQD::kXMMC;	//项目名称
QString WBQD::kXMTZ;	//项目特征
QString WBQD::kJLDW;	//计量单位
QString WBQD::kCKGCL;	//参考工程量
QString WBQD::kCKDJ;	//参考合价
QString WBQD::kCKHJ;	//参考单价
void WBQD::InitValue()
{
	WBQD::kXMBM = QObject::tr("项目编码");	//项目编码
	WBQD::kXMMC = QObject::tr("项目名称");	//项目名称
	WBQD::kXMTZ = QObject::tr("项目特征");	//项目特征
	WBQD::kJLDW = QObject::tr("计量单位");	//计量单位
	WBQD::kCKGCL= QObject::tr("参考工程量");	//参考工程量
	WBQD::kCKDJ = QObject::tr("参考单价");	//参考合价
	WBQD::kCKHJ = QObject::tr("参考合价");	//参考单价
}

bool WBQD::IsWBQDField(const QString & field)
{
	if (field == WBQD::kXMBM
		||field == WBQD::kXMMC
		||field == WBQD::kXMTZ
		||field == WBQD::kJLDW
		||field == WBQD::kCKGCL
		||field == WBQD::kCKDJ
		||field == WBQD::kCKHJ)
	{
		return true;
	}
	return false;
}

bool WBQD::IsXMMCAndXMTZ(const QString & field)
{
	QString strMergeField = WBQD::kXMMC;
	strMergeField += WBQD::kXMTZ;
	if (field == strMergeField)
		return true;
	return false;
}

void InitComboHeader(QComboBox * pCombox)
{
	QStringList listName;
	CWbqd_LoadExcel_Delegate::GetColumnName(listName);
	listName.insert(0,"");
	
	//
	pCombox->addItems(listName);
}

void CWbqd_LoadExcel_Delegate::GetColumnName(QStringList & nameList)
{
	nameList <<WBQD::kXMBM<<WBQD::kXMMC<<WBQD::kXMTZ<<WBQD::kJLDW<<WBQD::kCKGCL<<WBQD::kCKDJ<<WBQD::kCKHJ;
}

QWidget *    CWbqd_LoadExcel_Delegate::createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
	int nColumn = index.column();
	int nRow = index.row();
	QWidget *editor = NULL;
	if(0 == nRow && 0 != nColumn)
	{
		QComboBox * pCombox = new QComboBox(parent);
		editor = pCombox;
	}
	else if(0 == nRow && 0 == nColumn)
	{
		QCheckBox * pCheckBox = new QCheckBox(parent);
		editor = pCheckBox;
	}
	else
	{
		QLineEdit * pTxt = new QLineEdit(parent);
		editor = pTxt;
	}
	return editor;
}

void CWbqd_LoadExcel_Delegate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{
	int nColumn = index.column();
	int nRow = index.row();
	QStandardItemModel *pModel = static_cast<QStandardItemModel *>(m_pTable->model());
	if(0 == nRow && 0 != nColumn)
	{
		QComboBox * pCombox = static_cast<QComboBox *>(editor);
		InitComboHeader(pCombox);
		pCombox->setCurrentIndex(pCombox->findText(pModel->data(index).toString()));
		//读取结构体数据
		//pCombox->setCurrentIndex(pCombox->findData(pModel->data(index,Qt::UserRole)));
	}
	else if(0 == nRow && 0 == nColumn)
	{
		QCheckBox * pCheckBox = static_cast<QCheckBox *>(editor);
		pCheckBox->setChecked(pModel->data(index).toBool());
	}
	else
	{
		QLineEdit * pTxt = static_cast<QLineEdit *>(editor);
		pTxt->setText(pModel->data(index).toString());
	}
}

void CWbqd_LoadExcel_Delegate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
	int nColumn = index.column();
	int nRow = index.row();
	if(0 == nRow && 0 != nColumn)
	{
		QComboBox *	pCombox = static_cast<QComboBox *>(editor);
		QString str    = pCombox->currentText();
		model->setData(index,str);
		//存储结构提数据
		//int nComIndex  = pCombox->currentIndex();
		//QVariant varID = pCombox->itemData(nComIndex);
		//model->setData(index,varID,Qt::UserRole);
	}
	else if(0 == nRow && 0 == nColumn)
	{
		QCheckBox * pCheckBox = static_cast<QCheckBox *>(editor);
		model->setData(index,pCheckBox->isChecked());
	}
	else
	{
		QLineEdit * pTxt = static_cast<QLineEdit *>(editor);
		model->setData(index,pTxt->text());
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QWidget *    CWbqd_TreeView_Delegate::createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
	const QStandardItemModel * pModel = static_cast<const QStandardItemModel *>(index.model());
	QLineEdit * pTxt = new QLineEdit(parent);
	//QPalette lette;
	//QVariant var = pModel->data(index,Qt::BackgroundRole);
	//QColor clr = QColor::fromRgba(var.toUInt());
	//lette.setColor(QPalette::WindowText,clr);
	//pTxt->setPalette(lette);
	//
	return pTxt;
}

void CWbqd_TreeView_Delegate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{
	if(NULL == editor)
		return;
	QLineEdit * pTxt = static_cast<QLineEdit *>(editor);
	const QStandardItemModel * pModel = static_cast<const QStandardItemModel *>(index.model());
	pTxt->setText(pModel->data(index).toString());
	//QVariant clr = pModel->data(index,Qt::BackgroundColorRole);
	//pTxt->setBackgroundColor(QColor(clr));
}

void CWbqd_TreeView_Delegate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
	if(NULL == editor)
		return;
	//
	QLineEdit * pTxt = static_cast<QLineEdit *>(editor);
	model->setData(index,pTxt->text());
}