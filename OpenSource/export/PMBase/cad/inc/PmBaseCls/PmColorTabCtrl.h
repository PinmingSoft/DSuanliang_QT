#pragma once
#include "atlimage.h"
#include "PmTooltip.h"

/**
 * @brief  :ʵ�����б���ɫ��ͼƬ���Զ���tabctrl
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[11/27/2017]
 * @note   :
 */
using namespace ATL;
namespace Gdiplus
{
	class Image;
};
class PMBASECLASSAPI CColorTabCtrl : public CTabCtrl
{
public:
	DECLARE_DYNAMIC(CColorTabCtrl)
	CColorTabCtrl()
	{

	}

	virtual ~CColorTabCtrl()
	{

	}

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	DECLARE_MESSAGE_MAP()

};