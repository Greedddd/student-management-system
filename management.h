#ifndef MANAGEMENT_H
#define MANAGEMENT_H//��ֹ�ض���
#include"student.h"
#include<list>
#include<fstream>
#include<iostream>
using namespace std;
class management{
public:
	list<student>alist;//�����յ�list����
	void addstudent(student);//����ѧ��
	void deletestudent(student);//ɾ��ѧ��
	void modifystudent(student);//�޸�ѧ��
	void checkstudent();//��ʾȫ��ѧ��
	void sortstudent(int);//���ɼ���������ѧ��
private:
	student stu;
	
};
#endif