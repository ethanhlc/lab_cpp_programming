// CDlgTab1.cpp : implementation file
//

#include "pch.h"
#include "lab230307Tabs.h"
#include "CDlgTab1.h"
#include "afxdialogex.h"


// CDlgTab1 dialog

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB1, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTab1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgTab1 message handlers


void CDlgTab1::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Tab1 Button");
}
