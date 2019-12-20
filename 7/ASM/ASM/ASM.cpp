// ASM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iostream>

int  main()
{
	int a, b, c, result, i = 0;
	std::cout << "Enter 2 nums" << std::endl;
	std::cin >> a >> b;

	_asm
	{
		mov eax, a
		mov ebx, b
		begin:
			cmp eax, ebx
				je end
				jg gr
				sub ebx, eax
				jmp begin
				gr:
					sub eax, ebx
					jmp begin
						end:
							mov result, eax
	}

	std::cout << "result first task: " << result << std::endl;

	std::cout << "_______________________________________________" << std::endl;

	int nodResult;

	_asm
	{
		mov eax, a
		mov ebx, b
		start:
			cmp ebx, 0
			jz res
			xor edx, edx
			div ebx
			mov eax, ebx
			mov ebx, edx
			jmp start
				res:
					mov nodResult, eax
	}

	std::cout << "result second task: " << nodResult << std::endl;

	std::cout << "_______________________________________________" << std::endl;

	std::cout << "Enter 1 num for check" << std::endl;
	int t;
	std::cin >> t;

	_asm
	{
		mov eax, t
		shr eax, 3
		jnb zer
		jb one
		zer: 
			mov eax, 0
			jmp endd
				one:
					mov eax, 1
					jmp endd
						endd:
							mov result, eax
	}

	std::cout << "result third task: " << result << std::endl;

	getchar();
	return 0;
}