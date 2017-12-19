/********************************************************************
*@file		network_feedback.h
*file path	E:\work\webrtc_HLD_0516\trunk
*Author:	Shelley Liu 
*Data:		20130521
*@brief		���練����ر�����������
*
*********************************************************************/

#ifndef NETWORK_FEEDBACK_H_
#define NETWORK_FEEDBACK_H_

/** 
* @defgroup	NetworkFeedback
*
* @brief	���練����غ���
*
*/

/** 
* @ingroup NetworkFeedback
*@brief		��������ṹ��
*/
typedef struct 
{
///	@Todo
}NetParam;

/** 
* @ingroup NetworkFeedback
*@brief		ͳ�Ƹ������С�Ľṹ��
*/
typedef struct 
{
	int I_Packets_Counts;
	int P_Packets_Counts;
	int B_Packets_Counts;
///	@Todo
}Packetstatics;

/** 
* @ingroup NetworkFeedback
* @brief	�������綪����ʹ�õĺ����Ͳ���
*/
class NetworkFeedback
{
public:
	NetworkFeedback();

	virtual ~NetworkFeedback();

/**
* @ingroup NetworkFeedback
* @brief    ������������״������
* @req		GVE-SRS-00X 2511
* @param[in]     nInf:��������ṹ�� 
* @param[in]     avgLossRateThreshold��ƽ����������ֵ
* @param[in]     avgDelayThreshold��ƽ����ʱ��ֵ
* @param[in]     ratioDelay����ʱ����ϵ��
* @param[in]     meetingPeopleNumber���λ�����
* @returns		int, genBandWidth, ����
*/
	int genNetworkBandwidth(NetParam * nInf, int avgLossRateThreshold, int avgDelayThreshold, double ratioDelay, int meetingPeopleNumber);
	//genBandWidth = genNetworkBandwidth(nInf, avgLossRateThreshold, avgDelayThreshold, ratioDelay, meetingPeopleNumber);

/**
* @ingroup NetworkFeedback
* @brief    ������������㺯��
* @req		GVE-SRS-00X 2511
* @param[in]     nInf:��������ṹ�� 
* @param[in]     genBandWidth���ۺ��������
* @param[in]     minBitRate����Ƶ��С����
* @param[in]     maxBitRate����Ƶ������   
* @returns   int,  videoBandWidth, ��Ƶ���ô���
*/
	int upBandWidth(NetParam * nInf, int genBandWidth, int minBitRate, int maxBitRate);
	//videoBandWidth = upBandWidth(nInf, genBandWidth, minBitRate, maxBitRate);

/**
* @ingroup NetworkFeedback
* @brief    ���練������ģʽѡ��
* @req		GVE-SRS-00X 2512
* @param[in]     runModel	����ģʽ
* @param[in]     adjustBandWidth	���������
*/
	int selectMode(int runModel, Packetstatics * sps, int adjustBandWidth);

/**
* @ingroup NetworkFeedback
* @brief    һ��ģʽ������ģʽ������
* @req		GVE-SRS-00X 25121
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
	int generalMode(Packetstatics * sps, int adjustBandWidth);
	//adjustType = generalMode(sps, adjustBandWidth);

/**
* @ingroup NetworkFeedback
* @brief    ��������ģʽ����
* @req		GVE-SRS-00X 25122
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
	int qualityPriorityMode(Packetstatics * sps, int adjustBandWidth);

/**
* @ingroup NetworkFeedback
* @brief    �˶�����ģʽ����
* @req		GVE-SRS-00X 25123
* @param[in]    sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    adjustBandWidth:��Ҫ�����Ĵ�����    
* @returns   int, ����������ÿ��bitλ����ͬ�ĺ��壬�������SRS
*/
	int motionPriorityMode(Packetstatics * sps, int adjustBandWidth);

/**
* @ingroup NetworkFeedback
* @brief    ���ʵ���
* @req		GVE-SRS-00X 2513
* @param[in]     BitRate	����
* @param[in]     adjustType	���ڲ���
* @param[in]     adjustBandWidth	���������   
* @returns   int, ���º������
*/
	int AdjustBitRate(int BitRate, int adjustType, int adjustBandWidth);

/**
* @ingroup NetworkFeedback
* @brief    lossPacketFilter ��֡�Ͷ���
* @req		GVE-SRS-00X 2514
* @param[in]     adjustType:�������Բ���
* @param[in] [out]     dataBuffer:RTP���ݰ��ĵ�ַ	
*/
	void lossPacketFilter(int adjustType, unsigned char * dataBuffer);
	//lossPacketFilter(adjustType, dataBuffer);

/**
* @ingroup NetworkFeedback
* @brief    upThrowLayerFilter �������㣨ҵ������練����
* @req		GVE-SRS-00X 2515
* @param[in]     layer:��Ҫ�Ĳ���
* @param[in] [out]     dataBuffer:RTP���ݰ��ĵ�ַ   
*/
	void upThrowLayerFilter(int layer, unsigned char * dataBuffer);
	//upThrowLayerFilter(layer, dataBuffer);

/**
* @ingroup NetworkFeedback
* @brief    ͳ�Ƹ������С����
* @req		GVE-SRS-00X 2516
* @param[in] [out]     sps:ͳ�Ƹ������С�Ľṹ��
* @param[in]    dataBuffer:RTP���ݰ��ĵ�ַ
* @param[in]    dataSize:RTP���ݰ��Ĵ�С 
*/
	void statisticsPacketSize(Packetstatics * sps, unsigned char *dataBuffer, int dataSize);
	//statisticsPacketSize(sps, dataBuffer, dataSize);
		 
protected:
private:
	NetParam * nInf;
	Packetstatics * sps;

	///@Todo
};


#endif