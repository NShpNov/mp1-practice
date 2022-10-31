#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip> 
#include <Windows.h>
#define w 20
#define h 20
#define m 30
int k = 0;
char c[18] = { ' ', 'm', 'i', 'n', 'e', '(', 's',')', ' ', 'r', 'e', 'm', 'a', 'i', 'n', 'i', 'n', 'g'};
char b[60] = { 'a', 'n', 'd', ' ', 't', 'h', 'e', ' ', 'g', 'a', 'm', 'e', ' ', 'h', 'a', 's', 'n', '\'', 't', ' ', 'e', 'n', 'd', 'e', 'd', '.', ' ', 'A', 'r', 'e', ' ', 'y', 'o', 'u', ' ', 's', 'u', 'r', 'e', ',', ' ', 'y', 'o', 'u', ' ', 'd', 'o', 'i', 'n', 'g', ' ', 'a', 'l','r','i','g','h', 't', '?'};
char d[18] = { ' ', 'r', 'u', 'l', 'e', 's', ' ', 'a', 'r', 'e', ' ', 's', 'i', 'm', 'p', 'l', 'e', ':' };
char e[70] = { ' ', 'y', 'o', 'u', ' ', 'w', 'r', 'i', 't', 'e', ' ', '\'', 'o', '\'', ' ', '(', 'o', 'p', 'e', 'n', ' ', 't', 'h', 'e', ' ', 'c', 'e', 'l', 'l', ')', ' ', 'o', 'r', ' ', '\'', 'f', '\'', ' ', '(', 'p', 'u', 't', ' ', '(', 'o', 'r', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ')', ' ', 'f', 'l', 'a', 'g', ' ', 'o', 'n', ' ', 'a', ' ', 'c', 'e', 'l', 'l', ')' };
char f[50] = { ' ', 'a', 'n', 'd', ' ', 't', 'h', 'e', 'n', ' ', 'i', 't', '\'', 's', ' ', 'c', 'o', 'o', 'r', 'd', 'i', 'n', 'a', 't', 'e', 's',' ', '(', 'h', 'e', 'i', 'g', 'h', 't', ' ', 'a', 'n', 'd', ' ', 't', 'h', 'e', 'n', ' ', 'w', 'i', 'd', 't', 'h', ')'};
char g[26] = { ' ', 'e', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'o', ' ', '1', '0', ' ', '7', ' ', ' ', ' ', ' ', 'f', ' ', '4', ' ', '1', '5' };
char l[29] = { ' ', 'Y', 'o', 'u', '\'', 'v', 'e', ' ', 'f', 'a', 'i', 'l', 'e', 'd', '.', '.', '.', ' ', 'T', 'r', 'y', ' ', 'a', 'g', 'a', 'i', 'n', ':', '(' };
char n[24] = { ' ', 'T', 'h', 'a', 't', '\'', 's', ' ', 'a', ' ', 'w', 'i', 'n', '!', ' ', 'C', 'o', 'n', 'g', 'r', 'a', 't', 's', '!' };
char field[h][w];
char field_with_mines[h][w];
char typed;
int line, raw, flag_marker, true_flag;
int end_game;
void number_on_a_cell(int i, int j)
{
	if ((i >= 0) && (i < h) && (j >= 0) && (j < w)) {
		field_with_mines[i][j]++;
	}
}
void generate_mines()
{
	int mines_number = 0, i, j;
	time_t t;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			field_with_mines[i][j] = '0';
		}
	}

	srand((unsigned)time(&t));
	while (mines_number < m) {
		i = rand() % h;
		j = rand() % w;
		if (field_with_mines[i][j] == '0') {
			field_with_mines[i][j] = 'X';
			number_on_a_cell(i - 1, j);
			number_on_a_cell(i, j - 1);
			number_on_a_cell(i + 1, j);
			number_on_a_cell(i, j + 1);
			number_on_a_cell(i - 1, j - 1);
			number_on_a_cell(i - 1, j + 1);
			number_on_a_cell(i + 1, j + 1);
			number_on_a_cell(i + 1, j - 1);
			mines_number++;
		}
	}
}
void generate_field()
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			field[i][j] = '*';
		}
	}
}
void reveal(int i, int j)
{
	if ((field[i][j] == '*') && (field_with_mines[i][j] != 'X') && (i >= 0) && (i <= h) && (j >= 0) && (j <= w))
	{
		field[i][j] = field_with_mines[i][j];
		if (field_with_mines[i][j] == '0') {
			reveal(i - 1, j);
			reveal(i, j - 1);
			reveal(i + 1, j);
			reveal(i, j + 1);
			reveal(i + 1, j + 1);
			reveal(i - 1, j - 1);
			reveal(i + 1, j - 1);
			reveal(i - 1, j + 1);
		}
	}
}
void open_cell(int i, int j)
{
	if (field_with_mines[i][j] == 'X') {
		end_game += 1;
		field[i][j] = 'X';
	}
	else {
		reveal(i, j);
	}
}
void flag_move(int i, int j)
{
	if (field[i][j] == '*') {
		field[i][j] = 'F';
		flag_marker++;
		if (field_with_mines[i][j] == 'X') {
			true_flag++;
		}
	}
	else {
		field[i][j] = '*';
		flag_marker--;
	}
}
void move() {
	std::cin >> typed >> line >> raw;
	switch (typed)
	{
	case 'o':
		open_cell(line - 1, raw - 1); break;
	case 'f':
		flag_move(line - 1, raw - 1); break;
	default:
		move();
	}
}
bool win_check()
{
	if ((true_flag == m) && (flag_marker == m)) {
		return 1;
	}
	else {
		return 0;
	}
}
void print_field(char a[h][w])
{
	int i, j;
	std::cout << "     ";
	for (i = 0; i < w; i++) {
		if (k == 0) { Sleep(1); }
		std::cout << std::setw(3) << i + 1;
	}
	std::cout << std::endl << "   ";
	for (i = 0; i < 3 * w + 2; i++) {
		if (k == 0) { Sleep(1); }
		std::cout << "_";
	}
	std::cout << std::endl;
	for (i = 0; i < h; i++) {
		if (i >= 9) {
			std::cout << i + 1 << "  " << "|";
			if (k == 0) { Sleep(1); }
		}
		else {
			std::cout << i + 1 << "   " << "|";
			if (k == 0) { Sleep(1); }
		}
		for (j = 0; j < w; j++) {
			std::cout << std::setw(3) << a[i][j];
			if (k == 0) { Sleep(1); }
		}
		std::cout << std::endl;
	}
	k = 1;
	std::cout << std::endl << std::setw(5) << m - flag_marker;
	for (i = 0; i < 18; i++) {
		Sleep(50);
		std::cout << c[i];
	}
	if ((m - flag_marker <= 0) && (flag_marker != true_flag)) {
		Sleep(1000);
		std::cout << ".";
		Sleep(1000);
		std::cout << ".";
		Sleep(1000);
		std::cout << ". ";
		Sleep(1000);
		for (i = 0; i < 60; i++) {
			std::cout << b[i];
			Sleep(50);
			if (b[i] == '.') {
				Sleep(300);
			}
		}
		Sleep(950);
	}
	std::cout << std::endl << std::endl;
}
int main()
{
	int i;
	for (i = 0; i < 18; i++) {
		Sleep(30);
		std::cout << d[i];
	}
	std::cout << std::endl;
	for (i = 0; i < 70; i++) {
			Sleep(30);
			std::cout << e[i];
	}
	std::cout << std::endl;
	for (i = 0; i < 50; i++) {
		Sleep(30);
		std::cout << f[i];
	}
	std::cout << std::endl << std::endl;
	for (i = 0; i < 26; i++) {
		Sleep(30);
		std::cout << g[i];
	}
	std:: cout << std::endl << std::endl << std::endl;
	do
	{
		generate_field();
		generate_mines();
		while (!win_check()) {
			print_field(field);
			move();
			if (end_game == 1) {
				print_field(field);
				std::cout << std::endl;
				for (i = 0; i < 29; i++) {
					Sleep(30);
					std::cout << l[i];
				}
				std::cout << std::endl << std::endl;
				Sleep(1000);
				std::cout << std::endl << "3...";
				Sleep(1000);
				std::cout << std::endl << "2...";
				Sleep(1000);
				std::cout << std::endl << "1..." << std::endl;
				Sleep(1000);
				std::cout << std::endl;
				end_game = 0;
				break;
			}
		}
		if (win_check()) {
			print_field(field);
			std::cout << std::endl;
			for (i = 0; i < 24; i++) {
				Sleep(30);
				std::cout << n[i];
			}
			std::cout << std::endl;
			Sleep(400);
			return 0;
		}
	} while (1);
}
