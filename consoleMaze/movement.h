#pragma once
#include "input.h"
#include "defs.h"

struct s_row {
	int position = 1; // 1-8, left right
};

struct s_column {
	int position = 1; // 1-8, up down
};

class c_movement {
public:
	s_column column;
	s_row row;

	void updatePosition(std::vector<keyStruct> keys) {
		for (keyStruct key : keys) {
			switch (key.code) {
			case W:
				if (column.position > 1) column.position--;
				break;
			case S:
				if (column.position < MAX_VALUE) column.position++;
				break;
			case A:
				if (row.position > 1) row.position--;
				break;
			case D:
				if (row.position < MAX_VALUE) row.position++;
				break;
			default:
				break;
			}
		}
	}
};

std::shared_ptr<c_movement> movement = std::make_shared<c_movement>();