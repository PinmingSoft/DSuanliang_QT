#ifndef PMQTFUN_H
#define PMQTFUN_H

namespace PmQtFun
{
	/**
	* @brief   ��������ͷβ�Ŀո񡢻س������С�ָ�����
	*
	*			GB2312�涨"������һ��ͼ���ַ������������ֽڱ�ʾ��ÿ���ֽھ�������λ�����ʾ"��
	*			ϰ���ϳƵ�һ���ֽ�Ϊ"���ֽ�"���ڶ����ֽ�Ϊ"���ֽ�"��
	*          ����뷶Χ�Ǹ�λ0XA1-0XFE����λҲ��0XA1-0XFE�����ֱ��뷶Χ�Ǹ�λ0XB0-0XF7����λ��0XA1-0XFE.
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/9/2019]
	*/
	void TrimEnter(QString & des);
	void TrimEnterL(QString & des);
	void TrimEnterR(QString & des);
};

#endif // PMQTFUN_H
