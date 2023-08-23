
void IntervalMapTest()
{
	interval_map<int, char> intervalMap('A');

	/*
	intervalMap.assign(1, 2, 'B');
	intervalMap.assign(-2, 0, 'A');
	intervalMap.assign(3, 5, 'A');
	*/

	intervalMap.assign(-2, 0, 'A');
	intervalMap.assign(1, 5, 'B');
	intervalMap.assign(6, 7, 'B');
	intervalMap.assign(8, 10, 'A');

	/*
	intervalMap.assign(5, 7, 'B');
	intervalMap.assign(-2, 2, 'A');
	intervalMap.assign(11, 15, 'C');
	intervalMap.assign(21, 30, 'D');
	intervalMap.assign(8, 10, 'A');
	*/

	for (int i = -2; i <= 5; i++) {
		char ch = intervalMap[i];
		int ii = 0;
	}
}