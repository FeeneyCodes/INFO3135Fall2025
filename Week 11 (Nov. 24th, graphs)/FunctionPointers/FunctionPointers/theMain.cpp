
float AddStuff(float a, float b)
{
	return a + b;
}

float MultiplyStuff(float a, float b)
{
	return a * b;
}


int main()
{
	float (*doMath)(float A, float B);

	float A = 23.3f;
	float B = 9.9f;

//	doMath = AddStuff;
	doMath = MultiplyStuff;

	float c = doMath(A, B);

	//float c = AddStuff(A, B);
	//c = MultiplyStuff(A, B);

	return 0;
}

