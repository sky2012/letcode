//n give the sum of a list,and start give the first number of the list
void f(int n,list<int>& list1,int start) 
{
	if (n==1)
	{
		//输出前缀，当然前缀肯定也全部都是1
		print_list(list1.begin(),list1.end());
		//换行
		cout<<1<<endl;
	} 
	else
	{
		//1+2 和 2+1 认为是同一种情况 ,所以只输出n1+n2+n3+..., n1<=n2<=n3... 
		// 只输出后续组合从start开始的那些组合（1+2）（ + 3+3=6）=9
		for (int i=start;i<=n/2;i++) 
		{
			//（ + 3+3=6）
			list1.push_back(i); 
			//print 1+f(n-1)   print 2+f(n-2)...
			//每个函数打印它自己的所有子情况，
			//同时借助上层函数遗留的链表作为前缀，
			//有start决定从哪一个数字开始打印
			
			f(n-i,list1,i); 
			//the loop goto a new number at the end of the list
			//（1+2）                        =9 为进入下一个循环迭代做好准备
			list1.pop_back();   
		}
		//for循环之外的情况，即n自身的输出（当然也要先输出前缀）
		print_list(list1.begin(),list1.end());
		//输出自己，单独输出一行
		cout<<n<<endl;
	}
}
int main( void ) 
{
	list<int> list1 ;
	f(9,list1,1);
	return 0;
}