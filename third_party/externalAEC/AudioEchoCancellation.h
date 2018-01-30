// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� AUDIOECHOCANCELLATION_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// AUDIOECHOCANCELLATION_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef AUDIOECHOCANCELLATION_EXPORTS
#define AUDIOECHOCANCELLATION_API __declspec(dllexport)
#else
#define AUDIOECHOCANCELLATION_API __declspec(dllimport)
#endif

namespace audioechocancellation {
	// �����Ǵ� AudioEchoCancellation.dll ������
	class AUDIOECHOCANCELLATION_API CAudioEchoCancellation {
	public:
		CAudioEchoCancellation(void);
	public:

		static CAudioEchoCancellation* Create(int sampFreq, int scSampFreq);
		static void Destroy(CAudioEchoCancellation *ptr);

		virtual int BufferFarendFrame(const short* nFarend,
			size_t nrOfSamples) = 0;

		virtual int ProcessFrame(const short* nNearend,
			unsigned int num_bands,
			short* nOut,
			unsigned int nrOfSamples,
			short msInSndCardBuf,
			int skew) = 0;
	};
}

extern AUDIOECHOCANCELLATION_API int nAudioEchoCancellation;

AUDIOECHOCANCELLATION_API int fnAudioEchoCancellation(void);
