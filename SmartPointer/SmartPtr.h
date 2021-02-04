#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__
#pragma once

//����ָ��ģ����
template <typename T>
class SmartPtr
{
public:	//���еĹ��캯�����涼Ҫ�ԣ����ü���������ָ����г�ʼ��
	//���еĶ�������ü�����ַ�Ͷ���ָ���ַ����һ����,���ĳһ�����������ˣ����еĶ���ͬ���仯
	SmartPtr() :_ptr(new T()), _ref(new int(1)) {};								//Ĭ�Ϲ��캯��
	//SmartPtr() :_ptr(NULL), _ref(NULL) {};									//Ĭ�Ϲ��캯�� �������CreateInstance��Ӧ
	SmartPtr(T* p) :_ptr(p), _ref(new int(1)){};						//�������캯��1������������ָ���Ա������ʱ�����ġ�
	SmartPtr(const SmartPtr& sptr) :_ptr(sptr._ptr), _ref(sptr._ref){ ++ *_ref; };	//�������캯��2��
public:	//��������
	~SmartPtr()	//ÿһ�������������ڽ�����Ҫ�����ü�����1
	{
		if(--*_ref == 0)
		{//���ԭ�������ü���Ϊ0���ͷ�ԭ����ָ��
			delete _ptr;
			delete _ref;
		}
	}

public:	//���ز�����
	T* operator ->(){ return _ptr; }		//���ز����� ->
	T& operator *()	{ return *_ptr; }		//���ز����� *
	SmartPtr& operator =(SmartPtr& inst)	//���ز����� =
	{
		++ *inst._ref;	//���ü�����1
		if (--*_ref == 0)
		{//���ԭ�������ü�����1��Ϊ0���ͷ�ԭ����ָ��
			delete _ptr;
			delete _ref;
		}
		_ptr = inst._ptr;
		_ref = inst._ref;
		return *this;
	}

private:
	int* _ref;		//���ü�����ref��ʾreference���õ���˼
	T* _ptr;		//Ҫ����Ķ����ָ��

public:
	//void CreateInstance(){ _ptr = new T(); _ref = new int(1); }	
	void PrintInfo(){ printf("\nThis is a Smarter Pointer"); }
};



#endif  //_SMARTPTR_H__