#include <Windows.h>
#include <stdio.h>

void f(float a, float b, float c, HANDLE* file)
{
	float D, x1, x2;
	D = (b * b) + 4 * a * c;
	printf("Дискириминант: %f\n", D);
	//WriteFile(file, "Дискириминант: %f\n", D);
	if (D > 0)
	{
		x1 = (-b + sqrt(D) / (2 * a));
		x2 = (-b - sqrt(D) / (2 * a));
		char lpBuff = "x1=%f\n x2=%f", x1, x2;
		byte nNumberOfBytesToWrite = 100;
		Writefile(file, lpBuff, nNumberOfBytesToWrite,NULL);
		CloseHandle(file);
	}
	else if (D < 0)
	{
		printf("Вещественных корней нет");
		char lpBuff = "Вещественных корней нет";
		byte nNumberOfBytesToWrite = 100;
		Writefile(file, lpBuff, nNumberOfBytesToWrite, NULL);
		CloseHandle(file);
	}
	else if (D = 0)
	{
		x1 = (-b + sqrt(D) / (2 / a));
		printf("x1=%f", x1);
		char lpBuff = "x1=%f", x1;
		byte nNumberOfBytesToWrite = 100;
		Writefile(file, lpBuff, nNumberOfBytesToWrite, NULL);
		CloseHandle(file);
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HANDLE file; HANDLE otv;
	otv = CreateFile(L"Otvet.txt", GENERIC_READ |
		GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
	file = CreateFile(L"Znach.txt", GENERIC_READ |
		GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
	char line[254];
	float a, b, c;
	a = 0; b = 0; c = 0;
	int lpBuff[] = { a,b,c };
	byte nNumberOfBytesToWrite = 10;
	if ((ReadFile(file, lpBuff, nNumberOfBytesToWrite, NULL,NULL)))
	{
		if (file == INVALID_HANDLE_VALUE)
		{
			printf("Could not open file.");
			return 0;
		}
		//A
		int probelA = 0;
		int umnA = 1;
		int numA = 1;
		double Apr = 0;
		//счётчик символов до пробела
		for (int i = 0; i < 254; i++)
		{
			if (line[i] != 32)
			{
				probelA++;
			}
			else
			{
				break;
			}
		}
		//считывание числа A из файла
		for (int i = probelA - 1; i >= 0; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelA - 1; j++)
				{
					numA = numA * 10;
				}
				a = a / numA;
				umnA = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Apr = line[i] - '0';
						a += Apr * umnA;
						umnA = umnA * 10;
					}
					else
					{
						a = a * -1;
					}
				}
				else
				{
					Apr = line[i] - '0';
					a += Apr * umnA;
					umnA = umnA * 10;
				}
			}
		}
		//B
		int probelB = probelA;
		int umnB = 1;
		int numB = 1;
		double Bpr = 0;
		//счётчик символов до пробела		
		for (int i = probelA + 1; i < 255; i++)
		{
			if (line[i] != 32)
			{
				probelB++;
			}
			else
			{
				break;
			}
		}
		//считывание числа B из файла
		for (int i = probelB; i >= probelA + 1; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelB - 1; j++)
				{
					numB = numB * 10;
				}
				b = b / numB;
				umnB = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Bpr = line[i] - '0';
						b += Bpr * umnB;
						umnB = umnB * 10;
					}
					else
					{
						b = b * -1;
					}
				}
				else
				{
					Bpr = line[i] - '0';
					b += Bpr * umnB;
					umnB = umnB * 10;
				}
			}
		}
		//C
		int probelC = probelB;
		int umnC = 1;
		int numC = 1;
		double Cpr = 0;
		//счётчик символов до пробела		
		for (int i = probelB + 2; i < 255; i++)
		{
			if (line[i] != -52)
			{
				probelC++;
			}
			else
			{
				break;
			}
		}
		//считывание числа C из файла
		for (int i = probelC; i >= probelB + 2; i--)
		{
			if (line[i] == 46)
			{
				for (int j = 0; j < probelC - 1; j++)
				{
					numC = numC * 10;
				}
				c = c / numC;
				umnC = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						Cpr = line[i] - '0';
						c += Cpr * umnC;
						umnC = umnC * 10;
					}
					else
					{
						c = c * -1;
					}
				}
				else
				{
					Cpr = line[i] - '0';
					c += Cpr * umnC;
					umnC = umnC * 10;
				}
			}
		}

	}
	//f(a, b, c, otv);
}


