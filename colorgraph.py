import networkx as nx
from networkx import network_simplex as nx
import matplotlib.pyplot as plt

def greedy_region_coloring(graph, regions):
    colors = {}  # Dictionary để lưu màu của từng vùng

    # Sắp xếp các vùng theo thứ tự giảm dần của số lượng vùng kề nhau
    sorted_regions = sorted(regions.keys(), key=lambda region: -len(regions[region]))

    for region in sorted_regions:
        # Tìm các màu đã được sử dụng bởi các vùng kề nhau với vùng hiện tại
        used_colors = {colors[neighbor] for neighbor in regions[region] if neighbor in colors}

        # Chọn màu đầu tiên từ tập hợp màu có thể sử dụng mà chưa được sử dụng bởi các vùng kề nhau
        for color in range(1, len(regions) + 1):
            if color not in used_colors:
                colors[region] = color
                break

    return colors

def main():
    graph = {
        "A": ["B", "C", "D"],
        "B": ["A", "E", "C"],
        "C": ["A", "B", "D", "E", "F"],
        "D": ["A", "C", "F", "G"],
        "E": ["B", "C", "F", "Z"],
        "F": ["C", "D", "E", "Z", "G"],
        "G": ["D", "F", "Z"],
        "Z": ["E", "F", "G"]
    }

    result = greedy_region_coloring(graph, graph)

    # In kết quả
    for region, color in result.items():
        print(f"Đỉnh {region} được tô màu {color}")

    # Vẽ đồ thị minh họa
    G = nx.Graph(graph)
    pos = nx.spring_layout(G)
    node_colors = [result[node] for node in G.nodes()]
    nx.draw(G, pos, with_labels=True, node_color=node_colors, cmap=plt.cm.rainbow)
    plt.show()

if __name__ == "__main__":
    main()

#opencv 