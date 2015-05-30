#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
struct student{
	string name;
	int id;
	float chinese,math,english;
};
void Display(student &stu){
	cout<<stu.name<<' '<<stu.id<<' '<<stu.chinese
		<<' '<<stu.math<<' '<<stu.english<<endl;
}
void zjxx(){
	ofstream os("Info.txt",ios_base::app);
	student stu;
	char ch;
	cout<<"增加的人数：";
	int num,i=0;
	cin>>num;
	cout<<"姓名  学号  语文  数学  英语"<<endl;
	while(i<num){
		cin>>stu.name>>stu.id>>stu.chinese>>stu.math>>stu.english;
		os<<stu.name<<' '<<stu.id<<' '<<stu.chinese<<' '<<stu.math<<' '<<stu.english<<"\r\n";
		i++;
	}
	os.close();
}
void scxx(){
	cout<<"输入欲删除的学生学号：";
	int xh,count=0,i=0;
	cin>>xh;
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	while(is){
		is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is) break;
		count++;
		if(stu[i].id==xh){
			cout<<"找到学生"<<stu[i].id<<"的信息："<<endl;
			Display(stu[i]);  
			cout<<"删除成功!"<<endl;
		}
		i++;
	}
	is.close();
	i=0;
	ofstream os("Info.txt",ios_base::trunc); 
	while(i<count){
		if(stu[i].id==xh) i++;
		os<<stu[i].name<<' '<<stu[i].id<<' '<<stu[i].chinese<<' '<<stu[i].math<<' '<<stu[i].english<<"\r\n";
		i++;
	}
	system("pause");
	return;
}
void xgxx(){
	cout<<"输入欲修改的学生学号：";
	int xh,count=0,i=0;
	cin>>xh;
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	while(is){
		is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is) break;
		count++;
		if(stu[i].id==xh){
			cout<<"找到学生"<<stu[i].id<<"的信息："<<endl;
			Display(stu[i]);
			cout<<"修改为："<<endl;
			cin>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
			cout<<"修改成功!"<<endl;
		}
		i++;
	}
	i=0;
	ofstream os("Info.txt",ios_base::trunc); 
	while(i<count){
		os<<stu[i].name<<' '<<stu[i].id<<' '<<stu[i].chinese<<' '<<stu[i].math<<' '<<stu[i].english<<"\r\n";
		i++;
	}
	os.close();
	system("pause");
	return;
}
void xxwh(){
	int sel;
	while(1){
		system("cls");
		cout<<"信息维护子系统"<<endl;
		cout<<"1>增加学生信息"<<endl;
		cout<<"2>删除学生信息"<<endl;
		cout<<"3>修改学生信息"<<endl;
		cout<<"4>返回上级目录"<<endl;
		cin>>sel;
		switch(sel){
		case 1: zjxx(); break;
		case 2: scxx(); break;
		case 3: xgxx(); break;
		case 4: return ;
		default : cout<<"选择错误"<<endl;
		}
	}
} 

void xmcx(){
	cout<<"输入欲查询的学生姓名：";
	int count=0,i=0;
	string str;
	cin>>str;
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	while(is){
		is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is) break;
		count++;
		if(stu[i].name==str){
			cout<<stu[i].name<<"的查询结果："<<endl;
			Display(stu[i]);  
		}
		i++;
	}
	cout<<"查询完毕!"<<endl<<endl;
	system("pause");
	return;
}
void xhcx(){
	cout<<"输入欲查询的学生学号：";
	int xh,count=0,i=0;
	cin>>xh;
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	while(is){
		is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is) break;
		count++;
		if(stu[i].id==xh){
			cout<<stu[i].id<<"的查询结果："<<endl;
			Display(stu[i]);  
		}
		i++;
	}
	cout<<"查询完毕!"<<endl<<endl;
	system("pause");
	return;
}
void xxcx(){
	system("cls");
	int sel;
	cout<<"1>按姓名查询"<<endl;
	cout<<"2>按学号查询"<<endl; 
	cin>>sel; 
	switch(sel){
		case 1: xmcx();break;
		case 2: xhcx();break;
		default: cout<<"选择错误"<<endl;
	}
}

void cjtj(){
	cout<<"输入学科名和分数段(math 75 80)"<<endl;
	string str;
	int low,high,i=0;
	cin>>str>>low>>high; 
	cout<<"统计结果如下："<<endl;
	cout<<"姓名 学号 语文 数学 英语"<<endl;
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	if(str=="chinese"){
		while(is){
			is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
			if(!is) break;
			if(stu[i].chinese>=low&&stu[i].chinese<=high){
				Display(stu[i]); 
			}
			i++;
		}
	}
	if(str=="math"){
		while(is){
			is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
			if(!is) break;
			if(stu[i].math>=low&&stu[i].math<=high){
				Display(stu[i]); 
			}
			i++;
		}
	}
	if(str=="english"){
		while(is){
			is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
			if(!is) break;
			if(stu[i].english>=low&&stu[i].english<=high){
				Display(stu[i]); 
			}
			i++;
		}
	}
	cout<<endl;
	system("pause");
	return;
}

void swap(float *p1,float *p2){
	float temp=*p1;
	*p1=*p2; *p2=temp;
}
void sx(float *p,int count){
	for(int i=0;i<count;i++)
		for(int j=i+1;j<count;j++){
			if(p[i]>p[j]) swap(&p[i],&p[j]);
		}
}
void jx(float *p,int count){
	for(int i=0;i<count;i++)
		for(int j=i+1;j<count;j++){
			if(p[i]<p[j]) swap(&p[i],&p[j]);
		}
}
void px(){
	system("cls");
	int sel,count=0,i=0; 
	string str; 
	cout<<"输入待排序的课程三选一(chinese/math/english)"<<endl;
	cin>>str;
	cout<<"1>升序 2>降序"<<endl;
	cin>>sel;
	float a[30];
	student stu[30];
	ifstream is("Info.txt",ios_base::in);
	while(is){
		is>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is) break;
		if(str=="chinese"){
			a[i]=stu[i].chinese;
		}
		else if(str=="math"){
				a[i]=stu[i].math;
			}
			else { a[i]=stu[i].english; }
		count++;
		i++;
	}
	if(sel==1) sx(a,count);
	else jx(a,count);
	cout<<"姓名 学号 语文 数学 英语" <<endl;
	ifstream is2("Info.txt",ios_base::in);
	while(is2){
		is2>>stu[i].name>>stu[i].id>>stu[i].chinese>>stu[i].math>>stu[i].english;
		if(!is2) break;
		i++;
	}
	if(str=="math"){
		for(int i=0;i<count;i++){
			for(int j=0;j<count;j++)
				if(a[i]==stu[j].math) Display(stu[j]);
		}
	}
	else if(str=="english"){
			for(int i=0;i<count;i++){
				for(int j=0;j<count;j++)
					if(a[i]==stu[j].english) Display(stu[j]);
			}
		}
		else {
			for(int i=0;i<count;i++){
				for(int j=0;j<count;j++)
					if(a[i]==stu[j].chinese) Display(stu[j]);
			}
	}
	system("pause");
	return;
} 

int main(){
	student stu;
	string str;
	int sel;
	while(1){
		system("cls");
		cout<<"******欢迎使用本管理系统******"<<endl;
		cout<<"      1>信息维护"<<endl;
		cout<<"      2>信息查询"<<endl;
		cout<<"      3>成绩统计"<<endl;
		cout<<"      4>排序"<<endl; 
		cout<<"      5>退出系统"<<endl;
		cin>>sel;
		switch(sel){
		case 1: xxwh(); break;
		case 2: xxcx(); break;
		case 3: cjtj(); break;
		case 4: px(); break;
		case 5: exit(0);
		default : cout<<"选择错误"<<endl;
		}
	}
	system("pause");
	return 0;
}
