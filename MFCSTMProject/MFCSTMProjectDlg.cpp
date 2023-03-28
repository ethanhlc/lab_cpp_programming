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
    , m_strFile(_T(""))
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
    DDX_Text(pDX, IDC_EDIT_FILE, m_strFile);
    DDX_Control(pDX, IDC_COMBO_TEMPO, m_comboTempo);
    DDX_CBString(pDX, IDC_COMBO_TEMPO, m_strTempo);
}

BEGIN_MESSAGE_MAP(CMFCSTMProjectDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_RBUTTONDBLCLK()

    // SerialComm BEGIN
    ON_MESSAGE(WM_MYCLOSE, &CMFCSTMProjectDlg::OnThreadClosed)
    ON_MESSAGE(WM_MYRECEIVE, &CMFCSTMProjectDlg::OnReceive)
    // SerialComm END

    ON_WM_DESTROY()
    ON_CONTROL_RANGE(BN_CLICKED, IDC_R_HALF_NOTE, IDC_R_EIGHTH_REST, &CMFCSTMProjectDlg::OnBnClickedRNoteSelect)
    ON_BN_CLICKED(IDC_BTN_LIST, &CMFCSTMProjectDlg::OnBnClickedBtnList)
    ON_BN_CLICKED(IDC_BTN_ERASE, &CMFCSTMProjectDlg::OnBnClickedBtnErase)
    ON_BN_CLICKED(IDC_BTN_REDRAW, &CMFCSTMProjectDlg::OnBnClickedBtnRedraw)

    ON_CBN_SELCHANGE(IDC_COMBO_BAUD, &CMFCSTMProjectDlg::OnSelchangeComboBaud)
    ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &CMFCSTMProjectDlg::OnSelchangeComboComport)
    ON_CBN_DROPDOWN(IDC_COMBO_COMPORT, &CMFCSTMProjectDlg::OnDropdownComboComport)
    ON_BN_CLICKED(IDC_BTN_CONNECT_CLOSE, &CMFCSTMProjectDlg::OnBnClickedConnectClose)
    ON_BN_CLICKED(IDC_BTN_SEND, &CMFCSTMProjectDlg::OnBnClickedBtnSend)
    ON_BN_CLICKED(IDC_BTN_PLAY, &CMFCSTMProjectDlg::OnBnClickedBtnPlay)
    ON_BN_CLICKED(IDC_BTN_SAVE, &CMFCSTMProjectDlg::OnBnClickedBtnSave)
    ON_BN_CLICKED(IDC_BTN_LOAD, &CMFCSTMProjectDlg::OnBnClickedBtnLoad)
    ON_CBN_SELCHANGE(IDC_COMBO_TEMPO, &CMFCSTMProjectDlg::OnSelchangeComboTempo)
    ON_BN_CLICKED(IDC_BTN_TEMPO, &CMFCSTMProjectDlg::OnBnClickedBtnTempo)
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

    m_comboTempo.AddString(_T("  60"));
    m_comboTempo.AddString(_T("  80"));
    m_comboTempo.AddString(_T("100"));
    m_comboTempo.AddString(_T("120"));
    m_comboTempo.AddString(_T("200"));

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
void CMFCSTMProjectDlg::DrawNotes(int x, int y, int dur, bool rest)
{
    CClientDC dc(this);

    if (rest == false)
    {
        // draw note head (quarter note)
        dc.SelectStockObject(DC_BRUSH);
        dc.SetDCBrushColor(RGB(0, 0, 0));
        dc.Ellipse(x - 8, y - 7, x + 8, y + 7);
        // draw stem
        if (y > 90)     // stem on right
        {
            dc.MoveTo(x + 7, y);
            dc.LineTo(x + 7, y - 40);
        }
        else            // stem on left
        {
            dc.MoveTo(x - 8, y);
            dc.LineTo(x - 8, y + 40);
        }

        // draw additional staff
        if (y == (YTOP - 20) || y == (YTOP + 100))
        {
            dc.MoveTo(x - 13, y);
            dc.LineTo(x + 13, y);
        }
        else if (y == (YTOP - 30))
        {
            dc.MoveTo(x - 13, y + 10);
            dc.LineTo(x + 13, y + 10);
        }

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
            if (y > 90)
            {
                dc.MoveTo(x + 10, y - 36);
                dc.LineTo(x + 17, y - 36);
            }
            else
            {
                dc.MoveTo(x - 5, y + 36);
                dc.LineTo(x + 1, y + 36);
            }
        }
    }
    else
    {
        // brush definitions
        LOGBRUSH logBrush;
        logBrush.lbStyle = BS_SOLID;
        logBrush.lbColor = RGB(0, 0, 0);
        CPen qRest1(PS_GEOMETRIC | PS_ENDCAP_ROUND, 2, &logBrush);
        CPen qRest2(PS_GEOMETRIC | PS_ENDCAP_ROUND, 2, &logBrush);
        CPen halfRest(PS_GEOMETRIC | PS_ENDCAP_SQUARE, 4, &logBrush);

        // if (eighth rest)
        if (dur == 1)
        {
            dc.SelectStockObject(DC_BRUSH);
            dc.SetDCBrushColor(RGB(0, 0, 0));
            dc.Ellipse(x - 4, (YTOP + 33) - 4, x + 4, (YTOP + 33) + 4);
            dc.MoveTo(x + 4, YTOP + 30);
            dc.LineTo(x - 4, YTOP + 53);
        }
        // if (quarter rest)
        else if (dur == 2)
        {
            dc.SelectObject(&qRest1);
            dc.MoveTo(x + 2, YTOP + 23);
            dc.LineTo(x + 5, YTOP + 33);
            dc.SelectObject(&qRest2);
            dc.LineTo(x - 1, YTOP + 36);
            dc.SelectObject(&qRest1);
            dc.LineTo(x + 4, YTOP + 47);
            dc.LineTo(x - 2, YTOP + 47);
            dc.LineTo(x + 2, YTOP + 57);
        }
        // if (half rest)
        else if (dur == 4)
        {
            dc.SelectObject(&halfRest);
            dc.MoveTo(x - 2, YTOP + 38);
            dc.LineTo(x + 4, YTOP + 38);
        }
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

void CMFCSTMProjectDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    KillTimer(1000);
    m_comm->Close();
    m_comm = NULL;
}

// Draw note on mouse click location
void CMFCSTMProjectDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    //CClientDC dc(this);
    int x = point.x;
    int y = point.y;

    // 'rectify' vertical input
    y = (y + 5) / 10;
    y *= 10;

    if (y < (YTOP - 30) || y >(YTOP + 100) || x < 90)
        return;

    DrawNotes(x, y, m_nNoteLength, m_bRest);

    // push note into vector
    CNotes currNote(x, y, m_nNoteLength, m_bRest);
    m_vctNotes.push_back(currNote);

    // display note list (debug)
    CString strList;

    strList.Format(_T("x: %d, y: %d\r\n"), x, y);
    m_strDebug += strList;

    UpdateData(0);

    CDialogEx::OnLButtonDblClk(nFlags, point);
}

void CMFCSTMProjectDlg::OnBnClickedRNoteSelect(UINT nID)
{
    switch (nID)
    {
    case IDC_R_HALF_NOTE:
        m_nNoteLength = 4;
        m_bRest = false;
        break;
    case IDC_R_QUARTER_NOTE:
        m_nNoteLength = 2;
        m_bRest = false;
        break;
    case IDC_R_EIGHTH_NOTE:
        m_nNoteLength = 1;
        m_bRest = false;
        break;
    case IDC_R_HALF_REST:
        m_nNoteLength = 4;
        m_bRest = true;
        break;
    case IDC_R_QUARTER_REST:
        m_nNoteLength = 2;
        m_bRest = true;
        break;
    case IDC_R_EIGHTH_REST:
        m_nNoteLength = 1;
        m_bRest = true;
        break;
    default:
        break;
    }
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
        x = 90 + (idx * 20);
        DrawNotes(x, r.y, r.GetDur(), r.GetRest());

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
            GetDlgItem(IDC_COMBO_COMPORT)->EnableWindow(true);
            GetDlgItem(IDC_COMBO_BAUD)->EnableWindow(true);
            GetDlgItem(IDC_BTN_SEND)->EnableWindow(false);
            GetDlgItem(IDC_BTN_PLAY)->EnableWindow(false);
            GetDlgItem(IDC_BTN_TEMPO)->EnableWindow(false);
            GetDlgItem(IDC_COMBO_TEMPO)->EnableWindow(false);
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
            GetDlgItem(IDC_COMBO_COMPORT)->EnableWindow(false);
            GetDlgItem(IDC_COMBO_BAUD)->EnableWindow(false);
            GetDlgItem(IDC_BTN_SEND)->EnableWindow(true);
            GetDlgItem(IDC_BTN_TEMPO)->EnableWindow(true);
            GetDlgItem(IDC_COMBO_TEMPO)->EnableWindow(true);
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

void CMFCSTMProjectDlg::OnBnClickedBtnSend()
{
    CString strSend;
    SortNotes();

    //strSend = _T("LED 0\r\n");      // Debug
    m_comm->Send(_T("N"), 1);   // 0x4E : Note
    for (auto& note : m_vctNotes)
    {
        strSend = (char)note.note;
        m_comm->Send(strSend, 1);
    }

    m_comm->Send(_T("D"), 1);   // 0x44 : Duration
    for (auto& note : m_vctNotes)
    {
        strSend = (char)note.duration;
        m_comm->Send(strSend, 1);
    }

    strSend = (char)0x7f;       // end code
    m_comm->Send(strSend, 1);

    GetDlgItem(IDC_BTN_PLAY)->EnableWindow(true);   // enable 'Play' button
    //GetDlgItem(IDC_BTN_PLAY)->ShowWindow(true);     // display 'Play' button
}

void CMFCSTMProjectDlg::OnBnClickedBtnPlay()
{
    m_comm->Send(_T("P"), 1);   // 0x50 : Play
}

// Erase note on mouse right double click location
void CMFCSTMProjectDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
    int x = point.x;
    int y = point.y;

    // 'rectify' vertical input
    y = (y + 5) / 10;
    y *= 10;

    if (y < (YTOP - 10) || y >(YTOP + 90) || x < 90)
        return;

    std::vector<CNotes>::iterator it;
    for (it = m_vctNotes.begin(); it != m_vctNotes.end(); it++)
    {
        if (x > (it->x - 5) && x < (it->x + 5))
        {
            m_vctNotes.erase(it);
            break;
        }
    }

    // alternate erase method
    //int idx = 0;
    //for (auto& note : m_vctNotes)
    //{
    //    if (x > (note.x - 5) && x < (note.x + 5))
    //    {
    //        m_vctNotes.erase(m_vctNotes.begin() + idx);
    //        break;
    //    }
    //    idx++;
    //}

    OnBnClickedBtnRedraw();

    CDialogEx::OnRButtonDblClk(nFlags, point);
}

void CMFCSTMProjectDlg::OnBnClickedBtnSave()
{
    CFile file;
    SortNotes();

    UpdateData(1);
    if (file.Open(m_strFile, CFile::modeWrite | CFile::modeCreate) == false)
    {
        AfxMessageBox(_T("Could Not Save File"), MB_ICONSTOP);
        return;
    }

    CString strFormat;
    CString strWrite = _T("");
    for (auto& note : m_vctNotes)
    {
        strFormat.Format(_T("%d:%d:%d:%d\r\n"), note.x, note.y, note.duration, note.rest);
        strWrite += strFormat;
    }
    file.Write(strWrite.GetString(), strWrite.GetLength() * 2);
    file.Close();

    AfxMessageBox(_T("Music Saved"), MB_ICONASTERISK);
}

void CMFCSTMProjectDlg::OnBnClickedBtnLoad()
{
    CFile file;

    UpdateData(1);
    if (file.Open(m_strFile, CFile::modeRead) == false)
    {
        AfxMessageBox(_T("Could Not Open File"), MB_ICONSTOP);
        return;
    }

    OnBnClickedBtnErase();

    int x_in, y_in, dur_in;
    bool rest_in;
    CString strRead, subStr;
    CArchive ar(&file, CArchive::load);
    while (ar.ReadString(strRead))
    {
        if (strRead.GetLength())
        {
            //AfxMessageBox(strRead);
            int idx = 0;
            int pos = 0;
            subStr = strRead.Tokenize(_T(":"), pos);
            while (subStr != _T(""))
            {
                //AfxMessageBox(subStr);
                if (idx == 0)
                    x_in = _ttoi(subStr);
                else if (idx == 1)
                    y_in = _ttoi(subStr);
                else if (idx == 2)
                    dur_in = _ttoi(subStr);
                else if (idx == 3)
                    rest_in = _ttoi(subStr);
                idx++;
                subStr = strRead.Tokenize(_T(":"), pos);
            }
            CNotes currNote(x_in, y_in, dur_in, rest_in);
            m_vctNotes.push_back(currNote);
        }
    }
    ar.Close();
    file.Close();
    OnBnClickedBtnRedraw();

    AfxMessageBox(_T("Music Loaded"), MB_ICONASTERISK);
}

void CMFCSTMProjectDlg::OnSelchangeComboTempo()
{
    UpdateData(1);

    if (m_strTempo == _T("  60"))
        m_nTempo = 0;
    else if (m_strTempo == _T("  80"))
        m_nTempo = 1;
    else if (m_strTempo == _T("100"))
        m_nTempo = 2;
    else if (m_strTempo == _T("120"))
        m_nTempo = 3;
    else if (m_strTempo == _T("200"))
        m_nTempo = 4;
}

void CMFCSTMProjectDlg::OnBnClickedBtnTempo()
{
    UpdateData(1);
    CString strSend;
    m_comm->Send(_T("T"), 1);   // 0x54
    strSend = (char)m_nTempo;
    m_comm->Send(strSend, 1);
    AfxMessageBox(_T("Tempo set to: " + m_strTempo + "bpm"));
}
