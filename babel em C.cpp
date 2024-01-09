#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
        //      ------------------->>>>>>>>>>>>>!!!!!!!!!!!!!!!!!============SO RODA NO CODE BLOCK=========!!!!!!!!!!!!!!!!!!!!!!!<<<<<<<<<<<<<<<<<<<<<<<<<-------------------------
#define INF INT_MAX

typedef long long ll;

int dist[4005][26];

int main() {
    int n;
    char origem[25], destino[25];
    int marcaVertice;
    int i;
    char s1[25], s2[25], s3[25];
    int* adj[4005];
    int* adj_cost[4005];
    int adj_count[4005];
    int* queue;
    bool* in_queue;
    int queue_head, queue_tail;
    int u, v, cost;
    int new_dist;

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;

        scanf("%s %s", origem, destino);

        marcaVertice = 3;
        for (i = 0; i < 4005; i++) {
            adj_count[i] = 0;
        }

        for (i = 0; i < n; i++) {
            scanf("%s %s %s", s1, s2, s3);
            int x, y;
            if (strcmp(s1, origem) == 0) {
                x = 1;
            } else if (strcmp(s1, destino) == 0) {
                x = 2;
            } else {
                x = marcaVertice;
                marcaVertice++;
            }
            if (strcmp(s2, origem) == 0) {
                y = 1;
            } else if (strcmp(s2, destino) == 0) {
                y = 2;
            } else {
                y = marcaVertice;
                marcaVertice++;
            }
               adj[x]= y;
           adj_count[x]=y;
           adj_cost[x]= strlen(s3);
           adj_count[x]= strlen(s3);
            adj_count[x]++;
            adj[y]= x;
            adj_count[y] = x;
            adj_cost[y]= strlen(s3);
            adj_count[y] = strlen(s3);
            adj_count[y]++;
        }

        for (int i = 0; i < 4005; i++) {
            for (int j = 0; j < 26; j++) {

dist[i][j] = INF;
}
}
for (int i = 0; i < 26; i++) {
dist[1][i] = 0;
}

//Copy code
   queue = malloc(sizeof(int) * (2 * n + 10));
    in_queue = malloc(sizeof(bool) * (2 * n + 10));
    memset(in_queue, 0, sizeof(bool) * (2 * n + 10));
    queue_head = 0;
    queue_tail = 0;
    queue= 1;
    queue_tail = 1;
    queue_tail++;
    in_queue[1] = true;

    while (queue_head != queue_tail) {
        u = queue;
        queue_head++;
        in_queue[u] = false;
        for (i = 0; i <=adj_count[u]; i++) {
           v = adj[u];
             v = adj[i];
            cost = adj_cost[u];
            cost = adj_cost[i];
            new_dist = dist[u][s3[0] - 'a'] + cost;
            if (dist[v][s3[0] - 'a'] > new_dist) {
                dist[v][s3[0] - 'a'] = new_dist;
                if (!in_queue[v]) {
                    queue= v;
                    queue_tail= v;
                    queue_tail++;
                    in_queue[v] = true;
                }
            }
        }
    }

    int mn = INF;
    for (int i = 0; i < 26; i++) {
        mn = (mn > dist[2][i]) ? dist[2][i] : mn;
    }

    if (mn == INF) {
        printf("impossivel\n");
    } else {
        printf("%d\n", mn);
    }

    free(queue);
    free(in_queue);
}

return 0;
}
