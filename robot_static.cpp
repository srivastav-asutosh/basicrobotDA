#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    initwindow(1580, 920, "Moving Robot with Colourful Background");
    int page = 0;
    int x = 100;
    int y = 500;
    int dx = 5;
    int robot_h = 120;
    int robot_w = 80;
    int head_r = 20;
    int arm_h = 60;
    int arm_w = 20;
    int leg_h = 80;
    int leg_w = 20;
    int i;

    for (i = 0; i < 1000; i++) {
        i=0;
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        // Background
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(120, 2, WHITE);

        // Sun
        circle(200, 140, 50);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(200, 140, WHITE);

        // Buildings
        rectangle(1280, 250, 1580, 650);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        floodfill(1300, 550, WHITE);

        rectangle(780, 250, 1080, 650);
        setfillstyle(SOLID_FILL, BROWN);
        floodfill(800, 550, WHITE);

        // Road
        line(0, 650, 1600, 650);

        // Grass
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(0, 650, 1600, 920);
        floodfill(10, 900, WHITE);

        // Robot
        // Head
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, MAGENTA);
        circle(x + robot_w / 2, y - robot_h / 5, head_r);
        floodfill(x + robot_w / 2, y - robot_h / 5, BLACK);

        // Torso
        setcolor(BLACK);
        rectangle(x, y, x + robot_w, y + robot_h / 2);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + robot_w / 2, y + robot_h / 4, BLACK);

        // Arms
        rectangle(x - arm_w, y + robot_h / 4, x, y + arm_h + robot_h / 4);
        rectangle(x + robot_w, y + robot_h / 4, x + robot_w + arm_w, y + arm_h + robot_h / 4);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(x - arm_w / 2, y + robot_h / 2, BLACK);
        floodfill(x + robot_w + arm_w / 2, y + robot_h / 2, BLACK);

        // Legs
        rectangle(x, y + robot_h / 2, x + leg_w, y + leg_h + robot_h / 2);
        rectangle(x + robot_w - leg_w, y + robot_h / 2, x + robot_w, y + leg_h + robot_h / 2);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(x + leg_w / 2, y + robot_h * 3 / 4, BLACK);
        floodfill(x + robot_w - leg_w / 2, y + robot_h * 3 / 4, BLACK);


        // Flip pages
        page = 1 - page;
        setcolor(WHITE);
    }
    getch();
    return 0;
}
