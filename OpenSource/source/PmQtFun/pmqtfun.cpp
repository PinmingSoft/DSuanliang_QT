#include "stdafx.h"
#include "pmqtfun.h"

void PmQtFun::TrimEnter(QString & des)
{
	des.trimmed();
	TrimEnterL(des);
	TrimEnterR(des);
}

void PmQtFun::TrimEnterL(QString & des)
{
	bool bMatch = false;
	do
	{
		bMatch = false;
		if(des.isEmpty())
			break;
		//
		QChar chr = des[0];
		if(chr== ' '||chr == '\n'||chr == '\t'||chr == '\r')
		{
			des.remove(0,1);
			bMatch = true;
		}
	}while(bMatch);
}

void PmQtFun::TrimEnterR(QString & des)
{
	bool bMatch = false;
	do
	{
		bMatch = false;
		if(des.isEmpty())
			break;
		//
		int nLastIndex = des.length() - 1;
		QChar chr = des.at(nLastIndex);
		if(chr== ' '||chr == '\n'||chr == '\t'||chr == '\r')
		{
			des.remove(nLastIndex,1);
			bMatch = true;
		}
	}while(bMatch);
}