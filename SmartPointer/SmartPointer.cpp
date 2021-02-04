// SmartPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Teacher.h"
#include "SmartPtr.h"
#include "windows.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//其实teacher10是一个SmartPtr类对象，它的成员变量中又有CTeacher类的对象
	SmartPtr<CTeacher> teacher10;						//默认构造函数
	//teacher10.CreateInstance();
	SmartPtr<CTeacher> teacher20(new CTeacher());		//拷贝函数1；
	SmartPtr<CTeacher> teacher11(teacher10);			//拷贝函数2,引用计数加1；

	//重载操作符 =
	teacher20 = teacher10;	//teacher2的地址引用要减1；teacher10的地址引用要加1；

	//重载操作符 -> ; *
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

