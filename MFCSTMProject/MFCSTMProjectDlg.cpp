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

// Custom Defines
#define YTOP 50

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
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSTMProjectDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSTMProjectDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_WM_LBUTTONDBLCLK()
    ON_BN_CLICKED(IDC_R_HALF_NOTE, &CMFCSTMProjectDlg::OnBnClickedRHalfNote)
    ON_BN_CLICKED(IDC_R_QUARTER_NOTE, &CMFCSTMProjectDlg::OnBnClickedRQuarterNote)
    ON_BN_CLICKED(IDC_R_EIGHTH_NOTE, &CMFCSTMProjectDlg::OnBnClickedREighthNote)
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
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    // TODO: Add extra initialization here

    // Set default radio button
    CButton* pButton = (CButton*)GetDlgItem(IDC_R_QUARTER_NOTE);
    pButton->SetCheck(true);

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

// Draw note on mouse click location
void CMFCSTMProjectDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    CClientDC dc(this);
    int x = point.x;
    int y = point.y;

    // 'rectify' vertical input
    y = (y + 5) / 10;
    y *= 10;

    if (y < (YTOP - 10) || y >(YTOP + 90) || x < 90)
        return;

    // draw note head (quarter note)
    dc.SelectStockObject(DC_BRUSH);
    dc.SetDCBrushColor(RGB(0, 0, 0));
    dc.Ellipse(x - 8, y - 7, x + 8, y + 7);
    // draw stem
    dc.MoveTo(x + 7, y);
    dc.LineTo(x + 7, y - 40);

    // if (half note) : draw hole
    if (m_nNoteLength == 4)
    {
        dc.SetDCBrushColor(RGB(240, 240, 240));
        dc.Ellipse(x - 6, y - 5, x + 6, y + 5);
    }

    // if (eighth note) : draw flag
    if (m_nNoteLength == 1)
    {
        LOGBRUSH logBrush;
        logBrush.lbStyle = BS_SOLID;
        logBrush.lbColor = RGB(0, 0, 0);
        CPen thickline(PS_GEOMETRIC | PS_ENDCAP_SQUARE, 7, &logBrush);
        dc.SelectObject(&thickline);
        dc.MoveTo(x + 10, y - 36);
        dc.LineTo(x + 17, y - 36);
    }

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
