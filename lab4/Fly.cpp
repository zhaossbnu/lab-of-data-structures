#include "Fly.h"

string city[8]={"北京","上海","西安","广州","武汉","拉萨","昆明","乌鲁木齐"};			//查询城市的集合

int position(string place)				//判断某个城市在数组中的位置
{
	for(int i=0;i<8;i++)
		if(city[i]==place)
		{
			return i;
		}
	return -1;
}


Fly::Fly()							//构造函数
{
	for(int i=0;i<8;i++)						//初始化邻接矩阵
		for(int j=0;j<8;j++)
		{
			fly[i][j].Plane_Number="none";			
			fly[i][j].strart=city[i];
			fly[i][j].end=city[j];
			if(i==j)
			{
				fly[i][j].time_cost=0;
				fly[i][j].money_cost=0;
				fly[i][j].interchange_cost=0;
			}
			else
			{
				fly[i][j].time_cost=Max;
				fly[i][j].money_cost=Max;
				fly[i][j].interchange_cost=Max;
			}
		}

		fly[0][1].Plane_Number=fly[1][0].Plane_Number="6320";		//将有航班的航班号存入邻接矩阵
		fly[0][2].Plane_Number=fly[2][0].Plane_Number="201";
		fly[2][3].Plane_Number=fly[3][2].Plane_Number="2323";
		fly[3][4].Plane_Number=fly[4][3].Plane_Number="4723";
		fly[4][5].Plane_Number=fly[5][4].Plane_Number="3304";
		fly[5][6].Plane_Number=fly[6][5].Plane_Number="173";
		fly[6][7].Plane_Number=fly[7][6].Plane_Number="82";
		fly[7][0].Plane_Number=fly[0][7].Plane_Number="2104";

		fly[0][1].time_cost=65;					////将有航班的时间消耗存入邻接矩阵
		fly[1][0].time_cost=65;
		fly[0][2].time_cost=95;
		fly[2][0].time_cost=100;
		fly[2][3].time_cost=140;
		fly[3][2].time_cost=80;
		fly[3][4].time_cost=100;
		fly[4][3].time_cost=100;
		fly[4][5].time_cost=90;
		fly[5][4].time_cost=90;
		fly[5][6].time_cost=85;
		fly[6][5].time_cost=85;
		fly[6][7].time_cost=165;
		fly[7][6].time_cost=165;
		fly[7][0].time_cost=55;
		fly[0][7].time_cost=115;

		fly[0][1].money_cost=680;				//将有航班的费用存入邻接矩阵
		fly[1][0].money_cost=680;
		fly[0][2].money_cost=930;
		fly[2][0].money_cost=930;
		fly[2][3].money_cost=1320;
		fly[3][2].money_cost=1320;
		fly[3][4].money_cost=810;
		fly[4][3].money_cost=810;
		fly[4][5].money_cost=890;
		fly[5][4].money_cost=890;
		fly[5][6].money_cost=830;
		fly[6][5].money_cost=830;
		fly[6][7].money_cost=1480;
		fly[7][6].money_cost=1480;
		fly[7][0].money_cost=1150;
		fly[0][7].money_cost=1150;

		fly[0][1].interchange_cost=1;				//将有航班的换乘次数存入邻接矩阵，两地有航班则设为1
		fly[1][0].interchange_cost=1;
		fly[0][2].interchange_cost=1;
		fly[2][0].interchange_cost=1;
		fly[2][3].interchange_cost=1;
		fly[3][2].interchange_cost=1;
		fly[3][4].interchange_cost=1;
		fly[4][3].interchange_cost=1;
		fly[4][5].interchange_cost=1;
		fly[5][4].interchange_cost=1;
		fly[5][6].interchange_cost=1;
		fly[6][5].interchange_cost=1;
		fly[6][7].interchange_cost=1;
		fly[7][6].interchange_cost=1;
		fly[7][0].interchange_cost=1;
		fly[0][7].interchange_cost=1;
}

Fly::~Fly(void)
{

}

void Fly::time_min(string st,string ed)				//时间最少的函数
{
	int v=position(st);						//找到起点的位置

	bool station[8];						//最少时间的路径点集合
	int time[8];							//起点到每一个点的时间消耗
	int time_path[8];						//存放求到的最短路径
	for(int i=0;i<8;i++)					//初始化 
	{
		station[i]=false;
		time[i]=fly[v][i].time_cost;
		if(i!=v&&time[i]<Max)
			time_path[i]=v;
		else
			time_path[i]=-1;
	}
	station[v]=true;					//将起点加入顶点集合
	time[v]=0;

	for(int i=0;i<7;i++)
	{
		int minTime=Max;
		int u=v;						//选择不再顶点集合中的点u
		for(int j=0;j<8;j++)
			if(station[j]==false&&time[j]<minTime)
			{
				u=j;
				minTime=time[j];
			}
		station[u]=true;					//将顶点u加入顶点集合
		for(int k=0;k<8;k++)
		{
			int w=fly[u][k].time_cost;
			if(station[k]==false&&w<Max&&time[u]+w<time[k])			//顶点k未加入路径 且绕过u可以缩短路径
			{
				time[k]=time[u]+w;					//修改到k的最短路径
				time_path[k]=u;
			}
		}
	}
	v=position(st);								//确定起点的位置
	int vv=position(ed);						//确定终点的位置
	
	int p[8];									//存放起点的终点的路径
	for(int i=0;i<8;i++)						//初始化
		p[i]=-1;
	for(int i=7;i>=0;i--)			//从数组的后面向前输入路径点，则正向读出的路径就是正确路径
	{	
		p[i]=vv;				
		if(vv==v)
			break;
		vv=time_path[vv];	
	}
	int min=0;
	for(int i=0;i<8;i++)					//输出路径
	{
		if(p[i]!=-1&&i+1<8)
		{
			cout<<city[p[i]]<<"->"<<city[p[i+1]]<<"\t航班号:"<<fly[p[i]][p[i+1]].Plane_Number<<"\t飞行时间:"<<fly[p[i]][p[i+1]].time_cost<<"min"<<"\t票价:"<<fly[p[i]][p[i+1]].money_cost<<"元"<<endl;
			min=min+fly[p[i]][p[i+1]].time_cost;
		}
	}
	cout<<"最短时间为："<<min<<"min"<<endl;

}

void Fly::money_min(string st,string ed)			//费用最少的函数
{
	int v=position(st);

	bool station[8];
	int money[8];
	int money_path[8];
	for(int i=0;i<8;i++)
	{
		station[i]=false;
		money[i]=fly[v][i].money_cost;
		if(i!=v&&money[i]<Max)
			money_path[i]=v;
		else
			money_path[i]=-1;
	}
	station[v]=true;
	money[v]=0;

	for(int i=0;i<7;i++)
	{
		int minMoney=Max;
		int u=v;
		for(int j=0;j<8;j++)
			if(station[j]==false&&money[j]<minMoney)
			{
				u=j;
				minMoney=money[j];
			}
		station[u]=true;
		for(int k=0;k<8;k++)
		{
			int w=fly[u][k].money_cost;
			if(station[k]==false&&w<Max&&money[u]+w<money[k])
			{
				money[k]=money[u]+w;
				money_path[k]=u;
			}
		}
	}
	v=position(st);
	int vv=position(ed);
	
	int p[8];
	for(int i=0;i<8;i++)
		p[i]=-1;
	for(int i=7;i>=0;i--)
	{	
		p[i]=vv;
		if(vv==v)
			break;
		vv=money_path[vv];	
	}
	int min=0;
	for(int i=0;i<8;i++)					//输出路径
	{
		if(p[i]!=-1&&i+1<8)
		{
			cout<<city[p[i]]<<"->"<<city[p[i+1]]<<"\t航班号:"<<fly[p[i]][p[i+1]].Plane_Number<<"\t飞行时间:"<<fly[p[i]][p[i+1]].time_cost<<"min"<<"\t票价:"<<fly[p[i]][p[i+1]].money_cost<<"元"<<endl;
			min=min+fly[p[i]][p[i+1]].money_cost;
		}
	}
	cout<<"最少费用为："<<min<<"元"<<endl;
}

void Fly::Interchange_min(string st,string ed)				//换乘次数最少的函数
{
	int v=position(st);

	bool station[8];
	int interchange[8];
	int interchange_path[8];
	for(int i=0;i<8;i++)
	{
		station[i]=false;
		interchange[i]=fly[v][i].interchange_cost;
		if(i!=v&&interchange[i]<Max)
			interchange_path[i]=v;
		else
			interchange_path[i]=-1;
	}
	station[v]=true;
	interchange[v]=0;

	for(int i=0;i<7;i++)
	{
		int minTime=Max;
		int u=v;
		for(int j=0;j<8;j++)
			if(station[j]==false&&interchange[j]<minTime)
			{
				u=j;
				minTime=interchange[j];
			}
		station[u]=true;
		for(int k=0;k<8;k++)
		{
			int w=fly[u][k].interchange_cost;
			if(station[k]==false&&w<Max&&interchange[u]+w<interchange[k])
			{
				interchange[k]=interchange[u]+w;
				interchange_path[k]=u;
			}
		}
	}
	v=position(st);
	int vv=position(ed);
	
	int p[8];
	for(int i=0;i<8;i++)
		p[i]=-1;
	for(int i=7;i>=0;i--)
	{	
		p[i]=vv;
		if(vv==v)
			break;
		vv=interchange_path[vv];	
	}
	int min=0;
	for(int i=0;i<8;i++)					//输出路径
	{
		if(p[i]!=-1&&i+1<8)
		{
			cout<<city[p[i]]<<"->"<<city[p[i+1]]<<"\t航班号:"<<fly[p[i]][p[i+1]].Plane_Number<<"\t飞行时间:"<<fly[p[i]][p[i+1]].time_cost<<"min"<<"\t票价:"<<fly[p[i]][p[i+1]].money_cost<<"元"<<endl;
			min=min+fly[p[i]][p[i+1]].interchange_cost;
		}
	}
	cout<<"最少次数为："<<min<<"次"<<endl;
}