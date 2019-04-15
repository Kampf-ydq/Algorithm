#include <iostream>  
#include <algorithm>  
#define MAX_NUM 1000  
using namespace std;

struct Goods //info of goods定义物品信息结构体  
{
	int weight;// the weight of goods重量  
	int value;// the value of goods价值  
	double ValPerWei;// value per weight权重  
	double load; //物品装入背包的部分的系数（例如上图中物品全部装入则load为1，装入10/20则load为0.5）  
};
int cmp(Goods const &a, Goods const &b)//定义sort函数的比较函数  
{
	if (a.ValPerWei<b.ValPerWei) return 0;
	else return 1;
}
void Greedy(Goods g[], int good_num, int content)//贪心算法  
{
	for (int i = 0; i<good_num; i++)
	{
		if (content>g[i].weight)//如果背包足够装下整个物品  
		{
			content -= g[i].weight;
			g[i].load = 1;
		}
		else if (content>0) {//如果背包不足以装下整个物品  
			g[i].load = (double)content / g[i].weight;//计算物品装入背包的部分  
			content = 0;//背包容量置0  
			return;//程序结束，返回  
		}
	}
}
int main()
{
	int goods_num;
	int bagvol;
	double total_value = 0;
	double total_weight = 0;
	cout << "Please input the volum of bag:" << endl;
	cin >> bagvol;
	cout << "Please input the number of goods:" << endl;
	cin >> goods_num;
	Goods G[goods_num + 1];
	cout << "Please inuput the weight and value of goods:" << endl;
	for (int i = 0; i<goods_num; i++)
	{
		cin >> G[i].weight >> G[i].value;//输入重量价值  
		G[i].ValPerWei = (double)G[i].value / G[i].weight;//计算权重  
		G[i].load = 0;//load置0  
	}

	sort(G, G + goods_num, cmp);//sort by ValPerWei  

	Greedy(G, goods_num, bagvol);
	cout << "Info of loaded goods:" << endl;
	for (int i = 0; i<goods_num; i++)//output the info of goods  
	{
		if (G[i].load == 0.0)break;//如果检测到物品未被装入背包，则推出循环  

		total_value += (G[i].value*G[i].load);//装入背包的物品总价值  
		total_weight += (G[i].weight*G[i].load);//装入背包的物品总重量  
		cout << "weight: " << G[i].weight << "  " << "value: " << G[i].value << "  " << "the value per weight of good: " << G[i].ValPerWei << "  the part of goods: " << G[i].load << endl;//输出装入背包的物品信息  
	}
	cout << "the volum of bag is: " << bagvol << endl;//输出背包容量  
	cout << "the total weight is: " << total_weight << endl;//输出装入物品的总重量  
	cout << "the total value is: " << total_value << endl;//输出装入物品的总价值  
}