#include <iostream>
#include <vector>

int main() {
	int x, y;
	std::cout << "enter number:";
	std::cin >> x;
	std::vector<int> a;
	_asm {
		mov eax, x // eax =
		mov ecx, 1
		mov edi, eax // buffer
		cycle1:
			inc ecx
			mov eax, edi
			cdq
			idiv ecx
			cmp eax, 0
			je exi
			cmp edx, 0
			jne cycle1
			mov y, ecx
			push eax
			push ecx
	}
	std::cout << y << ", ";
	_asm {
		pop ecx
		pop eax
		cycle2:
			mov edi, eax
			cdq
			idiv ecx
			cmp edx, 0
		je cycle2
		mov eax, edi
		jmp cycle1
		exi:
	}
}