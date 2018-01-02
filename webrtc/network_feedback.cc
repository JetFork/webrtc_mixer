/********************************************************************
*@file		network_feedback.cc
*file path	E:\work\webrtc_HLD_0516\trunk
*Author:	Shelley Liu 
*Data:		20130521	
*@brief		���練��
*
*********************************************************************/

#include "network_feedback.h"

/**
* @brief    ������������״������
* @req		GVE-SRS-00X 2511
* @param[in]     nInf:��������ṹ�� 
* @param[in]     avgLossRateThreshold��ƽ����������ֵ
* @param[in]     avgDelayThreshold��ƽ����ʱ��ֵ
* @param[in]     ratioDelay����ʱ����ϵ��
* @param[in]     meetingPeopleNumber���λ�����
* @returns		int, genBandWidth, ����
*/
int NetworkFeedback::genNetworkBandwidth(NetParam * nInf, int avgLossRateThreshold, int avgDelayThreshold, double ratioDelay, int meetingPeopleNumber)
{
	int genBandWidth;
	//@Todo
	return genBandWidth;
}
//genBandWidth = genNetworkBandwidth(nInf, avgLossRateThreshold, avgDelayThreshold, ratioDelay, meetingPeopleNumber);

/**
* @brief    ������������㺯��
* @req		GVE-SRS-00X 2511
* @param[in]     nInf:��������ṹ�� 
* @param[in]     genBandWidth���ۺ��������
* @param[in]     minBitRate����Ƶ��С����
* @param[in]     maxBitRate����Ƶ������   
* @returns   int,  videoBandWidth, ��Ƶ���ô���
*/
int NetworkFeedback::upBandWidth(NetParam * nInf, int genBandWidth, int minBitRate, int maxBitRate);
{
	int videoBandWidth;
	//@Todo
	return videoBandWidth;
}
//videoBandWidth = upBandWidth(nInf, genBandWidth, minBitRate, maxBitRate);


/**
* @brief    ���練������ģʽѡ��
* @req		GVE-SRS-00X 2512
* @param[in]     runModel	����ģʽ
* @param[in]     adjustBandWidth	���������
*/
int NetworkFeedback::selectMode(int runModel, Packetstatics * sps, int adjustBandWidth)
{
	int adjustType;
	if (runModel == 1) //һ��ģʽ
	{
		adjustType = generalMode(sps, adjustBandWidth);
	} 
	else if (runModel == 2) //��������
	{
		adjustType = qualityPriorityMode(sps, adjustBandWidth);
	} 
	else //�˶�����
	{
		adjustType = motionPriorityMode(sps, adjustBandWidth);
	}
	//@Todo
	return adjustType;
}

/**
* @brief    һ��ģʽ������ģʽ������
* @req		GVE-SRS-00X 25121
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
int NetworkFeedback::generalMode(Packetstatics * sps, int adjustBandWidth)
{
	int adjustType;
	//@Todo
	return adjustType;
}
//adjustType = generalMode(sps, adjustBandWidth);

/**
* @brief    ��������ģʽ����
* @req		GVE-SRS-00X 25122
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
int NetworkFeedback::qualityPriorityMode(Packetstatics * sps, int adjustBandWidth)
{
	int adjustType;
	//@Todo
	return adjustType;
}

/**
* @brief    �˶�����ģʽ����
* @req		GVE-SRS-00X 25123
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
int NetworkFeedback::motionPriorityMode(Packetstatics * sps, int adjustBandWidth)
{
	int adjustType;
	//@Todo
	return adjustType;
}

/**
* @brief    ���ʵ���
* @req		GVE-SRS-00X 2513
* @param[in]     BitRate	����
* @param[in]     adjustType	���ڲ���
* @param[in]     adjustBandWidth	���������   
* @returns   int, ���º������
*/
int NetworkFeedback::AdjustBitRate(int BitRate, int adjustType, int adjustBandWidth)
{
	int New_BitRate;
	//@Todo;
	return New_BitRate;
}

/**
* @brief    lossPacketFilter ��֡�Ͷ���
* @req		GVE-SRS-00X 2514
* @param[in]     adjustType:�������Բ���
* @param[in] [out]     dataBuffer:RTP���ݰ��ĵ�ַ	
*/
void NetworkFeedback::lossPacketFilter(int adjustType, unsigned char * dataBuffer)
{
	//@Todo
}
//lossPacketFilter(adjustType, dataBuffer);

/**
* @brief    upThrowLayerFilter �������㣨ҵ������練����
* @req		GVE-SRS-00X 2515
* @param[in]     layer:��Ҫ�Ĳ���
* @param[in] [out]     dataBuffer:RTP���ݰ��ĵ�ַ   
*/
void NetworkFeedback::upThrowLayerFilter(int layer, unsigned char * dataBuffer)
{
	//@Todo
}
//upThrowLayerFilter(layer, dataBuffer);

/**
* @brief    ͳ�Ƹ������С����
* @req		GVE-SRS-00X 2516
* @param[in] [out]     sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    dataBuffer:RTP���ݰ��ĵ�ַ
* @param[in]    dataSize:RTP���ݰ��Ĵ�С 
*/
void NetworkFeedback::statisticsPacketSize(Packetstatics * sps, unsigned char *dataBuffer, int dataSize)
{
	//@Todo
}
//statisticsPacketSize(sps, dataBuffer, dataSize);