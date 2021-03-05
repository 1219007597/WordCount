#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<ctype.h>
#include<map>
#include<vector> 
#include<utility>
#include<algorithm>
using namespace std;
//定义类 
map<string,int> mp;
class countFile{
	public:
		//初始化 
		//void init();
		string getString(ifstream& in);
		//字符和行统计数 
		void countChara(string str,ofstream& out);
		void countLine(string str,ofstream& out);
		void countWord(string str,ofstream& out);
		//利用向量排序 
		vector<pair<int,string> > getSort();
}; 

string countFile::getString(ifstream& in){
	char ch;
	//文本内容作为字符串存储
	string str; 
	while((ch=in.get())!=EOF){
		//asii码字符范围 
		if(ch>0&&ch<=127){
			str.append(1,ch);
		}
	}
	return str;
}
void countFile::countChara(string str,ofstream& out){
	out<<"character: "<< str.length()<<endl;
}
void countFile::countLine(string str,ofstream& out){
	//需转换string->char [] 
	//const char* p=str.data();
	
	int lines=0;/*
	char p[1000000];
	for(int i=0;i<str.length();i++){
		p[i]=str[i];
	}
	char* cut=strtok(p," ");
	while(cut!=NULL){
		//cout<<cut<<endl;
		if(strcmp(cut,"\n")!=0){
			cut=strtok(NULL,"\n");	
			lines++;
		}
		
	}
	*/
	string s;
	//字母大写->小写 
    for(int i=0;i<str.length();i++){
		if(str[i]!='\n'){
			s+=str[i];
		}
		else{
			
		}
	}
	cout<<"lines:"<<lines<<endl;
	/*
	for(int i=0;i<str.length();i++){
	}
	*/
}

void countFile::countWord(string str,ofstream& out){
	int word=0;
    
	//字母大写->小写 
    for(int i=0;i<str.length();i++){
    	if(str[i]>=65&&str[i]<=90){
    		str[i]+=32;
		}
	}
	for(int i=0;i<str.length()-3;i++){
		//跳过非字母和非数字字符
		while(i<str.length() && !isdigit(str[i]) && !islower(str[i])){ 
			i++;
		} 
		
    	string temp;//存储合理单词 
		bool flag=true;	//判断是否符合四个字母开头 
		
		for(int j=0;j<4;j++){
			if(!islower(str[i+j])){
				flag=false;
				break;
			}
		}
		if(flag){
			for(int j=0;j<4;j++){
				temp.append(1,str[i+j]);
			}
			i+=4;
			while(i<str.length() && isdigit(str[i]) || islower(str[i])){
				temp.append(1,str[i]);
				i++; 
			} 
			mp[temp]++;
			word++;
		}
	}
	out<<"words: "<<word<<endl;	
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}

vector<pair<int,string> > countFile::getSort()
{
	map<string, int>::iterator it;
	vector<pair<int, string> > ve;
	for (it=mp.begin(); it!=mp.end(); it++)
	{
		ve.push_back(make_pair(it->second,it->first));
	}
	sort(ve.begin(), ve.end(),cmp);
	
	return ve;
}


    

int main(int argc,char* argv[]){
	countFile CF;
	//打开读写两文件 
	ifstream in;
	in.open(argv[1]);
	string s=CF.getString(in);
	
	ofstream out;
	out.open(argv[2]);
	
	// 字符数和行数
	CF.countChara(s,out);
	//CF.countLine(s);
	CF.countWord(s,out);
	vector<pair<int,string> > v=CF.getSort();
	for(int i=0;i<10;i++){
		out<<v[i].second<<" :"<<v[i].first<<endl;
	}
	out.close();
	
	 
}
