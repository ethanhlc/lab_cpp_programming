// MFCSTMProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCSTMProject.h"
#include "MFCSTMProjectDlg.h"
#include "afxdialogex.h"

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

// CMFCSTMProjectDlg dialog

CMFCSTMProjectDlg::CMFCSTMProjectDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFCSTMPROJECT_DIALOG, pParent)
    , m_strNoteDisp(_T(""))
    , m_strDebug(_T(""))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSTMProjectDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_LIST, m_strNoteDisp);
    DDX_Text(pDX, IDC_EDIT_DEBUG, m_strDebug);
    DDX_Control(pDX, IDC_COMBO_COMPORT, m_comboCOMPort);
    DDX_Control(pDX, IDC_COMBO_BAUD, m_comboBaudRate);
    DDX_CBString(pDX, IDC_COMBO_COMPORT, m_strCOMPort);
    DDX_CBString(pDX, IDC_COMBO_BAUD, m_strBaudRate);
}

BEGIN_MESSAGE_MAP(CMFCSTMProjectDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_LBUTTONDBLCLK()

    // SerialComm BEGIN
    ON_MESSAGE(WM_MYCLOSE, &CMFCSTMProjectDlg::OnThreadClosed)
    ON_MESSAGE(WM_MYRECEIVE, &CMFCSTMProjectDlg::OnReceive)
    // SerialComm END

    ON_BN_CLICKED(IDC_R_HALF_NOTE, &CMFCSTMProjectDlg::OnBnClickedRHalfNote)
    ON_BN_CLICKED(IDC_R_QUARTER_NOTE, &CMFCSTMProjectDlg::OnBnClickedRQuarterNote)
    ON_BN_CLICKED(IDC_R_EIGHTH_NOTE, &CMFCSTMProjectDlg::OnBnClickedREighthNote)
    ON_BN_CLICKED(IDC_BTN_LIST, &CMFCSTMProjectDlg::OnBnClickedBtnList)
    ON_BN_CLICKED(IDC_BTN_ERASE, &CMFCSTMProjectDlg::OnBnClickedBtnErase)
    ON_BN_CLICKED(IDC_BTN_REDRAW, &CMFCSTMProjectDlg::OnBnClickedBtnRedraw)
    ON_BN_CLICKED(IDC_BTN_CONNECT_CLOSE, &CMFCSTMProjectDlg::OnBnClickedConnectClose)
    ON_CBN_SELCHANGE(IDC_COMBO_BAUD, &CMFCSTMProjectDlg::OnSelchangeComboBaud)
    ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &CMFCSTMProjectDlg::OnSelchangeComboComport)
    ON_CBN_DROPDOWN(IDC_COMBO_COMPORT, &CMFCSTMProjectDlg::OnDropdownComboComport)
END_MESSAGE_MAP()

// CMFCSTMProjectDlg message handlers

BOOL CMFCSTMProjectDlg::OnInitDialog()
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
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon

    // TODO: Add extra initialization here

    // Set default radio button
    CButton* pButton = (CButton*)GetDlgItem(IDC_R_QUARTER_NOTE);
    pButton->SetCheck(true);

    // Init COM & Baud Combo Boxes
    m_comboBaudRate.AddString(_T("9600"));
    m_comboBaudRate.AddString(_T("19200"));
    m_comboBaudRate.AddString(_T("115200"));

    m_comboCOMPort.AddString(_T("COM1"));
    m_comboCOMPort.AddString(_T("COM2"));
    m_comboCOMPort.AddString(_T("COM3"));
    m_comboCOMPort.AddString(_T("COM4"));
    m_comboCOMPort.AddString(_T("COM5"));
    m_comboCOMPort.AddString(_T("COM6"));
    m_comboCOMPort.AddString(_T("COM7"));
    m_comboCOMPort.AddString(_T("COM8"));
    m_comboCOMPort.AddString(_T("COM9"));

    UpdateData(0);

    // Init SerialComm

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCSTMProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCSTMProjectDlg::OnPaint()
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

        for (int i = 0; i < 5; i++)
        {
            dc.MoveTo(25, YTOP + (i * 20));
            dc.LineTo(810, YTOP + (i * 20));
        }
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCSTMProjectDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

/// <summary>
/// Sort notes vector
/// </summary>
void CMFCSTMProjectDlg::SortNotes()
{
    std::sort(m_vctNotes.begin(), m_vctNotes.end());
}

/// <summary>
/// Draw notes into 'staff'
/// </summary>
void CMFCSTMProjectDlg::DrawNotes(int x, int y, int dur)
{
    CClientDC dc(this);

    // draw note head (quarter note)
    dc.SelectStockObject(DC_BRUSH);
    dc.SetDCBrushColor(RGB(0, 0, 0));
    dc.Ellipse(x - 8, y - 7, x + 8, y + 7);
    // draw stem
    dc.MoveTo(x + 7, y);
    dc.LineTo(x + 7, y - 40);

    // if (half note) : draw hole
    if (dur == 4)
    {
        dc.SetDCBrushColor(RGB(240, 240, 240));
        dc.Ellipse(x - 6, y - 5, x + 6, y + 5);
    }

    // if (eighth note) : draw flag
    if (dur == 1)
    {
        LOGBRUSH logBrush;
        logBrush.lbStyle = BS_SOLID;
        logBrush.lbColor = RGB(0, 0, 0);
        CPen thickline(PS_GEOMETRIC | PS_ENDCAP_SQUARE, 7, &logBrush);
        dc.SelectObject(&thickline);
        dc.MoveTo(x + 10, y - 36);
        dc.LineTo(x + 17, y - 36);
    }
}

// SerialComm BEGIN
LRESULT CMFCSTMProjectDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
    ((CSerialComm*)lpara)->HandleClose();
    delete ((CSerialComm*)lpara);

    return 0;
}

LRESULT CMFCSTMProjectDlg::OnReceive(WPARAM length, LPARAM lpara)
{
    return LRESULT();
}
// SerialComm END

// Draw note on mouse click location
void CMFCSTMProjectDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    //CClientDC dc(this);
    int x = point.x;
    int y = point.y;

    // 'rectify' vertical input
    y = (y + 5) / 10;
    y *= 10;

    if (y < (YTOP - 10) || y >(YTOP + 90) || x < 90)
        return;

    DrawNotes(x, y, m_nNoteLength);

    // push note into vector
    CNotes currNote(x, y, m_nNoteLength);
    m_vctNotes.push_back(currNote);

    // display note list (debug)
    CString strList;

    strList.Format(_T("x: %d, y: %d\r\n"), x, y);
    m_strDebug += strList;

    UpdateData(0);

    CDialogEx::OnLButtonDblClk(nFlags, point);
}

void CMFCSTMProjectDlg::OnBnClickedRHalfNote()
{
    m_nNoteLength = 4;
}

void CMFCSTMProjectDlg::OnBnClickedRQuarterNote()
{
    m_nNoteLength = 2;
}

void CMFCSTMProjectDlg::OnBnClickedREighthNote()
{
    m_nNoteLength = 1;
}

void CMFCSTMProjectDlg::OnBnClickedBtnList()
{
    m_strNoteDisp = "";
    CString strF;

    SortNotes();
    for (auto& r : m_vctNotes)
    {
        strF.Format(_T("Note: %d, Dur: %d\r\n"), r.GetNote(), r.GetDur());
        m_strNoteDisp += strF;
    }

    UpdateData(0);
}

void CMFCSTMProjectDlg::OnBnClickedBtnErase()
{
    Invalidate(true);   // erase notes
    m_vctNotes.clear();
    m_strNoteDisp = "";
    m_strDebug = "";
    UpdateData(0);
}

void CMFCSTMProjectDlg::OnBnClickedBtnRedraw()
{
    Invalidate(true);   // erase notes
    UpdateWindow();     // redraw staff
    SortNotes();

    int idx = 0;
    int x;
    for (auto& r : m_vctNotes)
    {
        x = 90 + (idx * 30);
        DrawNotes(x, r.y, r.GetDur());

        // update vector
        r.x = x;

        idx++;
    }
}

void CMFCSTMProjectDlg::OnBnClickedConnectClose()
{
    if (comport_state)  // connection exists
    {
        if (m_comm)     // comport exists
        {
            KillTimer(1000);
            m_comm->Close();
            m_comm = NULL;
            AfxMessageBox(_T("COM Port Closed"));
            GetDlgItem(IDC_BTN_CONNECT_CLOSE)->SetWindowText(_T("Open"));
            //GetDlgItem(IDC_BTN_SEND)->EnableWindow(false);
            comport_state = false;
        }
    }
    else
    {
        m_comm = new CSerialComm(_T("\\\\.\\") + m_strCOMPort, m_strBaudRate, _T("None"), _T("8 Bit"), _T("1 Bit"));
        if (m_comm->Create(GetSafeHwnd()) != 0) // open port & handover window handle
        {
            SetTimer(1000, 10, NULL);
            AfxMessageBox(_T("COM Port Opened"));
            //GetDlgItem(IDC_BTN_CONNECT_CLOSE)->SetWindowText(m_strCOMPort); // display connected port on btn
            GetDlgItem(IDC_BTN_CONNECT_CLOSE)->SetWindowText(_T("Close"));
            //GetDlgItem(IDC_BTN_SEND)->EnableWindow(true);
            comport_state = true;
        }
        else
        {
            AfxMessageBox(_T("Connection Error!"));
        }
    }
}

void CMFCSTMProjectDlg::OnSelchangeComboBaud()
{
    UpdateData(1);
}

void CMFCSTMProjectDlg::OnSelchangeComboComport()
{
    UpdateData(1);
}


void CMFCSTMProjectDlg::OnDropdownComboComport()
{
    // populate combo entry
    SendDlgItemMessage(IDC_COMBO_COMPORT, CB_RESETCONTENT);
    HKEY hKey;
    RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), &hKey);

    int index = 0;
    DWORD dwSize = 100;
    TCHAR szName[100] = { 0, };
    //char szName[100] = { 0, };
    //wchar_t szName[100] = { 0, };
    while (ERROR_SUCCESS == RegEnumValue(hKey, index, szName, &dwSize, NULL, NULL, NULL, NULL)) {
        DWORD dwType = REG_SZ;
        DWORD dwSize2 = 20;
        char szData[20] = { 0, };
        RegQueryValueEx(hKey, szName, NULL, &dwType, (LPBYTE)szData, &dwSize2);

        SendDlgItemMessage(IDC_COMBO_COMPORT, CB_ADDSTRING, 0, (LPARAM)szData);
        index++;

        dwSize = 100;
        memset(szName, 0, sizeof(szName));
    }
    RegCloseKey(hKey);
    // END populate combo entry
}
