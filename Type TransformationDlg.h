// Type TransformationDlg.h : header file
//
#if !defined(AFX_TYPETRANSFORMATIONDLG_H__3407224F_B713_4C9D_AF6E_388B2F1842CE__INCLUDED_)
#define AFX_TYPETRANSFORMATIONDLG_H__3407224F_B713_4C9D_AF6E_388B2F1842CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTypeTransformationDlg dialog

class CTypeTransformationDlg : public CDialog
{
// Construction
public:
	int m_FloatNume;
	CString m_FloatTemp;
	void CStringToFloat();
	void EditViewCode(CString CodeTemp);
	void CStringToLong();
	void CStringToInt();
	CString m_LongTemp;
	int m_longNume;
	CString m_EditStr;
	CString	m_EditView;
	CString m_DataType;
	int	m_IntNume;
	int m_StringNume;
	CString m_inttemp ;
	
	CTypeTransformationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTypeTransformationDlg)
	enum { IDD = IDD_TYPETRANSFORMATION_DIALOG };
	CComboBox	m_ComboDataTypeString;
	CComboBox	m_ComboDataType;
	CEdit	m_ViewEdit;
	CEdit	m_Edit;
	CButton	m_CleanEditButton;
	CButton	m_CodeButton;
	CButton	m_StatButton;
	int		m_RadioButtonCString;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeTransformationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTypeTransformationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabControy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonClean();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonCode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TYPETRANSFORMATIONDLG_H__3407224F_B713_4C9D_AF6E_388B2F1842CE__INCLUDED_)
