#include <stdio.h>

// Function to find and display the combinations of plays for a given score
void findCombinations(int score) {
    int td_2pt, td_fg, td, fg, safety;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
    
    for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (td_fg = 0; (td_2pt * 8 + td_fg * 7) <= score; td_fg++) {
            for (td = 0; (td_2pt * 8 + td_fg * 7 + td * 6) <= score; td++) {
                for (fg = 0; (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3) <= score; fg++) {
                    for (safety = 0; (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2) <= score; safety++) {
                        if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        // Prompt user for input
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // Break the loop if the score is 0 or 1
        if (score <= 1) {
            break;
        }

        // Call the function to find and display combinations
        findCombinations(score);
    }

    return 0;
}
