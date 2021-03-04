#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//定义类 
class countFile{
	public:
		//初始化 
		//void init();
		string getString(ifstream& in);
		//字符和行统计数 
		int countChara(string str);
		int countLine(string str);
		/*
	private:
		int chara;
		int lines;
		*/
}; 
/*
void init(){
	chara=0;
	linges=0;
	
}
*/
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
int countFile::countChara(string str){
	cout<<"character:"<< str.length()<<endl;
}
int countFile::countLine(string str){
	//需转换string->char [] 
	//const char* p=str.data();
	int lines=0;
	char p[10000];
	for(int i=0;i<str.length();i++){
		p[i]=str[i];
	}
	char* cut=strtok(p," ");
	while(cut!=NULL){
		//cout<<cut<<endl;
		if(strcmp(cut,"\n")!=0){
			cut=strtok(NULL," ");	
			lines++;
		}
		
	}
	cout<<"lines:"<<lines<<endl;
	/*
	for(int i=0;i<str.length();i++){
	}
	*/
}

int main(int argc,char* argv[]){
	countFile CF;
	//打开读写两文件 
	ifstream in;
	in.open(argv[1]);
	string s=CF.getString(in);
	// 字符数和行数
	CF.countChara(s);
	CF.countLine(s);
	/* 
	ofstream out;
	out.open(argv[2]); 
	*/ 
	
	
	 
}

