// SmartPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Teacher.h"
#include "SmartPtr.h"
#include "windows.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//��ʵteacher10��һ��SmartPtr��������ĳ�Ա����������CTeacher��Ķ���
	SmartPtr<CTeacher> teacher10;						//Ĭ�Ϲ��캯��
	//teacher10.CreateInstance();
	SmartPtr<CTeacher> teacher20(new CTeacher());		//��������1��
	SmartPtr<CTeacher> teacher11(teacher10);			//��������2,���ü�����1��

	//���ز����� =
	teacher20 = teacher10;	//teacher2�ĵ�ַ����Ҫ��1��teacher10�ĵ�ַ����Ҫ��1��

	//���ز����� -> ; *
	CTeacher* pTea = new CTeacher();
	pTea->SetName("Uncle");
	(*pTea).SetAge(34);
	
	teacher10->SetName("LuoZhengYi");
	(*teacher10).SetAge(23);
	(*teacher10).Print();
	teacher10.PrintInfo();
	system("pause");
	return 0;
}

