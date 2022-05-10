#pragma once
class PMProjectDBSERVICE CCalComponentBG
{
public:
	CCalComponentBG(void);
	~CCalComponentBG(void);

	/// 判断是否修改的是标高相关参数
	static BOOL IsChangeBG(int comtypeCur, const CString & parmChanged);

	/**
	* @brief   重新联动标高,基于基准标高不变，重新计算另外一个标高
	*			注意：1、重计算后，如果某个dataset本来的标高存在 kMultiValue，将被设置为具体值
	*				  2、内部重算的参数是基于CComponentInfo中缓存的标高参数，不是dataset，所以要记得先保存dataset中界面修改的参数到CComponentInfo缓存中
	*				
	*			1.用于某标高改动过后，另一标高或者插入点标高重算
	*			2.用于界面显示时的的工程标高重算
	*			3.本函数的定义修改是因为 qc:26038
	* @note  : 本函数 是 基于原先的 他人写的的 ReCalComponentBG 进行重新修改。重新 清晰定义了 参数含义
	* @param : nChangeMode : 0 表示 插入点标高、顶底标高 要减去一个楼地面标高 进行显示，通常用于将UI的dataset(工程标高)转为数据存储用
							 1 表示 插入点标高、顶底标高 根据实际标高模式决定加减进行联动，或者存储用dataset转界面用UI的dataset
							 2 通常 插入点标高、顶底标高 存在联动，顶底标高 不进行楼地面标高的加减,插入点标高根据实际标高模式决定加减进行联动。用于dataset间的复制
	*
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/17/2018]
	*/
	static BOOL ReCalComponentBG_Base(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	/**
	* @brief  重算顶 底 标高
	*			
	*          注意：1、qc:30186,此 pDataSetForDb 我们为数据库存储用的标高，统一为相对标高 ，不允许存在 非法的比如：kMultiValue
	*				 2、内部重算的参数是基于CComponentInfo中缓存的标高参数，不是dataset，所以要记得先保存dataset中界面修改的参数到CComponentInfo缓存中
	* @note  : 
	* @param : strEditParmName 表示被编辑的数据
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName, NDataModelDataSet * pDataSetForDb);
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName);

	/**
	* @brief  	对dataset中的标高进行工程标高或楼层标高的转化，如果参数中带有$符号，我们不进行转化，因为这种参数无论是界面ui的database还是保存到数据库用的dataset都是一致
	*			1、重计算后，如果某个dataset本来的标高存在 kMultiValue（此时通常是 ui用dataset），将被设置为具体值 
	*			2、这个转化用参数是基于pDataSet的，不要求pDataSet 要先保存到 CComponentInfo缓存中
	*          
	* @note  : 
	* @param : nChangeMode : 0 表示 插入点标高、顶底标高 要减去一个楼地面标高 进行显示，通常用于将UI的dataset(工程标高)转为数据存储用
							 1 表示 存储用dataset转界面用UI的dataset
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ChangeWithLCBG_GCBG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

private:
	/**
	* @brief  重算顶 底 标高
	*			
	*          注意：1、qc:30186,此 pDataSetForDb 我们为数据库存储用的标高，统一为相对标高 ，不允许存在 非法的比如：kMultiValue
	*				 2、内部重算的参数是基于CComponentInfo中缓存的标高参数，不是dataset，所以要记得先保存dataset中界面修改的参数到CComponentInfo缓存中
	* @note  : 
	* @param : strEditParmName 表示被编辑的数据
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_DibgImp(int iComID, CString strEditParmName,CString & strMdfName, CString & strMdfValue);
};

