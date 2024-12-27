#include<stdio.h>
#include<conio.h>

// Function prototypes
void sort(int p[], int d[], int n);
int job(int d[], int j[], int n);

void main() {
    int d[10], j[10], p[10], k, i, n, profit = 0;
    clrscr();
    printf("Enter the number of jobs\n");
    scanf("%d", &n);

    printf("Enter deadlines\n");
    for (i = 1; i <= n; i++) {
	scanf("%d", &d[i]);
    }

    printf("Enter profits\n");
    for (i = 1; i <= n; i++) {
	scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++) {
	j[i] = 0;  // Initialize job array to 0
    }

    sort(p, d, n);
    k = job(d, j, n);

    printf("Job Number  Profit  Deadline\n");
    for (i = 1; i <= k; i++) {
	if (j[i] != 0) {  // Only print scheduled jobs
	    printf("%3d\t   %3d\t  %3d\n", i, p[j[i]], d[j[i]]);
	    profit = profit + p[j[i]];
	}
    }

    printf("Total profit: %d\n", profit);

    getch();
}


void sort(int p[], int d[], int n) {
    int i, j, t;
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n - i; j++) {  // Corrected loop condition
	    if (p[j] < p[j + 1]) {
		t = p[j];
		p[j] = p[j + 1];
		p[j + 1] = t;

		t = d[j];
		d[j] = d[j + 1];
		d[j + 1] = t;
	    }
	}
    }
}

int job(int d[], int j[], int n) {
    int q, r, k, i;
    d[0] = j[0] = 0;
    k = 0;  // Initialize k to 0
    for (i = 1; i <= n; i++) {
        r = k;
        while ((d[j[r]] > d[i]) && (r > 0)) {  // Corrected condition
            r = r - 1;
        }
        if ((d[j[r]] <= d[i]) && (d[i] > r)) {
            for (q = k; q >= r + 1; q--) {  // Corrected loop direction
                j[q + 1] = j[q];
            }
            j[r + 1] = i;
            k = k + 1;
        }
    }
    return k;
}
