#include <stdio.h>
#include <math.h>

int main1(int argc, char **argv) {
	printf("hello world\n");
}

// + for int and float
float AddIAndF(int first, float second)
{
	return float(first) + second;
}

float AddFAndI(float first, int second)
{
	return first + float(second);
}

// - for int and float
float SubstractIAndF(int first, float second)
{
	return float(first) - second;
}

float SubstractFAndI(float first, int second)
{
	return first - float(second);
}

// * for int and float
float MultiplyIAndF(int first, float second)
{
	return float(first) * second;
}

float MultiplyFAndI(float first, int second)
{
	return first * float(second);
}


// / for int and float
float DivideIAndF(int first, float second)
{
	return float(first) / second;
}

float DivideFAndI(float first, int second)
{
	return first / float(second);
}

// Modulo
float ModuloIAndF(int first, float second)
{
	return fmod(float(first), second);
}

float ModuloFAndI(float first, int second)
{
	return fmod(first, float(second));
}

// Less
float LessIAndF(int first, float second)
{
	return float(first) < second;
}

float LessFAndI(float first, int second)
{
	return first < float(second);
}

// Equals
float EqualsIAndF(int first, float second)
{
	return float(first) == second;
}

float EqualsFAndI(float first, int second)
{
	return first == float(second);
}

