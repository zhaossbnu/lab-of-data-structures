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
const string AirQuality[7]={"��","��","��΢��Ⱦ","�����Ⱦ","�ж���Ⱦ","�ж�����Ⱦ","����Ⱦ"};
vector<string> CityName;


void ShowMenu()
{
	cout<<"����������ѯϵͳ"<<endl<<endl;
	cout<<"1����ͨ��ѯ"<<endl;
	cout<<"2��ͳ�Ʋ�ѯ"<<endl;
	cout<<"3�������ѯ"<<endl;
	cout<<"0���˳�ϵͳ"<<endl;
	cout<<"�������ѯģʽ��";
}

bool ReadFile()
{
	ifstream fin;
	fin.open("data.txt",ios::out);
	CityName.push_back("��ͨ");
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

//��һ����

void print(const City& temp)
{
	cout<<"�������ƣ�"<<temp.CityName<<endl;
	cout<<temp.year<<"��"<<temp.month<<"��"<<temp.day<<"��"<<endl;
	cout<<"��Ҫ��Ⱦ�"<<temp.FirstPollutant<<endl;
	cout<<"��Ⱦָ����"<<temp.Pollution<<endl;
	cout<<"��Ⱦ�Ｖ��"<<temp.PollutionLevelRome<<endl;
	cout<<"����״����"<<temp.PollutionLevel<<endl;
	cout<<endl;
}

void OneDaySearch(vector<City>& temp)
{
	char ch;
	do
	{
		int month=0,day=0;
		string temp1,temp2;
		cout<<"���������ڣ��� �գ���";
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
			cout<<"�����������󣡣������������ڣ�";
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
		cout<<"Ҫ�˳��ó��е�һ���ѯ��(Y/N)";
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
		cout<<"���������ڣ�С�ڵ���53����";
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
			cout<<"�����������󣡣������������ڣ�С�ڵ���53����";
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
		cout<<"Ҫ�˳��ó��е�һ�ܲ�ѯ��(Y/N)";
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
		cout<<"�������·ݣ�";
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
			cout<<"�·�������󣡣����������·ݣ�";
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
		cout<<"Ҫ�˳��ó��е�һ�²�ѯ��(Y/N)";
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
		cout<<"�����뼾�ȣ�";
		int quarter=0;
		cin>>temp1;
		quarter=(int)temp1[0]-48;
		while(quarter<=0||quarter>4)
		{
			cout<<"�����������󣡣��������뼾�ȣ�";
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
		cout<<"Ҫ�˳��ó��е�һ���Ȳ�ѯ��(Y/N)";
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
		cout<<"���������ѯ�������ƣ�";
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
			cout<<"��ʱû������Ҫ��ѯ�ĳ��У��������������ѯ�������ƣ�";
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
			cout<<"1����ѯĳһ��"<<endl;
			cout<<"2����ѯĳһ��"<<endl;
			cout<<"3����ѯĳһ��"<<endl;
			cout<<"4����ѯĳһ����"<<endl;
			cout<<"5����ѯһ��"<<endl;
			cout<<"�������ѯ���ͱ�ţ�";
			int choose=-1;
			string temp;
			cin>>temp;
			choose=(int)temp[0]-48;
			while(choose<=0||choose>5||temp.length()>1)
			{
				cout<<"�������󣡣����������ѯ���ͱ�ţ�";
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
			cout<<"Ҫ�˳��ó��е���ز�ѯ��(Y/N)";
			string t;
			cin>>t;
			c=t[0];
		}while(toupper(c)=='N');
		cout<<"Ҫ�˳���ͨ��ѯģʽ��(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
	cout<<"ллʹ����ͨ��ѯ��"<<endl;
}

//�ڶ�����
//�ڶ����� ��һ��
int StatisticsCount[7]={0,0,0,0,0,0,0};

void printStatisticsCount()
{
	cout<<"�ţ�"<<StatisticsCount[0]<<endl;
	cout<<"����"<<StatisticsCount[1]<<endl;
	cout<<"��΢��Ⱦ��"<<StatisticsCount[2]<<endl;
	cout<<"�����Ⱦ��"<<StatisticsCount[3]<<endl;
	cout<<"�ж���Ⱦ��"<<StatisticsCount[4]<<endl;
	cout<<"�ж�����Ⱦ��"<<StatisticsCount[5]<<endl;
	cout<<"����Ⱦ��"<<StatisticsCount[6]<<endl;
	cout<<endl;
}

void OneCityWeekStatistics(vector<City>& temp)
{
	char ch;
	do
	{
		string temp1;
		cout<<"���������ڣ�С�ڵ���53����";
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
			cout<<"�����������󣡣������������ڣ�С�ڵ���53����";
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
				if(it->PollutionLevel=="��")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="��")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="��΢��Ⱦ")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="�����Ⱦ")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="�ж���Ⱦ")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="�ж�����Ⱦ")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="����Ⱦ")
					StatisticsCount[6]++;
			}
			if(GetWeek(it->month,it->day)==week-1)
				break;
		}
		cout<<"���У�"<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"���"<<week<<"��"<<endl;
		printStatisticsCount();
		cout<<"Ҫ�˳��ó��е�һ��ͳ�Ʋ�ѯ��(Y/N)";
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
		cout<<"�������·ݣ�";
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
			cout<<"�·�������󣡣����������·ݣ�";
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
				if(it->PollutionLevel=="��")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="��")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="��΢��Ⱦ")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="�����Ⱦ")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="�ж���Ⱦ")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="�ж�����Ⱦ")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="����Ⱦ")
					StatisticsCount[6]++;
			}
			if(it->month==month-1)
				break;
		}
		cout<<"���У�"<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"���"<<month<<"��"<<endl;
		printStatisticsCount();
		cout<<"Ҫ�˳��ó��е�һ��ͳ�Ʋ�ѯ��(Y/N)";
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
		cout<<"�����뼾�ȣ�";
		int quarter=0;
		cin>>temp1;
		quarter=(int)temp1[0]-48;
		while(quarter<=0||quarter>4)
		{
			cout<<"�����������󣡣��������뼾�ȣ�";
			cin>>temp1;
			quarter=(int)temp1[0]-48;
		}
		for(int i=0;i<7;i++)
			StatisticsCount[i]=0;
		for(vector<City>::iterator it=temp.begin();it!=temp.end();it++)
		{
			if(quarter==GetQuarter(it->month))
			{
				if(it->PollutionLevel=="��")
					StatisticsCount[0]++;
				else if(it->PollutionLevel=="��")
					StatisticsCount[1]++;
				else if(it->PollutionLevel=="��΢��Ⱦ")
					StatisticsCount[2]++;
				else if(it->PollutionLevel=="�����Ⱦ")
					StatisticsCount[3]++;
				else if(it->PollutionLevel=="�ж���Ⱦ")
					StatisticsCount[4]++;
				else if(it->PollutionLevel=="�ж�����Ⱦ")
					StatisticsCount[5]++;
				else if(it->PollutionLevel=="����Ⱦ")
					StatisticsCount[6]++;
			}
			if(quarter-1==GetQuarter(it->month))
				break ;
		}
		cout<<"���У�"<<temp.begin()->CityName<<endl;
		cout<<temp.begin()->year<<"���"<<quarter<<"����"<<endl;
		printStatisticsCount();
		cout<<"Ҫ�˳��ó��е�һ����ͳ�Ʋ�ѯ��(Y/N)";
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
		if(it->PollutionLevel=="��")
			StatisticsCount[0]++;
		else if(it->PollutionLevel=="��")
			StatisticsCount[1]++;
		else if(it->PollutionLevel=="��΢��Ⱦ")
			StatisticsCount[2]++;
		else if(it->PollutionLevel=="�����Ⱦ")
			StatisticsCount[3]++;
		else if(it->PollutionLevel=="�ж���Ⱦ")
			StatisticsCount[4]++;
		else if(it->PollutionLevel=="�ж�����Ⱦ")
			StatisticsCount[5]++;
		else if(it->PollutionLevel=="����Ⱦ")
			StatisticsCount[6]++;
	}
	cout<<"���У�"<<temp.begin()->CityName<<endl;
	cout<<temp.begin()->year<<"��"<<endl;
	printStatisticsCount();
}

void OneCityStatisticsSearch()
{
	char ch;
	do
	{
		cout<<"���������ѯ�������ƣ�";
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
			cout<<"��ʱû������Ҫ��ѯ�ĳ��У��������������ѯ�������ƣ�";
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
			cout<<"1��ͳ��ĳһ��"<<endl;
			cout<<"2��ͳ��ĳһ��"<<endl;
			cout<<"3��ͳ��ĳһ����"<<endl;
			cout<<"4��ͳ��һ��"<<endl;
			cout<<"�������ѯ���ͱ��";
			int choose=-1;
			string temp;
			cin>>temp;
			choose=(int)temp[0]-48;
			while(choose<=0||choose>4||temp.length()>1)
			{
				cout<<"�������󣡣����������ѯ���ͱ�ţ�";
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
			cout<<"Ҫ�˳��ó���ͳ�Ʋ�ѯ��(Y/N)";
			string t;
			cin>>t;
			c=t[0];
		}while(toupper(c)=='N');
		cout<<"Ҫ�˳�����ͳ�Ʋ�ѯģʽ��(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

//�ڶ����� �ڶ���

void WeekAirStatisticsSearch(int PollutionType,int time)
{
	string temp1;
	cout<<"���������ڣ�С�ڵ���53����";
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
		cout<<"�����������󣡣������������ڣ�С�ڵ���53����";
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
	cout<<"�������·ݣ�";
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
		cout<<"�·�������󣡣����������·ݣ�";
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
	cout<<"�����뼾�ȣ�";
	int quarter=0;
	cin>>temp1;
	quarter=(int)temp1[0]-48;
	while(quarter<=0||quarter>4)
	{
		cout<<"�����������󣡣��������뼾�ȣ�";
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
		cout<<"�������ѯʱ�䷶Χ���"<<endl;
		cout<<"1��ͳ��ĳһ��"<<endl;
		cout<<"2��ͳ��ĳһ��"<<endl;
		cout<<"3��ͳ��ĳһ����"<<endl;
		cout<<"4��ͳ��һ��"<<endl;
		int choose=-1;
		string temp1;
		cin>>temp1;
		choose=(int)temp1[0]-48;
		while(choose<=0||choose>4||temp1.length()>1)
		{
			cout<<"�������󣡣����������ѯ���ͱ�ţ�";
			cin>>temp1;
			choose=(int)temp1[0]-48;
		}
		cout<<"��ѡ���ѯ�Ŀ�������״����"<<endl;
		cout<<"1����"<<endl;
		cout<<"2����"<<endl;
		cout<<"3����΢��Ⱦ"<<endl;
		cout<<"4�������Ⱦ"<<endl;
		cout<<"5���ж���Ⱦ"<<endl;
		cout<<"6���ж�����Ⱦ"<<endl;
		cout<<"7������Ⱦ"<<endl;
		int PollutionType=-1;
		string temp2;
		cin>>temp2;
		PollutionType=(int)temp2[0]-48;
		while(choose<=0||choose>7||temp2.length()>1)
		{
			cout<<"�������󣡣����������ѯ���ͱ�ţ�";
			cin>>temp2;
			PollutionType=(int)temp2[0]-48;
		}
		cout<<"�������Ⱦ���͵�������"<<endl<<endl;
		cout<<"ע�⣺������ܲ�ѯ������ <= 7 "<<endl<<endl;
		cout<<"      ������²�ѯ������ <= the day of month"<<endl<<endl;
		cout<<"      ����Ǽ��Ȳ�ѯ������ <= the day of quarter"<<endl<<endl;
		cout<<"      ��������ѯ������ <= 365 "<<endl<<endl;
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
		cout<<"Ҫ�˳���ʱ���ͳ�Ʋ�ѯ��(Y/N)";
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
		cout<<"1����ѯĳһ����"<<endl;
		cout<<"2����ѯĳһʱ���"<<endl;
		cout<<"�����ѯ���ͣ�";
		int choose=-1;
		string temp;
		cin>>temp;
		choose=(int)temp[0]-48;
		while(choose<=0||choose>2||temp.length()>1)
		{
			cout<<"�������󣡣����������ѯ���ͱ�ţ�";
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
		cout<<"Ҫ�˳�ͳ�Ʋ�ѯ��(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
}

//��������
vector<forSort> CitySort;

void printCitySort(int len)
{
	for(unsigned int i=0;i<len;i++)
		{
			cout<<"��"<<i+1<<"����"<<CitySort[i].city<<endl;
		}
}

void WeekSort(int len)
{
	string temp1;
	cout<<"���������ڣ�С�ڵ���53����";
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
		cout<<"�����������󣡣������������ڣ�С�ڵ���53����";
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
	cout<<"�������·ݣ�";
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
		cout<<"�·�������󣡣����������·ݣ�";
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
	cout<<"�����뼾�ȣ�";
	int quarter=0;
	cin>>temp1;
	quarter=(int)temp1[0]-48;
	while(quarter<=0||quarter>4)
	{
		cout<<"�����������󣡣��������뼾�ȣ�";
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
		cout<<"1��һ������"<<endl;
		cout<<"2��һ������"<<endl;
		cout<<"3��һ��������"<<endl;
		cout<<"4��һ������"<<endl;
		cout<<"��ѡ���ѯ���ͣ�";
		int choose=-1;
		string temp;
		cin>>temp;
		choose=(int)temp[0]-48;
		while(choose<=0||choose>5||temp.length()>1)
		{
			cout<<"�������󣡣����������ѯ���ͱ�ţ�";
			cin>>temp;
			choose=(int)temp[0]-48;
		}
		cout<<"�������а񳤶ȣ�";
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
		cout<<"Ҫ�˳������ѯ��(Y/N)";
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
			cout<<"����������������ȷ�ı�ţ�";
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
			cout<<"ллʹ�ã�"<<endl;
			break;
		default:
			cout<<"error!"<<endl;
			break;
		}
		cout<<"Ҫ�˳���ѯ��(Y/N)";
		string t;
		cin>>t;
		ch=t[0];
	}while(toupper(ch)=='N');
	
	return 0;
}

