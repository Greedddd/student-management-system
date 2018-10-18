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
}//list�����������

void management::addstudent(student stu){

	fstream stuf("D://Test.dat", ios::out | ios::app | ios::binary);
	stuf.write((char*)&stu, sizeof(student));
	stuf.close();
}//����ѧ��д���ļ���



void management::deletestudent(student stu){
	student a;
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);//�ļ���ָ��ָ���ļ�ͷ
	stuf.read((char*)&a, sizeof(student));
	alist.clear();//���list����
	while (!stuf.eof())
	{
		alist.push_back(a);
		stuf.read((char*)&a, sizeof(student));
	}//���ļ�������ѧ������Ž�list����
	stuf.close();
	list<student>::iterator p;//����list������
	for (p = alist.begin(); p != alist.end();){

		if (p->id == stu.id)
			p = alist.erase(p);//���ҵ���Ҫɾ��ѧ����ѧ�ţ���������ɾ��
		else  p++;
	}
	fstream stuf2("D://Test.dat", ios::out | ios::binary);//���������ɺ�д���ļ���
	for (p = alist.begin(); p != alist.end(); ++p){

		stuf2.write((char*)&(*p), sizeof(student));
	}
	stuf2.close();
}

void management::modifystudent(student b){

	student a;
	
	/*cout << "�������޸ĺ�ģ�" << endl;
	cin >> b.name >> b.id >> b.Gmath >> b.Gcode;*/
	fstream stuf("D://Test.dat", ios::in | ios::binary);
	stuf.seekg(0, ios::beg);
	stuf.read((char*)&a, sizeof(student));
	alist.clear();//��list�������
	while (!stuf.eof())
	{
		alist.push_back(a);
		stuf.read((char*)&a, sizeof(student));
	}
	stuf.close();
	list<student>::iterator p;//list������
	for (p = alist.begin(); p != alist.end();++p){//ѭ��Ȼ��ָ���ͷָ��β

		if (p->id == b.id){
			p->Gmath = b.Gmath;
			p->Gcode = b.Gcode;
			strcpy_s(p->name, b.name);
		}//���ҵ���Ҫѧ����ѧ�ţ������޸Ĳ���
		//else  p++;//�ҵ���Ҫ�޸ĵ����ݣ�ָ����Ȼ��Ҫ++����Ȼ�Ϳ���������
		//��Ϊָ�벻++������ָ���������ݵ�ID������Ҫ�ҵ�
		//������������ѭ��
	}
	fstream stuf2("D://Test.dat", ios::out | ios::binary);//���������ɺ�����д���ļ���
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
	cout << "ѧ�����ɼ���������£�" << endl;
	alist.sort(SORT);
	list<student>::iterator p;  
	/*for (p = alist.begin(); p != alist.end(); ++p){
		cout << "ѧ��������" << p->name << "    " << "ѧ��ѧ�ţ�" << p->id;
		cout << "�����ɼ���" << p->Gmath << "   " << "������ƣ�" << p->Gcode << endl;
	}*/
	fstream stuf3("D://Test.dat", ios::out | ios::binary);//���������ɺ�д���ļ���
	for (p = alist.begin(); p != alist.end(); p++){
		stuf3.write((char*)&(*p), sizeof(student));
	}
	stuf3.close();
}


void management::checkstudent(){
	student temp;
	cout << "��ʾȫ��ѧ���ɼ����£�" << endl;
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