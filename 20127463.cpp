1/
int calcSum(int** arr, int len, int wid)
{
	int sum = 0;
	for (int i = 0; i < wid; i++)
	{
		for (int j = 0; j < len; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int** concatenate2MatricesV(int** a, int** b, int len, int wid)
{
	int** c = new int* [wid * 2];
	for (int i = 0; i < wid * 2; i++)
	{
		*(c + i) = new int[len];
		if (calcSum(a, len, wid) > calcSum(b, len, wid))
		{
			for (int j = 0; j < len; j++)
			{
				if (i < wid) {
					*(*(c + i) + j) = *(*(a + i) + j);
				}
				else {
					*(*(c + i) + j) = *(*(b + i - wid) + j);
				}
			}
		}
		else
		{
			for (int j = 0; j < len; j++)
			{
				if (i < wid) {
					*(*(c + i) + j) = *(*(b + i) + j);
				}
				else {
					*(*(c + i) + j) = *(*(a + i - wid) + j);
				}
			}
		}
	}
	return c;
}

2/

int countEvenDigits(int n)
{
	if (n / 10 == 0 && n % 2 == 0) {
		return 1;
	}
	else if (n / 10 == 0 && n % 2 != 0) {
		return 0;
	}
	int sum = 0;
	if ((n % 10) % 2 == 0) {
		sum++;
	}
	return sum + countEvenDigits(n / 10);
}