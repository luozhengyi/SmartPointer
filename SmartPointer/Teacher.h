#ifndef __TEACHER_H__
#define __TEACHER_H__

class CTeacher
{
public:
	CTeacher();
	~CTeacher();
public:
	void SetName(const char* szName);
	void SetAge(int iAge);
	void Print();
private:
	char m_szName[20];
	int m_iAge;
};


#endif  //__TEACHER_H__