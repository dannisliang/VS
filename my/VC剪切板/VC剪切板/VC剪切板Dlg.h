
// VC���а�Dlg.h : ͷ�ļ�
//

#pragma once


// CVC���а�Dlg �Ի���
class CVC���а�Dlg : public CDialogEx
{
	// ����
public:
	CVC���а�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_VC_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	void WFile(LPCTSTR fileName, byte *content, UINT dLen);


	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnClipboardUpdate();
	afx_msg void OnBnClickedButton1();
	BOOL InArray(UINT a);
};
