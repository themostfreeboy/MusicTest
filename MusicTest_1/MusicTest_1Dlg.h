
// MusicTest_1Dlg.h : ͷ�ļ�
//

#pragma once


// CMusicTest_1Dlg �Ի���
class CMusicTest_1Dlg : public CDialogEx
{
// ����
public:
	CMusicTest_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MUSICTEST_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
