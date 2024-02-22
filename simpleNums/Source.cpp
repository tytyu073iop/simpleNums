#include <iostream>

int main() {
	int x, y;
	std::cout << "enter number:";
	std::cin >> x;
	_asm {
		mov eax, x // eax = x
		mov ecx, 2
		cycle1:
			xor edx, edx
			mov edi, eax // buffer
			idiv ecx
			cmp edx, 0
			je cycle1
			cmp eax, 0
			je exit
			mov y, ecx
	}
	std::cout << y << ", ";
	_asm {
		mov eax, edi
		inc ecx
		jmp cycle1
		exit:
	}
}