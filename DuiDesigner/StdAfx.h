#pragma once
#ifndef __STDAFX_H_2015_11_02
#define __STDAFX_H_2015_11_02
#define _SCL_SECURE_NO_WARNINGS
#include <wtypes.h>
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <sstream>

#ifdef _UNICODE
typedef std::wstring		_ZnString;
typedef std::wstringstream	_ZnSStream;
#else
typedef std::string			_ZnString;
typedef std::stringstream	_ZnSStream;
#endif

#define UILIB_STATIC
#include "../DuiLib/UIlib.h"
#include "../Lib/Lib.hpp"
#include "../Rapidxml/rapidxml_utils.hpp"
#include "../Rapidxml/rapidxml_print.hpp"
#include "ConfigManager.h"
#include "PluginManager.h"
#include "FileManager.h"
#include "Clipboard.h"
#include "Memorandum.h"
#include "Window/MainFrame.h"
#include "Window/SettingsWnd.h"
#include "Window/AboutWnd.h"
#include "Window/PreviewWnd.h"
#include "Window/DefaultAttrWnd.h"

extern CMainFrame*		g_pMainFrame;

// ���������
#ifdef _DEBUG
#define TRACE DuiLib::DUI__Trace
#else
#define TRACE
#endif

// �����ַ���
#define STR_WINDOW						_T("Window")
// ���������ַ���
#define STR_SCROLLBAR					_T("ScrollBar")
#define STR_HSCROLL						_T("HScrollBar")
#define STR_VSCROLL						_T("VScrollBar")
// ���ڵ�
#define STR_TREENODE					_T("TreeNode")
// ��Դ·��������
#define STR_RESOURCEPATH				_T("resousepath")
// �б�����
#define STR_LISTHEADER					_T("ListHeader")
#define STR_LISTHEADERITEM				_T("ListHeaderItem")
#define STR_LISTELEMENT					_T("ListElement")
#define STR_LISTLABELELEMENT			_T("ListLabelElement")
#define STR_LISTTEXTELEMENT				_T("ListTextElement")
#define STR_LISTCONTAINERELEMENT		_T("ListContainerElement")


// �Զ�����Ϣ

// ��ǰѡ��Ŀؼ������仯
#define MSG_EDIT_SELECTEDCHANGE		_T("MSG_EDIT_SELECTEDCHANGE")

// ��Ϣ�󶨺�
//#define Notify_Bind(class, name, message) {if(msg.pSender->GetName() == name && msg.sType == message){static class obj; obj.Work(msg);}}
//#define GlobleNotify_Bind(class, message) {if(msg.sType == message){static class obj; obj.Work(msg);}}
//#define Timer_Bind(class, name, timeid, elapse) {static bool bTimer = m_PaintManager.SetTimer(m_PaintManager.FindControl(name),timeid,elapse);if(msg.pSender->GetName() == name && msg.sType == DUI_MSGTYPE_TIMER && msg.wParam == timeid){static class obj; obj.Work(msg);}}
#define AutoHide(name, pt){static DuiLib::CControlUI* pObj = m_PaintManager.FindControl(name); if (pObj->IsVisible() && !::PtInRect(&pObj->GetPos(), pt)) {pObj->SetVisible(false);}}
#define DUI_GET_CONTROL_PTR(type, ptr, name) ptr = static_cast<type*>(m_PaintManager.FindControl(name))
#define ON_DUI_NOTIFY(fun, name, message) if (msg.pSender->GetName() == name && msg.sType == message) fun(msg)

// ��ȡ��ǰEXE·��
LPCTSTR cur_path();
// ���ļ�·���л�ȡ�ļ���
LPCTSTR get_filename(LPCTSTR _lpFilePath);
// ���ļ�·���л�ȡ·��
LPCTSTR get_path(LPCTSTR _lpFilePath);


// ������\0�ָ���\0\0��β���ַ�����
void split_string(LPCTSTR _lpStr, std::vector<DuiLib::CDuiString>& vecStr);
// ����DUILIB�������б�
void split_attrib_list(LPCTSTR _lpStr, std::map<DuiLib::CDuiString, DuiLib::CDuiString>& _mapAttr);
void create_attrib_list(_ZnString& _Str, const std::map<DuiLib::CDuiString, DuiLib::CDuiString>& _mapAttr);

// ����ת��
std::tr1::shared_ptr<char>		W2Str(const wchar_t* _lpwstr, UINT unCode = CP_ACP);
std::tr1::shared_ptr<wchar_t>	S2Wstr(const char* _lpStr, UINT unCode = CP_ACP);

// ��ȡ���ؼ�ָ��
DuiLib::CControlUI*			get_parent(DuiLib::CControlUI* _pControl);
// ��ȡ���ԵĽӿ�ָ��
IControlPlugin*				get_control_interface(DuiLib::CControlUI* _pControl);
// ���ݿؼ���ȡ���ⴰ��ָ��
DuiLib::CControlUI*			get_wnd_ptr(DuiLib::CControlUI* _pControl);
// ��ȡ���ڵĹ�������ָ��
IWindowSharedData*			get_wnd_shared_data(DuiLib::CControlUI* _pControl);
// ����һ��������Ψһ��ID
int							create_id();
// �ж�һ���ؼ��Ƿ���TreeNode�е���Ͽؼ� ���Ϊ�ٷ��ؿ�ָ�룬���Ϊ�淵������TreeNodeָ�룬���ΪTreeNode����ͷ��������ָ��
DuiLib::CTreeNodeUI*		is_tree_node_sub_control(DuiLib::CControlUI* _pControl);
// ������RECT��ԭ
RECT						normalize_rect(const RECT& _rc);
// ���������Ϣ
void						out_error(LPCTSTR _lpMsg);
#endif