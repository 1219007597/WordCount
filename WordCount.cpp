#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//������ 
class countFile{
	public:
		//��ʼ�� 
		//void init();
		string getString(ifstream& in);
		//�ַ�����ͳ���� 
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
	//�ı�������Ϊ�ַ����洢
	string str; 
	while((ch=in.get())!=EOF){
		//asii���ַ���Χ 
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
	//��ת��string->char [] 
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
	//�򿪶�д���ļ� 
	ifstream in;
	in.open(argv[1]);
	string s=CF.getString(in);
	// �ַ���������
	CF.countChara(s);
	CF.countLine(s);
	/* 
	ofstream out;
	out.open(argv[2]); 
	*/ 
	
	
	 
}

