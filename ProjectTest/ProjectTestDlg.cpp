// ProjectTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ProjectTest.h"
#include "ProjectTestDlg.h"
#include "afxdialogex.h"

//#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CProjectTestDlg dialog

CProjectTestDlg::CProjectTestDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_PROJECTTEST_DIALOG, pParent)
    , m_strInput(_T(""))
    , m_NoteList(_T(""))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_nNoteLength = 2;
}

void CProjectTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_PRINT_INPUT, m_strInput);
    DDX_Control(pDX, IDC_CLEF, m_Clef);
    DDX_Text(pDX, IDC_EDIT_LIST, m_NoteList);
}

BEGIN_MESSAGE_MAP(CProjectTestDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_LBUTTONDBLCLK()

    ON_MESSAGE(WM_MYCLOSE, &CProjectTestDlg::OnThreadClosed)
    ON_MESSAGE(WM_MYRECEIVE, &CProjectTestDlg::OnReceive)

    ON_BN_CLICKED(IDC_R_HALF, &CProjectTestDlg::OnBnClickedRHalf)
    ON_BN_CLICKED(IDC_R_QUARTER, &CProjectTestDlg::OnBnClickedRQuarter)
    ON_BN_CLICKED(IDC_R_EIGHTH, &CProjectTestDlg::OnBnClickedREighth)
    ON_BN_CLICKED(IDC_BN_ERASE, &CProjectTestDlg::OnBnClickedBnErase)
    ON_BN_CLICKED(IDC_BTN_LIST, &CProjectTestDlg::OnBnClickedBtnList)
    ON_BN_CLICKED(IDC_BTN_CONNECT, &CProjectTestDlg::OnBnClickedBtnConnect)
    ON_BN_CLICKED(IDC_BTN_SEND, &CProjectTestDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()

// CProjectTestDlg message handlers

BOOL CProjectTestDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
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
    CheckRadioButton(IDC_R_HALF, IDC_R_EIGHTH, IDC_R_QUARTER);

    CImage image;
    image.Load(_T("clef.png"));
    //HBITMAP h_clef = (HBITMAP) image;
    m_Clef.SetBitmap(image);
    UpdateData(0);

    //CBitmap bitm;
    //bitm.Attach(image.Detach());
    //((CStatic*)GetDlgItem(IDC_CLEF))->SetBitmap(image);
    //((CStatic*)GetDlgItem(IDC_CLEF))->SetBitmap(bitm);


    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjectTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjectTestDlg::OnPaint()
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
        //CDialogEx::OnPaint();
        CPaintDC dc(this);

        for (int y = 0; y < 5; y++) {
            dc.MoveTo(20, 50 + (y * 20));
            dc.LineTo(800, 50 + (y * 20));
        }

        //for (int y = 0; y < 18; y++)
        //{
        //	for (int x = 0; x < 18; x++)
        //	{
        //		dc.Rectangle(x * 30, y * 30, x * 30 + 30, y * 30 + 30);
        //	}
        //}
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProjectTestDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CProjectTestDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
    ((CSerialComm*)lpara)->HandleClose();
    delete ((CSerialComm*)lpara);

    return 0;
}

LRESULT CProjectTestDlg::OnReceive(WPARAM length, LPARAM lpara)
{
    return LRESULT();
}

void CProjectTestDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    CClientDC dc(this);
    int x = point.x;
    int y = (point.y + 5) / 10;
    //x = x * 20;
    y = y * 10;

    if (y < 40 || y > 140 || x < 90)
        return;

    dc.SelectStockObject(DC_BRUSH);
    dc.SetDCBrushColor(RGB(0, 0, 0));

    dc.Ellipse(x - 8, y - 7, x + 8, y + 7);

    if (m_nNoteLength == 4)
    {
        dc.SetDCBrushColor(RGB(255, 255, 255));
        dc.Ellipse(x - 6, y - 5, x + 6, y + 5);
    }

    // draw line
    // if (quarter note)
    dc.MoveTo(x + 7, y);
    dc.LineTo(x + 7, y - 40);

    // if (eight note)
    if (m_nNoteLength == 1) {
        LOGBRUSH logBrush;
        logBrush.lbStyle = BS_SOLID;
        logBrush.lbColor = RGB(0, 0, 0);
        CPen thickline(PS_GEOMETRIC | PS_ENDCAP_SQUARE, 7, &logBrush);
        dc.SelectObject(&thickline);
        dc.MoveTo(x + 10, y - 36);
        dc.LineTo(x + 17, y - 36);
    }

    CNotes currNote(x, y, m_nNoteLength);
    m_vctNotes.push_back(currNote);

    // Display Clicked Point
    CString strPoint;

    strPoint.Format(_T("x: %2d(%2d), y: %2d(%2d), note: %d"), point.x, x, point.y, y, currNote.GetNote());
    m_strInput += strPoint + _T("\t");

    UpdateData(0);
    // END Display

    CDialogEx::OnLButtonDblClk(nFlags, point);
}

void CProjectTestDlg::OnBnClickedRHalf()
{
    // TODO: Add your control notification handler code here
    m_nNoteLength = 4;
}

void CProjectTestDlg::OnBnClickedRQuarter()
{
    // TODO: Add your control notification handler code here
    m_nNoteLength = 2;
}

void CProjectTestDlg::OnBnClickedREighth()
{
    // TODO: Add your control notification handler code here
    m_nNoteLength = 1;
}


void CProjectTestDlg::OnBnClickedBnErase()
{
    // TODO: Add your control notification handler code here
    Invalidate(true);
    m_vctNotes.clear();
    UpdateData(1);
}


void CProjectTestDlg::OnBnClickedBtnList()
{
    // TODO: Add your control notification handler code here
    std::sort(m_vctNotes.begin(), m_vctNotes.end());

    m_NoteList = "";
    CString strF;
    for (auto& r : m_vctNotes)
    {
        strF.Format(_T("Note: %d, Dur: %d\r\n"), r.GetNote(), r.GetDur());
        m_NoteList += strF;
    }

    UpdateData(0);
}

bool CProjectTestDlg::sortFunc(const CNotes& a, const CNotes& b)
{
    return a.x > b.x;
}


void CProjectTestDlg::OnBnClickedBtnConnect()
{
    // TODO: Add your control notification handler code here
    if (comport_state)
    {
        if (m_comm)        //컴포트가존재하면
        {
            KillTimer(1000);
            m_comm->Close();
            m_comm = NULL;
            AfxMessageBox(_T("COM 포트닫힘"));
            comport_state = false;
            GetDlgItem(IDC_BTN_CONNECT)->SetWindowText(_T("OPEN"));
            GetDlgItem(IDC_BTN_SEND)->EnableWindow(false);
        }
    }
    else
    {
        m_comm = new CSerialComm(_T("\\\\.\\") + m_str_comport, m_combo_baudrate, _T("None"), _T("8 Bit"), _T("1 Bit"));         // initial Comm port
        if (m_comm->Create(GetSafeHwnd()) != 0) //통신포트를열고윈도우의핸들을넘긴다.
        {
            SetTimer(1000, 10, NULL);
            AfxMessageBox(_T("COM 포트열림"));
            comport_state = true;
            GetDlgItem(IDC_BTN_CONNECT)->SetWindowText(_T("CLOSE"));
            GetDlgItem(IDC_BTN_SEND)->EnableWindow(true);
        }
        else
        {
            AfxMessageBox(_T("ERROR!"));
        }
    }
}


void CProjectTestDlg::OnBnClickedBtnSend()
{
    // TODO: Add your control notification handler code here
    CString strSend;
    //strSend = _T("LED 0\r\n");
    m_comm->Send(_T("N"), 1);
    for (auto& note : m_vctNotes)
    {
        strSend = (char)note.note;
        m_comm->Send(strSend, 1);
    }
    m_comm->Send(_T("D"), 1);
    for (auto& note : m_vctNotes)
    {
        strSend = (char)note.duration;
        m_comm->Send(strSend, 1);
    }
        strSend = (char)0x7f;
        m_comm->Send(strSend, 1);

}
