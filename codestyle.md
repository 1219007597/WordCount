### 缩进

4个空格，以表示缩进，显示程序的层次级别，增加程序的可读性。

### 命名

#### 变量命名

临时变量优先用 i，j，z，flag，temp

全局变量用类型缩写

```
int x;
int y;
bool flag=true;
```



#### 类，函数命名

驼峰命名法，第一个字符小写，拼接的第二个字符首字母大写。

实例化类，使用拼接字母首字母大写组合。

```
class countFile{
	public:
		
		//获得字符串 ，写入map 
		string getString(ifstream& in);
		void loadMap(string str); 
		
		//字符和行统计数 
		void countChara(string str);
		void countLine(string str);
		void countWord(ofstream& out);
		//利用向量排序 
		void getSort(ofstream& out);
			
	private:
		map<string,int>	mp;
}; 
```



### 行宽

每行最大100字符

### 常量

常量命名全部使用大写，并按照单词用下划线分割，做到量如其名
不允许出现任何魔法值（即未经定义的常量）直接出现在代码中
常量命名全部大写，单词间用下划线隔开，力求语义表达完整清楚，不要嫌名字长



### 注释

//注释函数作用及意义

/**/方法注释



### 空行规则

函数与函数之间，方法与方法之间空行



