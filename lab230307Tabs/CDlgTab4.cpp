// CDlgTab4.cpp : implementation file
//

#include "pch.h"
#include "lab230307Tabs.h"
#include "CDlgTab4.h"
#include "afxdialogex.h"


// CDlgTab4 dialog

IMPLEMENT_DYNAMIC(CDlgTab4, CDialogEx)

CDlgTab4::CDlgTab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB4, pParent)
{

}

CDlgTab4::~CDlgTab4()
{
}

void CDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTab4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgTab4 message handlers
void CDlgTab4::OnCancel()
{
	;
}


void CDlgTab4::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Tab4 Button");
}
