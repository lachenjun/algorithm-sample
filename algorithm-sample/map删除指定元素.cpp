
void delete2(map<long,long> & ms)
{
	for (map<long, long>::iterator iter = ms.begin(); iter != ms.end();)
	{
		if (iter->second == 2)
		{	
			map<long, long>::iterator itertemmp = iter;
			++iter;
			ms.erase(itertemmp);
		}
		else
			++iter;
	}
}

void printmap(map<long,long> & ms)
{
	for (map<long, long>::iterator iter = ms.begin(); iter != ms.end(); ++iter)
	{
		cout << iter->first << iter->second << endl;
	}
}

void initmap(map<long, long> & ms)
{
	ms.insert(pair<long, long>(1,2));
	ms.insert(pair<long, long>(2,1));
	ms.insert(pair<long, long>(3,2));
	ms.insert(pair<long, long>(4,3));
	ms.insert(pair<long, long>(5,2));
	ms.insert(pair<long, long>(6,4));

}