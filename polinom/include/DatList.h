#ifndef _POLINOM_LIB_TDATLIST_
#define _POLINOM_LIB_TDATLIST_

#include <exception>
#include "DatLink.h"
#include "RootLink.h"

template<class T>
class TDatList {
protected:
	TDatLink<T>* pFirst; // ������ �����
	TDatLink<T>* pLast; // ��������� �����
	TDatLink<T>* pCurrLink; // ������� �����
	TDatLink<T>* pPrevLink; // ����� ����� �������
	TDatLink<T>* pStop; // �������� ���������, ����������� ����� ������
	int CurrPos; // ����� �������� ����� (��������� �� 0)
	int ListLen; // ���������� ������� � ������
protected: // ������
	//TDatLink* GetLink(T* pVal = NULL, TDatLink* pLink = NULL);
	void DelLink(const TDatLink<T>* pLink); // �������� �����
public:
	TDatList();
	TDatList(const TDatList<T>& q);
	~TDatList(void) { DelList(); }
	// ������
	T* GetDatValue(const int pos) const; // ��������
	T* GetDatValue(void) const { return GetDatValue(CurrPos); } // ��������
	virtual int IsEmpty(void) const { return pFirst == pStop; } // ������ ���� ?
	int GetLength(void) const { return ListLen; } // �-�� �������
	TDatLink<T>* GetFirst(void) const { return pFirst; }
	TDatLink<T>* GetLast(void) const { return pLast; }
	// ���������
	int SetCurrentPos(const int pos); // ���������� ������� �����
	int GetCurrentPos(void) const { return CurrPos; } // �������� ����� ���. �����
	virtual int Reset(void); // ���������� �� ������ ������
	virtual int IsListEnded(void) const; // ������ �������� ?
	virtual int GoNext(void); // ����� ������ �������� �����
	// (=1 ����� ���������� GoNext ��� ���������� ����� ������)
	// ������� �������
	virtual void InsFirst(T* pVal = NULL); // ����� ������
	virtual void InsLast(T* pVal = NULL); // �������� ���������
	virtual void InsCurrent(T* pVal = NULL); // ����� �������
	// �������� �������
	virtual void DelFirst(void); // ������� ������ �����
	virtual void DelCurrent(void); // ������� ������� �����
	virtual void DelList(void); // ������� ���� ������
	TDatList<T>& operator=(const TDatList<T>& q);
};

#include "../src/DatList.hpp"

#endif