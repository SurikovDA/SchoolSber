#include <stdio.h>

/// @brief ФУНКЦИЯ ДЛЯ ВЫВОДА ИЗОБРАЖЕНИЯ
/// @param pointX Позиция X мяча в данный момент
/// @param pointY Позиция Y мяча в данный момент
/// @param roketY Позиция Y рокетки в данный момент
void render(int pointX, int pointY, int fPr, int sPr, int score_player_1,
            int score_player_2);

void render_string(int pointX, int pointY, int fPr, int sPr, int score_1_x,
                   int score_1_y, int score_2_x, int score_2_y,
                   int score_player_1, int score_player_2, int y_os, int width,
                   int rocket_size);

///

/// @brief
/// @return
char key_board();

int top_board(int roketY);
int under_board(int roketY, int height, int rocket_size);

int point_r_rocket(int pointX, int height, int rocket_size);
int point_l_rocket(int pointX, int height, int rocket_size);

int point_in_left_rocket(int pointX);
int point_in_right_rocket(int pointX, int width, int rocket_size);

int point_board(int pointY, int rocketY);

void WIN(int score_player_1, int score_player_2);

/// @brief
void clear_screen();
void pls_kill_me();

int main() {


  int score_player_1 = 0; // Очки игрока
  int score_player_2 = 0;
  //   char term; // Введеный символ

  int pointX = 40;
  int pointY = 12;

  int speed_point_x = 1;
  int speed_point_y = 0;

  int fPr = 13; // Стартовая позиция ракетки игрока №1
  int sPr = 13; // Стартовая позиция ракетки игрока №2

  while (score_player_1 < 21 || score_player_2 < 21)
{
    render(pointX, pointY, fPr, sPr, score_player_1, score_player_2);
    
    char fp;
    char sp;
    scanf("%c%c", &fp, &sp);
  

}


  

  return 0;
}

void render(int pointX, int pointY, int fPr, int sPr, int score_player_1,
            int score_player_2) {
  // Задаем постоянные переменные для отрисовки поля
  // Не изменяемые переменные
  int height = 25;     // Высота
  int width = 80;      // Ширина
  int rocket_size = 3; // Размер ракетки

  int score_1_x = 0; // Расположение счета игрока 1
  int score_1_y = 0;

  int score_2_x = 0;
  int score_2_y = 0;
  char horizontal = '-';

  // Крышка поля
  // Крутим Y
  for (int y_os = 0; y_os < height; y_os++) {
    render_string(pointX, pointY, fPr, sPr, score_1_x, score_1_y, score_2_x,
                  score_2_y, score_player_1, score_player_2, y_os, width,
                  rocket_size);
    printf("\n");
  }
}

void render_string(int pointX, int pointY, int fPr, int sPr, int score_1_x,
                   int score_1_y, int score_2_x, int score_2_y,
                   int score_player_1, int score_player_2, int y_os, int width,
                   int rocket_size) {
  char point = 'O';
  char rocket = '#';
  char vertical = '|';
  char spaces = ' ';

  for (int x_os = 0; x_os < width; x_os++) {
    // Крутим X
    if ((pointY == y_os) && (pointX == x_os)) {
      printf("%c", point);
    }
    // Отрисовка ракет
    else if ((x_os == 2 && y_os >= fPr && y_os < (sPr + rocket_size)) ||
             (x_os == (width - 3) && y_os >= sPr &&
              y_os < (sPr + rocket_size))) {
      printf("%c", rocket);
    } else if ((x_os == 0 || x_os == (width - 1) || x_os == (width / 2))) {
      printf("%c", vertical);
    } else if (x_os == score_1_x && y_os == score_1_y) {
      printf("%.2d", score_player_1);
      x_os += 1;
    } else if (x_os == score_2_x && y_os == score_2_y) {
      printf("%.2d", score_player_2);
      x_os += 1;
    } else {
      printf("%c", spaces);
    }
  }
}

char key_board() {
  return term;
}

int top_board(int roketY) { return roketY == 0; }

int under_board(int roketY, int height, int rocket_size) {
  return roketY == (height - rocket_size);
}

int point_r_rocket(int pointX, int height, int rocket_size) {
  return pointX == (height - rocket_size);
}

int point_in_left_rocket(int pointX) { return pointX == 0; }

int point_l_rocket(int pointX) { return pointX == 0; }

/// "\33[0d\33[2J"

void clear_screen() { printf("\33[0d\33[2J"); }

void pls_kill_me() {
  clear_screen();
  return 0;
}
