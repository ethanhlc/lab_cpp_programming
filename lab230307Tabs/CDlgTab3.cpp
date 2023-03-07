// CDlgTab3.cpp : implementation file
//

#include "pch.h"
#include "lab230307Tabs.h"
#include "CDlgTab3.h"
#include "afxdialogex.h"


// CDlgTab3 dialog

IMPLEMENT_DYNAMIC(CDlgTab3, CDialogEx)

CDlgTab3::CDlgTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB3, pParent)
{

}

CDlgTab3::~CDlgTab3()
{
}

void CDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTab3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgTab3 message handlers


void CDlgTab3::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Tab3 Button");
}
