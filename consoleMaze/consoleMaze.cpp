#include <iostream>
#include "input.h"
#include <thread>
#include "movement.h"
#include "defs.h"

int main()
{
    int won = 0;
    while (won != 2) {
        if (won == true) {
            won == 2;
            break;
        }
        std::vector<keyStruct> keys = input->getPressedKeys();
        for (keyStruct key : keys) {
            std::cout << key.name << std::endl;
        }

        int cache_x = movement->row.position;
        int cache_y = movement->column.position;

        movement->updatePosition(keys);

        std::cout << "(" << movement->row.position << ", " <<
            movement->column.position << ")" << std::endl;

        int x = 1;
        int y = 1;

        int prints = 0;

        while (y <= MAX_VALUE) {
            const char* print = "  ";

            int maze_iter = 0;
            for (int thing : maze) {
                maze_iter++;
                if (thing == 1 && prints == maze_iter - 1) {
                    print = "%%";
                }

                if (thing == 2 && prints == maze_iter - 1) {
                    print = "{}";
                }
            }

            if (x == movement->row.position && y == movement->column.position) {
                if (print == "%%") {
                    movement->column.position = cache_y;
                    movement->row.position = cache_x;
                }
                print = "!!";
                int current_index = (y - 1) * MAX_VALUE + (x - 1);
                if (maze[current_index] == 2) {
                    won = true;
                    prints = MAX_VALUE_SQ;
                    break;
                }
            }

            std::cout << print;
            if (x == MAX_VALUE && y != MAX_VALUE) {
                std::cout << "\n";
                x = 1;
                y++;
            }
            else {
                x++;
            }

            prints++;
            if (prints >= MAX_VALUE_SQ) break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        system("cls");
    }

    std::cout << "You won!" << std::endl;
    system("pause");
    return 0;
}