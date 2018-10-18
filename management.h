#ifndef MANAGEMENT_H
#define MANAGEMENT_H//防止重定义
#include"student.h"
#include<list>
#include<fstream>
#include<iostream>
using namespace std;
class management{
public:
	list<student>alist;//建立空的list链表
	void addstudent(student);//增加学生
	void deletestudent(student);//删除学生
	void modifystudent(student);//修改学生
	void checkstudent();//显示全部学生
	void sortstudent(int);//按成绩排序所有学生
private:
	student stu;
	
};
#endif