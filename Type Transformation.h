// Type Transformation.h : main header file for the TYPE TRANSFORMATION application
//

#if !defined(AFX_TYPETRANSFORMATION_H__1721A49A_5190_4515_89EF_5ACCEC6A331E__INCLUDED_)
#define AFX_TYPETRANSFORMATION_H__1721A49A_5190_4515_89EF_5ACCEC6A331E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTypeTransformationApp:
// See Type Transformation.cpp for the implementation of this class
//

class CTypeTransformationApp : public CWinApp
{
public:
	CTypeTransformationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeTransformationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTypeTransformationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TYPETRANSFORMATION_H__1721A49A_5190_4515_89EF_5ACCEC6A331E__INCLUDED_)
