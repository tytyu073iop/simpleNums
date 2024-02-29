#include <iostream>
#include <vector>

// find simple

int main() {
	int x, y;
	std::cout << "enter number:";
	std::cin >> x;
	std::vector<int> a;
	_asm {
		mov eax, x // eax =
		mov ecx, 1 // counter
		mov edi, eax // buffer
		cycle1:
			inc ecx
			mov eax, edi
			cdq
			idiv ecx
			cmp eax, 0 // if end
			je exi
			cmp edx, 0 // if rem zero
		jne cycle1
		mov y, ecx
		push eax // save
		push ecx
	}
	std::cout << y << ", ";
	_asm {
		pop ecx
		pop eax
		cycle2: // clearing
			mov edi, eax
			cdq
			idiv ecx
			cmp edx, 0
		je cycle2
		mov eax, edi // recover from fail
		jmp cycle1
		exi:
	}
}