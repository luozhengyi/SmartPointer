#include "stdafx.h"
#include "Teacher.h"
#include "string.h"
#include <iostream>
using namespace std;

CTeacher::CTeacher()
{
	memset(m_szName,0,20);
	m_iAge=0;
}

CTeacher::~CTeacher()
{
	
}

void CTeacher::SetName(const char* szName)
{
	if(szName)
		strncpy(m_szName,szName,(20-1));
}

void CTeacher::SetAge(int iAge)
{
	m_iAge=iAge;
}

void CTeacher::Print()
{
	cout<<"ÐÕÃû£º"<<m_szName<<endl;
	cout<<"ÄêÁä£º"<<m_iAge<<endl;
}