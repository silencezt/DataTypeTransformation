// Type TransformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Type Transformation.h"
#include "Type TransformationDlg.h"
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString CstringToInt = "CString stre='abc';\r\n int intResult;\r\n intResult= atoi((const char*)stre); ";  //// CString to int Code
CString CStringtoLong = "CString stre='abc';\r\n long longResult;\r\n longResult = _ttol((const char*)stre);";//// CString to long Code
CString CStringfoFloat = "CString stre='1.2';\r\n float floatResult;\r\n floatResult = atof((const char*)stre);";///CString to float

/////////////////////////////////////////////////////////////////////////////
// CTypeTransformationDlg dialog

CTypeTransformationDlg::CTypeTransformationDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTypeTransformationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTypeTransformationDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTypeTransformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTypeTransformationDlg)
	DDX_Control(pDX, IDC_COMBO_CHECKDATATYPE, m_ComboDataType);
	DDX_Control(pDX, IDC_EDIT_VIEW, m_ViewEdit);
	DDX_Control(pDX, IDC_EDIT, m_Edit);
	DDX_Control(pDX, IDC_BUTTON_CLEAN, m_CleanEditButton);
	DDX_Control(pDX, IDC_BUTTON_CODE, m_CodeButton);
	DDX_Control(pDX, IDC_BUTTON_START, m_StatButton);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTypeTransformationDlg, CDialog)
//{{AFX_MSG_MAP(CTypeTransformationDlg)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_CLEAN, OnButtonClean)
ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
ON_BN_CLICKED(IDC_BUTTON_CODE, OnButtonCode)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTypeTransformationDlg message handlers

BOOL CTypeTransformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialogs
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	
	
	//// set Commbo box  
	   ((CComboBox*)GetDlgItem(IDC_COMBO_CHECKDATATYPE))->SetCurSel(0);
	   
	   return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTypeTransformationDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTypeTransformationDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CTypeTransformationDlg::OnButtonClean() 
{
	// TODO: Add your control notification handler code here
	
	m_Edit.SetWindowText(""); ///////Clean Editbox  
	m_ViewEdit.SetWindowText(""); ////Clean EditViewBox
	m_inttemp.Empty();
}

void CTypeTransformationDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	m_Edit.GetWindowText(m_EditStr); ///get edit content
	m_ComboDataType.GetWindowText(m_DataType);///get  commbobox content

	
    m_IntNume = strcmp(m_DataType,"CString --->int");//// commbox conten compare
	m_longNume = strcmp(m_DataType,"CString --->long");
	m_FloatNume = strcmp(m_DataType,"CString --->float");

	
	if (m_EditStr!="")	///  Determine input content
	{
		if (m_IntNume ==0)
		{	
			CStringToInt(); //// call Function
			
		}
		else if (m_longNume ==0)///  Determine input content 
		{
			CStringToLong(); //// call Function
		}
		else if (m_FloatNume==0) ///  Determine input content 
		{
			CStringToFloat();/// call Function
		}
		
	}
	else
	{
		MessageBox("The input box cannot be empty! ! !","WARING");
	}
	
}



void CTypeTransformationDlg::OnButtonCode() 
{
	// TODO: Add your control notification handler code here
	
	if (m_inttemp!=""&&m_IntNume ==0)//  Determine DataType and EditView  
	{
		EditViewCode(CstringToInt);
	}
	else if (m_LongTemp!=""&&m_longNume==0) //Determine DataType and EditView 
	{
		EditViewCode(CStringtoLong);
	}
	else if (m_FloatTemp!=""&&m_FloatNume==0)//Determine DataType and EditView 
	{
		EditViewCode(CStringfoFloat);
	}
	else
	{
		MessageBox("Please implement data conversion first Or Choose the right type!!!","WARNING");
	}
	
}

//////////////////////////////////////////Data type  to Function!!!!!!

void CTypeTransformationDlg::CStringToInt()
{
	int int_result = atoi((const char*)m_EditStr);	//// CString --> int
	m_inttemp.Format("%d",int_result);	/////  int-->CString
	m_ViewEdit.SetWindowText(m_inttemp);	////set  result view
}

void CTypeTransformationDlg::CStringToLong()
{
	long long_result = _ttol((const char*)m_EditStr);////CString -->long
	m_LongTemp.Format("%ld",long_result);///long --> CString
	m_ViewEdit.SetWindowText(m_LongTemp);///set result view

}
void CTypeTransformationDlg::CStringToFloat()
{
	float float_result = atof((const char*)m_EditStr);/////CString--->Float
	m_FloatTemp.Format("%f",float_result);/////Float ---> CString
	m_ViewEdit.SetWindowText(m_FloatTemp);////set result view
}


/////////////////////////////////////////////  

void CTypeTransformationDlg::EditViewCode(CString CodeTemp)/////////ViewCoeFuntion!!!!!!
{
	m_ViewEdit.SetWindowText(CodeTemp); 
}

