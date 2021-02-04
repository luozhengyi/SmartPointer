#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__
#pragma once

//智能指针模板类
template <typename T>
class SmartPtr
{
public:	//所有的构造函数里面都要对：引用计数、对象指针进行初始化
	//所有的对象的引用计数地址和对象指针地址都是一样的,如果某一对象对其操作了，所有的都会同步变化
	SmartPtr() :_ptr(new T()), _ref(new int(1)) {};								//默认构造函数
	//SmartPtr() :_ptr(NULL), _ref(NULL) {};									//默认构造函数 与下面的CreateInstance对应
	SmartPtr(T* p) :_ptr(p), _ref(new int(1)){};						//拷贝构造函数1：当类里面有指针成员变量的时候必须的。
	SmartPtr(const SmartPtr& sptr) :_ptr(sptr._ptr), _ref(sptr._ref){ ++ *_ref; };	//拷贝构造函数2：
public:	//析构函数
	~SmartPtr()	//每一个对象生命周期结束后都要对引用计数减1
	{
		if(--*_ref == 0)
		{//如果原本的引用计数为0，释放原本的指针
			delete _ptr;
			delete _ref;
		}
	}

public:	//重载操作符
	T* operator ->(){ return _ptr; }		//重载操作符 ->
	T& operator *()	{ return *_ptr; }		//重载操作符 *
	SmartPtr& operator =(SmartPtr& inst)	//重载操作符 =
	{
		++ *inst._ref;	//引用计数加1
		if (--*_ref == 0)
		{//如果原本的引用计数减1后为0，释放原来的指针
			delete _ptr;
			delete _ref;
		}
		_ptr = inst._ptr;
		_ref = inst._ref;
		return *this;
	}

private:
	int* _ref;		//引用计数；ref表示reference引用的意思
	T* _ptr;		//要管理的对象的指针

public:
	//void CreateInstance(){ _ptr = new T(); _ref = new int(1); }	
	void PrintInfo(){ printf("\nThis is a Smarter Pointer"); }
};



#endif  //_SMARTPTR_H__