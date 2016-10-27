#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
struct City
{
	string CityNumber;
	string CityName;
	string FirstPollutant;
	unsigned int Pollution;
	string PollutionLevelRome;
	string PollutionLevel;
	unsigned int year,month,day;
	friend istream& operator>>(istream& in,City& city)
	{
		in>>city.CityNumber>>city.CityName>>city.FirstPollutant>>city.Pollution
		>>city.PollutionLevelRome>>city.PollutionLevel>>city.year>>city.month>>city.day;
		return in;
	}
	friend ostream& operator<<(ostream& out,City& city)
	{
		out<<city.CityNumber<<endl<<city.CityName<<endl<<city.FirstPollutant<<endl<<city.Pollution
		<<endl<<city.PollutionLevelRome<<endl<<city.PollutionLevel<<endl<<city.year<<endl<<city.month<<endl<<city.day<<endl<<endl;
		return out;
	}
	
};

struct forSort
{
	string city;
	int EveragePollutionNumber;
	friend bool operator<(const forSort& left,const forSort& right)
	{
		return left.EveragePollutionNumber<right.EveragePollutionNumber;
	}
	friend bool operator>(const forSort& left,const forSort& right)
	{
		return left.EveragePollutionNumber>right.EveragePollutionNumber;
	}
};

vector<City> city;
int dayofmonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const string AirQuality[7]={"优","良","轻微污染","轻度污染","中度污染","中度重污染","重污染"};
vector<string> CityName;


void ShowMenu()
{
	cout<<"空气质量查询系统"<<endl<<endl;
	cout<<"1、普通查询"<<endl;
	cout<<"2、统计查询"<<endl;
	cout<<"3、排序查询"<<endl;
	cout<<"0、退出系统"<<endl;
	cout<<"请输入查询模式：";
}

bool ReadFile()
{
	ifstream fin;
	fin.open("data.txt",ios::out);
	CityName.push_back("南通");
	while(!fin.eof())
	{
		City temp;
		fin>>temp;
		city.push_back(temp);
		if(temp.CityName!=CityName[CityName.size()-1])
			CityName.push_back(temp.CityName);
	}
	fin.close();
	return true;
}

//第一部分

void print(const City& temp)
{
	cout<<"城市名称："<<temp.CityName<<endl;
	cout<<temp.year<<"年"<<temp.month<<"月"<<temp.day<<"日"<<endl;
	cout<<"首要污染物："<<temp.FirstPollutant<<endl;
	cout<<"污染指数："<<temp.Pollution<<endl;
	cout<<"污染物级别："<<temp.PollutionLevelRome<<endl;
	cout<<"空气状况："<<temp.PollutionLevel<<endl;
	cout<<endl;
}

void OneDaySearch(vector<City>& temp)
{
	char ch;
	do
	{
		int month=0,day=0;
		string temp1,temp2;
		cout<<"请输入日期（月 日）：";
		cin>>temp1>>temp2;
		if(temp1.length()==1)
			month=(int)temp1[0]-48;
		else if(temp1.length()==2)
			month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			month=0;
		if(temp2.length()==1)
			day=(int)temp2[0]-48;
		else if(temp2.length()==2)
			day=((int)temp2[0]-48)*10+(int)temp2[1]-48;
		else
			day=0;

		while(month<=0||month>12||day<=0||day>dayofmonth[month])
		{
			cout<<"输入日期有误！！！请输入日期：";
			cin>>temp1>>temp2;
			if(temp1.length()==1)
				month=(int)temp1[0]-48;
			else if(temp1.length()==2)
				month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
			else
				month=0;
			if(temp2.length()==1)
				day=(int)temp2[0]-48;
			else if(temp2.length()==2)
			{
				day=((int)temp2[0]-48)*10+(int)temp2[1]-48;
				cout<<(int)temp2[0]-48<<" "<<(int)temp2[1]-48<<endl;
			}
			else
				day=0;
		}
		cout<<month<<" "<<day<<endl;
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(it->month==month&&it->day==day)
			{
				print(*it);
				break;
			}
		}
		cout<<"要退出该城市的一天查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

int GetWeek(int month,int day)
{
	int sum=0;
	for(int i=0;i<month;i++)
	{
		sum+=dayofmonth[i];
	}
	sum+=day;
	if(sum%7==0)
		return sum/7;
	else
		return sum/7+1;
}

void OneWeekSearch(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入星期（小于等于53）：";
		int week=0;
		cin>>temp1;
		if(temp1.length()==1)
			week=(int)temp1[0]-48;
		else if(temp1.length()==2)
			week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			week=0;
		while(week<=0||week>53)
		{
			cout<<"输入星期有误！！！请输入星期（小于等于53）：";
			cin>>temp1;
			if(temp1.length()==1)
				week=(int)temp1[0]-48;
			else if(temp1.length()==2)
				week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
			else
				week=0;
		}
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(week==GetWeek(it->month,it->day))
				print(*it);
			if(GetWeek(it->month,it->day)==week-1)
				break ;
		}
		cout<<"要退出该城市的一周查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');

}

void OneMonthSearch(vector<City>&temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入月份：";
		int month=0;
		cin>>temp1;
		if(temp1.length()==1)
			month=(int)temp1[0]-48;
		else if(temp1.length()==2)
			month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			month=0;
		while(month<=0||month>12)
		{
			cout<<"月份输出有误！！！请输入月份：";
			cin>>temp1;
			if(temp1.length()==1)
				month=(int)temp1[0]-48;
			else if(temp1.length()==2)
				month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
			else
				month=0;

		}
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(month==it->month)
				print(*it);
			if(month-1==it->month)
				break;
		}
		cout<<"要退出该城市的一月查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

int GetQuarter(int month)
{
	if(month%3==0)
		return month/3;
	else
		return month/3+1;
}

void OneQuarterSearch(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入季度：";
		int quarter=0;
		cin>>temp1;
		quarter=(int)temp1[0]-48;
		while(quarter<=0||quarter>4)
		{
			cout<<"季度输入有误！！！请输入季度：";
			cin>>temp1;
			quarter=(int)temp1[0]-48;
		}
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(quarter==GetQuarter(it->month))
				print(*it);
			if(quarter>GetQuarter(it->month))
				break ;
		}
		cout<<"要退出该城市的一季度查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

void OneYearSearch(vector<City>& temp)
{
	for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		print(*it);
}

void CommenSearch()
{
	char ch;
	do
	{
		cout<<"请输入想查询城市名称：";
		string SearchCity;
		cin>>SearchCity;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == SearchCity)
			{
				OneCity.push_back(*iter);
			}
		}
		while(OneCity.empty())
		{
			cout<<"暂时没有您想要查询的城市！！！请输入想查询城市名称：";
			cin>>SearchCity;
			OneCity.clear();
			for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
			{
				if ((*iter).CityName == SearchCity)
				{
					OneCity.push_back(*iter);
				}
			}
		}
		char c;
		do
		{
			cout<<"1：查询某一天"<<endl;
			cout<<"2：查询某一周"<<endl;
			cout<<"3：查询某一月"<<endl;
			cout<<"4：查询某一季度"<<endl;
			cout<<"5：查询一年"<<endl;
			cout<<"请输入查询类型编号：";
			int choose=-1;
			string temp;
			cin>>temp;
			choose=(int)temp[0]-48;
			while(choose<=0||choose>5||temp.length()>1)
			{
				cout<<"输入有误！！！请输入查询类型编号：";
				cin>>temp;
				choose=(int)temp[0]-48;
			}
			switch(choose)
			{
			case 1:
				OneDaySearch(OneCity);
				break;
			case 2:
				OneWeekSearch(OneCity);
				break;
			case 3:
				OneMonthSearch(OneCity);
				break;
			case 4:
				OneQuarterSearch(OneCity);
				break;
			case 5:
				OneYearSearch(OneCity);
				break;
			default:
				cout<<"error!"<<endl;
				break;
			}
			cout<<"要退出该城市的相关查询吗？(Y/N)";
			string t;
			cin>>t;
			c=t[0];
		}while(toupper(c)=='N');
		cout<<"要退出普通查询模式吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
	cout<<"谢谢使用普通查询！"<<endl;
}

//第二部分
//第二部分 第一节
int StatisticsCount[7]={0,0,0,0,0,0,0};

void printStatisticsCount()
{
	cout<<"优："<<StatisticsCount[0]<<endl;
	cout<<"良："<<StatisticsCount[1]<<endl;
	cout<<"轻微污染："<<StatisticsCount[2]<<endl;
	cout<<"轻度污染："<<StatisticsCount[3]<<endl;
	cout<<"中度污染："<<StatisticsCount[4]<<endl;
	cout<<"中度重污染："<<StatisticsCount[5]<<endl;
	cout<<"重污染："<<StatisticsCount[6]<<endl;
	cout<<endl;
}

void OneCityWeekStatistics(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入星期（小于等于53）：";
		int week=0;
		cin>>temp1;
		if(temp1.length()==1)
			week=(int)temp1[0]-48;
		else if(temp1.length()==2)
			week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			week=0;
		while(week<=0||week>53)
		{
			cout<<"输入星期有误！！！请输入星期（小于等于53）：";
			cin>>temp1;
			if(temp1.length()==1)
				week=(int)temp1[0]-48;
			else if(temp1.length()==2)
				week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
			else
				week=0;
		}
		for(int i=0;i<7;i++)
			StatisticsCount[i]=0;
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(week==GetWeek(it->month,it->day))
			{
				if(it->PollutionLevel=="优")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="良")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="轻微污染")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="轻度污染")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="中度污染")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="中度重污染")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="重污染")
					StatisticsCount[6]++;
			}
			if(GetWeek(it->month,it->day)==week-1)
				break;
		}
		cout<<"城市："<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"年第"<<week<<"周"<<endl;
		printStatisticsCount();
		cout<<"要退出该城市的一周统计查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

void OneCityMonthStatistics(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入月份：";
		int month=0;
		cin>>temp1;
		if(temp1.length()==1)
			month=(int)temp1[0]-48;
		else if(temp1.length()==2)
			month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			month=0;
		while(month<=0||month>12)
		{
			cout<<"月份输出有误！！！请输入月份：";
			cin>>temp1;
			if(temp1.length()==1)
				month=(int)temp1[0]-48;
			else if(temp1.length()==2)
				month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
			else
				month=0;

		}
		for(int i=0;i<7;i++)
			StatisticsCount[i]=0;
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(month==it->month)
			{
				if(it->PollutionLevel=="优")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="良")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="轻微污染")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="轻度污染")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="中度污染")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="中度重污染")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="重污染")
					StatisticsCount[6]++;
			}
			if(it->month==month-1)
				break;
		}
		cout<<"城市："<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"年第"<<month<<"月"<<endl;
		printStatisticsCount();
		cout<<"要退出该城市的一月统计查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

void OneCityQuarterStatistics(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"请输入季度：";
		int quarter=0;
		cin>>temp1;
		quarter=(int)temp1[0]-48;
		while(quarter<=0||quarter>4)
		{
			cout<<"季度输入有误！！！请输入季度：";
			cin>>temp1;
			quarter=(int)temp1[0]-48;
		}
		for(int i=0;i<7;i++)
			StatisticsCount[i]=0;
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(quarter==GetQuarter(it->month))
			{
				if(it->PollutionLevel=="优")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="良")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="轻微污染")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="轻度污染")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="中度污染")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="中度重污染")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="重污染")
					StatisticsCount[6]++;
			}
			if(quarter-1==GetQuarter(it->month))
				break ;
		}
		cout<<"城市："<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"年第"<<quarter<<"季度"<<endl;
		printStatisticsCount();
		cout<<"要退出该城市的一季度统计查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

void OneCityYearStatistics(vector<City>& temp)
{
	for(int i=0;i<7;i++)
		StatisticsCount[i]=0;
	for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
	{
		if(it->PollutionLevel=="优")
			StatisticsCount[0]++;
		else if(it->PollutionLevel=="良")
			StatisticsCount[1]++;
		else if(it->PollutionLevel=="轻微污染")
			StatisticsCount[2]++;
		else if(it->PollutionLevel=="轻度污染")
			StatisticsCount[3]++;
		else if(it->PollutionLevel=="中度污染")
			StatisticsCount[4]++;
		else if(it->PollutionLevel=="中度重污染")
			StatisticsCount[5]++;
		else if(it->PollutionLevel=="重污染")
			StatisticsCount[6]++;
	}
	cout<<"城市："<<temp.begin()->CityName<<endl;
	cout<<temp.begin()->year<<"年"<<endl;
	printStatisticsCount();
}

void OneCityStatisticsSearch()
{
	char ch;
	do
	{
		cout<<"请输入想查询城市名称：";
		string SearchCity;
		cin>>SearchCity;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == SearchCity)
			{
				OneCity.push_back(*iter);
			}
		}
		while(OneCity.empty())
		{
			cout<<"暂时没有您想要查询的城市！！！请输入想查询城市名称：";
			cin>>SearchCity;
			OneCity.clear();
			for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
			{
				if ((*iter).CityName == SearchCity)
				{
					OneCity.push_back(*iter);
				}
			}
		}
		char c;
		do
		{
			cout<<"1：统计某一周"<<endl;
			cout<<"2：统计某一月"<<endl;
			cout<<"3：统计某一季度"<<endl;
			cout<<"4：统计一年"<<endl;
			cout<<"请输入查询类型编号";
			int choose=-1;
			string temp;
			cin>>temp;
			choose=(int)temp[0]-48;
			while(choose<=0||choose>4||temp.length()>1)
			{
				cout<<"输入有误！！！请输入查询类型编号：";
				cin>>temp;
				choose=(int)temp[0]-48;
			}
			switch(choose)
			{
			case 1:
				OneCityWeekStatistics(OneCity);
				break;
			case 2:
				OneCityMonthStatistics(OneCity);
				break;
			case 3:
				OneCityQuarterStatistics(OneCity);
				break;
			case 4:
				OneCityYearStatistics(OneCity);
				break;
			default:
				cout<<"error!"<<endl;
				break;
			}
			cout<<"要退出该城市统计查询吗？(Y/N)";
			string t;
			cin>>t;
			c=t[0];
		}while(toupper(c)=='N');
		cout<<"要退出城市统计查询模式吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

//第二部分 第二节

void WeekAirStatisticsSearch(int PollutionType,int time)
{
	string temp1;
	cout<<"请输入星期（小于等于53）：";
	int week=0;
	cin>>temp1;
	if(temp1.length()==1)
		week=(int)temp1[0]-48;
	else if(temp1.length()==2)
		week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
	else
		week=0;
	while(week<=0||week>53)
	{
		cout<<"输入星期有误！！！请输入星期（小于等于53）：";
		cin>>temp1;
		if(temp1.length()==1)
			week=(int)temp1[0]-48;
		else if(temp1.length()==2)
			week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			week=0;
	}
	vector<string> CityTemp;
	vector<int> TimeTemp;

	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if((week==GetWeek(it->month,it->day))&&it->PollutionLevel==AirQuality[PollutionType-1])
				count++;
			if(GetWeek(it->month,it->day)==week-1)
				break ;
		}
		if(count>=time)
		{
			CityTemp.push_back (OneCity.begin()->CityName);
			TimeTemp.push_back(count);
		}
	}
	for(unsigned int i=0;i<CityTemp.size();i++)
	{
		cout<<CityTemp[i]<<"	"<<TimeTemp[i]<<endl;
	}
}

void MonthAirStatisticsSearch(int PollutionType,int time)
{
	string temp1;
	cout<<"请输入月份：";
	int month=0;
	cin>>temp1;
	if(temp1.length()==1)
		month=(int)temp1[0]-48;
	else if(temp1.length()==2)
		month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
	else
		month=0;
	while(month<=0||month>12)
	{
		cout<<"月份输出有误！！！请输入月份：";
		cin>>temp1;
		if(temp1.length()==1)
			month=(int)temp1[0]-48;
		else if(temp1.length()==2)
			month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			month=0;
	}
	vector<string> CityTemp;
	vector<int> TimeTemp;

	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if(it->month==month&&it->PollutionLevel==AirQuality[PollutionType-1])
				count++;
			if(it->month==month-1)
				break ;
		}
		if(count>=time)
			{
				CityTemp.push_back (OneCity.begin()->CityName);
				TimeTemp.push_back(count);
			}
		
	}
	for(unsigned int i=0;i<CityTemp.size();i++)
	{
		cout<<CityTemp[i]<<"	"<<TimeTemp[i]<<endl;
	}
}

void QuarterAirStatisticsSearch(int PollutionType,int time)
{
	string temp1;
	cout<<"请输入季度：";
	int quarter=0;
	cin>>temp1;
	quarter=(int)temp1[0]-48;
	while(quarter<=0||quarter>4)
	{
		cout<<"季度输入有误！！！请输入季度：";
		cin>>temp1;
		quarter=(int)temp1[0]-48;
	}
	vector<string> CityTemp;
	vector<int> TimeTemp;

	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if(quarter==GetQuarter(it->month)&&it->PollutionLevel==AirQuality[PollutionType-1])
				count++;
			if(quarter>GetQuarter(it->month))
				break ;
		}
		if(count>=time)
			{
				CityTemp.push_back (OneCity.begin()->CityName);
				TimeTemp.push_back(count);
			}
	}
	for(unsigned int i=0;i<CityTemp.size();i++)
	{
		cout<<CityTemp[i]<<"	"<<TimeTemp[i]<<endl;
	}
}

void YearAirStatisticsSearch(int PollutionType,int time)
{
	vector<string> CityTemp;
	vector<int> TimeTemp;

	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if(it->PollutionLevel==AirQuality[PollutionType-1])
				count++;
		}
		if(count>=time)
			{
				CityTemp.push_back (OneCity.begin()->CityName);
				TimeTemp.push_back(count);
			}
		
	}
	for(unsigned int i=0;i<CityTemp.size();i++)
	{
		cout<<CityTemp[i]<<"	"<<TimeTemp[i]<<endl;
	}
}

void AirStatisticsSearch()
{
	char ch;
	do
	{
		cout<<"请输入查询时间范围编号"<<endl;
		cout<<"1：统计某一周"<<endl;
		cout<<"2：统计某一月"<<endl;
		cout<<"3：统计某一季度"<<endl;
		cout<<"4：统计一年"<<endl;
		int choose=-1;
		string temp1;
		cin>>temp1;
		choose=(int)temp1[0]-48;
		while(choose<=0||choose>4||temp1.length()>1)
		{
			cout<<"输入有误！！！请输入查询类型编号：";
			cin>>temp1;
			choose=(int)temp1[0]-48;
		}
		cout<<"请选择查询的空气质量状况："<<endl;
		cout<<"1：优"<<endl;
		cout<<"2：良"<<endl;
		cout<<"3：轻微污染"<<endl;
		cout<<"4：轻度污染"<<endl;
		cout<<"5：中度污染"<<endl;
		cout<<"6：中度重污染"<<endl;
		cout<<"7：重污染"<<endl;
		int PollutionType=-1;
		string temp2;
		cin>>temp2;
		PollutionType=(int)temp2[0]-48;
		while(choose<=0||choose>7||temp2.length()>1)
		{
			cout<<"输入有误！！！请输入查询类型编号：";
			cin>>temp2;
			PollutionType=(int)temp2[0]-48;
		}
		cout<<"请插入污染类型的天数："<<endl<<endl;
		cout<<"注意：如果是周查询，天数 <= 7 "<<endl<<endl;
		cout<<"      如果是月查询，天数 <= the day of month"<<endl<<endl;
		cout<<"      如果是季度查询，天数 <= the day of quarter"<<endl<<endl;
		cout<<"      如果是年查询，天数 <= 365 "<<endl<<endl;
		unsigned int time=0;
		cin>>time;
		switch(choose)
		{
		case 1:
			WeekAirStatisticsSearch(PollutionType,time);
			break;
		case 2:
			MonthAirStatisticsSearch(PollutionType,time);
			break;
		case 3:
			QuarterAirStatisticsSearch(PollutionType,time);
			break;
		case 4:
			YearAirStatisticsSearch(PollutionType,time);
			break;
		default:
			cout<<"error!"<<endl;
			break;
		}
		cout<<"要退出按时间的统计查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

void StatisticsSearch()
{
	char ch;
	do
	{
		cout<<"1：查询某一城市"<<endl;
		cout<<"2：查询某一时间段"<<endl;
		cout<<"输入查询类型：";
		int choose=-1;
		string temp;
		cin>>temp;
		choose=(int)temp[0]-48;
		while(choose<=0||choose>2||temp.length()>1)
		{
			cout<<"输入有误！！！请输入查询类型编号：";
			cin>>temp;
			choose=(int)temp[0]-48;
		}
		switch(choose)
		{
		case 1:
			OneCityStatisticsSearch();
			break;
		case 2:
			AirStatisticsSearch();
			break;
		default:
			cout<<"error!"<<endl;
			break;
		}
		cout<<"要退出统计查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

//第三部分
vector<forSort> CitySort;

void printCitySort(int len)
{
	for(unsigned int i=0;i<len;i++)
		{
			cout<<"第"<<i+1<<"名："<<CitySort[i].city<<endl;
		}
}

void WeekSort(int len)
{
	string temp1;
	cout<<"请输入星期（小于等于53）：";
	int week=0;
	cin>>temp1;
	if(temp1.length()==1)
		week=(int)temp1[0]-48;
	else if(temp1.length()==2)
		week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
	else
		week=0;
	while(week<=0||week>53)
	{
		cout<<"输入星期有误！！！请输入星期（小于等于53）：";
		cin>>temp1;
		if(temp1.length()==1)
			week=(int)temp1[0]-48;
		else if(temp1.length()==2)
			week=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			week=0;
	}
	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;	
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if((week==GetWeek(it->month,it->day)))
				count+=it->Pollution;
			if(GetWeek(it->month,it->day)==week-1)
				break ;
		}
		forSort temp;
		temp.city=OneCity.begin()->CityName;
		temp.EveragePollutionNumber=count/7;
		CitySort.push_back(temp);
	}
	sort(CitySort.begin(),CitySort.end()-1);
	printCitySort(len);
	CitySort.clear();
}

void MonthSort(int len)
{
	string temp1;
	cout<<"请输入月份：";
	int month=0;
	cin>>temp1;
	if(temp1.length()==1)
		month=(int)temp1[0]-48;
	else if(temp1.length()==2)
		month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
	else
		month=0;
	while(month<=0||month>12)
	{
		cout<<"月份输出有误！！！请输入月份：";
		cin>>temp1;
		if(temp1.length()==1)
			month=(int)temp1[0]-48;
		else if(temp1.length()==2)
			month=((int)temp1[0]-48)*10+(int)temp1[1]-48;
		else
			month=0;
	}
	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;	
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if(month==it->month)
				count+=it->Pollution;
			if(month-1==it->month)
				break ;
		}
		forSort temp;
		temp.city=OneCity.begin()->CityName;
		temp.EveragePollutionNumber=count/7;
		CitySort.push_back(temp);
	}
	sort(CitySort.begin(),CitySort.end()-1);
	printCitySort(len);
	CitySort.clear();
}

void QuarterSort(int len)
{
	string temp1;
	cout<<"请输入季度：";
	int quarter=0;
	cin>>temp1;
	quarter=(int)temp1[0]-48;
	while(quarter<=0||quarter>4)
	{
		cout<<"季度输入有误！！！请输入季度：";
		cin>>temp1;
		quarter=(int)temp1[0]-48;
	}
	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;	
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			if(quarter==GetQuarter(it->month))
				count+=it->Pollution;
			if(quarter-1==GetQuarter(it->month))
				break ;
		}
		forSort temp;
		temp.city=OneCity.begin()->CityName;
		temp.EveragePollutionNumber=count/7;
		CitySort.push_back(temp);
	}
	sort(CitySort.begin(),CitySort.end()-1);
	printCitySort(len);
	CitySort.clear();
}

void YearSort(int len)
{
	for(unsigned int i=0;i<CityName.size();i++)
	{
		int count=0;	
		vector<City> OneCity;
		OneCity.clear();
		for (vector<City>::iterator iter=city.begin();iter!=city.end();iter++)
		{
			if ((*iter).CityName == CityName[i])
			{
				OneCity.push_back(*iter);
			}
		}
		for(vector<City>::iterator it=OneCity.begin();it!=OneCity.end();it++)
		{
			count+=it->Pollution;
		}
		forSort temp;
		temp.city=OneCity.begin()->CityName;
		temp.EveragePollutionNumber=count/7;
		CitySort.push_back(temp);
	}
	sort(CitySort.begin(),CitySort.end()-1);
	printCitySort(len);
	CitySort.clear();
}

void SortSearch()
{
	char ch;
	do
	{
		cout<<"1、一周排行"<<endl;
		cout<<"2、一月排行"<<endl;
		cout<<"3、一季度排行"<<endl;
		cout<<"4、一年排行"<<endl;
		cout<<"请选择查询类型：";
		int choose=-1;
		string temp;
		cin>>temp;
		choose=(int)temp[0]-48;
		while(choose<=0||choose>5||temp.length()>1)
		{
			cout<<"输入有误！！！请输入查询类型编号：";
			cin>>temp;
			choose=(int)temp[0]-48;
		}
		cout<<"输入排行榜长度：";
		int len;
		cin>>len;
		switch(choose)
		{
		case 1:
			WeekSort(len);
			break;
		case 2:
			MonthSort(len);
			break;
		case 3:QuarterSort(len);
			break;
		case 4:
			YearSort(len);
			break;
		default:
			cout<<"error!"<<endl;
			break;
		}
		cout<<"要退出排序查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

int main(void)
{
	ReadFile();
	char ch;
	do
	{
		ShowMenu();
		string temp;
		int choice;
		cin>>temp;
		choice=(int)temp[0]-48;
		while(choice!=1&&choice!=2&&choice!=3&&choice!=0)
		{
			cout<<"输入有误，请输入正确的编号：";
			cin>>temp;
			choice=(int)temp[0]-48;
		}
		switch(choice)
		{
		case 1:
			CommenSearch();
			break;
		case 2:
			StatisticsSearch();
			break;
		case 3:
			SortSearch();
			break;
		case 0:
			cout<<"谢谢使用！"<<endl;
			break;
		default:
			cout<<"error!"<<endl;
			break;
		}
		cout<<"要退出查询吗？(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
	
	return 0;
}

