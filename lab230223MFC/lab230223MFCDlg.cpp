
// lab230223MFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab230223MFC.h"
#include "lab230223MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg: public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg(): CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab230223MFCDlg dialog



Clab230223MFCDlg::Clab230223MFCDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB230223MFC_DIALOG, pParent)
	, m_upper(_T(""))
	, m_lower(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_operand1 = 0;
	m_operand2 = 0;
	m_operator = 0;
	m_result = 0;
	m_opDone = false;
}

void Clab230223MFCDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITUPPER, m_upper);
	DDX_Text(pDX, IDC_EDITINPUT, m_lower);
}

BEGIN_MESSAGE_MAP(Clab230223MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NUM0, &Clab230223MFCDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_NUM1, &Clab230223MFCDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &Clab230223MFCDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &Clab230223MFCDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM4, &Clab230223MFCDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &Clab230223MFCDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &Clab230223MFCDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM7, &Clab230223MFCDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &Clab230223MFCDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &Clab230223MFCDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_BTNDEL, &Clab230223MFCDlg::OnBnClickedBtndel)
	ON_BN_CLICKED(IDC_CE, &Clab230223MFCDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_NUMNEG, &Clab230223MFCDlg::OnBnClickedNumneg)
	ON_BN_CLICKED(IDC_CLEAR, &Clab230223MFCDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_BTNPLUS, &Clab230223MFCDlg::OnBnClickedBtnplus)
	ON_BN_CLICKED(IDC_BTNEQUALS, &Clab230223MFCDlg::OnBnClickedBtnequals)
	ON_BN_CLICKED(IDC_BTNMINUS, &Clab230223MFCDlg::OnBnClickedBtnminus)
	ON_BN_CLICKED(IDC_BTNMUL, &Clab230223MFCDlg::OnBnClickedBtnmul)
	ON_BN_CLICKED(IDC_BTNDIV, &Clab230223MFCDlg::OnBnClickedBtndiv)
	ON_BN_CLICKED(IDC_BTNMOD, &Clab230223MFCDlg::OnBnClickedBtnmod)
END_MESSAGE_MAP()


// Clab230223MFCDlg message handlers

BOOL Clab230223MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab230223MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Clab230223MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Clab230223MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Clab230223MFCDlg::OnBnClickedNum0()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "0";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "0";
	}
	else
	{
		m_lower = m_lower + '0';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum1()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "1";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "1";
	}
	else
	{
		m_lower = m_lower + '1';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum2()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "2";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "2";
	}
	else
	{
		m_lower = m_lower + '2';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum3()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "3";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "3";
	}
	else
	{
		m_lower = m_lower + '3';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum4()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "4";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "4";
	}
	else
	{
		m_lower = m_lower + '4';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum5()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "5";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "5";
	}
	else
	{
		m_lower = m_lower + '5';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum6()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "6";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "6";
	}
	else
	{
		m_lower = m_lower + '6';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum7()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "7";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "7";
	}
	else
	{
		m_lower = m_lower + '7';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum8()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "8";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "8";
	}
	else
	{
		m_lower = m_lower + '8';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNum9()
{
	// TODO: Add your control notification handler code here
	if (m_opDone)
	{
		m_lower = "9";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0")
	{
		m_lower = "9";
	}
	else
	{
		m_lower = m_lower + '9';
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedNumneg()
{
	// TODO: Add your control notification handler code here
	if (m_lower[0] != '-')
	{
		//m_lower = '-' + m_lower;
		m_lower.Insert(0, '-');
	}
	else
	{
		m_lower.Remove('-');
	}
	UpdateData(0);
}

void Clab230223MFCDlg::OnBnClickedBtndel()
{
	// TODO: Add your control notification handler code here
	if (m_lower == "0")
	{
		return;
	}
	else
	{
		m_lower.Truncate(m_lower.GetLength() - 1);
	}
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedCe()
{
	// TODO: Add your control notification handler code here
	m_lower = "0";
	UpdateData(0);
}



void Clab230223MFCDlg::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	m_upper = "";
	m_lower = "0";
	m_operand1 = 0;
	m_operand2 = 0;
	m_operator = 0;
	m_opDone = false;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtnequals()
{
	// TODO: Add your control notification handler code here
	int temp_operand;
	if (!m_opDone)
		m_operand2 = GetDlgItemInt(IDC_EDITINPUT);
	if (m_operator == 1)	// plus
	{
		m_result = m_operand1 + m_operand2;
		m_upper.Format(L"%d + %d =", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 2)
	{
		m_result = m_operand1 - m_operand2;
		m_upper.Format(L"%d - %d =", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 3)
	{
		m_result = m_operand1 * m_operand2;
		m_upper.Format(L"%d x %d =", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 4)
	{
		m_result = m_operand1 / m_operand2;
		m_upper.Format(L"%d / %d =", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 5)
	{
		m_result = m_operand1 % m_operand2;
		m_upper.Format(L"%d %% %d =", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 0)
	{
		m_upper = m_lower + L" =";
	}
	m_operand1 = m_result;		// for consecutive operation
	m_opDone = true;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtnplus()
{
	// TODO: Add your control notification handler code here
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 1;
	m_upper = m_lower + L" +";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtnminus()
{
	// TODO: Add your control notification handler code here
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 2;
	m_upper = m_lower + L" -";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtnmul()
{
	// TODO: Add your control notification handler code here
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 3;
	m_upper = m_lower + L" x";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtndiv()
{
	// TODO: Add your control notification handler code here
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 4;
	m_upper = m_lower + L" /";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}


void Clab230223MFCDlg::OnBnClickedBtnmod()
{
	// TODO: Add your control notification handler code here
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 5;
	m_upper = m_lower + L" %";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}
