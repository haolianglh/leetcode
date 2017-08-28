int maxArea(int* height, int heightSize) 
{
	int i = 0,j = heightSize - 1;
	int ret = 0, tmp = 0;
	if (heightSize <= 1)
	{
		return 0;
	}
	while (i != j)
	{	
		if (height[i] < height[j])
		{
			tmp = (j-i)*height[i++];
		}
		else
		{
			tmp = (j-i)*height[j--];
		}
		ret = tmp > ret?tmp:ret;
	}
	return ret;  
}

