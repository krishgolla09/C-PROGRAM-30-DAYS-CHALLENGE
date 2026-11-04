
#include <stdio.h>
#define ROWS 5
#define COLS 8

void menu(void);
void printHall(int h[ROWS][COLS]);
void groupBooking(int h[ROWS][COLS]);
void takeSeat(int h[ROWS][COLS]);
void freeSeat(int h[ROWS][COLS]);
void report(int h[ROWS][COLS]);

int main(void)
{
  int h[ROWS][COLS] = {0};
   int pick;
 printf("cinema booking, rows 1-%d seats 1-%d\n", ROWS, COLS);
  for (;;) {
  menu();
 scanf("%d", &pick);

   if (pick == 6) break;
  else if (pick == 1) printHall(h);
 else if (pick == 2) takeSeat(h);
 else if (pick == 3) freeSeat(h);
  else if (pick == 4) groupBooking(h);
else if (pick == 5) report(h);
 else printf("1 to 6 only\n");
    }
 printf("closing\n");
    return 0;
}
void menu(void)
{
 printf("\n1 seats  2 book  3 cancel  4 group  5 stats  6 exit\n");
  printf("> ");
}
void printHall(int h[ROWS][COLS])
{ int i, j;
 printf("\n   ");
  for (j = 1; j <= COLS; j++) printf("%d", j);
 printf("\n");
for (i = 0; i < ROWS; i++) {
 printf("%d |", i + 1);
for (j = 0; j < COLS; j++) printf("%c", h[i][j] ? 'X' : '-');
printf("\n");
 }
printf("  X = taken, - = free\n");
}
void groupBooking(int h[ROWS][COLS])
{
int want, i, j, start, ok;
printf("how many together? ");
 scanf(" %d", &want);
 while (want < 1 || want > COLS) {
printf("must be 1-%d, again: ", COLS);
  scanf(" %d", &want);
    }
 for (i = 0; i < ROWS; i++)
        for (start = 0; start <= COLS - want; start++) {
    ok = 1;
    for (j = start; j < start + want; j++)
       if (h[i][j]) { ok = 0; break; }

            if (!ok) continue;

            for (j = start; j < start + want; j++) h[i][j] = 1;
            printf("booked row %d, seats %d-%d\n", i + 1, start + 1, start + want);
            return;
                }

    printf("nothing free for %d in a row\n", want);
}

void takeSeat(int h[ROWS][COLS])
{
    int r, c;

 printf("row seat: ");
scanf(" %d %d", &r, &c);

    r--; c--;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("out of range\n");
 return;
    }

if (h[r][c]) {
   printf("row %d seat %d already taken\n", r + 1, c + 1);
        return;
    }

    h[r][c] = 1;
 printf("ok, row %d seat %d is yours\n", r + 1, c + 1);
}

void freeSeat(int h[ROWS][COLS])
{
int r, c;
 printf("row seat to cancel: ");
 scanf(" %d %d", &r, &c);

    r--; c--;
 if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
    printf("out of range\n");
    return;
    }
 if (!h[r][c]) {
  printf("that one was empty anyway\n");
        return;
    }
 h[r][c] = 0;
 printf("row %d seat %d cancelled\n", r + 1, c + 1);
}

void report(int h[ROWS][COLS])
{
    int i, j, used = 0;
    float pct;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (h[i][j]) used++;

    pct = (float)used * 100.0f / (ROWS * COLS);

    printf("\nused %d, empty %d\n", used, ROWS * COLS - used);
    printf("that is %.1f%% of the hall\n", pct);
}
