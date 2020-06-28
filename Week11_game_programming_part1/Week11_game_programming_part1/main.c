
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define SCR_WIDTH 40
#define SCR_HEIGHT 20

typedef struct
{
    int width_;
    int height_;

    int pos_x_;
    int pos_y_;

    char* image_;
} Object;

Object player;
Object* p_bullet = NULL;

shootBullet()
{
    if (p_bullet == NULL)
    {
        p_bullet = (Object*)malloc(sizeof(Object));

        p_bullet->pos_x_ = player.pos_x_ + 2;
        p_bullet->pos_y_ = player.pos_y_;
        p_bullet->image_ = "!";
    }

}
void moveCursorTo(const short x, const short y)
{
    const COORD pos = { x, SCR_HEIGHT - y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawBoundary()
{
    int i = 0;
    for (int j = 0; j < SCR_HEIGHT; j++)
    {
        moveCursorTo(i, j);
        printf("|");
    }

    i = SCR_WIDTH - 1;
    for (int j = 0; j < SCR_HEIGHT; j++)
    {
        moveCursorTo(i, j);
        printf("|");
    }
}

int main()
{
    CONSOLE_CURSOR_INFO cur_info;
    cur_info.dwSize = 1;
    cur_info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);

    player.image_ = ">-O-<";
    player.width_ = 5;
    player.height_ = 1;
    player.pos_x_ = 10;
    player.pos_y_ = 3;

    
    printf(">-O-<");

    while (true)    // main game loop
    {
        if (kbhit() != 0)
        {
            char key_input = getch();

            switch (key_input)
            {
            case 72:    // up arrow key
                player.pos_y_++;
                break;
            case 80:
                player.pos_y_--;
                break;
            case 75:
                player.pos_x_--;
                break;
            case 77: // right
                if (player.pos_x_ < SCR_WIDTH - player.width_ -1)
                    player.pos_x_++;
                break;
            case 32: // space key (shooting)
                shootBullet();
                break;
            }
        }
        
        if (p_bullet != NULL)
        {
            if (p_bullet->pos_y_ >= SCR_HEIGHT - 1)
            {
                free(p_bullet);
                p_bullet = NULL;
            }
            else
                p_bullet->pos_y_++;
        }

        system("cls");

        // draw boundary
        drawBoundary();

        // draw player
        moveCursorTo(player.pos_x_, player.pos_y_);
        printf("%s", player.image_);

        // draw a bullet
        if (p_bullet != NULL)
        {
            moveCursorTo(p_bullet->pos_x_, p_bullet->pos_y_);
            printf("%s", p_bullet->image_);
        }

        Sleep(10);

    }
}
