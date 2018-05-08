#include <stdio.h>
#include <queue.h>

#define N 6

struct adj_matrix {
	int vertex[N];
	int edge[N][N];
};

struct adj_matrix matrix = {
	{1, 2, 3, 4, 5, 6},

	{{0, 1, 0, 1, 0, 0},
	 {0, 0, 0, 0, 1, 0},
	 {0, 0, 0, 0, 1, 1},
	 {0, 1, 0, 0, 0, 0},
	 {0, 0, 0, 1, 0, 0},
	 {0, 0, 0, 0, 0, 1}}
};

int visit[N] = {0, 0, 0, 0, 0, 0};

void bfs(struct adj_matrix *G)
{
	int i, j;
	int x;

	for (i = 0; i < N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;

			printf("%3d", G->vertex[i]);

			enqueue(i);
			while (!queue_empty()) {
				x = dequeue();
				for (j = 0; j < N; j++) {
					if (G->edge[x][j] == 1 && visit[j] != 1) {
						visit[j] = 1;
						printf("%3d", G->vertex[j]);
						enqueue(j);
					}
				}
			}
		}
	}
}

int main(void)
{
	bfs(&matrix);
	printf("\n");

	return 0;
}
