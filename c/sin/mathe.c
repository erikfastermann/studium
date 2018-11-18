double fak(int n)
{
	double fakul = 1;
	int j;

	if (n < 0)
		return -1;
	else
	{
		for (j = 1; j <= n; j++)
		{
			fakul = fakul * j;
		}

		return fakul;
	}
}