
// MusicTest_1.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "MusicTest_1.h"
#include "MusicTest_1Dlg.h"


#include "mmsystem.h"
#include "Digitalv.h"
#pragma comment(lib,"winmm")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMusicTest_1App

BEGIN_MESSAGE_MAP(CMusicTest_1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMusicTest_1App ����

CMusicTest_1App::CMusicTest_1App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMusicTest_1App ����

CMusicTest_1App theApp;


// CMusicTest_1App ��ʼ��

BOOL CMusicTest_1App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMusicTest_1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���


		LPWSTR   buf = NULL;
		//use   mciSendString()   
		//mciSendString("play   e:\\songs\\�Ѹ���ס.mp3",buf,sizeof(buf),NULL);   
		//mciSendString("play   e:\\songs\\zhj.mp3",buf,sizeof(buf),NULL);   
		//char   str[128]   =   {0};   
		//int   i   =   0;   

		//use   mciSendCommand   
		MCI_OPEN_PARMS   mciOpen;
		MCIERROR   mciError;
		//mciOpen.lpstrDeviceType   =   (LPCTSTR)MCI_ALL_DEVICE_ID;   
		//mciOpen.lpstrDeviceType   =   "waveaudio";   //ֻ�ܲ���.wav�ļ�   
		//mciOpen.lpstrDeviceType   =   "avivideo";     //*.avi   
		mciOpen.lpstrDeviceType = _T("mpegvideo");
		//mciOpen.lpstrDeviceType   =   "sequencer";   
		mciOpen.lpstrElementName = _T(".\\res\\MusicTest_1.mp3");
		//mciOpen.lpstrElementName   =   "e:\\movie\\first.avi";   
		//mciOpen.lpstrElementName   =   "c:\\winnt\\media\\Windows   ��¼��.wav";   
		mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
		if (mciError)
		{
			mciGetErrorString(mciError, buf, 128);
			MessageBox(NULL, _T("send MCI_PLAY command failed"), _T("ERROR"), MB_OK);
		}
		UINT   DeviceID = mciOpen.wDeviceID;
		MCI_PLAY_PARMS   mciPlay;

		//mciError   =   mciSendCommand(DeviceID,MCI_PLAY,0   ,(DWORD)&mciPlay);  
		//MCI_FROM | MCI_TO | 
		mciError = mciSendCommand(DeviceID, MCI_PLAY, MCI_WAIT | MCI_DGV_PLAY_REPEAT, (DWORD)(LPMCI_PLAY_PARMS)&mciPlay);  //MCI_DGV_PLAY_REPEAT, Ҫ #include "Digitalv.h",��Ҫ��#include "mmsystem.h"֮�󣬷��򱨴�
		if (mciError)
		{
			mciGetErrorString(mciError, buf, 128);
			MessageBox(NULL, _T("send MCI_PLAY command failed"), _T("ERROR"), MB_OK);
		}

	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

