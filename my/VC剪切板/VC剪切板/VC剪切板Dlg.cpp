
// VC���а�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VC���а�.h"
#include "VC���а�Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVC���а�Dlg �Ի���



CVC���а�Dlg::CVC���а�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVC���а�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVC���а�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVC���а�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_CLIPBOARDUPDATE()
	ON_BN_CLICKED(IDC_BUTTON1, &CVC���а�Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CVC���а�Dlg ��Ϣ�������

BOOL CVC���а�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	AddClipboardFormatListener(this->m_hWnd);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVC���а�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVC���а�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVC���а�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVC���а�Dlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	RemoveClipboardFormatListener(this->m_hWnd);

	CDialogEx::OnClose();
}


void CVC���а�Dlg::OnClipboardUpdate()
{
	// �˹���Ҫ�� Windows Vista ����߰汾��
	// _WIN32_WINNT ���ű��� >= 0x0600��
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!OpenClipboard())
		return;
	UINT uFormat;
	char szFormatName[1024];
	CString lpFormatName;
	uFormat = EnumClipboardFormats(0);
	while (uFormat)
	{
		//GetPriorityClipboardFormat()
		if (InArray(uFormat)){
			CString str;
			str.Format(_T("%d"), uFormat);
			lpFormatName = str;
		}
		else{
			if (GetClipboardFormatName(uFormat, (LPWSTR)szFormatName, 1024))
				lpFormatName = (LPWSTR)szFormatName;
			else
				lpFormatName = _T("(unknown)");
		}
		HGLOBAL hData = GetClipboardData(uFormat);
		byte *bData = (byte *)GlobalLock(hData);
		if (bData != NULL){
			WFile(lpFormatName, bData, GlobalSize(hData));
			GlobalUnlock(hData);
		}
		uFormat = EnumClipboardFormats(uFormat);
	}

	CloseClipboard();

	CDialogEx::OnClipboardUpdate();
}

void CVC���а�Dlg::WFile(LPCTSTR fileName, byte *content, UINT dLen){
	HANDLE hFile = CreateFile(CString("D:\\test\\clipboard\\") + CString(fileName), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE != hFile){
		DWORD dwSize = 0;
		WriteFile(hFile, content, dLen, &dwSize, NULL);
		CloseHandle(hFile);
	}
}


void CVC���а�Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileFind *cff = new CFileFind();
}

BOOL CVC���а�Dlg::InArray(UINT a){
	UINT ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 0x0080, 0x0081, 0x0082, 0x0083, 0x008E, 0x0200, 0x02FF, 0x0300, 0x03FF };;
	for (int i = 0; i < 27; i++){
		if (ar[i] == a)
			return TRUE;
	}
	return FALSE;
}