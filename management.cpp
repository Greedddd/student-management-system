#include "stdafx.h"
#include<iostream>
#include"student.h"
#include"management.h"
#include<list>
#include<fstream>
#include"student management system1.0Dlg.h"

int Dec = 0;

bool SORT(student a1, student a2){

	if (Dec == 1)return a1.Gmath > a2.Gmath;
	else return a1.Gcode > a2.Gcode;
}//list链表排序规则

void management::addstudent(student stu){

	fstream stuf("D://Test.dat", ios::out | ios::app | ios::binary);
	stuf.write((char*)&stu, sizeof(student));
	stuf.close();
}//增加学生写进文件中



void management::deletestudent(student stu){
	student a;
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);//文件读指针指向文件头
	stuf.read((char*)&a, sizeof(student));
	alist.clear();//清空list链表
	while (!stuf.eof())
	{
		alist.push_back(a);
		stuf.read((char*)&a, sizeof(student));
	}//将文件中所有学生提出排进list链表
	stuf.close();
	list<student>::iterator p;//建立list迭代器
	for (p = alist.begin(); p != alist.end();){

		if (p->id == stu.id)
			p = alist.erase(p);//查找到所要删除学生的学号，从链表中删除
		else  p++;
	}
	fstream stuf2("D://Test.dat", ios::out | ios::binary);//链表操作完成后，写进文件中
	for (p = alist.begin(); p != alist.end(); ++p){

		stuf2.write((char*)&(*p), sizeof(student));
	}
	stuf2.close();
}

void management::modifystudent(student b){

	student a;
	
	/*cout << "请输入修改后的：" << endl;
	cin >> b.name >> b.id >> b.Gmath >> b.Gcode;*/
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);
	stuf.read((char*)&a, sizeof(student));
	alist.clear();//将list链表清空
	while (!stuf.eof())
	{
		alist.push_back(a);
		stuf.read((char*)&a, sizeof(student));
	}
	stuf.close();
	list<student>::iterator p;//list迭代器
	for (p = alist.begin(); p != alist.end();++p){//循环然后指针从头指到尾

		if (p->id == b.id){
			p->Gmath = b.Gmath;
			p->Gcode = b.Gcode;
			strcpy_s(p->name, b.name);
		}//查找到所要学生的学号，进行修改操作
		//else  p++;//找到了要修改的数据，指针仍然需要++，不然就卡在这里了
		//因为指针不++，但是指向的这个数据的ID又是需要找的
		//所以在这里死循环
	}
	fstream stuf2("D://Test.dat", ios::out | ios::binary);//链表操作完成后，重新写进文件中
	for (p = alist.begin(); p != alist.end(); p++){

		stuf2.write((char*)&(*p), sizeof(student));
	}
	stuf2.close();
}

void management::sortstudent(int d){
	Dec = d;
	student a;
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);
	stuf.read((char*)&a, sizeof(student));
	alist.clear();
	while (!stuf.eof())
	{
		alist.push_back(a);
		stuf.read((char*)&a, sizeof(student));
	}
	stuf.close();
	cout << "学生按成绩排序后如下：" << endl;
	alist.sort(SORT);
	list<student>::iterator p;  
	/*for (p = alist.begin(); p != alist.end(); ++p){
		cout << "学生姓名：" << p->name << "    " << "学生学号：" << p->id;
		cout << "高数成绩：" << p->Gmath << "   " << "程序设计：" << p->Gcode << endl;
	}*/
	fstream stuf3("D://Test.dat", ios::out | ios::binary);//链表操作完成后，写进文件中
	for (p = alist.begin(); p != alist.end(); p++){
		stuf3.write((char*)&(*p), sizeof(student));
	}
	stuf3.close();
}


void management::checkstudent(){
	student temp;
	cout << "显示全部学生成绩如下：" << endl;
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);
	stuf.read((char*)&temp, sizeof(student));
	alist.clear();
	while (!stuf.eof())
	{
		alist.push_back(temp);
		stuf.read((char*)&temp, sizeof(student));
	}
	stuf.close();
}