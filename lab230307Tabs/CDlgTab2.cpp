// CDlgTab2.cpp : implementation file
//

#include "pch.h"
#include "lab230307Tabs.h"
#include "CDlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 dialog

IMPLEMENT_DYNAMIC(CDlgTab2, CDialogEx)

CDlgTab2::CDlgTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB2, pParent)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTab2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgTab2 message handlers
void CDlgTab2::OnCancel()
{
	;
}


void CDlgTab2::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Tab2 Button");
}
