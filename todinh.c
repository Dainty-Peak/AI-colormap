#include <stdio.h>

// Định nghĩa số đỉnh của đồ thị
#define V 5

// Hàm kiểm tra xem có thể sử dụng màu c cho đỉnh v hay không
int is_safe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Hàm đệ quy để tô màu đồ thị bắt đầu từ đỉnh v
int graph_coloring_util(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c)) {
            color[v] = c;
            if (graph_coloring_util(graph, m, color, v + 1)) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

// Hàm chính để tô màu đồ thị sử dụng số lượng màu ít nhất
int graph_coloring(int graph[V][V], int m) {
    int color[V];
    char *mau[] = {"do", "cam", "vang", "hong", "xanh"};
    
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graph_coloring_util(graph, m, color, 0) == 0) {
        return 0; // Không có giải pháp
    }

    printf("Tô màu thành công: Sử dụng ít nhất %d màu.\n", m);

    for (int i = 0; i < V; i++) {
        printf("Đỉnh %d sẽ được tô màu %s\n", i + 1, mau[color[i] - 1]);
    }

    return 1;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0}
    };
    int m = 5; // Số màu có sẵn

    if (!graph_coloring(graph, m)) {
        printf("Không có giải pháp.\n");
    }

    return 0;
}
