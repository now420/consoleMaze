#pragma once
#include <windows.h>
#include <vector>
#include <memory>

static enum GameKey {
	W = 0x57,
	A = 0x41,
	S = 0x53,
	D = 0x44
};

struct keyStruct {
	GameKey code;
	const char* name;
};

class c_input {
private:
	std::vector<keyStruct> keys = { {W, "W"}, {A, "A"}, {S, "S"}, {D, "D"} };
public:
	std::vector<keyStruct> getPressedKeys() {
		std::vector<keyStruct> pressedKeys;

		for (keyStruct key : keys) {
			if (GetAsyncKeyState(key.code)) {
				pressedKeys.push_back(key);
			}
		}

		return pressedKeys;
	}
};

std::shared_ptr<c_input> input = std::make_shared<c_input>();