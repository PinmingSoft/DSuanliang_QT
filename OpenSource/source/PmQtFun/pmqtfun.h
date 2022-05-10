#ifndef PMQTFUN_H
#define PMQTFUN_H

namespace PmQtFun
{
	/**
	* @brief   清楚输入的头尾的空格、回车、换行、指标符等
	*
	*			GB2312规定"对任意一个图形字符都采用两个字节表示，每个字节均采用七位编码表示"，
	*			习惯上称第一个字节为"高字节"，第二个字节为"低字节"。
	*          其编码范围是高位0XA1-0XFE，低位也是0XA1-0XFE；汉字编码范围是高位0XB0-0XF7，低位是0XA1-0XFE.
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
