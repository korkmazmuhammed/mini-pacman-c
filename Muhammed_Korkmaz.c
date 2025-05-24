#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char my_array[256] = {'\0'}; /* Array to represent the game board */
int start_point = 0;         /* Starting point (P) */
int ECTS = 0;                /* Total ECTS (collected) */
int collect_one = 0;         /* Counts collected 1 */
int collect_two = 0;         /* Counts collected 2 */
int move_num = 0;            /* Number of moves*/
int flag = 1;                /* Flag of the game loop */
char direction;              /* Direction input  */
int point = 0;               /* Index for the game board */
char character;              /* Character at the current position*/

char move_player(char direction)
{
    int wall_hit = 0; /* Variable that prevents passing through the wall */

    switch (direction)
    {
    case 'w':
    case 'W':

    case 's':
    case 'S':

    case 'a':
    case 'A':

    case 'd':
    case 'D':

        int next_point; /* Variable to store the next point*/

        switch (direction)
        {
        case 'w':
        case 'W':

            next_point = start_point - 16; /* Move upwards by 16 */
            break;
        case 's':
        case 'S':

            next_point = start_point + 16; /* Move downwards by 16*/
            if (next_point > 256)          /* Check if the next point exceeds the board size */
            {
                next_point -= 16; /* If it exceeds adjust to the last row */
            }
            break;
        case 'a':
        case 'A':

            next_point = start_point - 1; /* Move left by 1 */
            break;
        case 'd':
        case 'D':

            next_point = start_point + 1; /* Move right by 1 */
            break;
        }

        character = my_array[next_point]; /* Get the character at the next point */

        /* Check the character at the next point and do the requirements */
        if (character == '1')
        {
            ECTS += 8;
            collect_one++;
            my_array[start_point] = '.';
            my_array[next_point] = 'P';
            start_point = next_point;
            move_num++;
        }
        else if (character == '2')
        {
            ECTS += 8;
            collect_two++;
            my_array[start_point] = '.';
            my_array[next_point] = 'P';
            start_point = next_point;
            move_num++;
        }
        else if (character == '#')
        {
            /* Check conditions for collecting enough ECTS to pass through the wall */
            if (collect_one == 4 || collect_two >= 3)
            {
                /* Determine the direction of the wall hit */
                if (direction == 'w')
                    wall_hit = -16;
                else if (direction == 's')
                    wall_hit = 16;
                else if (direction == 'd')
                    wall_hit = 1;
                else if (direction == 'a')
                    wall_hit = -1;
                else
                    wall_hit = 0;

                collect_one++;
                next_point += wall_hit;
                my_array[start_point] = '.';
                my_array[next_point] = 'P';
                start_point = next_point;
                move_num++;
            }
            else
            {
                printf("You have not collected enough ECTS\n");
            }
        }
        else if (character == '.')
        {
            my_array[start_point] = '.';
            my_array[next_point] = 'P';
            start_point = next_point;
            move_num++;
        }
        else if (character == 'X')
        {
            my_array[start_point] = '.';
            my_array[next_point] = 'P';
            move_num++;
            return 0; /* End of the game */
        }
        else
        {
            printf("You hit the wall !\n");
        }
        break;
    default:
        printf("Invalid direction\n");
    }
}
void initialize_game()
{
    int init_one = 0; /* Counter for 1 to initialize */
    int count = 0;    /* Counter for 1 to help to initialize */
    int init_two = 0; /* Counter for 1 to initialize */
    srand(time(NULL));

    int y; /*column*/
    int x; /*row*/

    /* Loop of the game board that initialize the board to array */
    for (x = 1; x <= 16; x++)
    {
        for (y = 1; y <= 16; y++)
        {
            /* Check conditions to draw the board */
            if (x == 16 && y == 16)
            {
                printf("X "); /* Place the X */
                my_array[point] = 'X';
                point++;
            }
            else if (((x == 6 || x == 12) && (y >= 6 && y <= 12)) || ((x >= 6 && x <= 12) && (y == 6 || y == 12)))
            {
                int random2 = rand() % 4;
                if (random2 == 2 && init_two < 16)
                {
                    printf("2 "); /* Place the 2's*/
                    my_array[point] = '2';
                    point++;
                    init_two++;
                }
                else
                {
                    printf(". "); /* Place a (.) */
                    my_array[point] = '.';
                    point++;
                }
            }
            else if (x >= 5 && x <= 13)
            {
                if ((x == 7 || x == 11) && (y >= 7 && y <= 11))
                {
                    printf("# "); /* Place walls */
                    my_array[point] = '#';
                    point++;
                }
                /* Place walls */
                else if ((x > 7 && x < 11) && (y == 7 || y == 11))
                {
                    printf("# ");
                    my_array[point] = '#';
                    point++;
                }
                else if ((x == 5 || x == 13) && (y >= 5 && y <= 13))
                {
                    printf("# ");
                    my_array[point] = '#';
                    point++;
                }
                else if ((x > 5 && x < 13) && (y == 5 || y == 13))
                {
                    printf("# ");
                    my_array[point] = '#';
                    point++;
                }
                else if (x == 9 && y == 9)
                {
                    printf("P "); /* Place the (P) */
                    my_array[point] = 'P';
                    start_point = point;
                    point++;
                }
                else
                {
                    if (((x == 8 || x == 10) && (y >= 8 && y <= 10)) || ((x == 9) && (y == 8 || y == 10)))
                    {
                        int random = rand() % 2;

                        count++;
                        /* Place the 1's */
                        if ((count == 1 || count == 8 || count == 4) && (init_one < 4))
                        {
                            printf("1 ");
                            my_array[point] = '1';
                            point++;
                            init_one++;
                        }
                        else if (random == 1 && init_one < 4)
                        {
                            printf("1 ");
                            my_array[point] = '1';
                            point++;
                            init_one++;
                        }
                        else
                        {
                            printf(". "); /* Place a (.)*/
                            my_array[point] = '.';
                            point++;
                        }
                    }
                    else
                    {
                        printf(". "); /* Place a (.)*/
                        my_array[point] = '.';
                        point++;
                    }
                }
            }
            else
            {
                printf(". "); /* Place a (.)*/
                my_array[point] = '.';
                point++;
            }
        }
        printf("\n");
    }
}

void print_board()
{
    for (point = 0; point < 256; point++)
    {
        printf("%c ", my_array[point]); /* Print each character on the game board */
        if ((point + 1) % 16 == 0)      /* Check if it's the end of a row */
            printf("\n");               /* Move to the next line */
    }
    printf("\n");
    printf("Total ECTS: %d\n", ECTS); /* Print total ECTS collected */
}

int main()
{
    initialize_game(); /* Initialize the game board */

    /* Main game loop */
    while (flag)
    {
        printf("Enter your move: ");
        scanf(" %c", &direction); /* Get the player's move */
        printf("\n");
        flag = move_player(direction); /* Move the player and update the flag */
        print_board();                 /* Print the updated game board */

        /* Check if the game is over */
        if (flag == 0)
        {
            printf("Total Movements: %d", move_num); /* Print total movements */
            printf("\nGame Over\n");                 /* Print game over message */
        }
    }

    return 0;
}
