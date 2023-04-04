#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int matrix1[25][80]);
void initial(int matrix1[25][80], const char* s);
void initstdin(int matrix[25][80]);
void randomizer(int matrix[25][80]);
void draw(int matrix[25][80]);
void step(int matrix1[25][80], int matrix2[25][80]);
void check(int matrix1[25][80], int matrix2[25][80], int row, int col);

int main() {
    initscr();

    char c;
    int matrix1[25][80], matrix2[25][80];
    int s = 1, k = 3;
    halfdelay(k);

    c = getch();

    if (c != '8')
        menu(matrix1);
    else
        initstdin(matrix1);

    noecho();
    draw(matrix1);

    do {
        if (s == (-1)) {
            step(matrix2, matrix1);
            draw(matrix1);
        } else {
            step(matrix1, matrix2);
            draw(matrix2);
        }
        s *= (-1);
        c = getch();
        if (c == '=' && k > 1) k -= 1;
        if (c == '-') k++;
        halfdelay(k);
    } while (c != 'q');
    endwin();

    return 0;
}

void menu(int matrix1[25][80]) {
    const char* s;
    int d;

    do {
        clear();
        printw(
            "Choose initial conditions:\n 1. Gun\n 2. Galaxy\n 3. Pulsar\n 4. Virus\n 5. Clock\n 6. "
            "Random\n");
        refresh();
        d = getchar() - 48;

    } while (d < 1 || d > 6);

    switch (d) {
        case 1:
            s = "gun.map";
            break;
        case 2:
            s = "galaxy.map";
            break;
        case 3:
            s = "pulsar.map";
            break;
        case 4:
            s = "virus.map";
            break;
        case 5:
            s = "clock.map";
            break;
    }
    if (d == 6) {
        randomizer(matrix1);
    } else {
        initial(matrix1, s);
    }
}

void initial(int matrix1[25][80], const char* s) {
    FILE* map;
    char c;

    if ((map = fopen(s, "r")) == NULL) {
        printw("Не удалось открыть файл");
        getchar();
    } else {
        fscanf(map, "%c", &c);
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                fscanf(map, "%c", &c);
                matrix1[i][j] = c - 48;
            }
            fscanf(map, "%c", &c);
        }
    }
    fclose(map);
}

void initstdin(int matrix[25][80]) {
    char c;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            scanf("%c", &c);
            matrix[i][j] = c - 48;
        }
        scanf("%c", &c);
    }
    stdin = freopen("/dev/tty", "r", stdin);
}

void randomizer(int matrix[25][80]) {
    srand(time(NULL));
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

void draw(int matrix[25][80]) {
    clear();
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (matrix[i][j] == 0) {
                printw(" ");
            } else if (matrix[i][j] == 1) {
                printw("0");
            }
        }
        if (i < 24) {
            printw("\n");
        }
    }

    refresh();
}

void step(int matrix1[25][80], int matrix2[25][80]) {
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++) {
            check(matrix1, matrix2, i, j);
        }
}

void check(int matrix1[25][80], int matrix2[25][80], int row, int col) {
    int count = 0, y, x;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else {
                y = row + i;
                x = col + j;
                if (y < 0) y = 24;
                if (y > 24) y = 0;
                if (x < 0) x = 79;
                if (x > 79) x = 0;
                count += matrix1[y][x];
            }
        }
    }
    if (matrix1[row][col] == 1) {
        if (count != 2 && count != 3)
            matrix2[row][col] = 0;
        else
            matrix2[row][col] = 1;
    } else {
        if (count == 3) {
            matrix2[row][col] = 1;
        } else
            matrix2[row][col] = 0;
    }
}
